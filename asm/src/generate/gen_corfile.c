/*
** gen_corfile.c for q in /home/emad_n//v5.00/src/generate
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Sat Mar 23 04:18:39 2013 navid emad
** Last update Sat Mar 30 15:56:52 2013 navid emad
*/

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"
#include "asm_corewar.h"

char		gimme_type(char **tab, int i, int op_code, char *line_content)
{
  int		type;

  if (tab[i][0] == LABEL_CHAR || my_detect_sep(tab[i][0], "0123456789-+"))
    type = T_IND;
  else if (tab[i][0] == DIRECT_CHAR)
    {
      type = (tab[i][1] == LABEL_CHAR) ? T_LAB : T_DIR;
      if (type == T_LAB)
	exit(my_aff_error("Label not gered, sorry", line_content, 0));
    }
  else if (tab[i][0] == 'r')
    type = T_REG;
  else
    exit(my_aff_error("Invalid parameters", line_content, 0));
  if (!(type & op_tab[op_code].type[i]))
    exit(my_aff_error("Parameter not possible", line_content, 0));
  return (type);
}

static int	gimme_filecor_fd(char *file_name)
{
  char		*cor_file_name;
  int		len;
  int		fd;

  len = my_strlen(file_name);
  cor_file_name = xmalloc(len + 3);
  my_strcpy(cor_file_name, file_name);
  cor_file_name[len - 1] = 'c';
  cor_file_name[len] = 'o';
  cor_file_name[len + 1] = 'r';
  cor_file_name[len + 2] = '\0';
  fd = xopen(cor_file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  free(cor_file_name);
  return (fd);
}

static void	append_header(int fd, struct header_s *data)
{
  append_int(fd, COREWAR_EXEC_MAGIC, 0);
  append_string(fd, data->prog_name, PROG_NAME_LENGTH);
  append_string(fd, "\0\0\0\0", 4);
  append_int(fd, 0, 0);
  append_string(fd, data->comment, COMMENT_LENGTH);
  append_string(fd, "\0\0\0\0", 4);
}

static int	gimme_op_code(char *line_content)
{
  int		i;
  int		len;

  i = 0;
  while (op_tab[i].mnemonique)
    {
      len = my_strlen(op_tab[i].mnemonique);
      if (!my_strncmp(op_tab[i].mnemonique, line_content, len) &&
	  my_detect_sep(line_content[len], " \t"))
	return (i);
      i += 1;
    }
  return (-1);
}

void		gen_corfile(char *file_name, struct header_s *data, t_data *root)
{
  int		fd;
  t_data	*elem;
  int		op_code;
  char		tokens[3];

  fd = gimme_filecor_fd(file_name);
  append_header(fd, data);
  tokens[0] = COMMENT_CHAR;
  tokens[1] = '.';
  tokens[2] = '\0';
  elem = root->next;
  while (elem != root)
    {
      if (!my_detect_sep(elem->content[0], tokens))
	{
	  if ((op_code = gimme_op_code(elem->content)) == -1)
	    exit(my_aff_error("Unknown instruction line", elem->content, 0));
	  xwrite_lookatsize(fd, &(op_tab[op_code].code), 1);
	  handler_instruction(fd, op_code,
			    elem->content + my_strlen(op_tab[op_code].mnemonique));
	}
      elem = elem->next;
    }
  xlseek(fd, (PROG_NAME_LENGTH + 8), SEEK_SET);
  append_int(fd, (data->prog_size = xwrite_lookatsize(fd, NULL, 0)), 0);
}
