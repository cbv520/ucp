/*
 * **********************************************************************
 * File          : linked_list.c
 * **********************************************************************
 * Project       : Turtle Graphics - UCP 2018 Semester 2 Assignment
 * Author        : Christopher Villegas - 18359884
 * File Created  : Wednesday, 12th September 2018 4:27:01 pm
<<<<<<< HEAD
 * Last Modified : Friday, 14th September 2018 7:33:51 pm
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : Generic singly linked list with convenience methods
 *                 for iteration and cleanup.
=======
 * Last Modified : Wednesday, 12th September 2018 8:44:03 pm
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : 
>>>>>>> 80110704ca04716407bccfdd6e465453db9d5645
 * **********************************************************************
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"
<<<<<<< HEAD
#include "error.h"

/**
 * @brief Append a node to the end of the list
 * 
 * @param list List to append node to
 * @param value pointer to the value being stored at this node
 * @return int Error code stating the success of insertion
 * possible codes returned:
 * SUCCESS - 0
 * MALLOC_ERROR - 7
 */
int insert(List *list, void *value)
{
   ListNode *node;
   int err = SUCCESS;

   if(!(node = (ListNode*)malloc(sizeof(ListNode))))
   {
      err = MALLOC_ERROR;
   }
   else
   {
      node->value = value;
      node->next = NULL;
      if(list->head == NULL)
      {
         list->head = node;
         list->tail = list->head;
         list->current = list->head;
      }
      else
      {
         list->tail->next = node;
         list->tail = node;
      }
   }
   return err;
}

/**
 * @brief Increments the current pointer of the list to point to the next
 * node
 * 
 * @param list list being iterated 
 * @return int returns 0 if end of list has been reached 
 */
int next(List *list)
=======

/*int main(void)
{
   int a=1,b=2,c=3,d=4,e=5;
   List* list = (List*)malloc(sizeof(List));
   insert(list, &a);
   insert(list, &b);
   insert(list, &c);
   insert(list, &d);
   insert(list, &e);

   do
   {
      printf("%d\n",*(int*)list->current->value);
   }while(next(list));

   deleteList(list);
   printf("%f\n", atof("p"));
   printf("%d\n", atoi("p"));

   return 0;
}*/

void insert(List* list, void* value)
{
   ListNode* node = (ListNode*)malloc(sizeof(ListNode));
   
   node->value = value;
   node->next = NULL;
   if(list->head == NULL)
   {
      list->head = node;
      list->tail = list->head;
      list->current = list->head;
   }
   else
   {
      list->tail->next = node;
      list->tail = node;
   }
}

int next(List* list)
>>>>>>> 80110704ca04716407bccfdd6e465453db9d5645
{
   list->current = list->current->next;
   return list->current != NULL;
}

<<<<<<< HEAD
/**
 * @brief Free the memory used by the list, including the value. If the value
 * of a node points to other memory, that memory must be freed before calling
 * this function 
 * 
 * @param list List to be deleted
 */
void deleteList(List *list)
{
   ListNode **current = &list->head;
   ListNode **next;
   while(*current != NULL)
   {
      next = &(*current)->next;
      free((*current)->value);
      (*current)->value = NULL;
=======
void deleteList(List* list)
{
   ListNode** current = &list->head;
   ListNode** next;
   while(*current != NULL)
   {
      next = &(*current)->next;
      /*free((*current)->value);*/
>>>>>>> 80110704ca04716407bccfdd6e465453db9d5645
      free(*current);
      *current = *next;  
   }
   free(list);
<<<<<<< HEAD
   list = NULL;
}
=======
}
>>>>>>> 80110704ca04716407bccfdd6e465453db9d5645
