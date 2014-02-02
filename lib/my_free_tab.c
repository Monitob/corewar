/*
** my_free_tab.c for asm in /home/emad_n//v5.00/src/library
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Sun Mar 24 22:25:28 2013 navid emad
** Last update Sun Mar 24 22:26:23 2013 navid emad
*/

#include <stdlib.h>

void	my_free_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab)
    {
      while (tab[i])
	free(tab[i++]);
      free(tab);
    }
}
