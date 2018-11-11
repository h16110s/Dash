#include "GameSystem.h"
bool clear = false;

int main(void)
{
	GameSystem gs;
	gs.init();

	//printMenu();
	system("cls");
	printf("\n");

	gs.mainLoop();
	system("cls");
	printf("ƒQ[ƒ€I—¹‚Å‚·\n");

	return 0;
}
