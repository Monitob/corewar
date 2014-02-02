/*
** functs_2.c for corewar in /home/ninon_s//Dropbox/Epitech/current/corewar/src/battle
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Wed Jan 30 14:57:16 2013 simon ninon
** Last update Tue Mar 26 20:24:57 2013 simon ninon
*/

#include <stdio.h>
#include "vm_corewar.h"

void	and(t_uchar *arena, t_champ *champ)
{
  int	param_1;
  int	param_2;
  int	param_3;

  param_1 = gimme_param_value(champ, champ->cmd, 0, arena);
  param_2 = gimme_param_value(champ, champ->cmd, 1, arena);
  param_3 = gimme_param_value(champ, champ->cmd, 2, arena);
  if (champ->cmd->type_args[0] == 1)
    param_1 = champ->reg[gimme_reg_nbr(param_1)];
  if (champ->cmd->type_args[1] == 1)
    param_2 = champ->reg[gimme_reg_nbr(param_2)];
  param_3 = gimme_reg_nbr(param_3);
  champ->carry = (param_1 & param_2) ? 0 : 1;
  champ->reg[param_3] = param_1 & param_2;
}

void	or(t_uchar *arena, t_champ *champ)
{
  int	param_1;
  int	param_2;
  int	param_3;

  param_1 = gimme_param_value(champ, champ->cmd, 0, arena);
  param_2 = gimme_param_value(champ, champ->cmd, 1, arena);
  param_3 = gimme_param_value(champ, champ->cmd, 2, arena);
  if (champ->cmd->type_args[0] == 1)
    param_1 = champ->reg[gimme_reg_nbr(param_1)];
  if (champ->cmd->type_args[1] == 1)
    param_2 = champ->reg[gimme_reg_nbr(param_2)];
  param_3 = gimme_reg_nbr(param_3);
  champ->carry = (param_1 | param_2) ? 0 : 1;
  champ->reg[param_3] = param_1 | param_2;
}

void	xor(t_uchar *arena, t_champ *champ)
{
  int	param_1;
  int	param_2;
  int	param_3;

  param_1 = gimme_param_value(champ, champ->cmd, 0, arena);
  param_2 = gimme_param_value(champ, champ->cmd, 1, arena);
  param_3 = gimme_param_value(champ, champ->cmd, 2, arena);
  if (champ->cmd->type_args[0] == 1)
    param_1 = champ->reg[gimme_reg_nbr(param_1)];
  if (champ->cmd->type_args[1] == 1)
    param_2 = champ->reg[gimme_reg_nbr(param_2)];
  param_3 = gimme_reg_nbr(param_3);
  champ->carry = (param_1 ^ param_2) ? 0 : 1;
  champ->reg[param_3] = param_1 ^ param_2;
}

void		jump(t_uchar *arena, t_champ *champ)
{
  int		result;

  if (champ->carry == 0)
    return ;
  result = convert_int(champ->cmd->args, champ->cmd->type_args[0]);
  champ->PC = new_adress(champ->PC + result, arena);
}

void	load_index(t_uchar *arena, t_champ *champ)
{
  int		param_1;
  int		param_2;
  int		param_3;
  t_uchar	*tmp;
  int		value;

  param_1 = gimme_param_value(champ, champ->cmd, 0, arena);
  param_2 = gimme_param_value(champ, champ->cmd, 1, arena);
  param_3 = gimme_param_value(champ, champ->cmd, 2, arena);
  if (champ->cmd->type_args[0] == 1)
    param_1 = champ->reg[gimme_reg_nbr(param_1)];
  if (champ->cmd->type_args[1] == 1)
    param_2 = champ->reg[gimme_reg_nbr(param_2)];
  tmp = champ->PC + param_1 % IDX_MOD;
  tmp = new_adress(tmp, arena);
  value = convert_int_instruction(tmp, IND_SIZE, arena) + param_2;
  tmp = champ->PC + value % IDX_MOD;
  tmp = new_adress(tmp, arena);
  param_3 = gimme_reg_nbr(param_3);
  value = convert_int_instruction(tmp, REG_SIZE, arena);
  champ->carry = value ? 0 : 1;
  champ->reg[param_3] = value;
}
