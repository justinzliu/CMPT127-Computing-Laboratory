#include <stdlib.h>
#include <stdint.h>
#include <string.h> 
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "image.hpp"

Image::Image() {
   cols = 0;
   rows = 0;
   pixels = NULL;
}

Image::~Image() {
   cols = 0;
   rows = 0;
   if (pixels != NULL) {
      delete [] pixels;
   }
}

int resize( unsigned int width,  unsigned int height, uint8_t fillcolor ) {
   if (pixels != NULL) {
      delete [] pixels;
   }
   uint8_t* pixels = new uint8_t(width*height);
   if (pixels != NULL) {
      cols = width;
      rows = height;
      for (int i=0; i<width*height; i++) {
         pixels[i] = fillcolor;
      }
      return 0;
   }
   return 1; 
}
int set_pixel( unsigned int x, unsigned int y, uint8_t color ) {
   if (pixels != NULL && x < cols && y < rows) {
      pixels[x+y*cols] = color;
      return 0;
   }
   return 1;
}

int get_pixel( unsigned int x, unsigned int y, uint8_t* colorp ) {
   if (pixels != NULL && x < cols && y < rows) {
      *colorp = pixel[x+y*cols];
      return 0;
   }
   return 1;
}














