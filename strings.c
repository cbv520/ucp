/*
 * **********************************************************************
 * File          : strings.c
 * **********************************************************************
 * Project       : Turtle Graphics - UCP 2018 Semester 2 Assignment
 * Author        : Christopher Villegas - 18359884
 * File Created  : Wednesday, 12th September 2018 8:04:47 pm
 * Last Modified : Thursday, 13th September 2018 8:07:57 pm
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : 
 * **********************************************************************
 */


#include "string.h"
#include <stdlib.h>
#include <stdio.h>

void uppercase(char *str)
{
   for(; *str; str++)
   {
      if(*str >= 'a' && *str <= 'z')
      {
         *str = 'A' + *str - 'a';
      }
   }
}

int isWhitespace(char ch)
{
   return ch == ' ' || ch == '\t' || ch == '\n';
}

int isDouble(char *str)
{
   int b = 1;
   if(atof(str) == 0.0 && *str != '0')
   {
      b = 0;
   }
   return b; 
}

int isInt(char *str)
{
   int b = 1;
   if((atoi(str) == 0 && *str != '0') ||
      (atof(str) - (double)atoi(str)) != 0.0)
   {
         b = 0;
   }
   return b; 
}