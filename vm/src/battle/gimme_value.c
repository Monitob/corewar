/*
** gimme_value.c for corewar in /home/ninon_s/Dropbox/Epitech/current/corewar
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Mon Mar 11 17:12:15 2013 simon ninon
** Last update Tue Mar 26 20:25:24 2013 simon ninon
*/

#include "vm_corewar.h"

int	my_pow(int nb, int exp)
{
  int	i;
  int	result;

  i = 0;
  result = 1;
  while (i++ < exp)
    result *= nb;
  return (result);
}

t_uchar		*new_adress(t_uchar *wanted, t_uchar *arena)
{
  t_uchar	*new;

  new = wanted;
  if ((long)new >= (long)arena + MEM_SIZE)
    {
      new = (t_uchar *)((long)new - (long)arena);
      new = (t_uchar *)((long)new % (long)MEM_SIZE);
      new = (t_uchar *)((long)new + (long)arena);
    }
  else if ((long)new < (long)arena)
    {
      new = (t_uchar *)((long)new % (long)MEM_SIZE);
      new = (t_uchar *)((long)new + (long)arena);
    }
  return (new);
}

int	gimme_reg_nbr(int reg)
{
  reg -= 1;
  reg = ((reg >= 0) ? reg : -reg);
  reg = reg % REG_NUMBER;
  return (reg);
}

int		gimme_param_value(t_champ *champ, t_cmd *cmd,
				  int arg, t_uchar *arena)
{
  int		i;
  int		place;
  t_uchar	*tmp;

  i = 0;
  place = 0;
  while (i < arg)
    place += cmd->type_args[i++];
  if (cmd->type_args[arg] == 1)
    return (cmd->args[place]);
  else if (cmd->type_args[arg] == 4)
    return (convert_int(cmd->args + place, cmd->type_args[arg]));
  else
    {
      i = convert_int(cmd->args + place, cmd->type_args[arg]);
      if (cmd->funct > 12)
	tmp = champ->PC + i;
      else
	tmp = champ->PC + (i % IDX_MOD);
      tmp = new_adress(tmp, arena);
      return (convert_int_instruction(tmp, 4, arena));
    }
}
