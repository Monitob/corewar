/*
** convert_negative.c for corewar in /home/ninon_s//Dropbox/Epitech/current/corewar/src/battle
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Wed Mar 20 03:36:01 2013 simon ninon
** Last update Tue Mar 26 20:24:11 2013 simon ninon
*/

#include "vm_corewar.h"

int	negative_convert_int(t_uchar *args, int size)
{
  int	i;
  int	exp;
  int	result;

  i = 0;
  exp = size - 1;
  result = 0;
  while (exp >= 0)
    result += (255 - args[i++]) * my_pow(256, exp--);
  return ((result + 1) * -1);
}

int		negative_convert_int_instruction(t_uchar *args,
						 int size, t_uchar *arena)
{
  int		i;
  int		exp;
  int		result;
  t_uchar	*tmp;

  i = 0;
  exp = size - 1;
  result = 0;
  while (exp >= 0)
    {
      tmp = new_adress(args + i++, arena);
      result += (255 - tmp[0]) * my_pow(256, exp--);
    }
  return ((result + 1) * -1);
}
