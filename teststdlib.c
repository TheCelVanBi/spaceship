#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void main(){ 
	srand(time(NULL));
	int numb = rand()%2+1;
	printf("%d\n",numb);
}
