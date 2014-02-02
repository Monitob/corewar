/*
** linked_list.c for VM in /home/emad_n//v16
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Fri Jan 25 17:20:34 2013 navid emad
** Last update Tue Mar 26 20:26:21 2013 simon ninon
*/

#include <stdlib.h>
#include "my.h"
#include "vm_corewar.h"

void		add_elem(t_champ *root)
{
  t_champ	*new_elem;

  new_elem = malloc(sizeof(*new_elem));
  if (new_elem == NULL)
    my_error("Fail malloc");
  new_elem->next = root;
  new_elem->previous = root->previous;
  root->previous->next = new_elem;
  root->previous = new_elem;
}

t_champ		*gimme_root(void)
{
  t_champ	*root;

  root = malloc(sizeof(*root));
  if (root == NULL)
    my_error("Fail malloc");
  root->next = root;
  root->previous = root;
  root->pid = -1;
  return (root);
}

void	remove_elem(t_champ *elem)
{
  if (!elem->father)
    {
      free(elem->comment);
      free(elem->parsing->code_content);
      free(elem->parsing);
    }
  elem->previous->next = elem->next;
  elem->next->previous = elem->previous;
  free(elem->cmd);
  free(elem);
}
