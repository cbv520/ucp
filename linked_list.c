/*
 * **********************************************************************
 * File          : linked_list.c
 * **********************************************************************
 * Project       : Turtle Graphics - UCP 2018 Semester 2 Assignment
 * Author        : Christopher Villegas - 18359884
 * File Created  : Wednesday, 12th September 2018 4:27:01 pm
 * Last Modified : Wednesday, 12th September 2018 8:44:03 pm
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : 
 * **********************************************************************
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"

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
{
   list->current = list->current->next;
   return list->current != NULL;
}

void deleteList(List* list)
{
   ListNode** current = &list->head;
   ListNode** next;
   while(*current != NULL)
   {
      next = &(*current)->next;
      /*free((*current)->value);*/
      free(*current);
      *current = *next;  
   }
   free(list);
}