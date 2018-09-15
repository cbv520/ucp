/*
 * **********************************************************************
 * File          : file_io.c
 * **********************************************************************
 * Project       : Turtle Graphics - UCP 2018 Semester 2 Assignment
 * Author        : Christopher Villegas - 18359884
 * File Created  : Wednesday, 12th September 2018 4:29:57 pm
 * Last Modified : Friday, 14th September 2018 11:11:42 pm
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : Methods for file and stream I/O.
 * **********************************************************************
 */


#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "drawer.h"
#include "error.h"

/**
 * @brief Reads in a file containing turtle graphics commands and converts
 * them into Command structs. Commands are stored in a list to be executed
 * by the drawer.
 * 
 * @param filename name of file containing turtle graphics commands
 * @param list Exported list of commands
 * @return int Error code descirbing the success of reading the file.
 * possible codes returned:
 * SUCCESS - 0
 * FILE_NOT_FOUND - 1
 * FILE_EMPTY - 2 
 * UNKNOWN_COMMAND - 3
 * INVALID_NUMBER_OF_PARAMETERS - 4
 * INVALID_COMMAND_ARG - 5
 * MALLOC_ERROR - 7
 */
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
         if(!(cmd = (Command*)malloc(sizeof(Command))))
         {
            err = MALLOC_ERROR;
         }
         if(!err)
         {
            err = insert(list, cmd);
         }
         if(!err && sscanf(buffer, "%s %s", func_str, value_str) < 2)
         {
            err = INVALID_NUMBER_OF_PARAMETERS;
         }
         if(!err && !(cmd->function = getCommand(func_str)))
         {
            err = UNKNOWN_COMMAND;
         }
         if(!err)
         {  
            err = getValue(func_str, value_str, &cmd->value);
         }
      }
      if(!err && !list->head)
      {
         err = FILE_EMPTY;
      }
   }
   return err;
}

/**
 * @brief Appends a message to the log file log.txt. Each program execution
 * is seperated by ------
 * 
 * @param msg message to be logged
 */
void logMsg(char *msg)
{
   static int open = 0;
	FILE *file = fopen("log.txt", "a");
   if(file)
   {
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
}













