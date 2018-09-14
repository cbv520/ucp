/*
 * **********************************************************************
 * File          : file_io.h
 * **********************************************************************
 * Project       : Turtle Graphics - UCP 2018 Semester 2 Assignment
 * Author        : Christopher Villegas - 18359884
 * File Created  : Wednesday, 12th September 2018 4:30:12 pm
 * Last Modified : Thursday, 13th September 2018 11:25:30 pm
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : Methods for file and stream I/O.
 * **********************************************************************
 */


#ifndef FILE_IO_H
#define FILE_IO_H


#include "linked_list.h"

int readCommands(char *filename, List *list);
void logMsg(char *msg);

#endif
