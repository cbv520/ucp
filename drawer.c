/*
 * **********************************************************************
 * File          : drawer.c
 * **********************************************************************
 * Project       : Turtle Graphics - UCP 2018 Semester 2 Assignment
 * Author        : Christopher Villegas - 18359884
 * File Created  : Wednesday, 12th September 2018 4:36:42 pm
 * Last Modified : Thursday, 13th September 2018 10:41:37 pm
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
#include <math.h>
#include "strings.h"

#define PI 3.14159265358979323846

void runCommands(List *commands)
{
   PlotData *data = (PlotData*)malloc(sizeof(PlotData));
   Command *cmd;

   /*initial values*/
   data->angle = 0.0;
   data->x = 0.0;
   data->y =  0.0;
   
   #ifdef SIMPLE
   data->bg =  7;
   data->fg = 0;
   #else
   data->bg =  0;
   data->fg = 7;
   #endif
   
   data->pattern = '+';
   
   clearScreen();
   
   do
   {
      cmd = (Command*)(commands->current->value);
      cmd->function(cmd->value, data);
   }
   while(next(commands));
   
   penDown();
   
   free(data);
}

void move(void *value, PlotData *data)
{
   double x2 = data->x + *(double*)value*cos(data->angle * PI / 180.0);
   double y2 = data->y + *(double*)value*sin(data->angle * PI / 180.0);
   char msg[50];
   
   sprintf(msg, "MOVE (%8.3f,%8.3f)-(%8.3f,%8.3f)", 
           data->x, data->y, x2, y2);
   logMsg(msg);

   data->x = x2;
   data->y = y2;
}

void draw(void *value, PlotData *data)
{
   double x2 = data->x + *(double*)value*cos(data->angle * PI / 180.0);
   double y2 = data->y + *(double*)value*sin(data->angle * PI / 180.0);
   char msg[50];

   line(data->x, data->y, x2, y2, plotter, data);

   sprintf(msg, "DRAW (%8.3f,%8.3f)-(%8.3f,%8.3f)", 
           data->x, data->y, x2, y2);
   logMsg(msg);

   data->x = x2;
   data->y = y2;
}

void rotate(void *value, PlotData *data)
{
   data->angle += -*(double*)value;
}

void fg(void *value, PlotData *data)
{
   #ifndef SIMPLE
   data->fg = *(int*)value;
   #endif
}
void bg(void *value, PlotData *data)
{
   #ifndef SIMPLE
   data->bg = *(int*)value;
   #endif
}

void pattern(void *value, PlotData *data)
{
   data->pattern = *(char*)value;
}

void plotter(void *plotData)
{
   setFgColour(((PlotData*)plotData)->fg);
   setBgColour(((PlotData*)plotData)->bg);
   printf("%c", ((PlotData*)plotData)->pattern);
}

CmdFunction getCommand(char *cmd)
{
   CmdFunction func;

   uppercase(cmd);

   if(!strcmp(cmd, "ROTATE"))
   {
      func = rotate;
   }
   else if(!strcmp(cmd, "MOVE"))
   {
      func = move;
   }
   else if(!strcmp(cmd, "DRAW"))
   {
      func = draw;
   }
   else if(!strcmp(cmd, "FG"))
   {
      func = fg;
   }
   else if(!strcmp(cmd, "BG"))
   {
      func = bg;
   }
   else if(!strcmp(cmd, "PATTERN"))
   {
      func = pattern;
   }
   else
   {
      func = NULL;
   }
   return func;
}

void* getValue(char *cmd_str, char *val_str)
{
   void *val;

   if(!strcmp(cmd_str, "ROTATE") && isDouble(val_str))
   {
      if((val = (double*)malloc(sizeof(double))))
      {
         *(double*)val = atof(val_str);
      }
   }
   else if((!strcmp(cmd_str, "MOVE") || !strcmp(cmd_str, "DRAW")) && 
            isDouble(val_str))
   {
      if((val = (double*)malloc(sizeof(double))))
      {
         *(double*)val = atof(val_str);
      }
   }
   else if((!strcmp(cmd_str, "FG") || !strcmp(cmd_str, "BG")) && 
            isInt(val_str))
   {
      if((val = (int*)malloc(sizeof(int))))
      {
         *(int*)val = atoi(val_str);
      }
   }
   else if(!strcmp(cmd_str, "PATTERN") && !isWhitespace(*val_str))
   {
      if((val = (char*)malloc(sizeof(char))))
      {
         *(char*)val = *val_str;
      }
   }
   else
   {
      val = NULL;
   }
   return val;
}