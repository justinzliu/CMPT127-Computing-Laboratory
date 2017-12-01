#include <stdio.h>
#include <stdlib.h>
#include "intarr.h"

/* LAB 6 TASK 1 */

/*
  Save the entire array ia into a file called 'filename' in a binary
  file format that can be loaded by intarr_load_binary(). Returns
  zero on success, or a non-zero error code on failure. Arrays of
  length 0 should produce an output file containing an empty array.
*/
int intarr_save_binary( intarr_t* ia, const char* filename ) {
   if (ia != NULL) {
      FILE* f = fopen(filename, "w");
      if (f != NULL) {
         fwrite(&(ia->len),sizeof(unsigned int),1,f);
         if (fwrite(ia->data,sizeof(int),ia->len,f) == ia->len) {
            fclose(f);
            return 0;
         }
      }
      fclose(f);
   }
   return 1;
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.
*/
intarr_t* intarr_load_binary( const char* filename ) {
   FILE* f = fopen(filename,"r");
   if (f != NULL) {
      intarr_t* iaNew = malloc(sizeof(intarr_t));
      if (iaNew != NULL) {
         fread(&(iaNew->len),sizeof(unsigned int),1,f);
         iaNew->data = malloc(sizeof(int)*iaNew->len);
         if (iaNew->data != NULL) {
            if (fread(&(iaNew->data),sizeof(int),iaNew->len,f) == iaNew->len) {
               fclose(f);
               return iaNew;
            }
         }
      } 
   }
   fclose(f);
   return NULL;
}
