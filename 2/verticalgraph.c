#include <stdio.h>

int main() {
   int input[80] = {0};
   int i=0;
   int max = 0;
   while (scanf("%d", &input[i]) != EOF) {
      i++;
   }
   for (int j=0; j<80; j++) {
      if ( input[j] > max ) {
         max = input[j];
      }
   }
   for (int k=max; k>0; k--) {
       for (int l=0; l<80; l++) {
          if (input[l] >= k) {
             printf("#");
          }
          else {
             printf(" ");
          }
       }
       printf("\n");
   }
   return 0;
}
