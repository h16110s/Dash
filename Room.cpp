#include "Room.h"
#include <stdlib.h>
#include <windows.h>
//�����R�s�[�֐�
//ꎓ��T�m
void Room::roomCopy(Room src) {
	int i, j;
	for (i = 0; i < ROOM_NUM; i++) {
		for (j = 0; j < ROOM_NUM; j++) {
			pos[i][j] = src.pos[i][j];
		}
	}
}
//�����g�̐���
//ꎓ��T�m
void Room::roomFrame() {
	for (int j = 0; j < ROOM_NUM; j++) {
		printf("+--");
	}
	printf("+\n");
}
//�����̕\��
//ꎓ��T�m
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
				printf("%2s|", "��");
				break;

			case HERO:
				printf("%2s|", "��");
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
