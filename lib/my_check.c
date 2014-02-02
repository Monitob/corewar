/*
** my_check.c for corewar in /home/ninon_s//SVN/corewar-2017-ninon_s
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Sat Mar 30 16:14:52 2013 simon ninon
** Last update Sat Mar 30 16:23:31 2013 simon ninon
*/

#include <stdlib.h>
#include "vm_corewar.h"
#include "my.h"

void	check_maccros(void)
{
  if (T_REG != 1
      || T_DIR != 2
      || T_IND != 4
      || IND_SIZE != 2
      || DIR_SIZE != 4
      || REG_SIZE != 4)
    {
      my_putstr("Wrong maccros\n", 2);
      exit(-1);
    }
}
