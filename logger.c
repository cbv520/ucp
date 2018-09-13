/*
 * **********************************************************************
 * File          : logger.c
 * **********************************************************************
 * Project       : Turtle Graphics - UCP 2018 Semester 2 Assignment
 * Author        : Christopher Villegas - 18358884
 * File Created  : Wednesday, 12th September 2018 7:32:56 pm
 * Last Modified : Thursday, 13th September 2018 3:46:39 am
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : 
 * **********************************************************************
 */


#include <stdio.h>
#include "logger.h"

void logMove(double x1, double x2, double y1, double y2)
{
   printf("MOVE (%8.3f,%8.3f)-(%8.3f,%8.3f)\n", x1, y1, x2, y2);
}

void logDraw(double x1, double x2, double y1, double y2)
{
   printf("DRAW (%8.3f,%8.3f)-(%8.3f,%8.3f)\n", x1, y1, x2, y2);
}