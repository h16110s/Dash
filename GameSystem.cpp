#include "GameSystem.h"
void GameSystem::systemMessage() {
	printf("�C�x���g�F%s", sysMsg);
	strcpy_s(sysMsg,SYS_MSG_MAXLENGTH ,"");
}

void GameSystem::init() {
	dungeon.initDungeon();
	hero.initHero();
	Clear = false;
	submit = false;
	strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "");
}

void GameSystem::display(){
	COORD coord;
	HANDLE hStdout;
	//�o�͗p�̕����𐶐�
	Room disp;
	disp.roomCopy(dungeon.room[hero.roomNum]);
	disp.pos[hero.y][hero.x] = HERO;
	disp.printRoom();

	//�C���t�H���[�V�����E�B���h�E�̍쐬
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	for (coord.Y = 0; coord.Y < MAX_WINDOW_HEIGHT - 4; coord.Y++){
		coord.X = MAX_WINDOW_WIDTH - 50;
		SetConsoleCursorPosition(hStdout, coord);
		switch (coord.Y)
		{
		case 0:
			printf("|�ۑ�̒�o�󋵁F");
			if (submit){ printf("��o�ς�");}
			else { printf("����o"); }
			break;
		case 1:
			printf("|�c��s���� : %4d", hero.hp);
			break;
		case 2:
			printf("|�����|�[�V������: %4d", hero.potion);
			break;
		case 3 :
			printf("|�ǉ��ۑ萔	: %4d", hero.issue);	
			break;
		case 4:
			printf("|���݂���t���A�@: %4d", hero.roomNum);
			break;
		default:
			printf("|");
			break;
		}
	}

	//�C�x���g���b�Z�[�W�E�B���h�E�̍쐬
	coord.X = 0;
	coord.Y = MAX_WINDOW_HEIGHT - 4;
	SetConsoleCursorPosition(hStdout, coord);
	printf("==========================================================================\n");
	systemMessage();
}

void GameSystem::mainLoop() {
	display();
	while ( !Clear && hero.hp > 0) {
		//����
		if (hero.move(inputKeyBoard())) {
			switch (dungeon.room[hero.roomNum].pos[hero.y][hero.x]) {
			case ENEMY://�G��������
				strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "�ז������ꂽ�@�s���\��-2\n");
				hero.damage(1);
				break;
			case HEAL://�񕜃A�C�e����������
				strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "���A���ꂳ������΁E�E�E �񕜃A�C�e��+1\n");
				hero.potion++;
				dungeon.room[hero.roomNum].eliminateObject(hero.x, hero.y);
				break;
			case ISSUE://�ǉ��ۑ肾������
				strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "�ǉ��ۑ����S�Ƃ��񂶂�Ȃ������I\n");
				hero.issue++;
				dungeon.room[hero.roomNum].eliminateObject(hero.x, hero.y);
				break;
			case 'W': //WifiSpot
				if (hero.charge > 80){
					strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "�ۑ�̒�o�����܂���? Y/N -> ");
					hero.action(dungeon.room[hero.roomNum].pos[hero.y][hero.x]);
					system("cls");
					display();
					if (getchar() == 'Y' || getchar() == 'y'){
						submit = true;
					}
					else continue;
				}
				else {
					strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "PC���[�d���Ȃ��ƒ�o�ł����");
				}
				break;
			default:
				strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "�����Ȃ�����\n");
				break;
			}
			hero.action(dungeon.room[hero.roomNum].pos[hero.y][hero.x]);
		}
		else {
			strcpy_s(sysMsg, SYS_MSG_MAXLENGTH, "�O���ĕ���\n");
		}
		system("cls");
		display();
	}
}

//ꎓ�
void GameSystem::printMenu() {
	while (1) {
		printf("==================================================\n");
		printf("		  �P��DASH\n");
		printf("==================================================\n");
		printf("     �Q�[���X�^�[�g : 1         ���[�������F2 \n");
		printf("-> ");
		char input = getchar();
		if (input == '2') {
			printRule();
		}
		else if (input == '1') {
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
void GameSystem::printRule() {
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

//ꎓ�
char GameSystem::inputKeyBoard() {
	while (1) {
		if (_kbhit()) {
			int ch = _getch();
			switch ((char)ch) {
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
