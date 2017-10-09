#include <stdio.h>

int main() {

   long unsigned charcount = 0;
   long unsigned linecount = 0;
   long unsigned wordcount = 0;
   int OutIn = 0;
   char c;
   int cvalue;

   while ((c = getchar()) != EOF) {
      cvalue = c;
      charcount += 1;
      if ( c == '\n') {
         linecount += 1;
      }
      if (cvalue < 65 || cvalue > 122 || (cvalue > 90 && cvalue < 97) && cvalue != 39) {
         OutIn = 0;      
      }
      else if (OutIn == 0) {
         OutIn = 1;
         wordcount += 1;
      }
   }
   printf("%lu %lu %lu\n", charcount, wordcount, linecount);
   return 0;
}
