#include "Room.h"
#include <stdlib.h>
#include <windows.h>
void Room::roomCopy(Room src) {
	int i, j;
	for (i = 0; i < ROOM_NUM; i++) {
		for (j = 0; j < ROOM_NUM; j++) {
			pos[i][j] = src.pos[i][j];
		}
	}
}
void Room::roomFrame() {
	for (int j = 0; j < ROOM_NUM; j++) {
		printf("+--");
	}
	printf("+\n");
}
void Room::printRoom(){
	int i, j;
	for (i = 0; i < ROOM_NUM; i++){
		roomFrame();
		printf("|");

		for (j = 0; j < ROOM_NUM; j++){
			switch (pos[i][j])
			{
			case ENEMY:
				printf("%2c|", 'O');
				break;
			case ISSUE:
				printf("%2c|", 'O');
				break;
			case HEAL:
				printf("%2c|", 'O');
				break;
			case HERO:
				printf("%2c|", 'H');
				break;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
				printf("%2cl",pos[i][j]);
				break;
			default:
				printf("%2c|", '  ');
				break;
			}
		}
		printf("\n");
		
	}
	roomFrame();
}
