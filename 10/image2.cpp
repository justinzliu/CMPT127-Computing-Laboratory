#include <stdlib.h>
#include <stdint.h>
#include <string.h> 
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include "image2.hpp"
  
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

int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolor ) {
   if (pixels != NULL) {
      delete [] pixels;
   }
   pixels = new uint8_t[width*height];
   if (pixels != NULL) {
      cols = width;
      rows = height;
      for (unsigned int i=0; i<width*height; i++) {
         pixels[i] = fillcolor;
      }
      return 0;
   }
   return 1; 
}
int Image::set_pixel( unsigned int x, unsigned int y, uint8_t color ) {
   if (pixels != NULL && x < cols && y < rows) {
      pixels[x+(y*cols)] = color;
      return 0;
   }
   return 1;
}

int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colorp ) {
   if (pixels != NULL && colorp != NULL && x < cols && y < rows) {
      *colorp = pixels[x+(y*cols)];
      return 0;
   }
   return 1;
}
  /* Saves the image in the file filename. In a format that can be
     loaded by load().  Returns 0 on success, else a non-zero error
     code. */
int save( const char* filename ) {
   if (filename != NULL) {
      FILE* f = fopen(filename, "w");
      if (f != NULL) {
         int len = cols*rows;
         fwrite(cols,sizeof(uint8_t*),1,f);
         fwrite(rows,sizeof(uint8_t*),1,f);
         if (len > 0) {
            fwrite(pixels,sizeof(uint8_t*),len,f);
            if (fwrite(ia->data,sizeof(uint8_t*),len,f) == len) {
               fclose(f);
               return 0;
            }
         }
         else {
            fclose(f);
            return 0;
         }
      fclose(f);
      }
   }
   return 1;
}

  /* Load the an image from the file filename, replacing the current
     image size and data. The file is in a format that was saved by
     save().  Returns 0 success, else a non-zero error code . */
int load( const char* filename ) {
   if (filename != NULL) {
      FILE* f = fopen(filename,"r");
      if (f != NULL) {
         fread(&cols,sizeof(uint8_t*),1,f);
         fread(&rows,sizeof(uint8_t*),1,f);
         unsigned len = cols*rows;
         if (Image::resize(cols,rows,0) == 0) {
            for (int i=0; i<len; i++) {
               fread(pixels,sizeof(uint8_t*),ia->len,f);
            }
            fclose(f);
            return 0;
         }
      }
      fclose(f);
   }
   return 1;
}
