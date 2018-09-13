/*
 * **********************************************************************
 * File          : drawer.c
 * **********************************************************************
 * Project       : Turtle Graphics - UCP 2018 Semester 2 Assignment
 * Author        : Christopher Villegas - 18359884
 * File Created  : Wednesday, 12th September 2018 4:36:42 pm
 * Last Modified : Thursday, 13th September 2018 3:52:19 am
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : 
 * **********************************************************************
 */


#include "drawer.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "file_io.h"
#include "error.h"
#include "effects.h"
#include "logger.h"
#include <math.h>

int main(int argc, char** argv)
{
   int err = SUCCESS;
   List* list = (List*)malloc(sizeof(List));
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
      case SUCCESS:
         printf("success\n");
         break;
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

   return 0;
}

void runCommands(List* commands)
{
   Properties *props = (Properties*)malloc(sizeof(Properties));
   *props = (Properties){
      0.0,
      0.0,
      0.0,
      0,
      7,
      '+'
   };
   Command* cmd;
   clearScreen();
   do
   {
      cmd = (Command*)(commands->current->value);
      cmd->function(cmd->value, props);
   }
   while(next(commands));
}

CmdFunction getCommand(char* cmd)
{
   CmdFunction func;
   if(!strcmp(cmd, "rotate"))
   {
      func = rotate;
   }
   else if(!strcmp(cmd, "move"))
   {
      func = move;
   }
   else if(!strcmp(cmd, "draw"))
   {
      func = draw;
   }
   else if(!strcmp(cmd, "fg"))
   {
      func = fg;
   }
   else if(!strcmp(cmd, "bg"))
   {
      func = bg;
   }
   else if(!strcmp(cmd, "pattern"))
   {
      func = pattern;
   }
   else
   {
      func = NULL;
   }
   return func;
}

void* getValue(char* cmd_str, char* val_str)
{
   void* val;
   int *i;
   double *d;
   char *c;
   if(!strcmp(cmd_str, "rotate"))
   {
      d = (double*)malloc(sizeof(double));
      *d = atof(val_str);
      val = d;
   }
   else if(!strcmp(cmd_str, "move") || !strcmp(cmd_str, "draw"))
   {
      d = (double*)malloc(sizeof(double));
      *d = atof(val_str);
      val = d;
   }
   else if(!strcmp(cmd_str, "fg") || !strcmp(cmd_str, "bg"))
   {
      i = (int*)malloc(sizeof(int));
      *i = atoi(val_str);
      val = i;
   }
   else if(!strcmp(cmd_str, "pattern"))
   {
      c = (char*)malloc(sizeof(char));
      *c = *val_str;
      val = c;
   }
   else
   {
      val = NULL;
   }
   return val;
}

int rotate(void* value, Properties* props)
{
   props->angle += *(double*)value;
   return 0;
}

int move(void* value, Properties* props)
{
   double x2 = props->x + *(double*)value*cos(props->angle * M_PI / 180.0);
   double y2 = props->y + *(double*)value*sin(props->angle * M_PI / 180.0);

   //logMove(props->x, x2, props->y, y2);

   props->x = x2;
   props->y = y2;
   return 0;
}

int draw(void* value, Properties* props)
{
   double x2 = props->x + *(double*)value*cos(props->angle * M_PI / 180.0);
   double y2 = props->y + *(double*)value*sin(props->angle * M_PI / 180.0);

   //logDraw(props->x, x2, props->y, y2);
   line(props->x, props->y, y2, x2, plotter, &props->pattern);

   props->x = x2;
   props->y = y2;
   return 0;
}

int fg(void* value, Properties* props)
{
   props->fg = *(int*)value;
   setFgColour(*(char*)value);
   return 0;
}
int bg(void* value, Properties* props)
{
   props->bg = *(int*)value;
   setBgColour(*(char*)value);
   return 0;
}
int pattern(void* value, Properties* props)
{
   props->pattern = *(char*)value;
   return 0;
}

void plotter(void *plotData)
{
   char x = *(char*)plotData;
   printf("%c", x);
}