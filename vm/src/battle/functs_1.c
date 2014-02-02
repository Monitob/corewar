/*
** functs_1.c for corewar in /home/ninon_s//Dropbox/Epitech/current/corewar/src/battle
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Wed Jan 30 14:56:42 2013 simon ninon
** Last update Tue Mar 26 20:24:51 2013 simon ninon
*/

#include <stdio.h>
#include "vm_corewar.h"

void		live(t_uchar *arena, t_champ *champ)
{
  t_champ	*tmp;

  tmp = champ;
  if (exec_live(tmp, champ))
    return ;
  tmp = tmp->next;
  while (tmp != champ)
    {
      if (exec_live(tmp, champ))
	return ;
      tmp = tmp->next;
    }
}

void	load(t_uchar *arena, t_champ *champ)
{
  int	param_1;
  int	param_2;

  param_1 = gimme_param_value(champ, champ->cmd, 0, arena);
  param_2 = gimme_param_value(champ, champ->cmd, 1, arena);
  param_2 = gimme_reg_nbr(param_2);
  champ->carry = param_1 ? 0 : 1;
  champ->reg[param_2] = param_1;
}

void	store(t_uchar *arena, t_champ *champ)
{
  int	param_1;
  int	param_2;

  param_1 = gimme_param_value(champ, champ->cmd, 0, arena);
  param_2 = gimme_param_value(champ, champ->cmd, 1, arena);
  if (champ->cmd->type_args[0] == 1)
    param_1 = champ->reg[gimme_reg_nbr(param_1)];
  if (champ->cmd->type_args[1] == 1)
    champ->reg[gimme_reg_nbr(param_2)] = param_1;
  else if (champ->cmd->type_args[1] == 2)
    {
      param_2 = convert_int(champ->cmd->args + champ->cmd->type_args[0], 2);
      stock_convert_nbr(champ->PC + param_2, arena, param_1);
    }
}

void	add(t_uchar *arena, t_champ *champ)
{
  int	param_1;
  int	param_2;
  int	param_3;

  param_1 = gimme_param_value(champ, champ->cmd, 0, arena);
  param_2 = gimme_param_value(champ, champ->cmd, 1, arena);
  param_3 = gimme_param_value(champ, champ->cmd, 2, arena);
  param_1 = champ->reg[gimme_reg_nbr(param_1)];
  param_2 = champ->reg[gimme_reg_nbr(param_2)];
  param_3 = gimme_reg_nbr(param_3);
  champ->carry = (param_1 + param_2) ? 0 : 1;
  champ->reg[param_3] = param_1 + param_2;
}

void	sub(t_uchar *arena, t_champ *champ)
{
  int	param_1;
  int	param_2;
  int	param_3;

  param_1 = gimme_param_value(champ, champ->cmd, 0, arena);
  param_2 = gimme_param_value(champ, champ->cmd, 1, arena);
  param_3 = gimme_param_value(champ, champ->cmd, 2, arena);
  param_1 = champ->reg[gimme_reg_nbr(param_1)];
  param_2 = champ->reg[gimme_reg_nbr(param_2)];
  param_3 = gimme_reg_nbr(param_3);
  champ->carry = (param_1 - param_2) ? 0 : 1;
  champ->reg[param_3] = param_1 - param_2;
}
