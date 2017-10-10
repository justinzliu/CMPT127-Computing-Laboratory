#include <stdio.h>

int main() {
   char c;
   float charcount = 0;
   int cvalue;
   int count[26]={0};
   char alphabet[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};

   while ((c = getchar()) != EOF) {
      cvalue = c;
      if (cvalue > 96 && cvalue < 123) { 
         count[cvalue - 97] += 1;
         charcount += 1;
      }
      else if (cvalue > 64 && cvalue < 91) {
         count[cvalue - 65] += 1;
         charcount += 1;
      }
   }
   for (int i=0; i<26; i++) {
      if (count[i] != 0) {
         printf("%c %.4f\n", alphabet[i], count[i]/charcount);
      }
   }
   return 0;
}
