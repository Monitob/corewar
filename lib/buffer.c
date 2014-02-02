/*
** buffer.c for buffer.c in /home/ninon_s//Dropbox/Epitech/current/get_next_line/src
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Thu Jan  3 11:32:28 2013 simon ninon
** Last update Thu Jan  3 20:08:36 2013 simon ninon
*/

#include <stdlib.h>
#include "my.h"
#include "get_next_line.h"

int	check_buffer(char *read_buffer)
{
  int	i;

  i = 0;
  while (read_buffer[i])
    if (read_buffer[i++] == '\n')
      return (1);
  return (0);
}

char	*stock_in_buffer(char *fd_buffer, char *read_buffer)
{
  int	i;
  int	j;
  char	*new_fd_buffer;

  i = 0;
  j = 0;
  new_fd_buffer = malloc(my_strlen(fd_buffer) + my_strlen(read_buffer) + 1);
  if (new_fd_buffer == NULL)
    return (NULL);
  while (fd_buffer && fd_buffer[i])
    {
      new_fd_buffer[i] = fd_buffer[i];
      i++;
    }
  while (read_buffer[j])
    new_fd_buffer[i++] = read_buffer[j++];
  new_fd_buffer[i] = '\0';
  if (fd_buffer)
    free(fd_buffer);
  return (new_fd_buffer);
}

char	*modif_buffer(char *fd_buffer, int i)
{
  int	j;
  char	*new_fd_buffer;

  j = 0;
  new_fd_buffer = malloc(my_strlen(fd_buffer + i));
  if (new_fd_buffer == NULL)
    return (NULL);
  while (fd_buffer[++i])
    new_fd_buffer[j++] = fd_buffer[i];
  new_fd_buffer[j] = '\0';
  free(fd_buffer);
  return (new_fd_buffer);
}
