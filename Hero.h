#include <stdio.h>
struct Hero
{
	int hp;
	int x; //0 ~ 3
	int y; //0 ~ 3
	int charge;
	int roomNum;
	int potion;
	int issue;
	bool move(char key);
	void printState();
	void damage(int value){ hp -= value; }
};
typedef struct Hero Hero;
Hero initHero();
//bool move(Hero hero, char key);

