/*
** data_champ.c for VM in /home/emad_n//v16/src/init
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Wed Mar 20 01:19:05 2013 navid emad
** Last update Tue Mar 26 20:37:57 2013 simon ninon
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "my_printf.h"
#include "vm_corewar.h"

static void	gimme_code_content(int fd, t_champ *champ)
{
  int		i;
  int		j;
  int		total;
  int		ret;
  t_uchar	buffer[READ_SIZE];

  total = 0;
  i = 0;
  while ((ret = read(fd, buffer, READ_SIZE)) > 0)
    {
      if ((total += ret) > MEM_SIZE)
	my_error("Error: champ too big.\n");
      j = -1;
      while (++j < total)
	champ->parsing->code_content[i + j] = buffer[j];
      i += (j + 1);
    }
  if (total != champ->parsing->size)
    my_error("error: invalid champ->size.\n");
}

static void	gimme_datafile(char *filename, t_champ *champ)
{
  int		fd;
  t_uchar	buffer[READ_SIZE];

  if ((fd = open(filename, O_RDONLY)) == -1)
    my_error("error: open fail.\n");
  if (read(fd, buffer, READ_SIZE) < READ_SIZE)
    my_error("error: read fail.\n");
  champ->parsing->magic = convert_int_init(buffer, 4);
  if (champ->parsing->magic != COREWAR_EXEC_MAGIC)
    my_error("error: wrong magic_code.\n");
  if (!(champ->name = my_ustrndup(buffer + CURSOR_NAME, PROG_NAME_LENGTH)))
    my_error("error: malloc fail (name).\n");
  champ->parsing->size = convert_int_init(buffer + CURSOR_SIZE, 8);
  if (champ->parsing->size <= 0 || champ->parsing->size > MEM_SIZE - 1)
    my_error("error: invalid file size.\n");
  if (!(champ->comment = my_ustrndup(buffer + CURSOR_COMMENT, COMMENT_LENGTH)))
    my_error("error: malloc fail (comment).\n");
  gimme_code_content(fd, champ);
  if (close(fd) == -1)
    my_error("error: close fail.\n");
}

static int	find_good_id(int *start_id, char champions_state[4])
{
  while (*start_id < 4)
    {
      if (champions_state[*start_id] == '0')
	{
	  *start_id = *start_id + 1;
	  return (*start_id);
	}
      *start_id += 1;
    }
  return (0);
}

static void	gimme_number_taken(int ac, char **av, char champions_state[4])
{
  int		i;
  int		id_tiret_n;

  i = -1;
  while (++i < ac)
    {
      if (i >= 3)
	{
	  if (!my_strcmp(av[i - 2], "-n"))
	    {
	      id_tiret_n = my_getnbr(av[i - 1]);
	      if (id_tiret_n > 0)
		{
		  champions_state[id_tiret_n - 1] = '1';
		}
	    }
	}
    }
}

void		get_data_champions(int ac, char **av, t_champ *root)
{
  static char	champions_state[] = "0000";
  int		start_id;
  int		id_tiret_n;
  int		i;
  int		size;

  gimme_number_taken(ac, av, champions_state);
  start_id = 0;
  i = 0;
  while (++i < ac)
    {
      size = my_strlen(av[i]);
      if (size >= 4 && !my_strcmp(&(av[i][size - 4]), ".cor"))
	{
	  add_elem(root);
	  if ((root->previous->parsing = malloc(sizeof(t_parse))) == NULL)
	    my_error("Fail malloc.");
	  if (i >= 3 && !my_strcmp(av[i - 2], "-n") &&
	      ((id_tiret_n = my_getnbr(av[i - 1])) > 0))
	    init_champ(root->previous, id_tiret_n);
	  else
	    init_champ(root->previous, find_good_id(&start_id, champions_state));
	  gimme_datafile(av[i], root->previous);
	}
    }
}
