#include "GameSystem.h"

//表示用
//齊藤裕仁
void GameSystem::systemMessage() {
	printf("イベント：%s", sysMsg);
	strcpy_s(sysMsg,SYS_MSG_MAXLENGTH ,"");
}


//ゲームシステムの初期化
//齊藤裕仁
void GameSystem::init() {
	dungeon.initDungeon();
	hero.initHero();
	Clear = false;
	submit = false;
	strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "");
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
			if (submit){ printf("提出済み");}
			else { printf("未提出"); }
			break;
		case 1:
			printf("|残り行動回数 : %4d", hero.hp);
			break;
		case 2:
			printf("|所持ポーション数: %4d", hero.potion);
			break;
		case 3 :
			printf("|追加課題数	: %4d", hero.issue);	
			break;
		case 4:
			printf("|現在いるフロア　: %4d", hero.roomNum);
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
	while ( !Clear && hero.hp > 0) {
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


