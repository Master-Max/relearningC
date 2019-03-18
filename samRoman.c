#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool ProperRoman(const char romanNumeral[]) {
    for(int i = 0; i < strlen(romanNumeral); ++i){
        if((romanNumeral[i] != 'M') || (romanNumeral[i] != 'D') ||
	(romanNumeral[i] != 'C') || (romanNumeral[i] != 'L') ||
	(romanNumeral[i] != 'X') || (romanNumeral[i] != 'V') ||
	(romanNumeral[i] != 'I')){
            return false;
        }
    }
    return true;
}

void NumeralToDecimal(char romanNumeral[], int decimalValues[]) {
    for (int i = 0; i < strlen(romanNumeral); ++i) {
        if(romanNumeral[i] =='M'){
            decimalValues[i] = 1000;
        }
        else if(romanNumeral[i] =='D'){
            decimalValues[i] = 500;
        }
        else if(romanNumeral[i] =='C'){
            decimalValues[i] = 100;
        }
        else if(romanNumeral[i] =='L'){
            decimalValues[i] = 50;
        }
        else if(romanNumeral[i] =='X'){
            decimalValues[i] = 10;
        }
        else if(romanNumeral[i] =='V'){
            decimalValues[i] = 5;
        }
        else if(romanNumeral[i] =='I'){
            decimalValues[i] = 1;
        }
    }
}

int CalculateDecimalValue(int decimalValues[], int numDigits) {
	int total = 0;
	for(int i=0; i<numDigits;i++){
		if(decimalValues[i+1] > decimalValues[i]){
			i = i + 1;
			total += decimalValues[i+1] - decimalValues[i];
		}else{
			total += decimalValues[i];
		}
	} 
	return total;
}

bool Prompt(char romanNumeral[], int maxSize){
    printf("Please input a value in Roman numerals or EXIT to quit: ");
    fgets(romanNumeral, 20, stdin);
    printf("\n");

	printf("(hi, hi)  - %d\n", strcmp("hi", "hi"));    
	printf("(hi, bye) - %d\n", strcmp("hi", "bye"));
	printf("romanNumeral: %s\n", romanNumeral);
    while(strcmp(romanNumeral, "EXIT") != 0) {
        if(strlen(romanNumeral) > maxSize) {
            printf("Error too many characters! Must be less than 21 characters.\n");
        }
        else if(!ProperRoman(romanNumeral)) {
            printf("Illegal Characters\n");
        }
        else {
            int decimalValues[strlen(romanNumeral)];
            NumeralToDecimal(romanNumeral, decimalValues);
            printf("%s = %d\n", romanNumeral, CalculateDecimalValue(decimalValues, strlen(romanNumeral)));
        }
	// New Loop
    	printf("Please input a value in Roman numerals or EXIT to quit: ");
    	fgets(romanNumeral, 20, stdin);
    	printf("\n");
    }
    return true;
}
int main(void){
    char romanNumeral[20];
    Prompt(romanNumeral, 20);
    return 0;
}


// END
