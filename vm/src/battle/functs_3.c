/*
** functs_3.c for corewar in /home/ninon_s//Dropbox/Epitech/current/corewar/src/battle
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Wed Jan 30 14:57:43 2013 simon ninon
** Last update Tue Mar 26 20:25:03 2013 simon ninon
*/

#include <stdlib.h>
#include <stdio.h>
#include "vm_corewar.h"

void		store_index(t_uchar *arena, t_champ *champ)
{
  int		param_1;
  int		param_2;
  int		param_3;
  t_uchar	*tmp;

  param_1 = gimme_param_value(champ, champ->cmd, 0, arena);
  param_2 = gimme_param_value(champ, champ->cmd, 1, arena);
  param_3 = gimme_param_value(champ, champ->cmd, 2, arena);
  param_1 = champ->reg[gimme_reg_nbr(param_1)];
  if (champ->cmd->type_args[1] == 1)
    param_2 = champ->reg[gimme_reg_nbr(param_2)];
  if (champ->cmd->type_args[2] == 1)
    param_3 = champ->reg[gimme_reg_nbr(param_3)];
  tmp = champ->PC + (param_2 + param_3) % IDX_MOD;
  tmp = new_adress(tmp, arena);
  stock_convert_nbr(tmp, arena, param_1);
}

void	fork_corewar(t_uchar *arena, t_champ *champ)
{
  int	i;
  int	param_1;

  i = 1;
  if (champ->father > 0)
    return ;
  param_1 = convert_int(champ->cmd->args, 2) % IDX_MOD;
  add_elem(champ);
  champ->previous->PC = new_adress(champ->PC + param_1, arena);
  champ->previous->reg[0] = g_pid;
  champ->previous->pid = g_pid++;
  while (i < REG_NUMBER)
    champ->previous->reg[i] = champ->reg[i++];
  champ->previous->cycle = 0;
  champ->previous->carry = champ->carry;
  champ->previous->father = champ->pid;
  champ->previous->cycle_to_die = champ->cycle_to_die;
  champ->previous->cmd = malloc(sizeof(*(champ->previous->cmd)));
  if (champ->previous->cmd == NULL)
    my_error("Fail malloc()");
  champ->previous->cmd->type_args[0] = 0;
  champ->previous->cmd->type_args[1] = 0;
  champ->previous->cmd->type_args[2] = 0;
}

void	long_load(t_uchar *arena, t_champ *champ)
{
  int	param_1;
  int	param_2;

  param_1 = gimme_param_value(champ, champ->cmd, 0, arena);
  param_2 = gimme_param_value(champ, champ->cmd, 1, arena);
  param_2 = gimme_reg_nbr(param_2);
  champ->carry = param_1 ? 0 : 1;
  champ->reg[param_2] = param_1;
}

void		long_load_index(t_uchar *arena, t_champ *champ)
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
  tmp = champ->PC + param_1;
  tmp = new_adress(tmp, arena);
  value = convert_int_instruction(tmp, IND_SIZE, arena) + param_2;
  tmp = champ->PC + value;
  tmp = new_adress(tmp, arena);
  param_3 = gimme_reg_nbr(param_3);
  value = convert_int_instruction(tmp, REG_SIZE, arena);
  champ->carry = value ? 0 : 1;
  champ->reg[param_3] = value;
}

void	long_fork(t_uchar *arena, t_champ *champ)
{
  int	i;
  int	param_1;

  i = 1;
  param_1 = convert_int(champ->cmd->args, 2);
  champ->carry = param_1 ? 0 : 1;
  add_elem(champ);
  champ->previous->PC = new_adress(champ->PC + param_1, arena);
  champ->previous->reg[0] = g_pid;
  champ->previous->pid = g_pid++;
  while (i < REG_NUMBER)
    champ->previous->reg[i] = champ->reg[i++];
  champ->previous->cycle = 0;
  champ->previous->carry = champ->carry;
  champ->previous->father = champ->pid;
  champ->previous->cycle_to_die = champ->cycle_to_die;
  champ->previous->cmd = malloc(sizeof(*(champ->previous->cmd)));
  if (champ->previous->cmd == NULL)
    my_error("Fail malloc()");
  champ->previous->cmd->type_args[0] = 0;
  champ->previous->cmd->type_args[1] = 0;
  champ->previous->cmd->type_args[2] = 0;
}
