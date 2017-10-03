#include <stdio.h>
#include <math.h>

int main(void)
{
   float i;
   int check;
   check = scanf("%f", &i);
   if (check != 1)
   {
     printf("scanf error: (%d)\n", check);
   }
   else
   {
     float rounddown = floor(i);
     float stdround = round(i);
     float roundup = ceil(i);
     printf("%0.0f %0.0f %0.0f\n", rounddown, stdround, roundup);
   }
   return 0;
}
