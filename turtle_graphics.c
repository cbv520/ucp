/*
 * **********************************************************************
 * File          : turtle_graphics.c
 * **********************************************************************
 * Project       : Turtle Graphics - UCP 2018 Semester 2 Assignment
 * Author        : Christopher Villegas - 18359884
 * File Created  : Wednesday, 12th September 2018 4:31:07 pm
 * Last Modified : Friday, 14th September 2018 9:39:00 pm
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : Main method for the Turtle Graphics program
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
   List *list;
   if(!(list = (List*)malloc(sizeof(List))))
   {
      err = MALLOC_ERROR;
   }
   if(!err && argc != 2)
   {
      err = INVALID_ARGC;
   }
   if(!err)
   {
      err = readCommands(argv[1], list);
   }
   if(!err)
   {
      runCommands(list);
   }

   /* Error reporting */
   switch(err)
   {
      case FILE_NOT_FOUND:
         printf("File not found\n");
         break;
      case FILE_EMPTY:
         printf("File empty\n");
         break;
      case UNKNOWN_COMMAND:
         printf("Unkown command\n");
         break;
      case INVALID_NUMBER_OF_PARAMETERS:
         printf("Invalid number of command parameters\n");
         break;
      case INVALID_COMMAND_ARG: 
         printf("Invalid command argument\n");
         break;
      case INVALID_ARGC: 
         printf("Invalid number of command line arguments\n");
         break;
      case MALLOC_ERROR: 
         printf("Error allocating memory\n");
         break;
   }


   /* clean up */
   list->current = list->head;
   do
   {
      if(list->current)
      {
         free(((Command*)(list->current->value))->value);
      }
   }while(next(list));
   deleteList(list);

   return 0;
}