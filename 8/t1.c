#include <stdio.h>
#include "point_array.h"

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa ) {
   if (pa != NULL) {
      pa->points = NULL;
      pa->len = 0;
      pa->reserved = 0;
   }
   return;
}

// Resets the array to be empty, freeing any memory allocated if
// necessary.
void point_array_reset( point_array_t* pa ) {
   if (pa != NULL && pa->points != NULL) {
      free(pa->points);
      pa->len = 0;
      pa->points = NULL;
   }
   return;
}

// Append a point to the end of an array. If successful, return 0,
// else return 1;
int point_array_append( point_array_t* pa, point_t* p ) {
   if (pa != NULL && p != NULL) {
      pa->points = realloc(pa->points,sizeof(point_t)*(pa->len+1));
      if (pa->points != NULL) {
         pa->points[pa->len] = *p;
         pa->len = pa->len+1;
         return 0;
      }
   }
   return 1;
}

// Remove the point at index i from the array, reducing the size of
// the array by one. The order of points in the array may change.
int point_array_remove( point_array_t* pa, unsigned int i ) {
   if (pa != NULL && pa->points != NULL && i < pa->len && pa->len > 0) {
      pa->points[i] = pa->points[pa->len-1];
      pa->len = pa->len-1;
      return 0;
   }
   return 1;
}
