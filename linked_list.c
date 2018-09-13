/*
 * **********************************************************************
 * File          : linked_list.c
 * **********************************************************************
 * Project       : Turtle Graphics - UCP 2018 Semester 2 Assignment
 * Author        : Christopher Villegas - 18359884
 * File Created  : Wednesday, 12th September 2018 4:27:01 pm
 * Last Modified : Thursday, 13th September 2018 10:27:21 pm
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : 
 * **********************************************************************
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"
#include "error.h"

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

int next(List *list)
{
   list->current = list->current->next;
   return list->current != NULL;
}

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
