/*
** args.c for corewar in /home/ninon_s//Dropbox/Epitech/current/corewar/src/battle
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Fri Mar 15 13:44:58 2013 simon ninon
** Last update Tue Mar 26 20:23:49 2013 simon ninon
*/

#include <stdlib.h>
#include "vm_corewar.h"

void	gimme_args_type(t_champ *champ, char *args_type)
{
  int	i;

  i = 0;
  while (i < 5)
    {
      if (args_type[i] || args_type[i + 1])
	{
	  if (args_type[i] && args_type[i + 1])
	    champ->cmd->type_args[i / 2] = IND_SIZE;
	  else if (args_type[i])
	    champ->cmd->type_args[i / 2] = DIR_SIZE;
	  else if (args_type[i + 1])
	    champ->cmd->type_args[i / 2] = T_REG;
	  else
	    champ->cmd->type_args[i / 2] = 0;
	}
      i += 2;
    }
}

void	convert_dec_to_bin(int nbr, char *args_type)
{
  int	i;

  i = 7;
  while (i >= 0)
    {
      args_type[i--] = nbr % 2;
      nbr /= 2;
    }
}

void		gimme_args(t_champ *champ, t_uchar *arena)
{
  int		i;
  int		size;
  t_uchar	*tmp;

  size = champ->cmd->type_args[0] + champ->cmd->type_args[1];
  size += champ->cmd->type_args[2];
  i = -1;
  while (++i < size)
    {
      tmp = new_adress(champ->PC + 2 + i, arena);
      champ->cmd->args[i] = tmp[0];
    }
}
