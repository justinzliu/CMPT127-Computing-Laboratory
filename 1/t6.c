#include <stdio.h>
#include <math.h>

int main(void)
{
   long double i;
   long double smallest = 100000;
   long double largest = -100000;
   long double total;
   long double average;
   int count;
   int check;
   do
   {
      check = scanf("%Lf", &i);
      if (check == EOF)
      {
         average=total/count;
         printf("\n%0.2Lf %0.2Lf %0.2Lf\n", smallest, largest, average);
      }
      else if (check == 0)
      {
         printf("scanf error: (%d)\n", check);
      }
      else
      {
         total += i;
         count += 1;
         if (i > largest || largest == -100000)
         {
            largest = i;
         }
         if (i < smallest || smallest == 100000)
         {
            smallest = i;
         }
      }
   } while (check != EOF);
   return 0;
}
