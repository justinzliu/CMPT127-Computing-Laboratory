#include <stdio.h>

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
   if (rect_width == 0 || rect_height == 0) {
   }
   else if (rect_height > 0) {
      for (int i=y; i<TBboundary; i++) {
         if (rect_width > 0) {
            for (int j=x;j<RLboundary; j++) {
               if (i == y) {
                  array[j+i*cols] = color;
               }
               else if (i == TBboundary-1) {
                  array[j+i*cols] = color;
               }
               else if (j==x || j==RLboundary-1) {
                  array[j+i*cols] = color;            
               }
            }
         }
         if (rect_width < 0) {
            for (int j=x;j>RLboundary; j--) {
               if (i == y) {
                  array[j+i*cols] = color;
               }
               else if (i == TBboundary-1) {
                  array[j+i*cols] = color;
               }
               else if (j==x || j==RLboundary+1) {
                  array[j+i*cols] = color;            
               }
            }
         }
      }
   }
   else if (rect_height < 0) {
      for (int i=y; i>TBboundary; i--) {
         if (rect_width > 0) {
            for (int j=x;j<RLboundary; j++) {
               if (i == y) {
                  array[j+i*cols] = color;
               }
               else if (i == TBboundary+1) {
                  array[j+i*cols] = color;
               }
               else if (j==x || j==RLboundary-1) {
                  array[j+i*cols] = color;            
               }
            }
         }
         if (rect_width < 0) {
            for (int j=x;j>RLboundary; j--) {
               if (i == y) {
                  array[j+i*cols] = color;
               }
               else if (i == TBboundary+1) {
                  array[j+i*cols] = color;
               }
               else if (j==x || j==RLboundary+1) {
                  array[j+i*cols] = color;            
               }
            }
         }
      }
   }      
   return;
}
