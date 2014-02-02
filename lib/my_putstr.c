/*
** my_putstr.c for my_putstr in /home/ninon_s/
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Thu Oct  4 14:59:57 2012 simon ninon
** Last update Sun Mar 24 22:32:54 2013 navid emad
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	my_putstr(char *str, int fd)
{
  if (str != NULL)
    xwrite(fd, str, my_strlen(str));
  return (EXIT_FAILURE);
}
