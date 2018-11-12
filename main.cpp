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
	printf("ゲーム終了です\n");

	return 0;
}
