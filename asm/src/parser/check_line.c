/*
** check.c for asm-corewar in /home/emad_n//ASM-Corewar/src
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Sun Feb 24 16:28:42 2013 navid emad
** Last update Tue Mar 26 20:28:29 2013 simon ninon
*/

#include <stdlib.h>
#include "asm_corewar.h"
#include "my.h"

int	check_directives(char *content, int line_number)
{
  int	i;
  char	*directive;

  if (content[0] == '.')
    {
      i = 0;
      while (content[i] != ' ' && content[i])
	i += 1;
      directive = my_strndup(content, i);
      if (my_strcmp(directive, ".extend") == 0)
	my_aff_warning("Extend mode was not implanted");
      else if (my_strcmp(directive, ".code") == 0)
	my_aff_warning("Code ID is unused");
      else if (my_strcmp(directive, NAME_CMD_STRING) != 0 &&
	       my_strcmp(directive, COMMENT_CMD_STRING) != 0)
	{
	  free(directive);
	  return (my_aff_error("Unknown directive", content, line_number));
	}
      free(directive);
      return (EXIT_SUCCESS);
    }
  return (EXIT_SUCCESS);
}

int	sort_directives(char *content)
{
  int	i;

  if (content[0] == '.')
    {
      i = 0;
      while (content[i] != ' ' && content[i])
	i = i + 1;
      if (my_strncmp(content, ".name", i) == 0)
	return (1);
      else if (my_strncmp(content, ".comment", i) == 0)
	return (1);
    }
  return (0);
}

int	check_all_chars(char *content, int line_number)
{
  int	i;

  if (sort_directives(content) == 0)
    {
      i = 0;
      while (content[i])
	{
	  if (content[i] == COMMENT_CHAR)
	    return (EXIT_SUCCESS);
	  if (content[i] != COMMENT_CHAR && content[i] != LABEL_CHAR &&
	      content[i] != DIRECT_CHAR &&  content[i] != SEPARATOR_CHAR &&
	      content[i] != '+' && content[i] != '.' && content[i] != '=' &&
	      content[i] != ' ' && content[i] != '$' && content[i] != '-' &&
	      content[i] != '"' && content[i] != '_' && content[i] != ';' &&
	      !my_isalpha(content[i]) && !my_isnum(content[i]))
	    {
	      my_aff_error("Unknown character", content, line_number + 1);
	      return (EXIT_FAILURE);
	    }
	  i++;
	}
    }
  return (EXIT_SUCCESS);
}
