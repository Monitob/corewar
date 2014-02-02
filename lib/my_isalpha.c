/*
** my_isalpha.c for asm-corewar in /home/emad_n//ASM-Corewar/src/lib
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Sun Feb 24 01:33:45 2013 navid emad
** Last update Sun Feb 24 01:36:26 2013 navid emad
*/

int	my_isalpha(char ch)
{
  return ((ch < 'A' || (ch > 'Z' && ch < 'a') || ch > 'z') ? 0 : 1);
}
