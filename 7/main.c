#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main( int argc, char* argv[] ) {

   //test list_create
   int test;
   list_t* list = list_create();
   //check to see if the create function did everything it was supposed to
   if ( list == NULL ) {
       printf( "create: failed to malloc\n" );
       return 1;
   }
   if ( list->head != NULL || list->tail != NULL) {
      printf( "create: head or tail is not NULL\n" );
      return 1;
   }
   //now test all the other functions (except list_print) to see if they do what they are supposed to

   //test element_create
   element_t* element1 = element_create(1);
   if ( element1 == NULL || element1->val != 1 || element1->next != NULL) {
      printf( "element: failed to set correctly\n" );
      return 1;
   }
   free(element1);
   printf("flag 1\n");

   //test list_append
   test = list_append(list, 1);
   if (test == 0) {
      if (list->head == NULL || list->head->val != 1) {
         printf( "append: empty list border case, failed to correctly set new head\n" );
         return 1; 
      }
      test = list_append(list, 2);
      if (test == 0) {
         test = list_append(list, 3);
         if (test == 0) {
            if (list->head == NULL || list->head->next == NULL || list->head->next->next == NULL || list->head->val != 1 || list->head->next->val != 2 || list->head->next->next->val != 3) {
               printf( "append: linked list not correctly set\n" );
               return 1;
            }      
         }
         else {
            printf("append: returned 1, failed to malloc\n");
            return 1;
         }
      }
      else {
         printf("append: returned 1, failed to malloc\n");
         return 1;
      }
   }
   else {
      printf("append: returned 1, failed to malloc\n");
      return 1;
   }
   if (list->tail == NULL || list->tail->val != 3) {
      printf("append: tail not correctly set\n");
      return 1;   
   }
   printf("flag 2\n");
   //test list_destroy
   list_t* copylist = list;
   element_t* center = copylist->head->next;
   list_destroy(list);
   if (copylist->head->val == 1 || copylist->tail->val == 3 || center->val == 2 ) {
       printf( "destroy: destroy failed to free all elements\n" );
       return 1;      
   }
   printf("flag 3\n");

   //test list_prepend
   list = list_create();
   test = list_prepend(list, 3);
   if (test == 0) {
      if (list->head->val != 3) {
         printf( "prepend: empty list border case, failed to correctly set new head\n" );
         return 1; 
      }
      test = list_prepend(list, 2);
      if (test == 0) {
         test = list_prepend(list, 1);
         if (test == 0) {
            if (list->head == NULL || list->head->next == NULL || list->head->next->next == NULL || list->head->val != 1 || list->head->next->val != 2 || list->head->next->next->val != 3) {
               printf( "prepend: tail not correctly set\n" );
               return 1;
            }      
         }
         else {
            printf("prepend: returned 1, failed to malloc\n");
            return 1;
         }
      }
      else {
         printf("prepend: returned 1, failed to malloc\n");
         return 1;
      }
   }
   else {
      printf("prepend: returned 1, failed to malloc\n");
      return 1;
   }
   if (list->tail == NULL || list->tail->val != 3) {
      printf("prepend: tail not correctly set\n");
      return 1;   
   }
   printf("flag 4\n");
   list_destroy(list);

   //test list_index
   list = list_create();
   element_t* elementatindexempty = list_index(list,3);
   if (elementatindexempty != NULL) {
      printf( "index: empty list border case failed to return NULL\n" );
      return 1;
   }
   list_append(list, 2);
   list_append(list, 3);
   list_prepend(list, 1);
   element_t* elementatindex0 = list_index(list,0);
   if (elementatindex0 == NULL || list->head == NULL || elementatindex0->val != 1) {
      printf( "index: failed to return correct value at specified index\n" );
      return 1;        
   }
   element_t* elementatindex1 = list_index(list,1);
   if (elementatindex1 == NULL || list->head->next == NULL || elementatindex1->val != 2) {
      printf( "index: failed to return correct value at specified index\n" );
      return 1;    
   }
   element_t* elementatindex2 = list_index(list,2);
   if (elementatindex2 == NULL || list->head->next->next == NULL || elementatindex2->val != 3) {
      printf( "index: failed to return correct value at specified index\n" );
      return 1;    
   }
   element_t* elementatindex3 = list_index(list,3);
   if (elementatindex3 != NULL) {
      printf( "index: invalid index border case failed to return NULL\n" );
      return 1;  
   }
   printf("flag 5\n");

   printf( "all tests passed\n");
   return 0; // tests pass
}
