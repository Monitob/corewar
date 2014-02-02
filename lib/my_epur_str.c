/*
** my_epur_str.c for mysh2
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Tue Jan 22 15:29:24 2013 navid emad
** Last update Sat Mar 23 04:44:27 2013 navid emad
*/

#include <stdlib.h>
#include "my.h"

static char	*del_tab_to_space(char *str, int cur)
{
  if (str)
    {
      while (str[cur])
        {
          if (str[cur] == '\t' || str[cur] == '\v')
            str[cur] = ' ';
          cur++;
        }
    }
  return (str);
}

static int	del_maybe_multiple_space(char *str, int cur)
{
  while (str[cur] == ' ')
    cur++;
  return (cur);
}

char	*my_epur_str(char *str)
{
  char	*tmp;
  int	i;
  int	j;

  if (!str || !(tmp = malloc(sizeof(*tmp) * (my_strlen(str) + 1))))
    return (NULL);
  i = 0;
  j = 0;
  str = del_tab_to_space(str, 0);
  i = del_maybe_multiple_space(str, 0);
  while (str[i])
    {
      tmp[j++] = str[i++];
      i = str[i] == ' ' ? del_maybe_multiple_space(str, i) : i;
      if (str[i - 1] == ' ' && str[i])
	tmp[j++] = ' ';
    }
  tmp[j] = '\0';
  if (str)
    free(str);
  return (tmp);
}
