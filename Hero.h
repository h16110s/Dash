#pragma once
#include <stdio.h>
#include "Header.h"
typedef struct Hero
{
	int hp;
	int x; //0 ~ 3
	int y; //0 ~ 3
	int charge;
	school roomNum;
	int potion;
	int issue;
	Action  move(char key);
	void printState();
	void damage(int value){ hp -= value; }
	void heal(int value){ hp += value; }
	void initHero();
	void moveRoom(school pos);
	void movePos(int y, int x);


} Hero;
//bool move(Hero hero, char key);

