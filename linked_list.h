/*
 * **********************************************************************
 * File          : linked_list.h
 * **********************************************************************
 * Project       : Turtle Graphics - UCP 2018 Semester 2 Assignment
 * Author        : Christopher Villegas - 18359884
 * File Created  : Wednesday, 12th September 2018 4:27:53 pm
 * Last Modified : Thursday, 13th September 2018 10:27:30 pm
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : 
 * **********************************************************************
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct ListNode
{
   void *value;
   struct ListNode *next;
} ListNode;

typedef struct List
{
   ListNode *head;
   ListNode *tail;
   ListNode *current;
} List;

int insert(List *list, void *value);
int next(List *list);
void deleteList(List *list);

#endif