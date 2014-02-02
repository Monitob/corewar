/*
** verif.c for asm-corewar in /home/emad_n//ASM-Corewar/src
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Sat Feb 23 15:22:06 2013 navid emad
** Last update Sun Mar 31 21:50:13 2013 navid emad
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my.h"

int	verif_ext(char *file_name)
{
  int	length;

  length = my_strlen(file_name);
  if (length > 2 && my_strcmp(file_name + length - 2, ".s") == 0)
    return (EXIT_SUCCESS);
  else
    {
      my_printf("\033[4;33mUsage\033[0;0m: ");
      my_printf("\"\033[4;37m./asm file_name[.s]\033[0;0m\"\n");
      return (EXIT_FAILURE);
    }
}

int	verif_empty_and_if_is_exe(char *file_name)
{
  int	fd;
  char	buffer[50];
  int	ret;
  int	find;
  int	i;

  fd = xopen(file_name, O_RDONLY, 0644);
  if ((ret = read(fd, &buffer, 50)) <= 0)
    {
      my_printf("\033[4;33mError\033[0;0m: \"\033[4;37m%s\033[0;0m\"\n",
		!ret ? "file is empty" : "reading file failed");
      close(fd);
      return (EXIT_FAILURE);
    }
  find = 0;
  i = -1;
  while (++i < ret)
    if ((buffer[i] == 0 || buffer[i] == 1) && find++ > 25)
      {
	my_printf("\033[4;33mError\033[0;0m: \"\033[4;37m%s\033[0;0m\"\n",
		  "bad content in your file.");
	close(fd);
	return (EXIT_FAILURE);
      }
  return (EXIT_SUCCESS);
}
