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
   if (pa != NULL) {
      pa->points = realloc(pa->points,sizeof(point_t)*(pa->len+1));
      if (pa->points != NULL) {
         pa->points[pa->len].x = p->x;
         pa->points[pa->len].y = p->y;
         pa->points[pa->len].z = p->z;
         pa->len = pa->len+1;
         return 0;
      }
   }
   return 1;
}

// Remove the point at index i from the array, reducing the size of
// the array by one. The order of points in the array may change.
int point_array_remove( point_array_t* pa, unsigned int i ) {
   if (pa != NULL && pa->points != NULL && i < pa->len) {
      pa->points[i].x = pa->points[pa->len-1].x;
      pa->points[i].y = pa->points[pa->len-1].y;
      pa->points[i].z = pa->points[pa->len-1].z;
      if (pa->len > 0) { 
         pa->len = pa->len-1;
         pa->points = realloc(pa->points,sizeof(point_t)*(pa->len));
         if (pa->points != NULL) {
            return 0;
         }
      }
   }
   return 1;
}
/*
void point_array_init( point_array_t* pa );
int point_array_append( point_array_t* pa, point_t* p );

int main() {
   point_array_t* pa;
   //point_array_init(pa);
   point_t* p;
   p->x = 1;
   p->y = 1;
   p->z = 1;
   printf("point p is: x:%g y:%g z:%g \n", p->x, p->y, p->z);
   point_array_append(pa,p);
   printf("point p is: x:%g y:%g z:%g \n", pa->points[0].x, pa->points[0].y, pa->points[0].z);
   return 0;
}
*/
