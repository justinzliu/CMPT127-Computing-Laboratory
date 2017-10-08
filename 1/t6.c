#include <stdio.h>
#include <math.h>

int main(void)
{
   float i;
   float smallest = 100000;
   float largest = -100000;
   float total;
   float average;
   int count;
   int check;
   while (check != EOF)
   {
      check = scanf("%f", &i);
      if (check == EOF)
      {
         average=total/count;
         printf("%0.2f %0.2f %0.2f\n", smallest, largest, average);
      }
      else if (check == 0)
      {
         printf("scanf error: (%d)\n", check);
      }
      else
      {
         total += i;
         count += 1;
         if (i > largest || largest ==-100000)
         {
            largest = i;
         }
         if (i < smallest || smallest ==100000)
         {
            smallest = i;
         }
      }
   } 
   return 0;
}
