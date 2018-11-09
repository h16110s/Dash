#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Room.h"
#include "Dungeon.h"
#include "HERO.h"
//GameSystem Function=======
char inputKeyBoard();
void printMenu();
void printRule();
void getObject();
//=====================
bool clear = false;

int main(void)
{
	Dungeon dungeon = initDungeon();
	Room disp = {1};
	Hero hero = initHero();

	printMenu();
	system("cls");

	//dungeon.room[hero.roomNum].pos[hero.y][hero.x] = HERO;
	disp.roomCopy(dungeon.room[hero.roomNum]);
	disp.pos[hero.y][hero.x] = HERO;
	printRoom(disp);

	while (!clear){
		//����
		hero.move(inputKeyBoard());
		system("cls");

		switch (dungeon.room[hero.roomNum].pos[hero.x][hero.y]){
			case ENEMY://�G��������
				hero.damage(2);
				break;
			case HEAL://�񕜃A�C�e����������
				hero.potion++;
				dungeon.room[hero.roomNum].eliminateObject(hero.x, hero.y);
				break;
			case ISSUE://�ǉ��ۑ肾������
				hero.issue++;
				dungeon.room[hero.roomNum].eliminateObject(hero.x, hero.y);
				break;
		}

		//�\��
		disp.roomCopy(dungeon.room[hero.roomNum]);
		disp.pos[hero.y][hero.x] = HERO;
		printRoom(disp);
		hero.printState();
	}

	return 0;
}


//ꎓ�
char inputKeyBoard(){
	while (1) {
		if (_kbhit()) {
			int ch = _getch();
			switch ((char)ch){
			case 'w':
			case 's':
			case 'a':
			case 'd':
				return (char)ch;
			default:
				continue;
			}
			break;
		}
	}
}

//ꎓ�
void printMenu(){
	while (1){
		printf("==================================================\n");
		printf("		  �P��DASH\n");
		printf("==================================================\n");
		printf("     �Q�[���X�^�[�g : 1         ���[�������F2 \n");
		printf("-> ");
		char input = getchar();
		if (input == '2'){
			printRule();
		}
		else if (input == '1'){
			printf("�Q�[���J�n�I�I\n");
			break;
		}
		else {
			printf("�֌W�̂Ȃ����̂��������ȁH\n");
			printf("�Q�[���X�^�[�g��\n");
			break;
		}
	}
}


//���{����
void printRule(){
	system("cls");
	printf("�`�X�g�[���[�`\n�x���������ĒP�ʂ𗎂Ƃ������ȁu�H�ȑ��Y�v����B\n���ɒx��������o�ȓ���������Ȃ��ė��P�����肵�Ă��܂��B\n");
	printf("�������A�����Ɍ����ĉۑ��o�����Ȃ��Ă͂����Ȃ�...�B\n\n�H�ȑ��Y�͖����A���Ǝ��ԂɊԂɍ������Ƃ��ł���̂��I�H\n");
	getchar();

	printf("�`���[���`\n�@�ۑ��Wi-Fi�X�|�b�g�ɍs���Ē�o�B\n(���Y�N��PC�������Ă��邪�A�[�d���Ȃ��B\n�[�d�X�|�b�g���ɒT���āA�[�d���Ă��������B)\n");
	getchar();

	printf("�A��o��A���ƂɊԂɍ����悤�Ќ���GO!!\n(�G�E�񕜃A�C�e��(����2����)�E�ǉ��ۑ肪�o���I)\n");
	getchar();

	printf("�B�Ќ��ɂ̓{�X��...�B\n(�N�͓|���邩�ȁH)\n");
	getchar();

	printf("�`�ړ������[���`\n�E�s���\��(HP)�͏���30��\n�E1�s���ɂ�1HP����\n�E�G�ƐڐG�����ꍇ2����\n�E�񕜃A�C�e���̎g�p��HP��15��\n");
	printf("���G���񕜃A�C�e���A�ǉ��ۑ�͐ڐG���Ȃ��Ƃ킩��܂���B\n");
	getchar();

	printf("�`�{�X�탋�[���`\n");
	printf("�{�X��̓N�C�Y�`���ɂȂ�܂�\n�E�ԈႦ���HP��10����\n�E3�␳���Ń{�X�ɏ����I\n\n");
	getchar();

	printf("�Ō�ɁA�s���\��(HP)�Ɖۑ�̒�o��(�ǉ��ۑ�̂��܂�)���������A\n�X�R�A���Z�o����܂��B\n");
	getchar();

	printf("�����A�N�͍H�ȑ��Y�̒P�ʂ��~�����Ƃ͂ł���̂��H\n");
	system("cls");
}
