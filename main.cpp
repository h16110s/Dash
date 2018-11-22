#include "GameSystem.h"
bool clear = false;

int main(void)
{
	GameSystem gs;
	gs.init();

	//printMenu();
	system("cls");

	gs.mainLoop();
	system("cls");
	if (gs.Clear){
		printf("ゲームクリア！！\n");
	}
	else {
		printf("ゲームオーバー・・・\n");
	}
	printf("ゲーム終了です\n");

	return 0;
}
