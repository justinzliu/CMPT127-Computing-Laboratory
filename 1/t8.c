#include <stdio.h>

int main(){
   char array[100];
   while (fgets(array, sizeof(array), stdin) != 0){
      int a=0;
      int j;
      int pyramid[3];
      for(int i=0; sscanf(array+i,"%d%n",&pyramid[a],&j)!=EOF; i+=j){
         a++;
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
   }
   return 0;
}
