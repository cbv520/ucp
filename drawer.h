/*
 * **********************************************************************
 * File          : drawer.h
 * **********************************************************************
 * Project       : Turtle Graphics - UCP 2018 Semester 2 Assignment
 * Author        : Christopher Villegas - 18359884
 * File Created  : Wednesday, 12th September 2018 4:36:47 pm
 * Last Modified : Thursday, 13th September 2018 6:12:17 pm
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
} PlotData;

typedef void (*CmdFunction)(void *value, PlotData *data);

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