#include <stdio.h>
#include "Room.h"
struct Dungeon{
	struct Room room[11];
}; typedef struct Dungeon Dungeon;
Dungeon initDungeon();