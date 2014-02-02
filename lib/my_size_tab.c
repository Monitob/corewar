/*
** my_size_tab.c for asm in /home/emad_n//v5.00/src/library
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Sun Mar 24 23:49:11 2013 navid emad
** Last update Sun Mar 24 23:51:00 2013 navid emad
*/

int	my_size_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab)
    while (tab[i])
      i += 1;
  return (i);
}
