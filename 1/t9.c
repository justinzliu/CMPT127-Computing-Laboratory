#include <stdio.h>
#include <math.h>

int main() {
   int pyramid[3];
   int check;
   int xleft;
   int xright;
   for(int i=0; i<3; i++) {
      scanf("%d", &pyramid[i]);
   }
   for(int i=pyramid[2]; i>0; i--){
   int z=+1;
   xleft = floor( (i-1) * (pyramid[0]/(2.0*pyramid[2])) );
   xright = ceil( (pyramid[0]-1) + -(i-1) * (pyramid[0]/(2.0*pyramid[2])) ); 
      if (i==1){
         for(int j=0; j<=pyramid[0]-1; j++){
            if (j < xright) {
            printf("#");
            }
            else {
               printf("#\n");
            }
         }
      }
      else {
         for(int j=0; j<=pyramid[0]-1; j++){
            if (j == xleft) {
               printf("#");
            }
            else if (j == xright) {
               printf("#\n");
            }
            else if (j > xleft && j < xright) {
               if (i == pyramid[2]) {
                  printf("#");
               }
               else {
                  printf(".");
               }
            }
            else if (j < xright) {
               printf(" ");
            }
         }
      }    
   }
   return 0;
}
