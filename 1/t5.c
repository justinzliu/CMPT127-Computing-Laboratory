#include <stdio.h>
#include <math.h>

int main(void)
{
   float i;
   int check;
   do
   {
     check = scanf("%f", &i);
     if (check == 0)
     {
       printf("scanf error: (%d)\n", check);
     }
     else if (check == EOF)
     {
       printf("\nDone.\n");
     }
     else
     {
       float rounddown = floor(i);
       float stdround = round(i);
       float roundup = ceil(i);
       printf("%0.0f %0.0f %0.0f\n", rounddown, stdround, roundup);
     }
   } while (check != EOF);
   return 0;
}
