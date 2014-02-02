/*
** my_memset.c
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Sun Jan 20 17:34:42 2013 navid emad
** Last update Sat Mar 23 04:31:31 2013 navid emad
*/

void	*my_memset(void *ptr, int value, int size)
{
  int	i;
  char	*itr;

  itr = (char*)ptr;
  i = 0;
  while (i < size)
    itr[i++] = (char)value;
  return (ptr);
}
