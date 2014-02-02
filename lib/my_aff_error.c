/*
** my_aff_error.c for asm in /home/emad_n//v5.00/src/library
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Mon Mar 25 00:16:31 2013 navid emad
** Last update Mon Mar 25 20:48:23 2013 navid emad
*/

#include <stdlib.h>
#include "my.h"

int	my_aff_error(char *msg, char *content, int line_number)
{
  my_printf("\033[4;31mError\033[1;31m: \033[0;33m");
  my_printf("Syntax error for \"\033[4;33m%s\033[0;33m\"", msg);
  my_printf("\033[1;34m @ ");
  my_printf("\033[4;37mline #%d below\033[0;37m :\n", line_number);
  my_printf("\033[1;36m%s\033[0m\n", content);
  return (EXIT_FAILURE);
}

