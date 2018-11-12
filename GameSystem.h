#pragma once
#include "Header.h"
#include "Dungeon.h"
#include "Hero.h"
#include "Room.h"

typedef struct GameSystem {
	Dungeon dungeon;
	Hero hero;
	bool Clear;
	char sysMsg[SYS_MSG_MAXLENGTH];
	//GameSystem Function=======
	void init();
	void display();
	char inputKeyBoard();
	void printMenu();
	void printRule();
	void mainLoop();
	void systemMessage();
	//=====================
} GameSystem;