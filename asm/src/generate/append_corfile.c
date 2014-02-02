/*
** append_corfile.c for s in /home/emad_n//v5.00/src/generate
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Sat Mar 23 15:47:06 2013 navid emad
** Last update Tue Mar 26 20:22:11 2013 simon ninon
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "asm_corewar.h"

int		xwrite_lookatsize(int fd, void *buf, size_t count)
{
  static int    count_bytes = 0;

  if (buf != NULL)
    count_bytes += xuwrite(fd, buf, count);
  return (count_bytes);
}

void		append_int(int fd, int number, int state)
{
  int		i;
  unsigned char	string[4];
  int		tmp;

  tmp = number;
  i = 3;
  while (i >= 0)
    {
      string[i] = number % 256;
      string[i] -= (string[i] == 255) ? 1 : 0;
      number /= 256;
      i--;
    }
  if (tmp < 0)
    {
      i = -1;
      while (++i < 4)
	if (string[i] == 0)
	  string[i] = 255;
    }
  if (state)
    xwrite_lookatsize(fd, string, 4);
  else
    xuwrite(fd, string, 4);
}

void		append_short_int(int fd, short int number, int state)
{
  int		i;
  unsigned char	string[2];
  short int	tmp;

  tmp = number;
  i = 1;
  while (i >= 0)
    {
      string[i] = number % 256;
      string[i] -= (string[i] == 255 && i == 0) ? 1 : 0;
      number /= 256;
      i--;
    }
  if (tmp < 0 && string[0] == 0)
    string[0] = 255;
  else if (tmp >= 0 && string[0] == 255)
    string[0] = 0;
  if (state)
    xwrite_lookatsize(fd, string, 2);
  else
    xuwrite(fd, string, 2);
}

void		append_string(int fd, char *string, int len)
{
  xwrite(fd, string, len);
}
