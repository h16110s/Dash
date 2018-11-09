#include "Room.h"
#include <string.h>
void printRoom(Room room){
	int i, j;
	for (i = 0; i < ROOM_NUM; i++){
		printf("+--+--+--+--+\n|");
		for (j = 0; j < ROOM_NUM; j++){
			switch (room.pos[i][j])
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
				printf("%2cl", room.pos[i][j]);
				break;
			default:
				printf("%2c|", '  ');
				break;
			}
		}
		printf("\n");
	}
	printf("+--+--+--+--+\n");
}

