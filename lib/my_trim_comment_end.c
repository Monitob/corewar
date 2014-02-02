/*
** trim_comment_end.c for asm-corewar in /home/emad_n//ASM-Corewar/src/lib
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Sun Feb 24 01:00:37 2013 navid emad
** Last update Wed Mar 27 17:19:29 2013 simon ninon
*/

#include <stdlib.h>
#include "asm_corewar.h"
#include "my.h"

void	my_trim_comment_end(char *content)
{
  int	i;

  i = -1;
  while (content[++i])
    if (content[i] == COMMENT_CHAR)
      {
	content[i] = '\0';
	return ;
      }
}
