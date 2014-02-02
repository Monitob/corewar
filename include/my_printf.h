/*
** printf.h for printf in /home/ninon_s//printf
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Thu Nov 15 19:48:53 2012 simon ninon
** Last update Sun Mar 31 21:53:10 2013 navid emad
*/

#ifndef _PRINTF_H_
# define _PRINTF_H_

#include <stdarg.h>

# define RED	"\033[1;31m"
# define CYAN	"\033[1;36m"
# define GREEN	"\033[1;32m"
# define BLACK	"\033[1;30m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define PURPLE	"\033[1;35m"
# define GREY	"\033[1;37m"
# define WHITE	"\033[0m"

typedef void	(*ptr_funct)(va_list);

typedef struct	s_color
{
  char		*color;
  char		*code;
}		t_color;

/*
** my_printf.c
*/
void		my_printf(char *, ...);
char		*gimme_flags_tab(void);
ptr_funct	*gimme_ptr_funct(void);
void		check_flag(char *str, va_list ap,
			   ptr_funct *functions, char *flags_tab);

/*
** flags.c
*/
void	aff_char(va_list);
void	aff_str(va_list);
void	aff_nbr(va_list);
void	aff_color(va_list);

#endif /* !_PRINTF_H_ */
