/*
 * imageops.c - Simple operations on images
 *
 * C laboratory exercises.
 * Richard Vaughan, 2014.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* PAIR SECTION BEGINS - WORK WITH YOUR PARTNER ON THESE TASKS */

/*-------------------------------------------------
  PART 0: DEMONSTRATION
*/


// get the value in the array at coordinate (x,y)
uint8_t get_pixel( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows );
    return array[ y*cols + x ];
}

// set the pixel at coordinate {x,y} to the specified color
void set_pixel( uint8_t array[], 
        unsigned int cols, 
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
} 

// Set every pixel to 0 (black) 
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
   memset(array,0,rows*cols*sizeof(array[0]));
}

// Returns a pointer to a freshly allocated array that contains the
// same values as the original array, or a null pointer if the
// allocation fails. The caller is responsible for freeing the array
// later.
uint8_t* copy( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows )
{
  uint8_t* arr = malloc(sizeof(array[0])*rows*cols);
  if ( arr != NULL) {
     for (int i=0;i<rows*cols;i++) {
        arr[i] = array[i];
     }    
  }
 return arr;
}



/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE 
*/

/* TASK 1 - three easy functions to get started */

// Return the darkest color that appears in the array; i.e. the
// smallest value
uint8_t min( const uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows )
{
  unsigned int smallest = array[0];
  for (int i=1;i<cols*rows;i++){
     if (array[i]<smallest) {
        smallest = array[i];
     }
  }
  return smallest;
}

// Return the lightest color that appears in the array; i.e. the
// largest value
uint8_t max( const uint8_t array[], 
		 unsigned int cols, 
		 unsigned int rows )
{
  unsigned int largest = array[0];
  for (int i=1;i<cols*rows;i++){
     if (array[i]>largest) {
        largest = array[i];
     }
  }
  return largest;
}

// TASK 2

//  Replace every instance of pre_color with post_color.
void replace_color(  uint8_t array[], 
		     unsigned int cols, 
		     unsigned int rows,
		     uint8_t pre_color,
		     uint8_t post_color )
{
  for (int i=0;i<cols*rows;i++) {
     if (array[i] == pre_color) {
        array[i] = post_color;
     }
  }
}

/* TASK 3  - two functions */


// flip the image, left-to-right, like in a mirror.
void flip_horizontal( uint8_t array[], 
              unsigned int cols, 
              unsigned int rows )
{
  for (int i=0;i<rows;i++) {
     for (int j=0;j<cols/2;j++) {
        uint8_t tempvar = array[j+i*cols];
        array[j+i*cols] = array[(cols-1-j)+i*cols];
        array[cols-1-j+i*cols] = tempvar;
     }
  }
}

// flip the image top-to-bottom.
void flip_vertical( uint8_t array[], 
            unsigned int cols, 
            unsigned int rows )
{
  for (int i=0;i<cols;i++) {
     for (int j=0;j<rows/2;j++) {
        uint8_t tempvar = array[i+j*cols];
        array[i+j*cols] = array[i+(rows-1-j)*cols];
        array[i+(rows-1-j)*cols] = tempvar;
     }
  }
}

/* TASK 4 */

// Find the first coordinate of the first pixel with a value that
// equals color. Search from left-to-right, top-to-bottom. If it is
// found, store the coordinates in *x and *y and return 1. If it is
// not found, return 0.
int locate_color(  const uint8_t array[], 
		   unsigned int cols, 
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y )
{
    unsigned int* coordinates = malloc(sizeof(unsigned int)*2);
    for (int i=0;i<rows*cols;i++) {
       if (array[i] == color) {
          x = &coordinates;
          y = &coordinates+1;
          return 1;
       }
    }
    return 0;
}


/* TASK 5 */

// Invert the image, so that black becomes white and vice versa, and
// light shades of grey become the corresponding dark shade. 
void invert( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows )
{
    for (int i=0; i<rows*cols; i++) {
       array[i] = 255-array[i]; 
    }
}

/* TASK 6 */

// Multiply every pixel by scale_factor, in order to brighten or
// darken the image. Any resulting value over 255 is
// thresholded to 255.
void scale_brightness( uint8_t array[],
            unsigned int cols,
            unsigned int rows,
            double scale_factor )
{
  for (int i=0; i<rows*cols; i++) {
     array[i] = round(array[i]*scale_factor);
     if (array[i] > 255) {
        array[i] = 255;
     }
  }
}


/* TASK 7 */

// Normalize the dynamic range of the image, i.e. Shift and scale the
// pixel colors so that that darkest pixel is 0 and the lightest pixel
// is 255. Hint: you already wrote min() and max(). 
void normalize( uint8_t array[],
        unsigned int cols,
        unsigned int rows )
{
   float INmax = max(array,cols,rows);
   printf("max = %f\n", INmax);
   float INmin = min(array,cols,rows);
   printf("min = %f\n", INmin);
   float INrange = INmax-INmin;
   printf("range = %f\n", INrange);
   float scale;
   unsigned int normalizeValue;
   printf("\n");
   for (int i=0; i<rows*cols; i++) {
      scale = (array[i]-INmin)/INrange;
      normalizeValue = round((255*scale));
      array[i] = normalizeValue;
   }
}

/* TASK 8 */

// Return a new image of size rows/2 by cols/2 If the original image              
// has an odd number of columns, ignore its rightmost column. If the              
// original image has an odd number of rows, ignore its bottom row.               
// The value of a pixel at (p,q) in the new image is the average of               
// the four pixels at (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1) in               
// the original image.                                                            
uint8_t* half( const uint8_t array[],
	       unsigned int cols,
	       unsigned int rows )
{
  unsigned int NEWcols = cols/2;
  unsigned int NEWrows = rows/2;
  uint8_t* NEWarr= malloc(sizeof(array[0])*NEWcols*NEWrows);
  zero(NEWarr,NEWcols,NEWrows);
  unsigned int k=0;
  unsigned int l=0;
  for (int i=1;i<rows;i+=2) {
     //NEWarr[i] = NEWarr[i]+array[j+i*cols];
     l=0;
     for (int j=1; j<cols;j+=2) {
        NEWarr[l+k*NEWcols] += array[j+1];
        NEWarr[l+k*NEWcols] += array[j-1];
        NEWarr[l+k*NEWcols] += array[j+(i-1)*cols];
        NEWarr[l+k*NEWcols] += array[j+(i+1)*cols];
        l+=1;
     k+=1;
     }
  }
  return NEWarr;
}




/*-------------------------------------------------
  PART 2: OPERATIONS ON IMAGE SUB-REGIONS

  These functions operate only on a rectangular region of the array
  defined by a (left,top) corner (i.e. closer to the image origin) and
  (right,bottom) corner (i.e. further from the image origin).

  The region includes all the columns from [left, right-1] inclusive,
  and allthe rows from [top, bottom-1] inclusive.
  
  In every case, you may assume that left <= right and top <= bottom:
  do not need to test for this.

  The area of the region is right-left * bottom-top pixels, which
  implies that if left == right or top == bottom, the region has no
  area and is defined as "empty". Each function notes how to handle
  empty regions.
 
  In every function, use assert() to test bounds on the region
  corners.
*/

/* TASK 9 */

// Set every pixel in the region to color. If the region is empty, the
// image must be unchanged.
void region_set( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows,
         unsigned int left,
         unsigned int top,
         unsigned int right,
         unsigned int bottom,
         uint8_t color )
{
   unsigned int emptyCount = 0;
   int emptyTF = 1;
   for (int i=top; i<bottom; i++) {
      for (int j=left; j<right; j++) {
         if (emptyTF == 1 && array[j+i*cols] == 0) {
            emptyCount += 1;
         }
         else {
            array[j+i*cols] = color;
            emptyTF = 0;
            if (emptyCount > 0) {
               for (int k=top; k<=top+(emptyCount/(right-left)); k++) {
                  for (int l=left; l<=left+(emptyCount%(right-left)); l++) {
                     array[l+k*cols] = color;
                  }
               }
            }
         }
      }
   }
}

/* TASK 10 */

// Return the sum of all the pixels in the region. Notice the large
// return type to handle potentially large numbers. Empty regions
// return the sum 0.
unsigned long int region_integrate( const uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows,
                    unsigned int left,
                    unsigned int top,
                    unsigned int right,
                    unsigned int bottom )
{
   unsigned long int sum;
   for (int i=top; i<bottom; i++) {
      for (int j=right; j<left; j++) {
         sum += array[j+i*cols];
      }
   }
   return sum;
}

/* TASK 11 */

// Get a new image which is a copy of the region. Empty regions return
// a null pointer. If memory allocation fails, return a null
// pointer. The caller is responsible for freeing the returned array
// later.
uint8_t* region_copy( const uint8_t array[], 
              unsigned int cols, 
              unsigned int rows,
              unsigned int left,
              unsigned int top,
              unsigned int right,
              unsigned int bottom )
{
   uint8_t* COPYarr = malloc(sizeof(array[0]*(right-left)*(top-bottom)));
   int k=0;
   for (int i=top; i<bottom; i++) {
      for (int j=right; j<left; j++) {
         COPYarr[k] = array[j+i*cols];
         k+=1;   
         }
   }
   return COPYarr;
}


