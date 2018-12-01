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
	//ボーナスクイズの読み込み
	fscanf(fp, "%s", &(quiz[i].question));
	fscanf(fp, "%s", &(quiz[i].ans));
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
		coord.X = MAX_WINDOW_WIDTH - 60;
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
			printf("|現在いるフロア　: %4s", getPosName(hero.roomNum));
			break;
		case 5:
			printf("|PCの残りバッテリー: %4d％ ", hero.charge );
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
	printf("次の目標：%s\n", getTask());
	systemMessage();
	//目標表示
	
}

//マップ移動用の関数
//齊藤裕仁
bool GameSystem::mapMove(char mark) {
	switch (mark) {
		//Gate01
	case 'a':
		hero.moveRoom(plaza);
		hero.movePos(hero.y, 0);
		return true;
	case 'b':
		hero.moveRoom(busStop);
		hero.movePos(hero.y, 3);
		return true;

		//Gate12
	case 'c':
		hero.moveRoom(central);
		hero.movePos(3, hero.x);
		return true;
	case 'd':
		hero.moveRoom(plaza);
		hero.movePos(0, hero.x);
		return true;

		//Gate23
	case 'e':
		hero.moveRoom(wifiSpot);
		hero.movePos(3, hero.x);
		return true;
	case 'f':
		hero.moveRoom(plaza);
		hero.movePos(0, hero.x);
		return true;

		//Gate24
	case 'g':
		hero.moveRoom(chargeSpot);
		hero.movePos(hero.y, 0);
		return true;
	case 'h':
		hero.moveRoom(plaza);
		hero.movePos(hero.y, 3);
		return true;

		//Gate25
	case 'i':
		hero.moveRoom(leftPath1);
		hero.movePos(0, 3);
		return true;
	case 'j':
		hero.moveRoom(plaza);
		hero.movePos(3, 1);
		return true;

		//Gate26
	case 'k':
		hero.moveRoom(rightPath1);
		hero.movePos(0, 0);
		return true;
	case 'l':
		hero.moveRoom(plaza);
		hero.movePos(3, 2);
		return true;

		//Gate57
	case 'm':
		hero.moveRoom(leftPath2);
		hero.movePos(0, hero.x);
		return true;
	case 'n':
		hero.moveRoom(leftPath1);
		hero.movePos(3, hero.x);
		return true;

		//Gate68
	case 'o':
		hero.moveRoom(rightPath2);
		hero.movePos(0, hero.x);
		return true;
	case 'p':
		hero.moveRoom(rightPath1);
		hero.movePos(3, 0);
		return true;

		//Gate59
	case 'q':
		hero.moveRoom(katakura);
		hero.movePos(0, 1);
		return true;
	case 'r':
		hero.moveRoom(leftPath2);
		hero.movePos(3, 3);
		return true;

		//Gate89
	case 's':
		hero.moveRoom(katakura);
		hero.movePos(0, 2);
		return true;
	case 't':
		hero.moveRoom(rightPath2);
		hero.movePos(3, 0);
		return true;

		//Gate910
	case 'u':
		hero.moveRoom(bossRoom);
		hero.movePos(0, hero.x);
		return true;
	case 'v':
		hero.moveRoom(katakura);
		hero.movePos(3, hero.x);
		return true;
	default:
		return false;
	}
}


//ゲームシステムのメインループ
//齊藤裕仁
void GameSystem::mainLoop() {
	display();
	while (!Clear && hero.hp > 0) {
		//操作
		int heroAction = hero.move(inputKeyBoard());

		//回復操作がされたとき
		if (heroAction == HEALING){
			strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "回復しました。\n");
		}
		else if (heroAction == HEALFAILD) {
			strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "回復できぬ！？\n");
		}

		//移動が成功しているとき
		else if (heroAction == MOVE) {
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
				hero.heal(5);
				dungeon.room[hero.roomNum].eliminateObject(hero.x, hero.y);
				break;
			case 'W': //WifiSpot
				if (hero.charge > 80){
					fflush(stdin);
					system("cls");
					strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "課題の提出をしますか? Y/n -> ");
					display();
					if (getIs()){
						submit = true;
						strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "課題が提出されました。");
					}
					else {
						submit = true;
						strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "出す気がなくても、完成してなくても...出す！！");
					}
						;
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

			if (mapMove(dungeon.room[hero.roomNum].pos[hero.y][hero.x])) {
				strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "部屋を移動しました。\n");
			}
		}
		else{ 
			strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "前見て歩け\n"); 
		}

		system("cls");
		//ボス挑戦権があれば
		if (hero.roomNum == bossRoom && submit && isEnterBossRoom()){
			Clear = battle();
		}
		else {
			display();
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
		printf("操作");
		printf("w:上　s:下　a:左　d:右　で動く\n");
		printf("矢印キーでもできる（はず！！！）\n");
		printf("その他の動作　H:回復\n\n");
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
		else if (input == '3') {
			hero.moveRoom(katakura);
			submit = true;
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
			// 矢印キー入力
			if (ch == 0xE0){
				ch = _getch();
				if (ch == 0x48) ch = 'w';
				if (ch == 0x50) ch = 's';
				if (ch == 0x4B) ch = 'a';
				if (ch == 0x4D) ch = 'd';
			}
			switch ((char)ch) {
			//許可入力
			case 'w':
			case 's':
			case 'a':
			case 'd':
			case 'h':
			case 'm':
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
			return quiz[n];
		}
	}
	printf("問題足りないっすわ");
}

bool GameSystem::battle(){
	Quiz q;
	int bossHP = 100;
	int count = 0;
	int damage = 0;
	while (1){
		
		//system("cls");
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
			//printf("%d\n", q.answer);
			//printf("%d\n",input);
			printf("不正解！！ライフで受けろ！\n");
			hero.damage(10);
			damage -= 0;
		}
		//==============
		fflush(stdin);
		getchar();
	}
	//if (damage == 0){
	//	system("cls");
	//	printf("================ボーナス問題！！＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n");
	//	printf("%s\n",quiz[MAX_QUIZ_NUM].question);
	//	getchar();
	//}
	return true;
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

	printf("最後に、行動可能回数(HP)と課題の提出状況(追加課題のも含む)を加味し、\nスコアが算出されます。\nクリアするまで頑張ってください。");
	getchar();

	printf("さぁ、君は工科太郎の単位を救うことはできるのか？\n");
	system("cls");
}


int GameSystem::calcScore(){
	int scoreHP = (hero.hp * 5);
	printf("scoreHP : %d\n", scoreHP);
	int scorePotion = (hero.potion * USING_POTION_HP * 8);
	printf("scorePotion : %d\n", scorePotion);
	int scoreIssue = (hero.issue * 10);
	printf("scoreIssue : %d\n", scoreIssue);
	int scoreSubmit= 0;
	if (submit){
		scoreSubmit = 200;
	}
	printf("scoreSubmit: %d\n", scoreSubmit);
	int scoreClear = 0;
	if (Clear){
		scoreClear = 100;
	}
	printf("scoreClear: %d\n", scoreClear);
	return scoreHP + scorePotion + scoreIssue + scoreSubmit + scoreClear;
}

bool GameSystem::getIs(){
	while (true){
		char input = getchar();
		switch (input){
		case 'y':
		case 'Y':
			return true;
			break;
		case 'n':
		case 'N':
			return false;
			break;
		default:
			continue;
		}
	}
	return false;
}

bool GameSystem::isEnterBossRoom()
{
	printf("ボスの部屋に入ります。\n");
	printf("ボス戦に挑戦すると回復不能、戻ってもこれませぬ\n");
	printf("ボス戦に挑みますかな？\n Y/n? -> ");
	if (!getIs()) {
		system("cls");
		hero.moveRoom(katakura);
		hero.movePos(3, hero.x);
		return false;
	}
	system("cls");
	return true;
}

const char* GameSystem::getTask(){
	if (hero.charge == 0){
		return "PCの充電をしましょう";
	}
	else if (!submit){
		return "課題の提出をするためにWi-Fiが使える場所（W）に行こう";
	}
	else if (!Clear){
		return "ボスの部屋に向え！";
	}
}

const char* GameSystem::getPosName(school floor){
	switch (floor)
	{
	case wifiSpot:
		return "WiFiがつかえる";
	case central:
		return "朝の調べ";
	case busStop:
		return "八王子行きのバス停";
	case plaza:
		return "中央広場";
	case chargeSpot:	
		return "充電ポイント";
	case leftPath1:
	case rightPath1:	
		return "通路１";
	case leftPath2:	
	case rightPath2:	
		return "通路２";
	case katakura:	
		return "かたけん";
	case bossRoom:	
		return "ぼすのへや";
	default:
		break;
	}
	return "\0";
}
