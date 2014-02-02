/*
** main.c for main in /home/ninon_s//Makefile
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Fri Nov 23 17:52:28 2012 simon ninon
** Last update Sat Mar 30 16:14:49 2013 simon ninon
*/

#include <stdlib.h>
#include "my.h"
#include "vm_corewar.h"

void	my_error(char *error)
{
  my_printf("%s\n", error);
  exit(-1);
}

void		corewar(int ac, char **av)
{
  int		dump;
  t_uchar	*arena;
  t_champ	*champ;
  t_cycle	*cycles;

  g_pid = 5;
  g_winner_id = 0;
  g_winner_name = NULL;
  arena = init_arena();
  cycles  = init_cycles();
  dump = check_cmd(ac, av);
  champ = gimme_champ(ac, av, arena);
  battle_begins(dump, arena, champ, cycles);
}

int	main(int ac, char **av)
{
  if (ac > 1)
    {
      check_maccros();
      corewar(ac, av);
      return (0);
    }
  else
    {
      my_printf("./corewar ");
      my_printf("[-dumb nbr_cycle] ");
      my_printf("[[-n prog_number] [-a load_address] prog_name]\n");
      return (-1);
    }
}
