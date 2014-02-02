/*
** my_putchar.c for my_putchar in /home/ninon_s/
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Tue Oct  9 11:28:21 2012 simon ninon
** Last update Thu Jan  3 20:10:15 2013 simon ninon
*/

#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
  (void)write(1, &c, 1);
}
