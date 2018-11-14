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
	//�㉺���E�Ɉړ�
	//4*4�ȓ��ňړ�(0 <= x < 4 && 0 <= y < 4)
	switch (key) {
	case 'w'://��
		if (y == 0)return false;
		y--;
		hp--;
		break;

	case 's'://��
		if (y == ROOM_NUM -1)return false;
		y++;
		hp--;
		break;

	case 'a'://��
		if (x == 0)return false;
		x--;
		hp--;
		break;

	case 'd'://�E
		if (x == ROOM_NUM -1 )return false;
		x++;
		hp--;
		break;

	case 'h'://��
		if (potion == 0) return false;
		potion--;
		hp += USING_POTION_HP;
		break;
	}
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
			x = 3;
			y = 0;
			break;
		case 'j':
			roomNum = plaza;
			x = 1;
			y = 3;
			break;

		//Gate26
		case 'k':
			roomNum = rightPath1;
			x = 0;
			y = 0;
			break;
		case 'l':
			roomNum = plaza;
			x = 2;
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
			x = 1;
			y = 0;
			break;
		case 'r':
			roomNum = leftPath2;
			x = 3;
			y = 3;
			break;

		//Gate89
		case 's':
			roomNum = katakura;
			x = 2;
			y = 0;
			break;
		case 't':
			roomNum = rightPath2;
			x = 0;
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
	printf("�c��s����    : %d\n", hp);
	printf("�����|�[�V������: %d\n", potion);
	printf("�ǉ��ۑ萔		: %d\n", issue);
	printf("���݂���t���A�@: %d\n", roomNum);
	//printf("���\			x�F%d  y�F%d\n", x, y);
}



