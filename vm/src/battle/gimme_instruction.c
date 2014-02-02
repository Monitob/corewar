/*
** gimme_instruction.c for corewar in /home/ninon_s//Dropbox/Epitech/current/corewar/src/battle
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Wed Feb 20 14:39:49 2013 simon ninon
** Last update Tue Mar 26 20:25:19 2013 simon ninon
*/

#include <stdlib.h>
#include "vm_corewar.h"

int		specific_function(t_champ *champ, t_uchar *arena)
{
  t_uchar	*tmp;

  if (champ->cmd->funct == 1)
    champ->cmd->type_args[0] = 4;
  else if (champ->cmd->funct == 9)
    {
      champ->cmd->type_args[0] = 2;
      tmp = new_adress(champ->PC + 1, arena);
      champ->cmd->args[0] = tmp[0];
      tmp = new_adress(champ->PC + 2, arena);
      champ->cmd->args[1] = tmp[0];
    }
  else if (champ->cmd->funct == 12 || champ->cmd->funct == 15)
    {
      champ->cmd->type_args[0] = 2;
      tmp = new_adress(champ->PC + 1, arena);
      champ->cmd->args[0] = tmp[0];
      tmp = new_adress(champ->PC + 2, arena);
      champ->cmd->args[1] = tmp[0];
    }
  else
    return (0);
  return (1);
}

void		gimme_instruction(t_champ *champ, t_uchar *arena)
{
  t_uchar	*tmp;
  char		args_type[8];

  champ->cmd->funct = champ->PC[0];
  if (specific_function(champ, arena))
    return ;
  tmp = new_adress(champ->PC + 1, arena);
  convert_dec_to_bin(tmp[0], args_type);
  gimme_args_type(champ, args_type);
  gimme_args(champ, arena);
}
