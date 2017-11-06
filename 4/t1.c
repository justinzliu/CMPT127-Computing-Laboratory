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
   float distarray[5];
   if (r == 0) {
   }
   else {
      for (int i=0; i<rows; i++) {
         for (int j=0; j<cols; j++) {                           
            distarray[0] = pow((j-x),2)+pow((i-y),2);                       
            distarray[1] = pow((j-x+0.5),2)+pow((i-y+0.5),2);                                
            distarray[2] = pow((j-x-0.5),2)+pow((i-y+0.5),2);              
            distarray[3] = pow((j-x-0.5),2)+pow((i-y-0.5),2);                             
            distarray[4] = pow((j-x+0.5),2)+pow((i-y-0.5),2);
         for (int k=0; k<5; k++) {
               if (distarray[k] < r) {
                  img[j+i*cols] = color;
               }
         }
         }
      }            
   }
   return;
}
