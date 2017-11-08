#include <stdio.h>
#include <stdint.h>

int xysearch ( int xy, unsigned int rowscols ) {
   if (xy < 0) {
      xy = rowscols - 1; 
   }
   else {
      xy = xy % rowscols;
   }
   return xy;
}

int xysearch ( int xy, unsigned int rowscols );

void life ( uint8_t array[],
            unsigned int cols,
            unsigned int rows )
{
   int x;
   int y;
   unsigned int count;
   uint8_t arr[cols*rows];
   //INITIALIZE TEMP ARRAY
   for (int i=0;i<rows*cols;i++) {
      arr[i] = 0;
   }
   for (int i=0; i<rows; i++) {
      for (int j=0; j<cols; j++) {
         count = 0; 
         //CHECK RIGHT
         x = xysearch(j+1,cols);
         y = xysearch(i,rows);   
         if (array[x+y*cols] > 0) {
            count+=1;
         }
         //CHECK BOTTOM RIGHT
         x = xysearch(j+1,cols);
         y = xysearch(i+1,rows);   
         if (array[x+y*cols] > 0) {
            count+=1;
         }
         //CHECK BOTTOM
         x = xysearch(j,cols);
         y = xysearch(i+1,rows);   
         if (array[x+y*cols] > 0) {
            count+=1;
         }  
         //CHECK BOTTOM left
         x = xysearch(j-1,cols);
         y = xysearch(i+1,rows);   
         if (array[x+y*cols] > 0) {
            count+=1;
         }          
         //CHECK LEFT
         x = xysearch(j-1,cols);
         y = xysearch(i,rows);   
         if (array[x+y*cols] > 0) {
            count+=1;
         }
         //CHECK TOP LEFT
         x = xysearch(j-1,cols);
         y = xysearch(i-1,rows);   
         if (array[x+y*cols] > 0) {
            count+=1;
         }  
         //CHECK TOP
         x = xysearch(j,cols);
         y = xysearch(i-1,rows);   
         if (array[x+y*cols] > 0) {
            count+=1;
         } 
         //CHECK TOP RIGHT
         x = xysearch(j+1,cols);
         y = xysearch(i-1,rows);   
         if (array[x+y*cols] > 0) {
            count+=1;
         }  
         //CREATE NEXT STEP OF LIFE
         if (array[j+i*cols] == 0) {
            if (count == 3) {
               arr[j+i*cols] = 255;
            }
         }
         else {
            if (count == 3 || count == 2) {
               arr[j+i*cols] = 255;
            }
         }
      }
   }
      //OVERWRITE ARRAY
      for (int i=0;i<rows*cols;i++) {
         array[i] = arr[i];
      }
   return;
}
