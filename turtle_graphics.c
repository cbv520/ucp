/*
 * **********************************************************************
 * File          : turtle_graphics.c
 * **********************************************************************
 * Project       : Turtle Graphics - UCP 2018 Semester 2 Assignment
 * Author        : Christopher Villegas - 18359884
 * File Created  : Wednesday, 12th September 2018 4:31:07 pm
 * Last Modified : Thursday, 13th September 2018 11:08:39 pm
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : 
 * **********************************************************************
 */


#include <stdio.h>
#include <stdlib.h>
#include "drawer.h"
#include "linked_list.h"
#include "file_io.h"
#include "error.h"
#include "effects.h"

int main(int argc, char **argv)
{
   int err = SUCCESS;
   List *list = (List*)malloc(sizeof(List));
   if(argc != 2)
   {
      err = INVALID_ARGC;
   }
   if(!err)
   {
      err = readCommands(argv[1], list);
   }
   switch(err)
   {
      case FILE_NOT_FOUND:
         printf("file not found\n");
         break;
      case FILE_EMPTY:
         printf("file empty\n");
         break;
      case UNKNOWN_COMMAND:
         printf("unkown command\n");
         break;
      case INVALID_NUMBER_OF_PARAMETERS:
         printf("invalid number of command parameters\n");
         break;
      case INVALID_PARAMETER_TYPE: 
         printf("invalid command parameter type\n");
         break;
      case INVALID_ARGC: 
         printf("invalid number of command line args\n");
         break;
   }
   if(!err)
   {
      runCommands(list);
   }
   list->current = list->head;
   do
   {
      free(((Command*)(list->current->value))->value);
   }while(next(list));
   deleteList(list);

   return 0;
}