/*
** corewar.h for corewar in /home/ninon_s//Dropbox/Epitech/current/corewar/src
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Fri Jan 25 16:53:09 2013 simon ninon
** Last update Tue Mar 26 18:17:27 2013 simon ninon
*/

#ifndef COREWAR_H_
# define COREWAR_H_

# include "op.h"

# define ABS(x)	(((x) < 0) ? -(x) : (x))

typedef unsigned char	t_uchar;
typedef unsigned int	t_uint;

/*
** t_cmd : command parsing
**
** funct : function number
** args  : type of parameters
**
*/
typedef struct		s_cmd
{
  int			funct;
  int			type_args[3];
  t_uchar		args[(IND_SIZE + REG_SIZE + DIR_SIZE) * 4];
}			t_cmd;

/*
** t_parse      : line command parsing
**
** magic        : magic code
** size         : instructions size in memory
** code_content : instructions
**
*/
typedef struct	s_parse
{
  int		magic;
  int		size;
  char		*code_content;
}		t_parse;

/*
** t_champ : champions data
**
** PC      : program counter
** reg     : registers
** cycle   : nb of cycles left (0 == check, 1 == exec, 2+ == wait)
** cycle_to_die : nb of cycles left to make a live
** father  : pid of the father
** pid     : champions pid
**
*/
typedef struct		s_champ
{
  t_uint		father;
  t_uint		pid;
  int			carry;
  char			*name;
  char			*comment;
  t_uchar		*PC;
  t_cmd			*cmd;
  t_uint       		reg[REG_NUMBER];
  int			cycle;
  int			cycle_to_die;
  t_parse		*parsing;
  struct s_champ	*next;
  struct s_champ	*previous;
}			t_champ;

/*
** t_data     : fight data
*/
typedef struct		s_cycle
{
  int			nbr_live;
  int			cycle_to_die;
  int			current_cycle;
}			t_cycle;


/*
** t_tab
** function ptr and cycles
*/
typedef struct		s_tab
{
  int			cycles;
  void			(*function)(t_uchar *, t_champ *);
}			t_tab;

# include "battle.h"
# include "init.h"

/*
** main.c
*/
void		corewar(int, char **);
void		my_error(char *);

#endif /* !COREWAR_H_ */
