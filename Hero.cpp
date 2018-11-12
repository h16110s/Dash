#include "Hero.h"
void Hero::initHero(){
	hp = 30;
	x = 0;
	y = 0;
	roomNum = busStop;
	charge = 100;
	potion = 2;
	issue = 0;
}

bool Hero::move( char key){
	//上下左右に移動
	//4*4以内で移動(0 <= x < 4 && 0 <= y < 4)
	switch (key){
		case 'w'://上
			if (y == 0)return false;
			y--;
			break;

		case 's'://下
			if (y == ROOM_NUM)return false;
			y++;
			break;

		case 'a'://左
			if (x == 0)return false;
			x--;
			break;

		case 'd'://右
			if (x == ROOM_NUM)return false;
			x++;
			break;
	}
	hp--;
	return true;
}

void Hero::action(char mark){
	switch (mark){
		//Gate01
		case 'a':
			roomNum = plaza;
			x = 0;
			break;
		case 'b':
			roomNum = busStop;
			x = 3;
			break;

		//Gate12
		case 'c':
			roomNum = central;
			y = 3;
			break;
		case 'd':
			roomNum = plaza;
			y = 0;
			break;

		//Gate23
		case 'e':
			roomNum = wifiSpot;
			y = 3;
			break;
		case 'f':
			roomNum = plaza;
			y = 0;
			break;

		//Gate24
		case 'g':
			roomNum = chargeSpot;
			x = 0;
			break;
		case 'h':
			roomNum = plaza;
			x = 3;
			break;

		//Gate25
		case 'i':
			roomNum = leftPath1;
			y = 0;
			break;
		case 'j':
			roomNum = plaza;
			y = 3;
			break;

		//Gate26
		case 'k':
			roomNum = rightPath1;
			y = 0;
			break;
		case 'l':
			roomNum = plaza;
			y = 3;
			break;

		//Gate57
		case 'm':
			roomNum = leftPath2;
			y = 0;
			break;
		case 'n':
			roomNum = leftPath1;
			y = 3;
			break;

		//Gate68
		case 'o':
			roomNum = rightPath2;
			y = 0;
			break;
		case 'p':
			roomNum = rightPath1;
			y = 3;
			break;

		//Gate59
		case 'q':
			roomNum = katakura;
			y = 0;
			break;
		case 'r':
			roomNum = leftPath2;
			y = 3;
			break;

		//Gate89
		case 's':
			roomNum = katakura;
			y = 0;
			break;
		case 't':
			roomNum = rightPath2;
			y = 3;
			break;

		//Gate910
		case 'u':
			roomNum = bossRoom;
			y = 0;
			break;
		case 'v':
			roomNum = katakura;
			y = 3;
			break;
		default:
			break;
	}

}

void Hero::printState(){
	printf("残り行動回数    : %d\n", hp);
	printf("所持ポーション数: %d\n", potion);
	printf("追加課題数		: %d\n", issue);
	printf("現在いるフロア　: %d\n", roomNum);
	//printf("座表			x：%d  y：%d\n", x, y);
}



