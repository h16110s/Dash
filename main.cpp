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
		printf("�Q�[���N���A�I�I\n");
	}
	else {
		printf("�Q�[���I�[�o�[�E�E�E\n");
	}
	printf("�Q�[���I���ł�\n");

	return 0;
}
