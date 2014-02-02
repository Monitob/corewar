/*
** my_put_nbr.c for my_put_nbr in /home/ninon_s/
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Fri Oct 26 11:31:09 2012 simon ninon
** Last update Thu Jan  3 20:10:30 2013 simon ninon
*/

#include "my.h"

void	my_put_nbr(int nbr)
{
  if (nbr >= 10 || nbr <= -10)
    my_put_nbr(nbr / 10);
  else if (nbr < 0)
    my_putchar('-');
  if (nbr > 0)
    my_putchar('0' + (nbr % 10));
  else
    my_putchar('0' - (nbr % 10));
}
