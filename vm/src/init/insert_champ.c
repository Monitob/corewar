/*
** insertion_champ.c for VM in /home/emad_n//v16/src/init
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Wed Mar 20 01:17:39 2013 navid emad
** Last update Tue Mar 26 20:26:08 2013 simon ninon
*/

#include "vm_corewar.h"
#include "my_printf.h"

/*
** Calcule la somme de taille de chaque champion
** @int sum
*/
static int	sum_mem_champions(t_champ *champ)
{
  t_champ	*tmp;
  int		sum;

  tmp = champ->next->next;
  sum = 0;
  while (tmp != champ)
    {
      sum += tmp->parsing->size;
      tmp = tmp->next;
    }
  return (sum);
}

/*
** Calcule le nombre de champions à traiter
** @int count
*/
static int	gimme_count_champs(t_champ *champ)
{
  t_champ	*tmp;
  int		count;

  tmp = champ->next;
  count = 0;
  while (tmp != champ)
    {
      count += 1;
      tmp = tmp->next;
    }
  return (count);
}

/*
** Place le contenu du chamion dans l'arène
** @void
*/
static void	put_to_memory(t_champ *champ)
{
  int		i;

  i = 0;
  while (i < champ->parsing->size && i < MEM_SIZE)
    {
      champ->PC[i] = champ->parsing->code_content[i];
      i = i + 1;
    }
}

static void	place_others_champions(t_champ *champ, t_uchar *arena)
{
  t_champ	*tmp;
  int		position;
  int		mem_left;
  int		margin;
  int		sum_memory_champs;

  position = 0;
  tmp = champ->next;
  mem_left = MEM_SIZE - tmp->parsing->size;
  sum_memory_champs = sum_mem_champions(champ);
  if (sum_memory_champs > mem_left)
    my_error("Error: pas assez de mémoire de libre.\n");
  margin = ((mem_left - sum_memory_champs) / gimme_count_champs(champ));
  tmp = tmp->next;
  while (tmp != champ)
    {
      position += (margin + tmp->previous->parsing->size);
      tmp->PC = &(arena[position]);
      put_to_memory(tmp);
      tmp = tmp->next;
    }
}

/*
** Placement des champions le plus éloignés les uns des autres
** On place le 1er champion à 0 jusqu'à champ->size
** Puis, on calcule la mémoire libre
** On déduit de cette mémoire libre, la somme de la taille de tous les champs
** Margin idéal vaut alors cette mémoire restante / nbr de champions
** On boucle sur les champions en les décalant à chaque fois de ce Margin
** @void
*/
void		insert_champions_in_arena(t_champ *champ, t_uchar *arena)
{
  t_champ	*tmp;

  tmp = champ->next;
  tmp->PC = &(arena[0]);
  put_to_memory(tmp);
  if (tmp->next != champ)
    place_others_champions(champ, arena);
}
