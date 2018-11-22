#include "Header.h"
typedef struct Quiz{
	int score;
	char question[1000];
	char select[4][100];
	int answer;
	bool already;
	void Quiz_View();
}Quiz;


