/*
** check.c for corewar in /home/ninon_s//Dropbox/Epitech/current/corewar/src/battle
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Fri Mar 15 13:24:17 2013 simon ninon
** Last update Tue Mar 26 20:23:59 2013 simon ninon
*/

#include "vm_corewar.h"

t_tab    funct_tab[] =
  {
    {10, live},
    {5, load},
    {5, store},
    {10, add},
    {10, sub},
    {6, and},
    {6, or},
    {6, xor},
    {20, jump},
    {25, load_index},
    {25, store_index},
    {800, fork_corewar},
    {10, long_load},
    {50, long_load_index},
    {1000, long_fork},
    {2, aff},
  };

int		check_round(t_champ *champ, t_cycle *cycles)
{
  int		i;
  t_champ	*tmp;

  i = 0;
  tmp = champ->next;
  if (cycles->cycle_to_die <= 0)
    return (0);
  while (tmp != champ)
    {
      if (tmp->cycle_to_die < cycles->cycle_to_die)
	{
	  if (!tmp->father)
	    i++;
	  tmp = tmp->next;
	}
      else
	{
	  remove_main_and_fork(champ, tmp);
	  tmp = champ->next;
	  i = 0;
	}
    }
  return (i);
}

void	check_instructions(t_champ *champ, t_uchar *arena)
{
  if (*champ->PC > 0 && *champ->PC < 17)
    {
      champ->cycle = funct_tab[*champ->PC - 1].cycles;
      gimme_instruction(champ, arena);
    }
  else
      champ->PC = new_adress(champ->PC + 1, arena);
}

void	check_cycles(t_champ *champ, t_uchar *arena, t_cycle *cycle)
{
  if (champ->cycle == 0)
    check_instructions(champ, arena);
  else if (--champ->cycle == 1)
    {
      exec_instructions(champ, arena, cycle);
      champ->cycle = 0;
    }
}

void	exec_instructions(t_champ *champ, t_uchar *arena, t_cycle *cycle)
{
  int	args;

  if (specific_function(champ, arena))
    args = 1;
  else
    args = 2;
  args += champ->cmd->type_args[0];
  args += champ->cmd->type_args[1];
  args += champ->cmd->type_args[2];
  funct_tab[champ->cmd->funct - 1].function(arena, champ);
  champ->cmd->type_args[0] = 0;
  champ->cmd->type_args[1] = 0;
  champ->cmd->type_args[2] = 0;
  if (champ->cmd->funct == 9 && champ->carry)
    return ;
  else if (champ->cmd->funct == 1)
    cycle->nbr_live++;
  champ->PC = new_adress(champ->PC + args, arena);
}
