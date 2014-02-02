/*
** my.h for my.h in /home/ninon_s/
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Thu Oct 11 23:20:15 2012 simon ninon
** Last update Sun Mar 31 22:06:05 2013 simon ninon
*/

#ifndef MY_H_
# define MY_H_

# include <sys/types.h>
# include <stdarg.h>

# include "my_printf.h"

void	check_maccros(void);
int	my_getnbr(char *);
void	my_putchar(char);
void	my_put_nbr(int);
int	my_putstr(char *, int);
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
int	my_strlen(char *);
char	*my_strcat(char *, char*);
char	*my_strdup(char *);
char	*my_strndup(char *, int);
char	*my_ustrndup(unsigned char *, int);
void	*my_memset(void *, int, int);
void	my_append(char **, char);
int	my_isnum(char);
int	my_isnum_str(char *);
int	my_isalpha(char);
void	my_trim_comment_end(char *);
char	*my_epur_str(char *);
char	*my_strcpy(char *, char *);
char	**my_str_to_wordtab(char *, char *);
int	my_detect_sep(char, char *);
void	my_free_tab(char **);
int	my_size_tab(char **);
char	*my_trim(char *);
int	my_aff_error(char *, char *, int);
int	my_aff_warning(char *);
int	xopen(char *, int, mode_t);
int	xwrite(int, char *, size_t);
int	xuwrite(int, unsigned char *, size_t);
void	*xmalloc(size_t);
off_t	xlseek(int, off_t, int);

#endif /* !MY_H_ */
