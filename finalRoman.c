#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool ProperRoman(const char romanNumeral[]){
	char numerals[7] = {'I','V','X','L','C','D','M'};
	//printf("len: %d\n",strlen(romanNumeral));
	for(int i=0; i<strlen(romanNumeral); i++){
		if(romanNumeral[i] == 'I'){
			//printf("i");
		}else
		if(romanNumeral[i] == 'V'){
			//printf("v");
		}else
		if(romanNumeral[i] == 'X'){
			//printf("x");
		}else
		if(romanNumeral[i] == 'L'){
			//printf("l");
		}else
		if(romanNumeral[i] == 'C'){
			//printf("c");
		}else
		if(romanNumeral[i] == 'D'){
			//printf("d");
		}else
		if(romanNumeral[i] == 'M'){
			//printf("m");
		}
		else{
			return false;
		}
	}
	//printf("\ngot here\n");
	return true;
}

/*
void inputCleaner(char input[]){
	if(input[strlen(input)-1] == '\n'){
		input[strlen(input-1)] = '\0';
	}
}
*/

bool Prompt(char romanNumeral[], int maxSize){
	printf("Please input a value in Roman numerals or EXIT to quit: ");
	fgets(romanNumeral, maxSize, stdin);
	romanNumeral[strlen(romanNumeral) -1 ] = '\0'; // Clips off the /n fgets adds
	printf("Your input was: %s\n", romanNumeral);
	if(strcmp(romanNumeral, "EXIT") == 0){
		printf("Exiting...\n");
		return false;
	}else
	if(strlen(romanNumeral) > maxSize){
		printf("Error: Too many characters! Must be less than %d.\n", maxSize);
		return false;
	}else
	if(!ProperRoman(romanNumeral)){
		printf("Error: Illegal Characters\n");
		return false;
	}else{
		printf("Valid Input\n");
		return true;
	}
}

void NumeralToDecimal (char romanNumeral[], int decimalValues[]){
	// printf("|rN| %s\n",romanNumeral);
	// printf("|dV| %d\n",sizeof decimalValues);
	char NUM[7] = {'I','V','X','L','C','D','M'};
	int VAL[7]  = { 1 , 5 , 10,50,100,500,1000};
	for(int i=0; i<strlen(romanNumeral); i++){
		for(int j=0; j<7; j++){
			if(romanNumeral[i] == NUM[j]){
				decimalValues[i] = VAL[j];
			}
		}
	}
}

int CalculateDecimalValue(int decimalValues[], int numDigits){
	int total = 0;
	for(int i=0; i<numDigits; i++){
		// printf("dV[i]   : %d\n", decimalValues[i]);
		// printf("dV[i+1] : %d\n", decimalValues[i+1]);
		// printf("i: %d\n", i);
		if(i+1 < numDigits && decimalValues[i+1] > decimalValues[i]){
			int a = decimalValues[i];
			int b = decimalValues[i+1];
			int c = b - a;
			// printf("%d - %d = %d\n",b,a,c);
			total += c;
			i += 1;
		}else{
			total += decimalValues[i];
		}
		// printf("t: %d\n",total);
	}
	return total;
}

int main(void){
	int maxSize = 20;
	char romanNumeral[maxSize];
	do{
		// printf("Please input a value in Roman numerals or EXIT to quit: ");
		// fgets(romanNumeral, maxSize, stdin);
		if(Prompt(romanNumeral, maxSize)){
			int decimalValues[strlen(romanNumeral)];
			NumeralToDecimal(romanNumeral, decimalValues);		
			for(int i=0; i<sizeof(decimalValues) / sizeof(int); i++){
				//printf("%c|%d\n",romanNumeral[i],decimalValues[i]);
			}
			int total = CalculateDecimalValue(decimalValues, sizeof(decimalValues) / sizeof(int));
			printf("Total: %d\n\n", total);
		}
		// printf("|R| %s\n", romanNumeral);
	}while(strcmp(romanNumeral, "EXIT") != 0);
	return 0;
}
