/*
** my_isnum.c for asm-corewar in /home/emad_n//ASM-Corewar/src/lib
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Sun Feb 24 01:40:46 2013 navid emad
** Last update Sun Feb 24 16:58:59 2013 navid emad
*/

int	my_isnum(char ch)
{
  return ((ch >= '0' && ch <= '9') ? 1 : 0);
}

int	my_isnum_str(char *str)
{
  int	i;

  i = (str[0] == '-');
  while (str[i] != '\0')
    {
      if ('0' > str[i] || str[i] > '9')
	return (0);
      i += 1;
    }
  return (1);
}
