#include "Quiz.h"
void Quiz::Quiz_View(){
	int i;
	printf("–â‘è:%s\n",question);
	for(i = 0; i < 4; i++){
		printf("%d.%s\n",i+1,select[i]);
	}
}
