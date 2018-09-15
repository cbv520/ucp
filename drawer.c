/*
 * **********************************************************************
 * File          : drawer.c
 * **********************************************************************
 * Project       : Turtle Graphics - UCP 2018 Semester 2 Assignment
 * Author        : Christopher Villegas - 18359884
 * File Created  : Wednesday, 12th September 2018 4:36:42 pm
 * Last Modified : Friday, 14th September 2018 11:05:26 pm
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : Methods related to the commands run by turtle graphics
 * **********************************************************************
 */


#include "drawer.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "linked_list.h"
#include "file_io.h"
#include "error.h"
#include "effects.h"
#include "strings.h"

#define PI 3.14159265358979323846

/**
 * @brief Runs the list of CmdFunctions stored in a list.
 * 
 * @param commands List of commands
 */
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
   
   commands->current = commands->head;
   do
   {
      cmd = (Command*)(commands->current->value);
      cmd->function(cmd->value, data);
   }
   while(next(commands));
   
   penDown();
   
   free(data);
}

/**
 * @brief Move the cursor in the direction of the current facing angle.
 * Calls to this function are logged in the log file log.txt.
 * 
 * @param value Distance for cursor to move
 * @param data Current values being used by the plotter
 */
void move(void *value, PlotData *data)
{
   char msg[50];
   double x2 = data->x + *(double*)value*cos(data->angle * PI / 180.0);
   double y2 = data->y + *(double*)value*sin(data->angle * PI / 180.0);
   
   sprintf(msg, "MOVE (%8.3f,%8.3f)-(%8.3f,%8.3f)", 
           data->x, data->y, x2, y2);
   logMsg(msg);

   data->x = x2;
   data->y = y2;
}

/**
 * @brief Draw a line in the direction of the current facing angle.
 * Calls to this function are logged in the log file log.txt.
 * 
 * @param value Distance for cursor to move
 * @param data Current values being used by the plotter
 */
void draw(void *value, PlotData *data)
{
   char msg[50];
   double x2 = data->x + *(double*)value*cos(data->angle * PI / 180.0);
   double y2 = data->y + *(double*)value*sin(data->angle * PI / 180.0);

   line(data->x, data->y, x2, y2, plotter, data);

   sprintf(msg, "DRAW (%8.3f,%8.3f)-(%8.3f,%8.3f)", 
           data->x, data->y, x2, y2);
   logMsg(msg);

   data->x = x2;
   data->y = y2;
}

/**
 * @brief Update the angle the cursor is currently facing
 * 
 * @param value Angle to turn in relation to current angle
 * @param data Current values being used by the plotter
 */
void rotate(void *value, PlotData *data)
{
   data->angle += -*(double*)value;
}

/**
 * @brief Change the color of the foreground used by the plotter
 * values range from 0 to 7
 * 0 - black
 * 1 - red
 * 2 - green
 * 3 - yellow
 * 4 - blue
 * 5 - purple
 * 6 - light blue
 * 7 - white
 * 
 * @param value Color of the foreground
 * @param data Current values being used by the plotter
 */
void fg(void *value, PlotData *data)
{
   #ifndef SIMPLE
   data->fg = *(int*)value;
   #endif
}

/**
 * @brief Change the color of the background used by the plotter
 * values range from 0 to 7
 * 0 - black
 * 1 - red
 * 2 - green
 * 3 - yellow
 * 4 - blue
 * 5 - purple
 * 6 - light blue
 * 7 - white
 * 
 * @param value Color of the background
 * @param data Current values being used by the plotter
 */
void bg(void *value, PlotData *data)
{
   #ifndef SIMPLE
   data->bg = *(int*)value;
   #endif
}

/**
 * @brief Sets the character being printed when plotting each pixel of
 * a line
 * 
 * @param value Character to be printed. Must not be whitespace 
 * @param data Current values being used by the plotter
 */
void pattern(void *value, PlotData *data)
{
   data->pattern = *(char*)value;
}

/**
 * @brief Plotting function used plotting each pixel, applying the 
 * foreground, background and pattern settings set in the PlotData struct
 * 
 * @param plotData PlotData struct containing values being used by the 
 * plotter
 */
void plotter(void *plotData)
{
   setFgColour(((PlotData*)plotData)->fg);
   setBgColour(((PlotData*)plotData)->bg);
   printf("%c", ((PlotData*)plotData)->pattern);
}

/**
 * @brief Get the Command function by name. Case insensitive.
 * Available Commands:
 * ROTATE - change angle relative to current angle
 * MOVE - move in the direction currently facing
 * DRAW - draw a line from the current position in the direction 
 *        currently facing
 * FG - foreground color of the pixel(s) being drawn
 * BG - background color of the pixel(s) being drawn
 * PATTERN - character printed when plotting a pixel
 * 
 * @param cmd String representing the name of the command.
 * @return CmdFunction Pointer to the command function. Returns NULL if
 * the command isnt found
 */
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

/**
 * @brief Get the value associated with a command
 * Valid values for each command:
 * ROTATE - real number between -360 and 360
 * MOVE - real number
 * DRAW - real number
 * FG - integer between 0 and 7
 * BG - integer between 0 and 7
 * PATTERN - non-whitespace character
 * 
 * @param cmd_str name of the command
 * @param val_str value represented as a string
 * @param val_ptr pointer to the void pointer storing the command's value.
 * void** used since this is where the value's void pointer is initialised.
 * @return int Error code stating the success parsing the argument
 * possible codes:
 * SUCCESS - 0
 * INVALID_COMMAND_ARG - 5 
 * MALLOC_ERROR - 7
 */
int getValue(char *cmd_str, char *val_str, void **val_ptr)
{
   int err = SUCCESS;
   void *val;

   if(!strcmp(cmd_str, "ROTATE"))
   {
      if((val = (double*)malloc(sizeof(double))))
      {
         *(double*)val = atof(val_str);
         if(!isDouble(val_str) || 
            !(*(double*)val >= -360.0 && *(double*)val <= 360.0))
         {
            err = INVALID_COMMAND_ARG;
         }
      }
   }

   else if((!strcmp(cmd_str, "MOVE") || !strcmp(cmd_str, "DRAW")))
   {
      if((val = (double*)malloc(sizeof(double))))
      {
         *(double*)val = atof(val_str);
         if(!isDouble(val_str))
         {
            err = INVALID_COMMAND_ARG;
         }
      }
   }

   else if((!strcmp(cmd_str, "FG") || !strcmp(cmd_str, "BG")))
   {
      if((val = (int*)malloc(sizeof(int))))
      {
         *(int*)val = atoi(val_str);
         if(!(*(char*)val >= 0 && *(char*)val <= 7) || !isInt(val_str))
         {
            err = INVALID_COMMAND_ARG;
         }
      }
   }

   else if(!strcmp(cmd_str, "PATTERN"))
   {
      if((val = (char*)malloc(sizeof(char))))
      {
         *(char*)val = *val_str;
         if(isWhitespace(*val_str))
         {
            err = INVALID_COMMAND_ARG;
         }
      }
   }

   else
   {
      err = UNKNOWN_COMMAND;
   }

   if(!err && !val)
   {
      err = MALLOC_ERROR;
   }

   *val_ptr = val;

   return err;
}