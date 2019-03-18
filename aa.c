#include <stdio.h>

int main(void){

	int i;
	int j;
	int index;
	int alpha[50];

	index = 0;

	for (i = 0; i < 50; i++){
		alpha[i] = i;
	}

	printf("The first array element: alpha[0] = %d\n", alpha[0]);
	printf("The first array element: alpha[49] = %d\n", alpha[49]);



	return (0);
}
