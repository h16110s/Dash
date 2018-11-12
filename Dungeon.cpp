#include "Dungeon.h"
//1:敵
//2:追加課題
//3:回復アイテム

//藤本
void Dungeon::initDungeon(){
	int i, j, k;
	for (i = 0; i < 11; i++){
		for (j = 0; j < ROOM_NUM; j++){
			for (k = 0; k < ROOM_NUM; k++){
				room[i].pos[j][k] = 0;
			}
		}
	}
	room[0].pos[0][0] = 2;
	room[0].pos[0][2] = 'W';
	room[0].pos[1][1] = 1;
	room[0].pos[2][1] = 1;
	room[0].pos[2][2] = 1;
	room[0].pos[3][1] = 'f';

	room[1].pos[0][1] = 'e';
	room[1].pos[0][3] = 3;
	room[1].pos[1][3] = 1;
	room[1].pos[2][1] = 1;
	room[1].pos[3][0] = 2;
	room[1].pos[3][2] = 'd';
	room[1].pos[3][3] = 1;

	room[2].pos[0][3] = 2;
	room[2].pos[1][2] = 1;
	room[2].pos[2][0] = 1;
	room[2].pos[2][3] = 'a'; // a

	room[3].pos[0][0] = 2;
	room[3].pos[0][2] = 'c';
	room[3].pos[1][2] = 1;
	room[3].pos[1][3] = 'g';
	room[3].pos[2][0] = 'b'; // b
	room[3].pos[2][1] = 3;
	room[3].pos[3][0] = 1;
	room[3].pos[3][1] = 'i';
	room[3].pos[3][2] = 'k';
	room[3].pos[3][3] = 1;

	room[4].pos[1][0] = 'h';
	room[4].pos[3][0] = 1;
	room[4].pos[0][1] = 3;
	room[4].pos[2][1] = 1;
	room[4].pos[0][2] = 1;
	room[4].pos[2][2] = 1;
	room[4].pos[0][3] = 2;
	room[4].pos[3][3] = 'C';

	room[5].pos[1][0] = 2;
	room[5].pos[3][1] = 'j';
	room[5].pos[1][2] = 1;
	room[5].pos[3][2] = 3;
	room[5].pos[0][3] = 'm';

	room[6].pos[0][0] = 'l';
	room[6].pos[3][0] = 1;
	room[6].pos[1][1] = 1;
	room[6].pos[1][2] = 1;
	room[6].pos[3][2] = 'o';
	room[6].pos[2][3] = 1;

	room[7].pos[1][0] = 1;
	room[7].pos[2][0] = 3;
	room[7].pos[0][1] = 'n';
	room[7].pos[1][2] = 1;
	room[7].pos[0][3] = 2;
	room[7].pos[3][3] = 'q';

	room[8].pos[0][0] = 2;
	room[8].pos[0][2] = 'p';
	room[8].pos[1][3] = 1;
	room[8].pos[2][2] = 1;
	room[8].pos[2][3] = 3;
	room[8].pos[3][0] = 's';

	room[9].pos[0][0] = 1;
	room[9].pos[0][1] = 'r';
	room[9].pos[0][2] = 't';
	room[9].pos[0][3] = 1;
	room[9].pos[1][2] = 1;
	room[9].pos[1][3] = 1;
	room[9].pos[2][0] = 2;
	room[9].pos[2][3] = 3;
	room[9].pos[3][3] = 1;
	room[9].pos[3][1] = 'u';
	room[9].pos[3][2] = 'u';

	room[10].pos[0][1] = 'v';
}
