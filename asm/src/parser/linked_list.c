/*
** list.c for asm-corewar in /home/emad_n//ASM-Corewar/src
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Sat Feb 23 22:42:31 2013 navid emad
** Last update Tue Mar 26 20:22:47 2013 simon ninon
*/

#include <stdlib.h>
#include "asm_corewar.h"
#include "my.h"
#include "get_next_line.h"

t_data		*gimme_root(void)
{
  t_data	*root;

  root = malloc(sizeof(*root));
  if (root == NULL)
    return (NULL);
  root->previous = root;
  root->next = root;
  return (root);
}

t_data		*add_to_list(t_data *elem, char *content, int line_number)
{
  t_data	*new_elem;

  new_elem = malloc(sizeof(*new_elem));
  if (new_elem == NULL)
    return (NULL);
  new_elem->content = content;
  new_elem->line_number = line_number;
  new_elem->next = elem;
  new_elem->previous = elem->previous;
  elem->previous->next = new_elem;
  elem->previous = new_elem;
  return (new_elem);
}

int		stock_data(t_data *root, int fd)
{
  t_data	*elem;
  char		*content;
  int		i;

  i = 0;
  while ((content = my_epur_str(get_next_line(fd))))
    {
      if (*content && *content != '#' && *content != ';')
	{
	  my_trim_comment_end(content);
	  if (check_all_chars(content, i) == EXIT_FAILURE ||
	      check_directives(content, i) == EXIT_FAILURE)
	    {
	      free(content);
	      return (EXIT_FAILURE);
	    }
	  if ((elem = add_to_list(root, my_strdup(content), i++)) == NULL)
	    return (EXIT_FAILURE);
	}
      free(content);
    }
  return (EXIT_SUCCESS);
}

void		aff_list(t_data *root)
{
  t_data	*elem;

  my_printf("\n\033[4;32mFile\033[0;0m:\n");
  elem = root->next;
  while (elem != root)
    {
      my_printf("[\033[1;34m#%d\033[0;0m]\t<%s>\n",
		elem->line_number, elem->content);
      elem = elem->next;
    }
}

void		free_all(t_data *root)
{
  t_data	*elem;

  elem = root->next;
  while (elem != root)
    {
      free(elem->content);
      elem = elem->next;
      free(elem->previous);
    }
  free(root);
}
