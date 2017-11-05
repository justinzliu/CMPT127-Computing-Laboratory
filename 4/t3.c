#include <stdio.h>
#include <stdint.h>

int xsearch ( int x, unsigned int cols ) {
   if (x < 0) {
      x = cols - 1; 
   }
   else {
      x = x % cols;
   }
   return x;
}

int ysearch ( int y, unsigned int rows ) {
   if (y < 0) {
      y = rows - 1; 
   }
   else {
      y = y % rows;
   }
   return y;
}

int xsearch ( int x, unsigned int cols );
int ysearch ( int y, unsigned int rows );

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
         x = xsearch(j+1,cols);
         y = ysearch(i,rows);   
         if (array[x+y*cols] > 0) {
            count+=1;
         }
         //CHECK BOTTOM RIGHT
         x = xsearch(j+1,cols);
         y = ysearch(i+1,rows);   
         if (array[x+y*cols] > 0) {
            count+=1;
         }
         //CHECK BOTTOM
         x = xsearch(j,cols);
         y = ysearch(i+1,rows);   
         if (array[x+y*cols] > 0) {
            count+=1;
         }  
         //CHECK BOTTOM left
         x = xsearch(j-1,cols);
         y = ysearch(i+1,rows);   
         if (array[x+y*cols] > 0) {
            count+=1;
         }          
         //CHECK LEFT
         x = xsearch(j-1,cols);
         y = ysearch(i,rows);   
         if (array[x+y*cols] > 0) {
            count+=1;
         }
         //CHECK TOP LEFT
         x = xsearch(j-1,cols);
         y = ysearch(i-1,rows);   
         if (array[x+y*cols] > 0) {
            count+=1;
         }  
         //CHECK TOP
         x = xsearch(j,cols);
         y = ysearch(i-1,rows);   
         if (array[x+y*cols] > 0) {
            count+=1;
         } 
         //CHECK TOP RIGHT
         x = xsearch(j+1,cols);
         y = ysearch(i-1,rows);   
         if (array[x+y*cols] > 0) {
            count+=1;
         }  
         //CREATE NEXT STEP OF LIFE
         if (array[j+i*cols] == 0) {
            if (count == 3) {
               arr[j+i*cols] = 1;
            }
         }
         else {
            if (count == 3 || count == 2) {
               arr[j+i*cols] = 1;
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
