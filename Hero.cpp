#include "Hero.h"

//Heroの初期化
//齊藤裕仁
void Hero::initHero(){
	hp = 30;
	x = 0;
	y = 0;
	roomNum = busStop;
	charge = 0;
	potion = 2;
	issue = 0;
}


//移動用の関数
//金子凌也
Action Hero::move( char key){
	//上下左右に移動
	//4*4以内で移動(0 <= x < 4 && 0 <= y < 4)
	switch (key) {
	case 'w'://上
		if (y == 0) return MOVEFAILD;
		y--;
		hp--;
		break;

	case 's'://下
		if (y == ROOM_NUM -1) return MOVEFAILD;
		y++;
		hp--;
		break;

	case 'a'://左
		if (x == 0) return MOVEFAILD;
		x--;
		hp--;
		break;

	case 'd'://右
		if (x == ROOM_NUM -1 ) return MOVEFAILD;
		x++;
		hp--;
		break;

	case 'h'://回復
		if (potion > 0){
			potion--;
			hp += USING_POTION_HP;
			return HEALING;
		}
		else {
			return HEALFAILD ;
		}
		break;
	case'm':
		break;
	}
	return MOVE;
}

void Hero::moveRoom(school pos){
	roomNum = pos;
}

void Hero::movePos(int inputY, int inputX){
	y = inputY;
	x = inputX;
}


//Hero情報の表示
//藤本周平
void Hero::printState(){
	printf("hp   : %d\n", hp);
	printf("potion: %d\n", potion);
	printf("issue	: %d\n", issue);
	printf("floor : %d\n", roomNum);
	//printf("座表			x：%d  y：%d\n", x, y);
}



