#include <stdio.h>
#include <stdlib.h>

/* Implements a linked list of integers

 A list is comprised of a single header and zero or more elements. The
 header contains pointers to the first and last elements in the list,
 or NULL if the list is empty. The first element contains a pointer to
 the next element, and so on. The last element in the list has its
 "next" pointer set to NULL.

 ** Global Precondition **

 Functions that operate on an existing list require a valid pointer to
 a list_t header as their first argument. 
*/

#include "list.h"

list_t* list_create( void ) {
   list_t* l = malloc( sizeof(list_t) );
   if( l != NULL) {
      l->head = NULL;
      l->tail = NULL;
   }
   return l;
}

void list_destroy( list_t* list ) {
   if (list != NULL) {
      if (list->head != NULL) {
         element_t* current = list->head;
         while( current != NULL ) {
            element_t* freeme = current;
            current = current->next;
            free( freeme );
         }
      }
   }      
   free( list );
}

element_t* element_create( int i ) {
   element_t* el = malloc( sizeof(element_t) );
   if( el != NULL) {
      el->val = i;
      el->next = NULL;
   }
   return el;
}

int list_append( list_t* list, int i ) {
   element_t* el = element_create( i );
   if( el != NULL ) {
      //empty list
      if ( list->head == NULL ) {
         list->head = el; 
      } 
      //non-empty list
      else {
         list->tail->next = el;
      }
      list->tail = el;
      return 0;
   }
   return 1;
}

int list_prepend( list_t* list, int i ) {
   element_t* el = element_create( i );
   if( el != NULL ) {
      //empty list
      if( list->head == NULL ) {
         list->tail = el;
      }
      //non-empty list
      else {
         el->next = list->head;
      }
      list->head = el;
      return 0;
  }
  return 1;
}

element_t* list_index( list_t* list, unsigned int i ) {
   element_t* target = list->head;
   unsigned int j = 0;
   while (j < i) {
      if (target == NULL) {
         return NULL;
      }
      target = target->next;
      j++;
   }     
  return target;
}


void list_print( list_t* list ) {
  printf( "{" );
  
  for( element_t* el = list->head;
       el;
       el = el->next )
    printf( " %d", el->val );

  printf( " }\n" );
}
