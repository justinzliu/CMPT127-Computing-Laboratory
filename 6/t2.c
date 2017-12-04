#include <stdio.h>
#include <stdlib.h>
#include "intarr.h"

/* LAB 6 TASK 2 */

/*
  Save the entire array ia into a file called 'filename' in a JSON
  text file array file format that can be loaded by
  intarr_load_json(). Returns zero on success, or a non-zero error
  code on failure. Arrays of length 0 should produce an output file
  containing an empty array.
  
  The JSON output should be human-readable.

  Examples:

  The following line is a valid JSON array:
  [ 100, 200, 300 ]
  
  The following lines are a valid JSON array:
  [ 
   100, 
   200, 
   300 
  ]
*/

int intarr_save_json( intarr_t* ia, const char* filename ) {
   if (ia != NULL && filename != NULL && ia->data != NULL) {
      FILE* f = fopen(filename, "w");
      if (f != NULL) {
         if (ia->len > 0) {
            fprintf(f, "[ ");
            for (int i=0; i<ia->len-1; i++) {
               fprintf(f, "%d, ", ia->data[i]);
            }
            fprintf(f, "%d", ia->data[ia->len-1]);
            fprintf(f, " ]");
            fclose(f);
            return 0;
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

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save(). The file may contain an array
  of length 0. Returns a pointer to a newly-allocated intarr_t on
  success (even if that array has length 0), or NULL on failure.
*/
intarr_t* intarr_load_json( const char* filename ) {
   if (filename != NULL) {
      FILE* f = fopen(filename,"r");
      if (f != NULL) {
         intarr_t* ia = malloc(sizeof(intarr_t));
         if (ia != NULL) {
            unsigned int len = 0;
            int num;
            while(fscanf(f,"%*c %d", &num) == 1) {
               len++;
            }
            fseek(f,0,SEEK_SET);
            ia->len = len;
            ia->data = malloc(sizeof(int)*ia->len);
            if (ia->data != NULL) {
               for (int i=0; i<ia->len; i++) {
                  fscanf(f,"%*c %d", &ia->data[i]);
               }
               fclose(f);
               return ia;
            }
         }
      fclose(f); 
      }
   }
   return NULL;
}
