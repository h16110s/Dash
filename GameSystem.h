#pragma once
#include "Header.h"
#include "Dungeon.h"
#include "Hero.h"
#include "Room.h"
#include "Quiz.h"

typedef struct GameSystem {
	Dungeon dungeon;
	Hero hero;
	Quiz quiz[MAX_QUIZ_NUM];
	bool Clear;
	bool submit;
	char sysMsg[SYS_MSG_MAXLENGTH];
	//GameSystem Function=======
	void init();
	void display();
	char inputKeyBoard();
	void printMenu();
	void printRule();
	void mainLoop();
	void systemMessage();
	bool battle();
	Quiz getQuiz();
	void Quiz_Set();
	int calcScore();
	bool getIs();
	//=====================
} GameSystem;