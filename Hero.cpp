#include "Hero.h"
Hero initHero(){
	Hero hero;
	hero.hp = 30;
	hero.x = 0;
	hero.y = 0;
	hero.roomNum = 0;
	hero.potion = 2;
	hero.issue = 0;
	return hero;
}

bool Hero::move( char key){
	hp--;
	//�㉺���E�Ɉړ�
	//4*4�ȓ��ňړ�(0 <= x < 4 && 0 <= y < 4)
	switch (key){
		case 'w'://��
			if (y -1 < 0)return false;
			y--;
			break;

		case 's'://��
			if (y == 3)return false;
			y++;
			break;

		case 'a'://��
			if (x == 0)return false;
			x--;
			break;

		case 'd'://�E
			if (x == 3)return false;
			x++;
			break;
	}
	return true;
}

void Hero::printState(){
	printf("�c��s����    : %d\n", hp);
	printf("�����|�[�V������: %d\n", potion);
	printf("�ǉ��ۑ萔		: %d\n", issue);
	printf("���݂���t���A�@: %d\n", roomNum);
}



