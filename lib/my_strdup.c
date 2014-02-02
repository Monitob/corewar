/*
** my_strdup.c for my_strdup in /home/ninon_s//Dropbox/Epitech/Makefile/lib/my
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Fri Jan 25 23:19:05 2013 simon ninon
** Last update Mon Mar 18 21:59:09 2013 navid emad
*/

#include <stdlib.h>
#include "my.h"

char	*my_ustrndup(unsigned char *str, int n)
{
  int	i;
  char	*new_str;

  i = 0;
  new_str = malloc(my_strlen((char *)str) + 1);
  if (new_str == NULL)
    exit(-1);
  while (str[i] && i < n)
    {
      new_str[i] = str[i];
      i++;
    }
  new_str[i] = '\0';
  return (new_str);
}

char	*my_strndup(char *str, int n)
{
  int	i;
  char	*new_str;

  i = 0;
  new_str = malloc(my_strlen(str) + 1);
  if (new_str == NULL)
    exit(-1);
  while (str[i] && i < n)
    {
      new_str[i] = str[i];
      i++;
    }
  new_str[i] = '\0';
  return (new_str);
}

char	*my_strdup(char *str)
{
  int	i;
  char	*new_str;

  i = 0;
  new_str = malloc(my_strlen(str) + 1);
  if (new_str == NULL)
    return (NULL);
  while (str[i])
    {
      new_str[i] = str[i];
      i++;
    }
  new_str[i] = '\0';
  return (new_str);
}
