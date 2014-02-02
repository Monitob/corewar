/*
** flags.c for my_printf in /home/ninon_s/Dropbox/Epitech/Makefile/lib/my
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Wed Mar  6 23:43:36 2013 simon ninon
** Last update Sun Mar 31 21:54:20 2013 navid emad
*/

#include <stdlib.h>
#include "my_printf.h"
#include "my.h"

t_color	g_color_tab[10] =
  {
    {"RED", RED},
    {"CYAN", CYAN},
    {"GREEN", GREEN},
    {"BLACK", BLACK},
    {"YELLOW", YELLOW},
    {"BLUE", BLUE},
    {"PURPLE", PURPLE},
    {"GREY", GREY},
    {"WHITE", WHITE},
    {NULL, NULL}
  };

void	aff_char(va_list ap)
{
  my_putchar((char)va_arg(ap, int));
}

void	aff_str(va_list ap)
{
  char	*str;

  str = va_arg(ap, char *);
  if (str)
    my_putstr(str, 1);
}

void	aff_nbr(va_list ap)
{
  my_put_nbr(va_arg(ap, int));
}

void	aff_color(va_list ap)
{
  int	i;
  char	*color;

  i = 0;
  color = va_arg(ap, char *);
  while (g_color_tab[i].color &&
	 !my_strncmp(g_color_tab[i].color, color, my_strlen(color)))
    i++;
  if (g_color_tab[i].color)
    my_putstr(g_color_tab[i].code, 1);
}
