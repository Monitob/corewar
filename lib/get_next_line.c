/*
** main.c for main in /home/ninon_s//Makefile
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Fri Nov 23 17:52:28 2012 simon ninon
** Last update Thu Feb 28 11:29:42 2013 sacha ifrah
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "my.h"
#include "get_next_line.h"

char	*gimme_good_line(char **fd_buffer)
{
  int	i;
  char	*line;

  i = 0;
  line = malloc(my_strlen(*fd_buffer) + 1);
  if (line == NULL)
    return (NULL);
  while ((*fd_buffer)[i] && (*fd_buffer)[i] != '\n')
    {
      line[i] = (*fd_buffer)[i];
      i++;
    }
  line[i] = '\0';
  *fd_buffer = modif_buffer(*fd_buffer, i);
  return (line);
}

char	*read_the_fd(int fd, char **fd_buffer)
{
  int	read_ret;
  char	read_buffer[MAX_READ + 1];

  while ((read_ret = read(fd, read_buffer, MAX_READ)))
    {
      read_buffer[read_ret] = '\0';
      if (read_ret < MAX_READ
	  || !read_buffer[read_ret - 1]
	  || check_buffer(read_buffer))
	{
	  *fd_buffer = stock_in_buffer(*fd_buffer, read_buffer);
	  return (gimme_good_line(fd_buffer));
	}
      else
	*fd_buffer = stock_in_buffer(*fd_buffer, read_buffer);
    }
  return (NULL);
}

char	*get_next_line(int fd)
{
  static char	*fd_buffer;

  if (fd_buffer && check_buffer(fd_buffer))
    return (gimme_good_line(&fd_buffer));
  else
    return (read_the_fd(fd, &fd_buffer));
}
