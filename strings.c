/*
 * **********************************************************************
 * File          : strings.c
 * **********************************************************************
 * Project       : Turtle Graphics - UCP 2018 Semester 2 Assignment
 * Author        : Christopher Villegas - 18359884
 * File Created  : Wednesday, 12th September 2018 8:04:47 pm
 * Last Modified : Friday, 14th September 2018 8:41:28 pm
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : Methods for handling and manipulating strings.
 * **********************************************************************
 */


#include "string.h"
#include <stdlib.h>

/**
 * @brief converts a string to upper case.
 * 
 * @param str string being converted to upper case.
 */
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

/**
 * @brief checks to see if a character is a white space character.
 * 
 * @param ch char being checked
 * @return int 1 if char is white space.
 */
int isWhitespace(char ch)
{
   return ch == ' ' || ch == '\t' || ch == '\n';
}

/**
 * @brief checks to see if a string is a valid real number.
 * invalid values given to atof() return 0.0, so the first character is 
 * checked to see whether in fact the string represents 0 or is invalid.
 * 
 * @param str string being checked
 * @return int 1 if the string is a valid real number
 */
int isDouble(char *str)
{
   int b = 1;
   if(atof(str) == 0.0 && *str != '0')
   {
      b = 0;
   }
   return b; 
}

/**
 * @brief checks to see if a string is a valid int.
 * invalid values given to ato() return 0, so the first character is 
 * checked to see whether in fact the string represents 0 or is invalid.
 * this method also invalidates real numbers where the fractional part is 
 * non 0.
 * 
 * @param str string being checked
 * @return int 1 if the string is a valid int
 */
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
