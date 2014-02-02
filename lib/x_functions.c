/*
** x_functions.c for asm in /home/emad_n//v5.00/src/library
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Sun Mar 24 20:40:18 2013 navid emad
** Last update Mon Mar 25 19:05:22 2013 navid emad
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	xopen(char *filename, int flags, mode_t mode)
{
  int	fd;

  fd = open(filename, flags, mode);
  if (fd < 0)
    {
      my_putstr("Error: cannot open.\n", 2);
      exit(EXIT_FAILURE);
    }
  return (fd);
}

int	xwrite(int fd, char *string, size_t len)
{
  int	ret;

  if ((ret = write(fd, string, len)) == -1)
    {
      my_putstr("Error: cannot write.\n", 2);
      exit(EXIT_FAILURE);
    }
  return (ret);
}

int	xuwrite(int fd, unsigned char *string, size_t len)
{
  int	ret;

  if ((ret = write(fd, string, len)) == -1)
    {
      my_putstr("Error: cannot write.\n", 2);
      exit(EXIT_FAILURE);
    }
  return (ret);
}

void	*xmalloc(size_t n)
{
  void	*p;

  if (!(p = malloc(n)))
    {
      my_putstr("Error: cannot allocate mem.\n", 2);
      exit(EXIT_FAILURE);
    }
  return p;
}

off_t	xlseek(int fd, off_t offset, int whence)
{
  off_t	cur;

  if ((cur = lseek(fd, offset, whence)) == -1)
    {
      my_putstr("Error: cannot execute lseek.\n", 2);
      exit(EXIT_FAILURE);
    }
  return (cur);
}
