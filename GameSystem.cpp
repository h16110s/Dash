#include "GameSystem.h"

//表示用
//齊藤裕仁
void GameSystem::systemMessage() {
	printf("イベント：%s", sysMsg);
	strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "");
}

//Quizファイルの初期化を行う
//金子凌也
void GameSystem::Quiz_Set(){
	int c, i, j;
	FILE *fp;
	fopen_s(&fp, "./Quiz.txt", "r");
	if (fp == NULL){
		printf("クイズファイルがありません。\n");
		exit(0);
	}

	for (i = 0; i < MAX_QUIZ_NUM; i++){
		//問題文
		fscanf(fp, "%s", &(quiz[i].question));
		for (j = 0; j < 4; j++){
			//選択肢(*4)
			fscanf(fp, "%s", &(quiz[i].select[j]));
		}
		//正解の番号(1~4)
		fscanf(fp, "%d", &(quiz[i].answer));
		quiz[i].already = false;
	}
}


//ゲームシステムの初期化
//齊藤裕仁
void GameSystem::init() {
	dungeon.initDungeon();
	hero.initHero();
	Clear = false;
	submit = false;
	Quiz_Set();
	strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "");
	srand((unsigned)time(NULL));
}


//表示関数
//齊藤裕仁
void GameSystem::display(){
	COORD coord;
	HANDLE hStdout;
	//出力用の部屋を生成
	Room disp;
	disp.roomCopy(dungeon.room[hero.roomNum]);
	disp.pos[hero.y][hero.x] = HERO;
	disp.printRoom();

	//インフォメーションウィンドウの作成
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	for (coord.Y = 0; coord.Y < MAX_WINDOW_HEIGHT - 4; coord.Y++){
		coord.X = MAX_WINDOW_WIDTH - 50;
		SetConsoleCursorPosition(hStdout, coord);
		switch (coord.Y)
		{
		case 0:
			printf("|課題の提出状況：");
			if (submit){ printf("提出済み"); }
			else { printf("未提出"); }
			break;
		case 1:
			printf("|残り行動回数 : %4d", hero.hp);
			break;
		case 2:
			printf("|所持ポーション数: %4d", hero.potion);
			break;
		case 3:
			printf("|追加課題数	: %4d", hero.issue);
			break;
		case 4:
			printf("|現在いるフロア　: %4d", hero.roomNum);
			break;
		case 5:
			printf("|PCの残りバッテリー: %4d％ ", hero.charge * 10);
			break;
		default:
			printf("|");
			break;
		}
	}

	//イベントメッセージウィンドウの作成
	coord.X = 0;
	coord.Y = MAX_WINDOW_HEIGHT - 4;
	SetConsoleCursorPosition(hStdout, coord);
	printf("==========================================================================\n");
	systemMessage();
}


//ゲームシステムのメインループ
//齊藤裕仁
void GameSystem::mainLoop() {
	display();
	while (!Clear && hero.hp > 0) {
		//操作
		if (hero.move(inputKeyBoard())) {
			switch (dungeon.room[hero.roomNum].pos[hero.y][hero.x]) {
			case ENEMY://敵だったら
				strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "邪魔をされた　行動可能回数-2\n");
				hero.damage(1);
				break;
			case HEAL://回復アイテムだったら
				strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "こ、これさえあれば・・・ 回復アイテム+1\n");
				hero.potion++;
				dungeon.room[hero.roomNum].eliminateObject(hero.x, hero.y);
				break;
			case ISSUE://追加課題だったら
				strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "追加課題やればSとれるんじゃないか説！\n");
				hero.issue++;
				dungeon.room[hero.roomNum].eliminateObject(hero.x, hero.y);
				break;
			case 'W': //WifiSpot
				if (hero.charge > 80){
					strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "課題の提出をしますか? Y/N -> ");
					hero.action(dungeon.room[hero.roomNum].pos[hero.y][hero.x]);
					system("cls");
					display();
					if (getchar() == 'Y' || getchar() == 'y'){
						submit = true;
					}
					else continue;
				}
				else {
					strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "PCを充電しないと提出できんな");
				}
				break;
			case 'C': //ChargeSpot
				strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "このPC・・・動くぞ！？");
				hero.charge = 100;
				break;
			default:
				strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "何もなかった\n");
				break;
			}
			hero.action(dungeon.room[hero.roomNum].pos[hero.y][hero.x]);
		}
		else {
			strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "前見て歩け\n");
		}
		system("cls");
		display();
		//ボス部屋ならば
		if (hero.roomNum == bossRoom){
				system("cls");
				Clear = battle();
		}
	}
}

//ゲームのメニュー表示
//齊藤裕仁
void GameSystem::printMenu() {
	while (1) {
		printf("==================================================\n");
		printf("		  単位DASH\n");
		printf("==================================================\n");
		printf("     ゲームスタート : 1         ルール説明：2 \n");
		printf("-> ");
		char input = getchar();
		if (input == '2') {
			printRule();
		}
		else if (input == '1') {
			printf("ゲーム開始！！\n");
			break;
		}
		else {
			printf("関係のないものを押したな？\n");
			printf("ゲームスタートだ\n");
			break;
		}
	}
}

//キー入力関数
char GameSystem::inputKeyBoard() {
	while (1) {
		if (_kbhit()) {
			int ch = _getch();
			switch ((char)ch) {
			case 'w':
			case 's':
			case 'a':
			case 'd':
			case 'h':
				return (char)ch;
			default:
				continue;
			}
			break;
		}
	}
}
Quiz GameSystem::getQuiz(){
	for (int i = 0; i < MAX_QUIZ_NUM; i++){
		int n = rand() % MAX_QUIZ_NUM;
		if (quiz[n].already){
			continue;
		}
		else {
			quiz[n].already = true;
			//printf("%d", n);
			return quiz[n];
		}
	}
	printf("問題足りないっすわ");
}


bool GameSystem::battle(){
	Quiz q;
	int bossHP = 100;
	int count = 0;
	while (1){
		if (bossHP <= 0)	return true;
		else if (hero.hp <= 0){
			Clear = true;
			return false;
		}

		hero.printState();
		printf("========================================\n");
		printf("ボスHP：%4d\n", bossHP);
		//問題の表示＝＝＝＝＝＝
		q = getQuiz();
		printf("\n");
		q.Quiz_View();
		//==============

		//入力待ち＝＝＝＝＝＝＝
		int input;
		scanf_s("%d", &input);
		//==============

		//答えとの照合＝＝＝＝＝＝
		//あってるー＞ボスのHPを減らす
		//間違ってるー＞主人公のHPを減らす
		if (input == q.answer){
			printf("正解！\n");
			bossHP -= 15;
		}
		else {
			printf("残念\n");
			//printf("%d\n", q.answer);
			//printf("%d\n",input);
			hero.damage(10);
		}
		//==============
		getchar();
		fflush(stdin);
		system("cls");
	}
}



//ゲームのルール表示
//松本風雅
void GameSystem::printRule() {
	system("cls");
	printf("〜ストーリー〜\n遅刻しすぎて単位を落としそうな「工科太郎」くん。\n次に遅刻したら出席日数が足りなくて落単が決定してしまう。\n");
	printf("しかし、今日に限って課題提出もしなくてはいけない...。\n\n工科太郎は無事、授業時間に間に合うことができるのか！？\n");
	getchar();

	printf("〜ルール〜\n①課題をWi-Fiスポットに行って提出。\n(太郎君はPCを持っているが、充電がない。\n充電スポットを先に探して、充電してください。)\n");
	getchar();

	printf("②提出後、授業に間に合うよう片研にGO!!\n(敵・回復アイテム(初期2つ所持)・追加課題が出現！)\n");
	getchar();

	printf("③片研にはボスが...。\n(君は倒せるかな？)\n");
	getchar();

	printf("〜移動中ルール〜\n・行動可能回数(HP)は初期30回\n・1行動につき1HP減少\n・敵と接触した場合2減少\n・回復アイテムの使用でHPが15回復\n");
	printf("※敵か回復アイテム、追加課題は接触しないとわかりません。\n");
	getchar();

	printf("〜ボス戦ルール〜\n");
	printf("ボス戦はクイズ形式になります\n・間違えるとHPが10減少\n・3問正解でボスに勝利！\n\n");
	getchar();

	printf("最後に、行動可能回数(HP)と課題の提出状況(追加課題のも含む)を加味し、\nスコアが算出されます。\n");
	getchar();

	printf("さぁ、君は工科太郎の単位を救うことはできるのか？\n");
	system("cls");
}


