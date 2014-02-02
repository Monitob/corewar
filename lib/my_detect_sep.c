/*
** my_detect_sep.c for asm in /home/emad_n//v5.00/src/library
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Sun Mar 24 22:07:56 2013 navid emad
** Last update Tue Mar 26 15:04:32 2013 navid emad
*/

int	my_detect_sep(char ch, char *tokens)
{
  int	i;

  i = 0;
  while (tokens && tokens[i])
    if (tokens[i++] == ch)
      return (1);
  return (0);
}
