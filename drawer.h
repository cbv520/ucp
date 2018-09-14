/*
 * **********************************************************************
 * File          : drawer.h
 * **********************************************************************
 * Project       : Turtle Graphics - UCP 2018 Semester 2 Assignment
 * Author        : Christopher Villegas - 18359884
 * File Created  : Wednesday, 12th September 2018 4:36:47 pm
 * Last Modified : Friday, 14th September 2018 6:53:43 pm
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : Methods related to the commands run by turtle graphics
 * **********************************************************************
 */


#ifndef DRAWER_H
#define DRAWER_H

#include "linked_list.h"

/**
 * @brief Data used by the plotter when moving and drawing. 
 * Values are set each time a command in the command list is executed. 
 * 
 * x - current x position. 0 is the leftmost position.
 * y - current y position. 0 is the topmost position 
 * angle - current angle the drawer is facing.
 * bg - background color
 * fg - foreground color
 * pattern - pixel pattern
 */
typedef struct
{
   double x;
   double y;
   double angle;
   int bg;
   int fg;
   char pattern;
} PlotData;

/**
 * @brief Pointer to a function that executes one of the turtle graphics 
 * commands including:
 * rotate
 * move
 * draw
 * fg
 * bg
 * pattern
 * 
 */
typedef void (*CmdFunction)(void *value, PlotData *data);

/**
 * @brief A command to be executed by the program. Commands are provided to
 * the program via a text file which are then converted into Command structs 
 * 
 * function - function pointer that points to one of the turtle graphics 
 *            functions  
 * value - a pointer to the value representing the argument given for a 
 *         command.
 */
typedef struct
{
   CmdFunction function;
   void *value;
} Command;

void runCommands(List *commands);
CmdFunction getCommand(char *cmd);
void* getValue(char *cmd, char *val);
void rotate(void *value, PlotData *data);
void move(void *value, PlotData *data);
void draw(void *value, PlotData *data);
void fg(void *value, PlotData *data);
void bg(void *value, PlotData *data);
void pattern(void *value, PlotData *data);
void plotter(void *plotData);

#endif