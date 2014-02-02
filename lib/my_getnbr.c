/*
** my_getnbr.c for my_getnbr in /home/ninon_s/
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Thu Oct 18 11:12:16 2012 simon ninon
** Last update Thu Jan  3 20:09:46 2013 simon ninon
*/

#include "my.h"

int	obtain_nbr(char *str, int nbr)
{
  if (!(*str >= '0' && *str <= '9'))
    return (nbr);
  nbr = nbr * 10 + (*str - '0');
  return (obtain_nbr(str + 1, nbr));
}

int	my_getnbr(char *str)
{
  int	nbr_sign;

  nbr_sign = 1;
  while (*str == '-' || *str == '+')
    {
      if (*str == '-')
	nbr_sign *= -1;
      str = str + 1;
    }
  return (obtain_nbr(str, 0) * nbr_sign);
}
