/*
** my_strcat_malloc.c for Corewar in corewar/ASM/v3/src/lib
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Thu Mar 14 01:26:18 2013 navid emad
** Last update Sat Mar 23 04:37:07 2013 navid emad
*/

#include <stdlib.h>
#include "my.h"

void	my_append(char **str, char c)
{
  int	len;

  len = my_strlen(*str);
  if (!(*str = realloc(*str, len + 2)))
    exit(1);
  (*str)[len] = c;
  (*str)[len + 1] = '\0';
}
