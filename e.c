#include <stdio.h>
#include <string.h>

void MakeSentenceExcited(char* sentenceText) {

	//printf("Length: %d", strlen(sentenceText));


   	for(int i = 0; i < strlen(sentenceText); i++){
		if(sentenceText[i] == '.'){
			sentenceText[i] = '!';
		}
	}
}

int main(void) {
   const int TEST_STR_SIZE = 50;
   char testStr[TEST_STR_SIZE];

   strcpy(testStr, "Hello. I'm Miley. Nice to meet you.");
   MakeSentenceExcited(testStr);
   printf("%s", testStr);

   return 0;
}
