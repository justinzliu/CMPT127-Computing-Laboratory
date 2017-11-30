#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void concatenate(list_t* list, list_t* list2) {
   if (list2->head != NULL) {
      if (list->head != NULL) {
         list->tail->next = list2->head;
         list->tail = list2->tail;
      }
      else {
         list->head = list2->head;
         list->tail = list2->tail; 
      }
   } 
}

void concatenate(list_t* list1, list_t* list2);

void list_sort(list_t* list) {
   if (list->head == list->tail) {
      return;
   }
   element_t* thepivot = list->head;
   int pivot = list->head->val;
   list->head = list->head->next;
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
   list->head = NULL;
   list->tail = NULL;
   list_sort(less);
   list_sort(greater);
   concatenate(list, less);
   list_append(list, thepivot->val);
   concatenate(list, greater);
}


