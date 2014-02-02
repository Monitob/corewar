/*
** battle.c for corewar in /home/ninon_s//Dropbox/Epitech/current/corewar/src
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Tue Jan 29 01:03:56 2013 simon ninon
** Last update Tue Mar 26 20:23:54 2013 simon ninon
*/

#include <stdlib.h>
#include "vm_corewar.h"
#include "my_printf.h"

void		remove_main_and_fork(t_champ *root, t_champ *tmp)
{
  t_champ	*tmp_2;

  tmp_2 = root->next;
  while (tmp_2 != root)
    {
      tmp_2 = tmp_2->next;
      if (tmp_2->previous != tmp && tmp_2->previous->father == tmp->pid)
	remove_main_and_fork(root, tmp_2->previous);
    }
  remove_elem(tmp);
}

void		clean(t_champ *champ, t_cycle *cycle, t_uchar *arena)
{
  t_champ	*tmp;

  free(arena);
  free(cycle);
  tmp = champ->next;
  while (tmp != champ)
    {
      tmp = tmp->next;
      remove_elem(tmp->previous);
    }
  free(champ);
  exit(0);
}

void	is_there_a_winner(t_uchar *arena, t_champ *champ, t_cycle *cycles)
{
  if (g_winner_name)
    my_printf("Le joueur %d (%s) a gagne.\n", g_winner_id, g_winner_name);
  else
    my_printf("Egalite.\n");
  clean(champ, cycles, arena);
}

void		battle_begins(int dump, t_uchar *arena,
			      t_champ *champ, t_cycle *cycles)
{
  t_champ	*tmp;

  while (cycles->cycle_to_die > 0 && check_round(champ, cycles))
    {
      tmp = champ->next;
      while (tmp != champ)
	{
	  check_cycles(tmp, arena, cycles);
	  tmp->cycle_to_die++;
	  tmp = tmp->next;
	  if (cycles->nbr_live >= NBR_LIVE)
	    {
	      cycles->cycle_to_die -= CYCLE_DELTA;
	      cycles->nbr_live = 0;
	    }
	}
      if (cycles->current_cycle == dump)
	dump_memory(champ, cycles, arena);
      cycles->current_cycle += 1;
    }
  is_there_a_winner(arena, champ, cycles);
}
