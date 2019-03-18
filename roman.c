// Test
// Convert Roman Numeral to number


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int numValue(char a, char b){
	char NUMERALS[7] = 	{'I','V','X','L','C','D','M'};
	int VALUES[7] = 	{ 1 , 5 , 10,50,100,500,1000};
	int A = 0;
	int B = 0;
	
	for(int i=0;i<7;i++){// While loop would be more efficient
		if(a == NUMERALS[i]){
			A = VALUES[i];		
		}
		if(b == NUMERALS[i]){
			B = VALUES[i];		
		}
	}

	if (B > A){
		return (B - A) * -1;
	}else
	if (A >= B){
		return A;
	}else{
		return 0;
	}
}

int main(){
	char romanNumeral[20];
	printf("Enter Roman Numeral: ");
	fgets(romanNumeral, 20, stdin);

	printf("|R| %s", romanNumeral);

	int total = 0;
	for (int i=0;i<strlen(romanNumeral);i++){
		int tmp = numValue(romanNumeral[i], romanNumeral[i+1]);

		if (tmp < 0){
			i = i + 1;
			total += tmp * -1;
		} else {
			total += tmp;
		}
	}

	printf("|Total?| %d\n", total);
}
