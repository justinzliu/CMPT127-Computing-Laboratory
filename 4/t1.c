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
   r = r*r;
   float distance;
   if (r == 0) {
   }
   else {
      for (int i=0; i<rows; i++) {
         for (int j=0; j<cols; j++) {
            if (j == x || i == y) {                                // PIXEL LIES ON THE X OR Y AXIS
               distance = pow((j-x),2)+pow((i-y),2);
            }
            else if (j > x && i > y) {                                  // PIXEL LIES IN QUADRANT 1
               distance = pow((j-x+0.5),2)+pow((i-y+0.5),2);
            }
            else if (j < x && i > y) {                                  // PIXEL LIES IN QUADRANT 2
               distance = pow((j-x-0.5),2)+pow((i-y+0.5),2);
            }
            else if (j < x && i < y) {                                  // PIXEL LIES IN QUADRANT 3
               distance = pow((j-x-0.5),2)+pow((i-y-0.5),2);
            }
            else if (j > x && i < y) {                                  // PIXEL LIES IN QUADRANT 4
               distance = pow((j-x+0.5),2)+pow((i-y-0.5),2);
            }
            if (distance <= r) {
               img[j+i*cols] = color;
            }
         }            
      }
   }
   return;
}
