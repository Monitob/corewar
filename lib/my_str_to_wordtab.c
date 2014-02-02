/*
** my_str_to_wordtab.c for lib in /home/emad_n//mysh1/lib/lib_my
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Thu Dec 27 16:01:53 2012 navid emad
** Last update Tue Mar 26 15:14:55 2013 navid emad
*/

#include <stdlib.h>
#include "my.h"

static int     count(char *str, char *tokens)
{
  int		i;
  int		nb_words;

  if (!tokens || *tokens == '\0' || my_detect_sep(str[0], tokens))
    return (0);
  i = 1;
  nb_words = 1;
  while (str[i] != '\0')
    {
      if (my_detect_sep(str[i], tokens) && str[i + 1])
	nb_words += 1;
      i += 1;
    }
  return (nb_words);
}

char		**my_str_to_wordtab(char *str, char *tokens)
{
  int		i;
  int		j;
  int		k;
  int		nb_words;
  char		**tab;

  i = 0;
  j = 0;
  k = 0;
  nb_words = count(str, tokens);
  tab = malloc((nb_words + 1) * sizeof(char *));
  while (i < nb_words)
    {
      while (my_detect_sep(str[k], tokens))
        k = k + 1;
      tab[i] = malloc((my_strlen(str) + 1) * sizeof(char));
      j = 0;
      while (!my_detect_sep(str[k], tokens) && str[k] != '\0')
        tab[i][j++] = str[k++];
      tab[i][j] = '\0';
      k = k + 1;
      i = i + 1;
    }
  tab[i] = NULL;
  return (tab);
}
