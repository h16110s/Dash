#include "GameSystem.h"
int main(void){
	GameSystem gs;
	while (true){
		gs.init();
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

			printf("スコアを残しますか？Y/n -> ");
			if (gs.getIs()){
				char n[MAX_NAME_LENGTH];
				printf("名前を入力してくだちい ->   ");
				scanf_s("%s", n, MAX_NAME_LENGTH);
				gs.addRanking(n, score);
				gs.writeRanking();
				gs.readRanking();
				printf("ランキングに追加しました。\n\n\n");
			}
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

