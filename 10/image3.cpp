#include <stdlib.h>
#include <stdint.h>
#include <string.h> 
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include "image3.hpp"
  
  /* Constructs an image of 0x0 pixels. */
Image::Image() {
   cols = 0;
   rows = 0;
   pixels = NULL;
}
  
  /* Frees all memory allocated for img */
Image::~Image() {
   cols = 0;
   rows = 0;
   if (pixels != NULL) {
      for (unsigned int i=0; i<rows; i++) {
         delete [] pixels[i];
      }
      delete [] pixels;
      pixels = NULL;
   }
}

  
  /* Changes the size of an image, allocating memory as necessary, and
     setting all pixels to fillcolor. Returns 0 on success, or a
     non-zero error code.*/ 
int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolor ) {
   //I would imagine this would be a good line of code... but apparently I'm getting a double free call.
   if (pixels != NULL) {
      for (unsigned int i=0; i<rows; i++) {
         delete [] pixels[i];
      }
      delete [] pixels;
      pixels = NULL;
   }
   pixels = new uint8_t*[height];
   if (pixels != NULL) {
      for (unsigned int i=0; i<height; i++) {
         pixels[i] = new uint8_t[width];
         if (pixels[i] == NULL) {
            return 1;
         }
      }
      cols = width;
      rows = height;
      for (unsigned int i=0; i<height; i++) {
         for (unsigned int j=0; j<width; j++) {
            pixels[i][j] = fillcolor;
         }
      }
      return 0;
   }
   return 1; 
}
  
  /* Sets the color of the pixel at (x,y) to color. Returns 0 on
     success, else a non-zero error code. If (x,y) is not a valid
     pixel, the call fails and the image does not change.*/
int Image::set_pixel( unsigned int x, unsigned int y, uint8_t color ) {
   if (pixels != NULL && x < cols && y < rows) {
      pixels[y][x] = color;
      return 0;
   }
   return 1;
}

  
  /* Gets the color of the pixel at (x,y) and stores at the address
     pointed to by colorp. Returns 0 on success, else a non-zero error
     code. */
int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colorp ) {
   if (pixels != NULL && colorp != NULL && x < cols && y < rows) {
      *colorp = pixels[y][x];
      return 0;
   }
   return 1;
}
  
  /* Saves the image in the file filename. In a format that can be
     loaded by load().  Returns 0 on success, else a non-zero error
     code. */
int Image::save( const char* filename ) {
   if (filename != NULL) {
      FILE* f = fopen(filename, "w");
      if (f != NULL) {
         unsigned int len = cols*rows;
         int check = 0;
         if (len > 0) {
            fwrite(&cols,sizeof(uint8_t*),1,f);
            fwrite(&rows,sizeof(uint8_t*),1,f);
            for (unsigned int i=0; i<rows; i++) {
               for (unsigned int j=0; j<cols; j++) {
                  fwrite(&pixels[i][j],sizeof(uint8_t*),1,f);
                  check++;
               }
            }
            if (check == len) {
               fclose(f);
               return 0;
            }
         else if (len == 0) {
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
int Image::load( const char* filename ) {
   if (filename != NULL) {
      FILE* f = fopen(filename,"r");
      if (f != NULL) {
         fread(&cols,sizeof(uint8_t*),1,f);
         fread(&rows,sizeof(uint8_t*),1,f);
         if (resize(cols,rows,0) == 0) {
         int check = 0;
            for (unsigned int i=0; i<rows; i++) {
               for (unsigned int j=0; j<cols; j++) {
                  fread(&pixels[i][j],sizeof(uint8_t*),1,f);
                  check++;
               }
            }
            if (check == cols*rows) {
               fclose(f);
               return 0;
            }
         }   
      fclose(f);
      }
   }
   //any errors or empty file
   return 1;
}

