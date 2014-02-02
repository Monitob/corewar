/*
** my_strcat.c for my_strcat in /home/ninon_s//Makefile/lib/my
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Sun Dec 30 19:04:32 2012 simon ninon
** Last update Sat Jan 19 11:48:42 2013 simon ninon
*/

#include <stdlib.h>
#include "my.h"

char	*my_strcat(char *str1, char *str2)
{
  int	i;
  int	j;
  char	*new_str;

  i = 0;
  j = 0;
  new_str = malloc(my_strlen(str1) + my_strlen(str2) + 1);
  if (new_str == NULL)
    return (NULL);
  while (str1[i])
    {
      new_str[i] = str1[i];
      i++;
    }
  while (str2[j])
    new_str[i++] = str2[j++];
  new_str[i] = '\0';
  return (new_str);
}
