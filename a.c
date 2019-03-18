#include <stdio.h>
int main(void) {
    
	int i;
	int j;
	int index;
	int alpha[50];

	index = 0;

	for(i = 0; i < 50; ++i) {
    		alpha[i] = i;
	}

	printf("The first array element: alpha[0] = %d\n", alpha[0]);

	printf("The last array element: alpha[49] = %d\n", alpha[49]);

	alpha[24] = 62;

	printf("The 25th array element: alpha[24] = %d\n", alpha[24]);

	alpha[9] = 3 * alpha[49] + 10;

	printf("The 10th array element: alpha[9] = %d\n", alpha[9]);
    

	// Number 7
	printf("\n");

	for(i = 0; i < 5; ++i) {
    		for(j = 0; j < 10; ++j) {
        		printf("%d ", alpha[index]);
        		index = index + 1;
    		}
		printf("\n");
	}

	printf("\n");

	// Number 8
	for(i = 0; i < 50; ++i) {
		if (i%2 == 0 || i%3 == 0){
			printf("alpha[%d] = %d\n", i, alpha[i]);
		}
	}
	
	// Number 9
	for(i = 0; i<50; i++){
		if (i%2 == 0){
			alpha[i] = alpha[i] + 1;
		}
	}
	printf("\n");
	// Number 10
	index = 0;
	for(i = 0; i < 10; ++i) {
        	for(j = 0; j<5; j++){
			printf("%d ", alpha[index]);
        		index = index + 1;
		}
		printf("\n");
	}

	//printf("\n");

	return (0);
}

