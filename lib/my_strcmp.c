/*
** my_strcmp.c for my_strcmp in /home/ninon_s/
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Mon Oct  8 16:53:46 2012 simon ninon
** Last update Sat Mar 23 05:00:52 2013 navid emad
*/

#include "my.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i] && i < n)
    {
      if (s1[i] != s2[i])
	return (1);
      i++;
    }
  if (i == n)
    return (0);
  return (1);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i])
    {
      if (s1[i] != s2[i])
	return (1);
      i = i + 1;
    }
  if (!s1[i] && !s2[i])
    return (0);
  return (1);
}
