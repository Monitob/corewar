/*
** header.c for asm-corewar in /home/emad_n//ASM-Corewar/src
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Sun Feb 24 17:02:58 2013 navid emad
** Last update Tue Mar 26 20:22:57 2013 simon ninon
*/

#include <stdlib.h>
#include "my.h"
#include "asm_corewar.h"

static void	verif_and_copy(struct header_s *data, char *value, char *field)
{
  if (!my_strcmp(field, ".name"))
    {
      if (my_strlen(value) > PROG_NAME_LENGTH)
	{
	  my_putstr("\033[1;31mError Champion Name Is Too Long\033[0m\n", 2);
	  exit(EXIT_FAILURE);
	}
      my_strcpy(data->prog_name, value);
    }
  else
    {
      if (my_strlen(value) > COMMENT_LENGTH)
	{
	  my_putstr("\033[1;31mError Champion Comment Is Too Long\033[0m\n", 2);
	  exit(EXIT_FAILURE);
	}
      my_strcpy(data->comment, value);
    }
}

static int	get_value(char *field, struct header_s *data,
			  char *content, int line_number)
{
  char		*value;
  int		cursor;
  int		i;

  cursor = my_strlen(field);
  if (content[cursor] && content[cursor] == ' ' &&
      content[cursor + 1] && content[cursor + 1] == '"')
    {
      value = my_strdup(content + cursor + 2);
      i = -1;
      while (value[++i])
	if (value[i] == '"')
	  {
	    value[i] = '\0';
	    verif_and_copy(data, value, field);
	    free(value);
	    return (EXIT_SUCCESS);
	  }
      my_aff_error("Unterminated string", content, line_number + 1);
    }
  else
    my_aff_error("Ambiguous value", content, line_number + 1);
  return (EXIT_FAILURE);
}

int		stock_header(struct header_s *data, t_data *root)
{
  t_data	*elem;

  elem = root->previous;
  while (elem != root)
    {
      if (my_strncmp(elem->content, ".name", 5) == 0)
	{
	  if (EXIT_FAILURE ==
	      get_value(".name", data, elem->content, elem->line_number))
	    return (EXIT_FAILURE);
	}
      else if (my_strncmp(elem->content, ".comment", 5) == 0)
	{
	  if (EXIT_FAILURE ==
	      get_value(".comment", data, elem->content, elem->line_number))
	    return (EXIT_FAILURE);
	}
      elem = elem->previous;
    }
  return (EXIT_SUCCESS);
}
