/*
** my_strlen.c for my_strlen in /home/ninon_s/
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Thu Oct  4 15:31:25 2012 simon ninon
** Last update Thu Jan  3 20:11:29 2013 simon ninon
*/

#include <stdlib.h>
#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    while (str[i])
      i = i + 1;
  return (i);
}
