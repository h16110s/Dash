#include "Room.h"
#include <stdlib.h>
#include <windows.h>
//部屋コピー関数
//齊藤裕仁
void Room::roomCopy(Room src) {
	int i, j;
	for (i = 0; i < ROOM_NUM; i++) {
		for (j = 0; j < ROOM_NUM; j++) {
			pos[i][j] = src.pos[i][j];
		}
	}
}
//部屋枠の生成
//齊藤裕仁
void Room::roomFrame() {
	for (int j = 0; j < ROOM_NUM; j++) {
		printf("+--");
	}
	printf("+\n");
}
//部屋の表示
//齊藤裕仁
void Room::printRoom(){
	int i, j;
	for (i = 0; i < ROOM_NUM; i++){
		roomFrame();
		printf("|");
		for (j = 0; j < ROOM_NUM; j++){
			switch (pos[i][j])
			{
			case ENEMY:
			case ISSUE:
			case HEAL:
				printf("%2c|", '@');
				break;

			case HERO:
				printf("%2c|", 'H');
				break;
			case NONE:
				printf("%2c|", '  ');
				break;
			default:
				printf("%2cl",pos[i][j]);
				break;
			}
		}
		printf("\n");
	}
	roomFrame();
}
