/*
** instructions.c for asm in /home/emad_n//v5.00/src/generate
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Sun Mar 24 22:01:19 2013 navid emad
** Last update Tue Mar 26 20:22:26 2013 simon ninon
*/

#include <stdlib.h>
#include <stdio.h>
#include "asm_corewar.h"
#include "my.h"

static void	append_desc_oct(int fd, char **tab, int op_code, char *content)
{
  int		i;
  char		type;
  char		codage_octet;

  if (op_code != OP_LIVE && op_code != OP_ZJMP &&
      op_code != OP_FORK && op_code != OP_LFORK)
    {
      i = -1;
      codage_octet = 0;
      while (++i < MAX_ARGS_NUMBER)
	{
	  type = 0;
	  if (my_size_tab(tab) > i)
	    type = gimme_type(tab, i, op_code, content);
	  if (type == T_REG)
	    type = 1;
	  else if (type == T_DIR)
	    type = 2;
	  else if (type == T_IND)
	    type = 3;
	  codage_octet |= (type << ((MAX_ARGS_NUMBER - 1 - i) << 1));
	}
      xwrite_lookatsize(fd, &codage_octet, 1);
    }
}

static void	append_registry_value(int fd, char *reg, char *line_content)
{
  char		registry_number;

  registry_number = (char)my_getnbr(reg + 1);
  if (registry_number < 1 || registry_number > REG_NUMBER)
    {
      my_aff_error("Number registry value excepted [1;16]", line_content, 0);
      exit(EXIT_FAILURE);
    }
  xwrite_lookatsize(fd, &registry_number, 1);
}

static void	append_indirect_value(int fd, char *str, char *line_content)
{
  short int	indirect_value;
  char		tokens[14];

  my_strcpy(tokens, "0123456789-+");
  tokens[12] = DIRECT_CHAR;
  tokens[13] = '\0';
  if (my_detect_sep(str[0], tokens))
    {
      indirect_value =
	(short int)my_getnbr(str[0] == DIRECT_CHAR ? str + 1 : str);
      if (indirect_value > IDX_MOD || -indirect_value > IDX_MOD)
	exit(my_aff_error("Warning Direction too far", line_content, 0));
      append_short_int(fd, indirect_value, 1);
    }
  else
    exit(my_aff_error("Invalid indirect parameter value", line_content, 0));
}

static void	append_direct_value(int fd, char *str, char *line_content)
{
  int		direct_value;
  char		tokens[14];

  my_strcpy(tokens, "0123456789-+");
  tokens[12] = DIRECT_CHAR;
  tokens[13] = '\0';
  if (my_detect_sep(str[0], tokens))
    {
      direct_value = my_getnbr(str[0] == DIRECT_CHAR ? str + 1 : str);
      if (direct_value > IDX_MOD || -direct_value > IDX_MOD)
	exit(my_aff_error("Warning Direction too far", line_content, 1));
      append_int(fd, direct_value, 1);
    }
  else
    exit(my_aff_error("Invalid direct parameter value", line_content, 0));
}

void		handler_instruction(int fd, int op_code, char *content)
{
  int		i;
  char		type;
  char		**tab;
  char		tokens[2];

  tokens[0] = SEPARATOR_CHAR;
  tokens[1] = '\0';
  tab = my_str_to_wordtab(my_trim(content), tokens);
  if (my_size_tab(tab) != op_tab[op_code].nbr_args)
    exit(my_aff_error("Incorrect number of arguments", content, 0));
  append_desc_oct(fd, tab, op_code, content);
  i = -1;
  while (tab[++i])
    {
      type = gimme_type(tab, i, op_code, content);
      if (type == T_REG)
	append_registry_value(fd, tab[i], content);
      else if (type == T_IND
	       || op_code == OP_ZJMP || op_code == OP_FORK
	       || op_code == OP_LFORK || op_code == OP_STI)
	append_indirect_value(fd, tab[i], content);
      else if (type == T_DIR)
	append_direct_value(fd, tab[i], content);
    }
  my_free_tab(tab);
}
