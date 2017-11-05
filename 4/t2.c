#include <stdio.h>
#include <stdint.h>

int check_boundary(unsigned int cols, unsigned int rows, int x, int y, int i, int j) {
   if (j > -1 && j < cols && i > -1 && i < rows) {
      return 1;
   }  
   return 0;
}

int check_boundary(unsigned int cols, unsigned int rows, int x, int y, int i, int j);

void draw_rectangle( uint8_t array[],
                     unsigned int cols,
                     unsigned int rows,
                     int x,
                     int y,
                     int rect_width,
                     int rect_height,
                     uint8_t color )
{
   int TBboundary = y+rect_height;
   int RLboundary = x+rect_width;
   //NO RECTANGLE
   if (rect_width == 0 || rect_height == 0) {
   }
   //RECTANGLE DRAWS DOWN
   else if (rect_height > 0) {
      for (int i=y; i<TBboundary; i++) {
         //RECTANGLE DRAWS RIGHT
         if (rect_width > 0) {
            for (int j=x;j<RLboundary; j++) {
               if (check_boundary(cols,rows,x,y,i,j)==1) {
                  if (i == y || i == TBboundary-1) {
                     array[j+i*cols] = color;
                  }
                  else if (j==x || j==RLboundary-1) {
                     array[j+i*cols] = color;            
                  }
               }
            }
         }
         //RECTANGLE DRAWS LEFT
         else if (rect_width < 0) {
            for (int j=x;j>RLboundary; j--) {
               if (check_boundary(cols,rows,x,y,i,j)==1) {          
                  if (i == y || TBboundary-1) {
                     array[j+i*cols] = color;
                  }
                  else if (j==x || j==RLboundary+1) {
                     array[j+i*cols] = color;            
                  }
               }
            }
         }
      }
   }
   //RECTANGLE DRAWS UP
   else if (rect_height < 0) {
      for (int i=y; i>TBboundary; i--) {

         //RECTANGLE DRAWS RIGHT
         if (rect_width > 0) {
            for (int j=x;j<RLboundary; j++) {
               if (check_boundary(cols,rows,x,y,i,j)==1) {
                  if (i == y || TBboundary+1) {
                     array[j+i*cols] = color;
                  }
                  else if (j==x || j==RLboundary-1) {
                     array[j+i*cols] = color;            
                  }
               }
            }
         }
         //RECTANGLE DRAWS LEFT
         else if (rect_width < 0) {
            for (int j=x;j>RLboundary; j--) {
               if (check_boundary(cols,rows,x,y,i,j)==1) {
                  if (i == y || TBboundary+1) {
                     array[j+i*cols] = color;
                  }
                  else if (j==x || j==RLboundary+1) {
                     array[j+i*cols] = color;            
                  }
               }
            }
         }
      }
   }      
   return;
}
