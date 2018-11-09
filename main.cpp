#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Room.h"
#include "Dungeon.h"
#include "HERO.h"
//GameSystem Function=======
char inputKeyBoard();
void printMenu();
void printRule();
void getObject();
//=====================
bool clear = false;

int main(void)
{
	Dungeon dungeon = initDungeon();
	Room disp = {1};
	Hero hero = initHero();

	printMenu();
	system("cls");

	//dungeon.room[hero.roomNum].pos[hero.y][hero.x] = HERO;
	disp.roomCopy(dungeon.room[hero.roomNum]);
	disp.pos[hero.y][hero.x] = HERO;
	printRoom(disp);

	while (!clear){
		//操作
		hero.move(inputKeyBoard());
		system("cls");

		switch (dungeon.room[hero.roomNum].pos[hero.x][hero.y]){
			case ENEMY://敵だったら
				hero.damage(2);
				break;
			case HEAL://回復アイテムだったら
				hero.potion++;
				dungeon.room[hero.roomNum].eliminateObject(hero.x, hero.y);
				break;
			case ISSUE://追加課題だったら
				hero.issue++;
				dungeon.room[hero.roomNum].eliminateObject(hero.x, hero.y);
				break;
		}

		//表示
		disp.roomCopy(dungeon.room[hero.roomNum]);
		disp.pos[hero.y][hero.x] = HERO;
		printRoom(disp);
		hero.printState();
	}

	return 0;
}


//齊藤
char inputKeyBoard(){
	while (1) {
		if (_kbhit()) {
			int ch = _getch();
			switch ((char)ch){
			case 'w':
			case 's':
			case 'a':
			case 'd':
				return (char)ch;
			default:
				continue;
			}
			break;
		}
	}
}

//齊藤
void printMenu(){
	while (1){
		printf("==================================================\n");
		printf("		  単位DASH\n");
		printf("==================================================\n");
		printf("     ゲームスタート : 1         ルール説明：2 \n");
		printf("-> ");
		char input = getchar();
		if (input == '2'){
			printRule();
		}
		else if (input == '1'){
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


//松本風雅
void printRule(){
	system("cls");
	printf("～ストーリー～\n遅刻しすぎて単位を落としそうな「工科太郎」くん。\n次に遅刻したら出席日数が足りなくて落単が決定してしまう。\n");
	printf("しかし、今日に限って課題提出もしなくてはいけない...。\n\n工科太郎は無事、授業時間に間に合うことができるのか！？\n");
	getchar();

	printf("～ルール～\n①課題をWi-Fiスポットに行って提出。\n(太郎君はPCを持っているが、充電がない。\n充電スポットを先に探して、充電してください。)\n");
	getchar();

	printf("②提出後、授業に間に合うよう片研にGO!!\n(敵・回復アイテム(初期2つ所持)・追加課題が出現！)\n");
	getchar();

	printf("③片研にはボスが...。\n(君は倒せるかな？)\n");
	getchar();

	printf("～移動中ルール～\n・行動可能回数(HP)は初期30回\n・1行動につき1HP減少\n・敵と接触した場合2減少\n・回復アイテムの使用でHPが15回復\n");
	printf("※敵か回復アイテム、追加課題は接触しないとわかりません。\n");
	getchar();

	printf("～ボス戦ルール～\n");
	printf("ボス戦はクイズ形式になります\n・間違えるとHPが10減少\n・3問正解でボスに勝利！\n\n");
	getchar();

	printf("最後に、行動可能回数(HP)と課題の提出状況(追加課題のも含む)を加味し、\nスコアが算出されます。\n");
	getchar();

	printf("さぁ、君は工科太郎の単位を救うことはできるのか？\n");
	system("cls");
}
