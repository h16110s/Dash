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

	int score[10];
	char name[10][100];
	//GameSystem Function=======
	const char* getTask();
	const char* getPosName(school floor);
	bool mapMove(char mark);
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
	int choice();
	bool isEnterBossRoom();
	void readRanking();
	void writeRanking();
	void addRanking(char inName[100], int inScore);
	void viewRanking();
	//=====================
} GameSystem;