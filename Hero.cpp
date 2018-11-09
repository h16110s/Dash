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
	//上下左右に移動
	//4*4以内で移動(0 <= x < 4 && 0 <= y < 4)
	switch (key){
		case 'w'://上
			if (y -1 < 0)return false;
			y--;
			break;

		case 's'://下
			if (y == 3)return false;
			y++;
			break;

		case 'a'://左
			if (x == 0)return false;
			x--;
			break;

		case 'd'://右
			if (x == 3)return false;
			x++;
			break;
	}
	return true;
}

void Hero::printState(){
	printf("残り行動回数    : %d\n", hp);
	printf("所持ポーション数: %d\n", potion);
	printf("追加課題数		: %d\n", issue);
	printf("現在いるフロア　: %d\n", roomNum);
}



