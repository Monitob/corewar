/*
** init_structs.c for VM in /home/emad_n//v16/src
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Wed Mar 20 01:27:44 2013 navid emad
** Last update Tue Mar 26 20:26:16 2013 simon ninon
*/

#include <stdlib.h>
#include "my_printf.h"
#include "vm_corewar.h"

t_uchar		*init_arena(void)
{
  int		i;
  t_uchar	*arena;

  i = 0;
  arena = malloc(MEM_SIZE * sizeof(unsigned char));
  if (arena == NULL)
    my_error("Fail malloc()");
  while (i < MEM_SIZE)
    arena[i++] = 0;
  return (arena);
}

t_cycle		*init_cycles(void)
{
  t_cycle	*cycles;

  cycles = malloc(sizeof(*cycles));
  if (cycles == NULL)
    my_error("Fail malloc()");
  cycles->nbr_live = 0;
  cycles->cycle_to_die = CYCLE_TO_DIE;
  cycles->current_cycle = 1;
  return (cycles);
}

void		init_champ(t_champ *champ, int id)
{
  int		i;

  i = 1;
  champ->reg[0] = id;
  champ->pid = id;
  champ->father = 0;
  while (i < REG_NUMBER)
    champ->reg[i++] = 0;
  champ->cycle = 0;
  champ->cycle_to_die = 0;
  champ->carry = 0;
  champ->cmd = malloc(sizeof(*(champ->cmd)));
  champ->parsing->code_content = malloc(MEM_SIZE);
  if (champ->cmd == NULL || champ->parsing->code_content == NULL)
    my_error("Fail malloc()");
  champ->cmd->type_args[0] = 0;
  champ->cmd->type_args[1] = 0;
  champ->cmd->type_args[2] = 0;
}

t_champ		*gimme_champ(int ac, char **av, t_uchar *arena)
{
  t_champ	*root;

  root = gimme_root();
  get_data_champions(ac, av, root);
  insert_champions_in_arena(root, arena);
  return (root);
}
