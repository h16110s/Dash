#pragma once
#include <stdio.h>
#include "Header.h"

typedef struct Room {
	int pos[ROOM_NUM][ROOM_NUM];
	void eliminateObject(int x, int y){
		pos[y][x] = 0;
	}
	void printRoom(); 
	void roomFrame();
	void roomCopy(Room src);
} Room;
