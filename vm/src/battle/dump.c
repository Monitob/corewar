/*
** dump.c for corewar in /home/ninon_s//Dropbox/Epitech/current/corewar/src
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Tue Jan 29 15:11:17 2013 simon ninon
** Last update Tue Mar 26 20:24:29 2013 simon ninon
*/

#include <stdlib.h>
#include "vm_corewar.h"
#include "my.h"
#include "my_printf.h"

void	convert_base(int nbr, int base)
{
  int	modulo;

  modulo = nbr % base;
  nbr /= base;
  if (nbr)
    convert_base(nbr, base);
  if (modulo > 9)
    my_putchar('A' + (modulo % 10));
  else
    my_put_nbr(modulo);
}

void	new_line(int i, int *line)
{
  my_putchar('\n');
  if (i < MEM_SIZE)
    {
      convert_base(*line, 16);
      my_printf("\t: ");
      *(line) += 1;
    }
}

void	dump_memory(t_champ *champ, t_cycle *cycle, t_uchar *arena)
{
  int	i;
  int	line;

  i = 0;
  line = 0;
  convert_base(line++, 16);
  my_printf("\t: ");
  while (i < MEM_SIZE)
    {
      if (arena[i] < 17)
	my_putchar('0');
      convert_base((int)arena[i], 16);
      i++;
      if (i % 16 == 0)
	new_line(i, &line);
      else if (i < MEM_SIZE)
	my_putchar(' ');
    }
  clean(champ, cycle, arena);
}
