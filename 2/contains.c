#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
   char *find;
   find = strstr(argv[1], argv[2]);
   if (find != NULL){
      printf("true\n");
   }
   else {
      printf("false\n");
   }
return 0;
}
