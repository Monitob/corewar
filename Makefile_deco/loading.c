/*
** loading.c for loading in /home/ninon_s//SVN/my_printf-2017-ninon_s
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Fri Nov 23 17:35:36 2012 simon ninon
** Last update Tue Mar 26 20:34:08 2013 simon ninon
*/

#include "my.h"
#include "my_printf.h"

void	homemade_usleep(void)
{
  int	i;

  i = 0;
  while (i < 2899999)
    i++;
}

int	main(void)
{
  int	percent;
  int	equals;

  percent = 0;
  equals = 0;
  while (percent <= 100)
    {
      equals = percent / 10;
      my_printf("\r%C[ %d%% ] [", "GREEN", percent);
      while (equals--)
	my_printf("%C==", "GREEN");
      equals = percent / 10;
      while (10 - equals++)
	my_putstr("  ", 1);
      my_printf("%C]", "GREEN");
      percent = percent + 1;
      homemade_usleep();
    }
  my_putchar('\n');
  return (0);
}
