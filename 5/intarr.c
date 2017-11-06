#include <stdio.h>

typedef struct {
   int* data;
   unsigned int len;
} intarr_t;

typedef enum {
  INTARR_OK,
  INTARR_BADARRAY,
  INTARR_BADINDEX,
  INTARR_BADALLOC,
  INTARR_NOTFOUND
} intarr_result_t;

/* LAB 5 TASK 1 */

// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.
intarr_t* intarr_create( unsigned int len ) {
   intarr_t* ptr = malloc(sizeof(intarr_t)*len);
   if (ptr != NULL) {
      return ptr;
   }
   return NULL;
}

// frees all memory allocated for ia. If the pointer is null, do
// nothing. If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia ) {
   if (ia != NULL) {
      free(ia);
   }
   return;
}

