#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
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
   if (Image->pixels != NULL) {
      delete [] Image->pixels;
   }
   uint8_t* pixels = new uint8_t(width*height);
   if (Image->pixels != NULL) {
      Image->cols = width;
      Image->rows = height;
      for (int i=0; i<width*height; i++) {
         Image->pixels[i] = fillcolor;
      }
      return 0;
   }
   return 1; 
}
int set_pixel( unsigned int x, unsigned int y, uint8_t color ) {
   if (Image->pixels != NULL && x < Image->cols && Image->y < rows) {
      Image->pixels[x+y*cols] = color;
      return 0;
   }
   return 1;
}

int get_pixel( unsigned int x, unsigned int y, uint8_t* colorp ) {
   if (Image->pixels != NULL && x < Image->cols && Image->y < rows) {
      *colorp = Image->pixel[x+y*cols];
      return 0;
   }
   return 1;
}















