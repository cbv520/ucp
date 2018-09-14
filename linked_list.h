/*
 * **********************************************************************
 * File          : linked_list.h
 * **********************************************************************
 * Project       : Turtle Graphics - UCP 2018 Semester 2 Assignment
 * Author        : Christopher Villegas - 18359884
 * File Created  : Wednesday, 12th September 2018 4:27:53 pm
<<<<<<< HEAD
 * Last Modified : Friday, 14th September 2018 7:20:14 pm
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : Generic singly linked list with convenience methods
 *                 for iteration and cleanup.
=======
 * Last Modified : Wednesday, 12th September 2018 8:14:11 pm
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : 
>>>>>>> 80110704ca04716407bccfdd6e465453db9d5645
 * **********************************************************************
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

<<<<<<< HEAD
/**
 * @brief individual node of a singly linked list. 
 * 
 * value - pointer to the value being stored in this node
 *         void pointer allows any varuable type to be stored
 * next - pointer to the next node in the list
 */
typedef struct ListNode
{
   void *value;
   struct ListNode *next;
} ListNode;

/**
 * @brief Wrapper struct storing the head, tail, and current node of a list
 * allowing for easier management of the list
 * 
 * head - first node in the list
 * tail - last node in the list, allows for inserting into the list without
 *        having to iteration from the beginning each time
 * current - Used when iterating over the list, pointing to the current node.
 *           Before each time iterating over the list, this pointer must 
 *           point to the same node as head to begin iterating from the 
 *           beginning.
 */
typedef struct List
{
   ListNode *head;
   ListNode *tail;
   ListNode *current;
} List;

int insert(List *list, void *value);
int next(List *list);
void deleteList(List *list);
=======
typedef struct ListNode
{
   void* value;
   struct ListNode* next;
} ListNode;

typedef struct List
{
   ListNode* head;
   ListNode* tail;
   ListNode* current;
} List;

void insert(List* list, void* value);
int next(List* list);
void deleteList(List* list);
>>>>>>> 80110704ca04716407bccfdd6e465453db9d5645

#endif