/*
** functs_4.c for corewar in /home/ninon_s//Dropbox/Epitech/current/corewar/src/battle
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Wed Jan 30 14:58:04 2013 simon ninon
** Last update Tue Mar 26 20:25:09 2013 simon ninon
*/

#include <stdio.h>
#include "my.h"
#include "vm_corewar.h"
#include "my_printf.h"

void	aff(t_uchar *arena, t_champ *champ)
{
  int	param_1;

  param_1 = gimme_param_value(champ, champ->cmd, 0, arena);
  if (champ->cmd->type_args[0] == 1)
    param_1 = champ->reg[gimme_reg_nbr(param_1)];
  param_1 = param_1 % 256;
  param_1 = ABS(param_1);
  my_putchar(param_1);
}

int	exec_live(t_champ *tmp, t_champ *champ)
{
  if (tmp->pid == champ->reg[0])
    {
      if (!tmp->father)
	{
	  my_printf("Le joueur %d (%s) est en vie.\n"
		    , tmp->pid, tmp->name);
	  g_winner_id = tmp->pid;
	  g_winner_name = tmp->name;
	}
      tmp->cycle_to_die = 0;
      return (1);
    }
  return (0);
}
