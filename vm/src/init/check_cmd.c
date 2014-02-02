/*
** check_cmd.c for VM in /home/ninon_s//Dropbox/Epitech/current/corewar/src
**
** Made by navid emad
** Login   <emad_n@epitech.net>
**
** Started on  Fri Jan 25 23:30:29 2013 navid emad
** Last update Tue Mar 26 20:38:36 2013 simon ninon
*/

#include <stdlib.h>
#include "my.h"
#include "vm_corewar.h"

static void	cmd_error(char *error)
{
  my_printf("Error: wrong parameters (%s)\n", error);
  exit(-1);
}

static int	check_a(int ac, char **av, int i)
{
  int		adress;

  if (my_strcmp(av[i], "-a"))
    return (i);
  if (i + 2 < ac)
    {
      adress = my_getnbr(av[i + 1]);
      if (adress < 0 || adress > MEM_SIZE - 1)
	cmd_error("invalid adress position in memory");
      i += 2;
    }
  else
    cmd_error("number of arguments is wrong");
  return (i);
}

static int	check_n(int ac, char **av, int i)
{
  int		numero_champ;
  static char	champion_state[] = "0000";

  if (my_strcmp(av[i], "-n"))
    return (i);
  if (i + 2 < ac)
    {
      numero_champ = my_getnbr(av[i + 1]);
      if (numero_champ <= 0 || numero_champ > 4)
	cmd_error("numero of champion must be between 1 and 4");
      if (champion_state[numero_champ - 1] == '1')
	cmd_error("cannot take twice number of champions");
      champion_state[numero_champ - 1] = '1';
      i += 2;
    }
  else
    cmd_error("number of arguments is wrong");
  return (i);
}

int		check_cor(char **av, int i)
{
  static int	nb_champ;
  int		size;

  size = my_strlen(av[i]);
  if (size < 4)
    cmd_error("invalid file format");
  else if (my_strcmp(&(av[i][size - 4]), ".cor"))
    cmd_error("invalid file format");
  nb_champ++;
  if (nb_champ > 4)
    cmd_error("corewar cannot played with more than 4 players");
  return (i + 1);
}

int	check_cmd(int ac, char **av)
{
  int	i;
  int	cycles;

  i = 1;
  cycles = -1;
  if (!my_strcmp(av[i], "-dump"))
    {
      if (i + 2 < ac)
	{
	  cycles = my_getnbr(av[i + 1]);
	  if (cycles <= 0)
	    cmd_error("cycles must be strictly positive if inserted");
	  i += 2;
	}
      else
	cmd_error("number of arguments is wrong");
    }
  while (i < ac)
    {
      i = check_n(ac, av, i);
      i = check_a(ac, av, i);
      i = check_cor(av, i);
    }
  return (cycles);
}
