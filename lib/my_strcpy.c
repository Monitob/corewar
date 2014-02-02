/*
** my_strcpy.c for a in /home/emad_n//v5.00/lib/my
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Sat Mar 23 04:45:45 2013 navid emad
** Last update Sat Mar 23 04:45:45 2013 navid emad
*/

#include <stdlib.h>

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  if (!dest || !src)
    return (NULL);
  i = -1;
  while (src[++i])
    dest[i] = src[i];
  dest[i] = 0x00;
  return (dest);
}
