#include <stdio.h>
#include <math.h>

int main(void)
{
   float i = 0.0;
   scanf("%f", &i);
   float rounddown = floor(i);
   float stdround = round(i);
   float roundup = ceil(i);
   printf("%0.0f %0.0f %0.0f\n", rounddown, stdround, roundup);
   return 0;
}
