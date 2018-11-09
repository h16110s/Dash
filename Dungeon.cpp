#include "Dungeon.h"
//1:敵
//2:追加課題
//3:回復アイテム

//藤本
Dungeon initDungeon(){
	Dungeon dungeon;
	int i, j, k;
	for (i = 0; i < 11; i++){
		for (j = 0; j < ROOM_NUM; j++){
			for (k = 0; k < ROOM_NUM; k++){
				dungeon.room[i].pos[j][k] = 0;
			}
		}
	}
	dungeon.room[0].pos[2][0] = 1;
	dungeon.room[0].pos[1][2] = 1;
	dungeon.room[0].pos[0][3] = 2;
	dungeon.room[0].pos[2][3] = 97;

	dungeon.room[1].pos[0][0] = 2;
	dungeon.room[1].pos[2][0] = 97;
	dungeon.room[1].pos[3][0] = 1;
	dungeon.room[1].pos[2][1] = 3;
	dungeon.room[1].pos[3][1] = 101;
	dungeon.room[1].pos[0][2] = 98;
	dungeon.room[1].pos[1][2] = 1;
	dungeon.room[1].pos[3][2] = 102;
	dungeon.room[1].pos[1][3] = 100;
	dungeon.room[1].pos[3][3] = 1;

	dungeon.room[2].pos[3][0] = 2;
	dungeon.room[2].pos[0][1] = 99;
	dungeon.room[2].pos[2][1] = 1;
	dungeon.room[2].pos[3][2] = 98;
	dungeon.room[2].pos[0][3] = 3;
	dungeon.room[2].pos[1][3] = 1;
	dungeon.room[2].pos[3][3] = 1;

	dungeon.room[3].pos[0][0] = 2;
	dungeon.room[3].pos[1][1] = 1;
	dungeon.room[3].pos[2][1] = 1;
	dungeon.room[3].pos[3][1] = 99;
	dungeon.room[3].pos[0][2] = 110;
	dungeon.room[3].pos[2][2] = 1;

	dungeon.room[4].pos[1][0] = 100;
	dungeon.room[4].pos[3][0] = 1;
	dungeon.room[4].pos[0][1] = 3;
	dungeon.room[4].pos[2][1] = 1;
	dungeon.room[4].pos[0][2] = 1;
	dungeon.room[4].pos[2][2] = 1;
	dungeon.room[4].pos[0][3] = 2;
	dungeon.room[4].pos[3][3] = 111;

	dungeon.room[5].pos[1][0] = 2;
	dungeon.room[5].pos[3][1] = 101;
	dungeon.room[5].pos[1][2] = 1;
	dungeon.room[5].pos[3][2] = 3;
	dungeon.room[5].pos[0][3] = 103;

	dungeon.room[6].pos[0][0] = 102;
	dungeon.room[6].pos[3][0] = 1;
	dungeon.room[6].pos[1][1] = 1;
	dungeon.room[6].pos[1][2] = 1;
	dungeon.room[6].pos[3][2] = 104;
	dungeon.room[6].pos[2][3] = 1;

	dungeon.room[7].pos[1][0] = 1;
	dungeon.room[7].pos[2][0] = 3;
	dungeon.room[7].pos[0][1] = 103;
	dungeon.room[7].pos[1][2] = 1;
	dungeon.room[7].pos[0][3] = 2;
	dungeon.room[7].pos[3][3] = 105;

	dungeon.room[8].pos[0][0] = 2;
	dungeon.room[8].pos[3][0] = 106;
	dungeon.room[8].pos[0][2] = 104;
	dungeon.room[8].pos[2][2] = 1;
	dungeon.room[8].pos[1][3] = 1;
	dungeon.room[8].pos[2][3] = 3;

	dungeon.room[9].pos[0][0] = 1;
	dungeon.room[9].pos[2][0] = 2;
	dungeon.room[9].pos[0][1] = 105;
	dungeon.room[9].pos[4][1] = 107;
	dungeon.room[9].pos[0][2] = 106;
	dungeon.room[9].pos[1][2] = 1;
	dungeon.room[9].pos[4][2] = 107;
	dungeon.room[9].pos[0][3] = 1;
	dungeon.room[9].pos[1][3] = 1;
	dungeon.room[9].pos[2][3] = 3;
	dungeon.room[9].pos[3][3] = 1;

	dungeon.room[10].pos[0][1] = 107;
	
	dungeon.room[0].right = &dungeon.room[1];

	dungeon.room[1].Left = &dungeon.room[0];

	return dungeon;
}