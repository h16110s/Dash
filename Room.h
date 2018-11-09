#ifndef ROOM_HEAD
#define ROOM_HEAD
#define ROOM_NUM 4
#define OBJECT 5
#define HERO 4
#define ENEMY 1
#define ISSUE 2
#define HEAL 3


#include <stdio.h>
struct Room{
public : 
	int pos[ROOM_NUM][ROOM_NUM];
	Room *right;
	Room *Left;
	Room *top;
	Room *down;
	void roomCopy( Room src){
		int i, j;
		for (i = 0; i < ROOM_NUM; i++){
			for (j = 0; j < ROOM_NUM; j++){
				pos[i][j] = src.pos[i][j];
			}
		}
	}
	void eliminateObject(int x, int y){
		pos[y][x] = 0;
	}
}; typedef struct Room Room;
void printRoom(Room room);
//void roomCopy(Room dst, Room src);
#endif // !ROOM_HEAD