#include <stdio.h>
#include <stdint.h>

void life ( uint8_t array[],
            unsigned int cols,
            unsigned int rows )
{
      uint8_t arr[cols*rows];
      }
      for (int i=0;i<rows*cols;i++) {
         arr[i] = 0;
      }
      for (int i=0; i<rows; i++) {
         for (int j=0; j<cols; j++) {
            unsigned int count = 0;
	    //Top
            if (i==0) {
               //Top Left
               if (j==0) {
                  if (array[j+1+i*cols] > 0) {
                     count+=1;
                  }
                  if (array[j+(i+1)*cols] > 0) {
                     count+=1;
                  }
                  if (array[j+1+(i+1)*cols] > 0) {
                     count+=1;
                  } 
               }
	       //Top Right
               else if (j==cols-1) {
                  if (array[j-1+i*cols] > 0) {
                     count+=1;
                  }
                  if (array[j+(i+1)*cols] > 0) {
                     count+=1;
                  }
                  if (array[j-1+(i+1)*cols] > 0) {
                     count+=1;
                  }
               }
               //Top Middle
               else {
                  if (array[j-1+i*cols] > 0) {
                     count+=1;
                  }
                  if (array[j+1+i*cols] > 0) {
                     count+=1;
                  }
                  if (array[j+(i+1)*cols] > 0) {
                     count+=1;
                  }
                  if (array[j-1+(i+1)*cols] > 0) {
                     count+=1;
                  }  
                  if (array[j+1+(i+1)*cols] > 0) {
                     count+=1;
                  }              
               }  
            }
            //Bottom
            else if (i==rows-1) {    
               //Bottom Left
               if (j==0) {
                  if (array[j+1+i*cols] > 0) {
                     count+=1;
                  }
                  if (array[j+(i-1)*cols] > 0) {
                     count+=1;
                  }
                  if (array[j+1+(i-1)*cols] > 0) {
                     count+=1;
                  }
               }
	       //Bottom Right
               else if (j==cols-1) {
                  if (array[j-1+i*cols] > 0) {
                     count+=1;
                  }
                  if (array[j+(i-1)*cols] > 0) {
                     count+=1;
                  }
                  if (array[j-1+(i-1)*cols] > 0) {
                     count+=1;
                  }
               }
               //Bottom Middle
               else {
                  if (array[j-1+i*cols] > 0) {
                     count+=1;
                  }
                  if (array[j+1+i*cols] > 0) {
                     count+=1;
                  }
                  if (array[j+(i-1)*cols] > 0) {
                     count+=1;
                  }
                  if (array[j-1+(i-1)*cols] > 0) {
                     count+=1;
                  }  
                  if (array[j+1+(i-1)*cols] > 0) {
                     count+=1;
                  }              
               }                    
            }
            //Center
            else {    
               //Center Left
               if (j==0) {
                  if (array[j+1+i*cols] > 0) {
                     count+=1;
                  }
                  if (array[j+1+(i+1)*cols] > 0) {
                     count+=1;
                  }
                  if (array[j+(i+1)*cols] > 0) {
                     count+=1;
                  }
                  if (array[j+(i-1)*cols] > 0) {
                     count+=1;
                  }
                  if (array[j+1+(i-1)*cols] > 0) {
                     count+=1;
                  }
               }
      	       //Center Right
               else if (j==cols-1) {
                  if (array[j-1+i*cols] > 0) {
                     count+=1;
                  }
                  if (array[j-1+(i+1)*cols] > 0) {
                     count+=1;
                  }
                  if (array[j+(i+1)*cols] > 0) {
                     count+=1;
                  }
                  if (array[j+(i-1)*cols] > 0) {
                     count+=1;
                  }
                  if (array[j-1+(i-1)*cols] > 0) {
                     count+=1;
                  }
               }
               //Center Middle
               else {
                  if (array[j-1+i*cols] > 0) {
                     count+=1;
                  }
                  if (array[j+1+i*cols] > 0) {
                     count+=1;
                  }
                  if (array[j+1+(i+1)*cols] > 0) {
                     count+=1;
                  }
                  if (array[j-1+(i+1)*cols] > 0) {
                     count+=1;
                  }
                  if (array[j+(i+1)*cols] > 0) {
                     count+=1;
                  }
                  if (array[j+(i-1)*cols] > 0) {
                     count+=1;
                  }
                  if (array[j-1+(i-1)*cols] > 0) {
                     count+=1;
                  }  
                  if (array[j+1+(i-1)*cols] > 0) {
                     count+=1; 
                  }              
               }                     
            } 
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
      for (int i=0;i<rows*cols;i++) {
         array[i] = arr[i];
      }
   return;
}
