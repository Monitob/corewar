/*
** init.h for init_h in /home/ninon_s//Dropbox/Epitech/current/corewar
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Mon Mar 18 20:35:54 2013 simon ninon
** Last update Tue Mar 26 20:30:50 2013 simon ninon
*/

#ifndef INIT_H_
# define INIT_H_

/*
** .cor define cursor
*/
# define READ_SIZE	(4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH + 4)
# define CURSOR_MAGIC	(0)
# define CURSOR_NAME	(CURSOR_MAGIC + 4)
# define CURSOR_SIZE	(CURSOR_NAME + PROG_NAME_LENGTH)
# define CURSOR_COMMENT	(CURSOR_SIZE + 8)

/*
** init_structs.c
** init variables of cycles, champ, arena struct
*/
t_champ		*gimme_champ(int, char **, t_uchar *);
void		init_champ(t_champ *, int);
t_uchar		*init_arena(void);
t_cycle		*init_cycles(void);

/*
** data_champ.c
** store file informations, and option -n
*/
void		get_data_champions(int, char **, t_champ *);

/*
** insert_champ.c
** place champion in the best place in arena, and option -a
*/
void		insert_champions_in_arena(t_champ *, t_uchar *);

/*
** check_cmd.c
** check if cmd is good
*/
int		check_cmd(int, char **);

/*
** linked_list.c
** create / edit linked list
*/
t_champ		*gimme_root(void);
void		add_elem(t_champ *);
void		remove_elem(t_champ *);

#endif /* !INIT_H_ */
