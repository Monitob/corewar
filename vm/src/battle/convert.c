/*
** convert.c for corewar in /home/ninon_s//Dropbox/Epitech/current/corewar/src/battle
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Fri Mar 15 14:54:11 2013 simon ninon
** Last update Tue Mar 26 20:24:05 2013 simon ninon
*/

#include "vm_corewar.h"

void		stock_convert_nbr(t_uchar *tmp, t_uchar *arena, int value)
{
  int		i;
  int		value_cpy;
  t_uchar	tab[4];

  i = 3;
  value_cpy = value;
  while (i >= 0)
    {
      tab[i--] = (value_cpy >= 0 ? value % 256 :
		  value ? 255 + value % 256 + 1 : 255 + value % 256);
      value /= 256;
    }
  i = 0;
  while (i < 4)
    {
      tmp[0] = tab[i++];
      tmp = new_adress(tmp + 1, arena);
    }
}

int		convert_int_instruction(t_uchar *args, int size, t_uchar *arena)
{
  int		i;
  int		exp;
  int		result;
  t_uchar	*tmp;

  if (args[0] >= 128)
    return (negative_convert_int_instruction(args, size, arena));
  i = 0;
  exp = size - 1;
  result = 0;
  while (exp >= 0)
    {
      tmp = new_adress(args + i++, arena);
      result += tmp[0] * my_pow(256, exp--);
    }
  return (result);
}

int	convert_int(t_uchar *args, int size)
{
  int	i;
  int	exp;
  int	result;

  if (args[0] >= 128)
    return (negative_convert_int(args, size));
  i = 0;
  exp = size - 1;
  result = 0;
  while (exp >= 0)
    result += args[i++] * my_pow(256, exp--);
  return (result);
}

int	convert_int_init(t_uchar *args, int size)
{
  int	i;
  int	exp;
  int	result;

  i = 0;
  exp = size - 1;
  result = 0;
  while (exp >= 0)
    result += args[i++] * my_pow(256, exp--);
  return (result);
}
