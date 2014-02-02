/*
** main.c for asm in /home/emad_n//v5.00
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Mon Mar 25 13:21:18 2013 navid emad
** Last update Sat Mar 30 16:37:40 2013 navid emad
*/

#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "asm_corewar.h"
#include "get_next_line.h"

static void		display_log(struct header_s *data)
{
  my_printf("\n\033[4;32mInformations\033[0;37m:\n");
  my_printf("# Name:\t\t<%s>\n", data->prog_name);
  my_printf("# Comment:\t<%s>\n", data->comment);
  my_printf("# Size:\t\t<%d>\n\033[0;0m", data->prog_size);
}

static int		verif(char *file_name)
{
  if (verif_ext(file_name) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (verif_empty_and_if_is_exe(file_name) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

static void		init_var(struct header_s *data)
{
  data->magic = COREWAR_EXEC_MAGIC;
  data->prog_size = 0;
  my_memset(data->prog_name, 0, PROG_NAME_LENGTH + 1);
  my_memset(data->comment, 0, COMMENT_LENGTH + 1);
}

static int		parser(char *file_name)
{
  struct header_s	data;
  int			fd;
  t_data		*root;
  t_data		*label;

  if ((root = gimme_root()) == NULL)
    return (EXIT_FAILURE);
  if ((label = gimme_root()) == NULL)
    return (EXIT_FAILURE);
  fd = xopen(file_name, O_RDONLY, 0644);
  if (stock_data(root, fd) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  init_var(&data);
  if (stock_header(&data, root) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  aff_list(root);
  stock_label_define(root, label);
  check_label_call(root, label);
  gen_corfile(file_name, &data, root);
  display_log(&data);
  free_all(root);
  free_all(label);
  return (EXIT_SUCCESS);
}

int			main(int ac, char **av)
{
  int			i;

  if (ac > 1)
    {
      check_maccros();
      i = 0;
      while (++i < ac)
	{
	  if (verif(av[i]) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	  if (parser(av[i]) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
      return (EXIT_SUCCESS);
    }
  my_printf("\033[4;33mUsage\033[0;0m: ");
  my_printf("\"\033[4;37m./asm file_name[.s]\033[0;0m\"\n");
  return (EXIT_FAILURE);
}
