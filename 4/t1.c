#include <stdio.h>
#include <math.h>
#include <stdint.h>

void draw_circle(uint8_t img[], 
                 unsigned int cols, 
                 unsigned int rows,
                 int x,
                 int y,
                 int r,
                 uint8_t color )
{
   if (r == 0) {
   }
   else {
      for (int i=0; i<rows; i++) {
         for (int j=0; j<cols; j++) {
            int distance = round(sqrt((pow((j-x),2)+pow((i-y),2))/1.0));
            if (distance <= r) {
               img[j+i*cols] = color;
            }
         }
      }
   }
   return;
}
