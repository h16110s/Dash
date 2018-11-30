#include "Room.h"
#include <stdlib.h>
#include <windows.h>
//•”‰®ƒRƒs[ŠÖ”
//ê“¡—Tm
void Room::roomCopy(Room src) {
	int i, j;
	for (i = 0; i < ROOM_NUM; i++) {
		for (j = 0; j < ROOM_NUM; j++) {
			pos[i][j] = src.pos[i][j];
		}
	}
}
//•”‰®˜g‚Ì¶¬
//ê“¡—Tm
void Room::roomFrame() {
	for (int j = 0; j < ROOM_NUM; j++) {
		printf("+--");
	}
	printf("+\n");
}
//•”‰®‚Ì•\¦
//ê“¡—Tm
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
				printf("%2s|", "›");
				break;

			case HERO:
				printf("%2s|", "š");
				break;
			case NONE:
				printf("%2c|", '  ');
				break;
			case 'a':
			case 'g':
				printf("%2s|","¨");
				break;
			case 'b':
			case 'h':
				printf("%2s|", "©");
				break;
			case 'e':
			case 'c':
			case 'j':
			case 'l':
			case 'n':
			case 'p':
			case 'r':
			case 't':
			case 'v':
				printf("%2sl", "ª");
				break;
			case 'f':
			case 'd':
			case 'i':
			case 'k':
			case 'm':
			case 'o':
			case 'q':
			case 's':
			case 'u':
				printf("%2s|", "«");
				break;
						
			default:

				printf("%2c|",pos[i][j]);
				break;
			}
		}
		printf("\n");
	}
	roomFrame();
}
