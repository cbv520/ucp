/*
 * **********************************************************************
 * File          : drawer.h
 * **********************************************************************
 * Project       : Turtle Graphics - UCP 2018 Semester 2 Assignment
 * Author        : Christopher Villegas - 18359884
 * File Created  : Wednesday, 12th September 2018 4:36:47 pm
 * Last Modified : Thursday, 13th September 2018 3:20:43 am
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : 
 * **********************************************************************
 */


#ifndef DRAWER_H
#define DRAWER_H

#include "linked_list.h"

typedef struct
{
   double x;
   double y;
   double angle;
   int bg;
   int fg;
   char pattern;
} Properties;

typedef int (*CmdFunction)(void* value, Properties* props);

typedef struct
{
   CmdFunction function;
   void* value;
} Command;

void runCommands(List* commands);
CmdFunction getCommand(char* cmd);
void* getValue(char* cmd, char* val);
int rotate(void* value, Properties* props);
int move(void* value, Properties* props);
int draw(void* value, Properties* props);
int fg(void* value, Properties* props);
int bg(void* value, Properties* props);
int pattern(void* value, Properties* props);
void plotter(void *plotData);

#endif