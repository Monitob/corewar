/*
** my_trim.c for asm in /home/emad_n//v5.00/src/library
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Mon Mar 25 22:10:40 2013 navid emad
** Last update Tue Mar 26 19:09:20 2013 navid emad
*/

#include "my.h"

char	*my_trim(char *str)
{
  char	*p1;
  char	*p2;

  p1 = str;
  p2 = str;
  while (*p1 != '\0')
    {
      if (*p1 == ' ' || *p1 == '\t')
	++p1;
      else
	*p2++ = *p1++;
    }
  *p2 = '\0';
  return (str);
}
