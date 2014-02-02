/*
** my_aff_warning.c for asm in /home/emad_n//v5.00/src/library
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Mon Mar 25 13:13:57 2013 navid emad
** Last update Mon Mar 25 22:49:45 2013 navid emad
*/

#include <stdlib.h>
#include "my.h"

int	my_aff_warning(char *msg)
{
  my_printf("\033[4;33mWarning\033[0;0m: ");
  my_printf("\"\033[4;37m%s\033[0;0m\"\n", msg);
  return (EXIT_FAILURE);
}
