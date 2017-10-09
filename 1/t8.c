#include <stdio.h>

int main() {
   int pyramid[3];
   int check;
   for (int i=0; i<3; i++){
      scanf("%d", &pyramid[i]);
   }
   for(int i=0; i<=pyramid[1]-1; i++){
      if (i==0){
         for(int i=0; i<=pyramid[0]-1; i++){
            printf("#");
         }
      }
      else if (i==pyramid[1]-1){
         for(int i=0; i<=pyramid[0]-1; i++){
            printf("#");
         }
      }
      else {
	 for(int i=0; i<=pyramid[0]-1; i++){
	    if (i==0 || i==pyramid[0]-1){
               printf("#");
            }
	    else {
	       printf(".");
            }
	 }  
      } 
      printf("\n");   
   }
   return 0;
}
