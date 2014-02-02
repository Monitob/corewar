/*
** corewar.h for init_h in /home/ninon_s//Dropbox/Epitech/current/corewar
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Mon Mar 18 20:35:54 2013 simon ninon
** Last update Sun Mar 31 21:52:13 2013 navid emad
*/

#ifndef COREWAR_H_
# define COREWAR_H_

# include "op.h"

/*
** .cor define cursor
*/
# define CURSOR_MAGIC	(0)
# define CURSOR_NAME	(CURSOR_MAGIC + 4)
# define CURSOR_SIZE	(CURSOR_NAME + PROG_NAME_LENGTH)
# define CURSOR_COMMENT	(CURSOR_SIZE + 8)

/*
** define for more visibility
*/
# define OP_LIVE (0)
# define OP_ZJMP (8)
# define OP_STI (10)
# define OP_FORK (11)
# define OP_LFORK (14)

/*
** structure
*/
typedef struct	s_data
{
  char		*content;
  int		line_number;
  struct s_data	*previous;
  struct s_data	*next;
}		t_data;

/*
** src/verif/verif_file.c
** check file validity
*/
int	verif_ext(char *file_name);
int	verif_empty_and_if_is_exe(char *file_name);

/*
** src/verif/verif_label.c
** check label validity
*/
void	check_label_call(t_data *root, t_data *label);

/*
** src/parser/linked_list.c
** linked list double circular for parsing
*/
t_data	*gimme_root(void);
t_data	*add_to_list(t_data *elem, char *content, int line_number);
int	stock_data(t_data *root, int fd);
void	aff_list(t_data *root);
void	free_all(t_data *root);

/*
** src/parser/check_line.c
** check directives and char in line
*/
int	check_directives(char *content, int line_number);
int	sort_directives(char *content);
int	check_all_chars(char *content, int line_number);

/*
** src/parser/error_display.c
** display error with some colorations
*/
void	aff_error(char *msg, char *content, int line_number);
void	aff_warning(char *msg);

/*
** src/parser/stock_label.c
** stock label name
*/
void	stock_label_define(t_data *root, t_data *label);
int	detect_label(char *str);

/*
** src/parser/stock_header.c
** stock name, comment
*/
int	stock_header(struct header_s *data, t_data *root);

/*
** src/generate/gen_corfile.c
** convert parsed buffer to a .cor file with a norme
*/
void	gen_corfile(char *file_name,  header_t *data, t_data *root);
char	gimme_type(char **tab, int i, int op_code, char *line_content);

/*
** src/generate/append_corfile.c
** insert functions
*/
int	xwrite_lookatsize(int fd, void *buf, size_t count);
void	append_int(int fd, int number, int state);
void	append_short_int(int fd, short int number, int state);
void	append_string(int fd, char *string, int len);

/*
** src/generate/instructions.c
** insert functions
*/
void	handler_instruction(int fd, int op_code, char *line_content);

#endif /* !COREWAR_H_ */
