/*
 * **********************************************************************
 * File          : file_io.c
 * **********************************************************************
 * Project       : Turtle Graphics - UCP 2018 Semester 2 Assignment
 * Author        : Christopher Villegas - 18359884
 * File Created  : Wednesday, 12th September 2018 4:29:57 pm
 * Last Modified : Thursday, 13th September 2018 11:08:52 pm
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : 
 * **********************************************************************
 */


#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "drawer.h"
#include "error.h"

int readCommands(char *filename, List *list)
{
   Command *cmd;
   char buffer[50];
   int err = SUCCESS;
   FILE *file = fopen(filename, "r");
   if(!file)
   {
      err = FILE_NOT_FOUND;
   }
   else
   {
      while(fgets(buffer, sizeof(buffer), file)) 
      {
         char func_str[20];
         char value_str[20];
         if(sscanf(buffer, "%s %s", func_str, value_str) < 2)
         {
            err = INVALID_NUMBER_OF_PARAMETERS;
         }
         if(!err && !(cmd = (Command*)malloc(sizeof(Command))))
         {
            err = MALLOC_ERROR;
         }
         if(!err)
         {
            err = insert(list, cmd);
         }
         if(!err && !(cmd->function = getCommand(func_str)))
         {
            err = UNKNOWN_COMMAND;
         }
         if(!err && !(cmd->value = getValue(func_str, value_str)))
         {
            err = INVALID_PARAMETER_TYPE;
         }
      }
      if(!err && !list->head)
      {
         err = FILE_EMPTY;
      }
   }
   return err;
}

void logMsg(char *msg)
{
   static int open = 0;
	FILE *file = fopen("log.txt", "a");
   if(!open)
   {
      fprintf(file, "------\n");
    	open = 1;
	}
   fprintf(file, "%s\n", msg);
   
   #ifdef DEBUG
   printf("%s\n", msg);
   #endif

   fclose(file);
}













