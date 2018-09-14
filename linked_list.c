/*
 * **********************************************************************
 * File          : linked_list.c
 * **********************************************************************
 * Project       : Turtle Graphics - UCP 2018 Semester 2 Assignment
 * Author        : Christopher Villegas - 18359884
 * File Created  : Wednesday, 12th September 2018 4:27:01 pm
 * Last Modified : Friday, 14th September 2018 8:52:07 pm
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : Generic singly linked list with convenience methods
 *                 for iteration and cleanup.
 * **********************************************************************
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"
#include "error.h"

/**
 * @brief Append a node to the end of the list. If the list is empty, the 
 * list is initialised, otherwise an new node is linked to the tail node
 * and the tail pointer is updated.
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
{
   list->current = list->current->next;
   return list->current != NULL;
}

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
      free(*current);
      *current = *next;  
   }
   free(list);
   list = NULL;
}
