/*
** stock_label.c for Corewar in /home/ifrah_s//ASM-Corewar/src
**
** Made by sacha ifrah
** Login   <ifrah_s@epitech.net>
**
** Started on  Wed Mar 13 19:44:37 2013 sacha ifrah
** Last update Tue Mar 26 20:23:02 2013 simon ninon
*/

#include <stdlib.h>
#include "my.h"
#include "asm_corewar.h"

int		detect_label(char *str)
{
  int		i;

  i = -1;
  while (str[++i])
    if (str[i] == LABEL_CHAR)
      return (1);
  return (0);
}

static char	*get_label(char *str)
{
  int		i;

  if (detect_label(str))
    {
      i = 0;
      while (str[++i])
	if (str[i] == LABEL_CHAR &&
	    str[i - 1] != ' ' &&
	    str[i - 1] != '\t' &&
	    str[i - 1] != '%')
	  return (my_strndup(str, i));
    }
  return (NULL);
}

static void	aff_list_label(t_data *label)
{
  t_data	*elem;

  elem = label->previous;
  my_printf("\n\033[4;32mLabels\033[0;0m:\n");
  while (elem != label)
    {
      my_printf("[\033[0;36m%s\033[0;0m]\n", elem->content);
      elem = elem->previous;
    }
}

void		stock_label_define(t_data *root, t_data *label)
{
  t_data	*elem;
  char		*label_str;

  elem = root->previous;
  while (elem != root)
    {
      label_str = get_label(elem->content);
      if (label_str != NULL)
	add_to_list(label, label_str, elem->line_number);
      elem = elem->previous;
    }
  aff_list_label(label);
}
