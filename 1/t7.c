#include <stdio.h>

int main(){
   char array[100];
   while (fgets(array, sizeof(array), stdin) != 0){
      int a;
      int j;
      for(int i=0; sscanf(array+i,"%d%n",&a,&j)!=EOF; i+=j){
         while(a>0){
            printf("#");
            a--;
         }
           printf("\n");
       }
   }
   return 0;
}
