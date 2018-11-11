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
	bool move(char key);
	void action(char mark);
	void printState();
	void damage(int value){ hp -= value; }
	void initHero();
} Hero;
//bool move(Hero hero, char key);

