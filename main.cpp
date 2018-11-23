﻿#include "GameSystem.h"

int main(void)
{
	GameSystem gs;
	gs.init();
	while (true){
		gs.printMenu();
		system("cls");

		gs.mainLoop();
		system("cls");
		if (gs.Clear){
			printf("ゲームクリア！！\n");
			int score = gs.calcScore();
			printf("ゲームスコアは・・・");
			getchar();
			printf("%dでした！！\n\n\n\n\n\n", score);
		}
		else {
			printf("ゲームオーバー・・・\n\n");
		}

		printf("リトライ？　Y/n -> ");
		if (gs.getIs()){
			continue;
		}
		else {
			break;
		}
	}
	getchar();
	printf("ゲーム終了です\n");

	return 0;
}
