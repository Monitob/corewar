/*
** stock_label.c for Corewar in /home/ifrah_s//ASM-Corewar/src
**
** Made by sacha ifrah
** Login   <ifrah_s@epitech.net>
**
** Started on  Wed Mar 13 19:44:37 2013 sacha ifrah
** Last update Sun Mar 31 21:51:27 2013 navid emad
*/

#include <stdlib.h>
#include "asm_corewar.h"
#include "my.h"

static int	check_ch(char c)
{
  int		i;
  int		limit;

  i = -1;
  limit = my_strlen(LABEL_CHARS);
  while (++i < limit)
    if (LABEL_CHARS[i] == c)
      return (1);
  return (0);
}

static int	check_syntax_label(char *label)
{
  int		i;

  i = -1;
  while (label[++i])
    if (!check_ch(label[i]))
      return (0);
  return (1);
}

static char	*get_label_call(char *str)
{
  int		i;
  char		*buff;

  buff = NULL;
  i = my_strlen(str);
  while (str[i] != LABEL_CHAR && i >= 0)
    --i;
  ++i;
  while (str[i] != '\0' &&
	 str[i] != ' ' &&
	 str[i] != '+' &&
	 str[i] != SEPARATOR_CHAR &&
	 str[i] != '\t')
    my_append(&buff, str[i++]);
  return ((my_strlen(buff) > 0) ? buff : NULL);
}

static int	check_label_existing(t_data *label, char *str)
{
  t_data	*elem;

  elem = label->previous;
  while (elem != label)
    {
      if (!my_strcmp(str, elem->content))
      	return (1);
      elem = elem->previous;
    }
  return (0);
}

void		check_label_call(t_data *root, t_data *label)
{
  t_data	*elem;
  char		*label_str;

  elem = root->previous;
  while (elem != root)
    {
      if (detect_label(elem->content))
	{
	  if ((label_str = get_label_call(elem->content)))
	    {
	      if (!check_syntax_label(label_str))
		{
		  my_printf("\n\033[4;32mInvalid label [%s] \033[0;0m\n", label_str);
	      	  exit(EXIT_FAILURE);
		}
	      else if (!check_label_existing(label, label_str))
	      	{
		  my_printf("\n\033[4;32mUndefined label [%s]\033[0;0m\n", label_str);
	      	  exit(EXIT_FAILURE);
	      	}
	      free(label_str);
	    }
	}
      elem = elem->previous;
    }
}
