#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void concatenate(list_t* list, list_t* list2) {
   if (list == NULL) {
      
   }
}

void list_sort(list_t* list) {
   // base case:  0 or 1 node
   if (list->head == list->tail) {
      return;
   }

   // remove the head from intlist (pivot)
   int pivot = list->head->val;
   element_t* thepivot = list->head;
   list->head = list->head->next;

   // partition
   list_t* less = list_create();
   list_t* greater = list_create();
   element_t* current = list->head;
   element_t* next;
   while (current != NULL) {
      next = current->next;
      current->next = NULL;
      if (current->val <= pivot) {
         list_append(less, current->val);
      } 
      else {
         list_append(greater, current->val);
      }
      current = next;
   }
   printf("less is: \n");
   list->head = NULL;
   list->tail = NULL;

   //LLprint(first);
   //LLprint(second);

   list_sort(less);
   list_sort(greater);

    // join
   concatenate(list, less);
   /*if (less->head == NULL || list->head == NULL) {
      *list = *less;
   }
   if (list->head != NULL && less->head != NULL) {
      list->tail->next = less->head;
      list->tail = less->tail;
   }*/
   list_append(list, thepivot->val);
   concatenate(list, greater);
   /*if (list->head != NULL && greater->head != NULL) {
      list->tail->next = greater->head;
      list->tail = greater->tail;
   } */
   printf("\n");
}

void concatenate(list_t* list1, list_t* list2);
void list_sort(list_t* list);

int main () {
   
   list_t* list = list_create();
   list_append(list, 5);
   list_append(list, 4);
   list_append(list, 18);
   list_append(list, 14);
   list_append(list, 4);
   list_append(list, 15);
   list_append(list, 2);
   list_append(list, 7);
   element_t* current = list->head;
   printf("original list is: ");
   while (current != NULL) {
      printf("%d ", current->val);
      current = current->next;
   }
   printf("\n");
   list_sort(list);
   current = list->head;
   printf("new list is: ");
   list_print(list);

   printf("\n");
   return 0;  
}
