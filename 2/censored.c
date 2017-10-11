#include <stdio.h>
#include <string.h>

int main( int argc, char* argv[] ) {
   char c;
   int ToF = 0;
   while ((c=getchar()) != EOF) {
      if (argc <= 1) {
         putchar(c);
      }
      else {
         for (int i = 1; i < argc; i++) {
            if (argv[i][0] == c) {
               char check[100] = {'0'};
               check[0] = c;
               for (int j = 1; j < strlen(argv[i]); j++) {
                  c = getchar();
                  if (argv[i][j] != c) {
                     for (int k=0; k < strlen(check); k++) {
                     printf("%c", check[k]);
                     }
                     break;
                  }
                  else {
                     check[j] = c;
                  }
               }
               if ((strstr(check, argv[i])) != NULL) {
                  printf("CENSORED");
                  ToF = 1;
               }
            }
      }
      if ( ToF == 0){
         putchar(c);
      }
      else {
         ToF = 0;
      }
   }
   }
   return 0;
}
               
