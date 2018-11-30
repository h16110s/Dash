#include "Header.h"
typedef struct Quiz{
	int score;
	char question[1000];
	char select[4][100];
	int answer;
	char ans[100];
	bool already;
	void Quiz_View();
}Quiz;


