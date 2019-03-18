#include <stdio.h>

void CoordTransform(int a, int b, int *x, int *y){
	*x = (a + 1) * 2;
	*y = (b + 1) * 2;
}


int main(void) {
   int xValNew;
   int yValNew;

   CoordTransform(3, 4, &xValNew, &yValNew);
   printf("(3, 4) becomes (%d, %d)\n", xValNew, yValNew);

   return 0;
}
