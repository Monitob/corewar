/*
** battle.h for battle.h in /home/ninon_s//Dropbox/Epitech/current/corewar
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Mon Mar 18 20:34:26 2013 simon ninon
** Last update Tue Mar 26 18:20:40 2013 simon ninon
*/

#ifndef BATTLE_H_
# define BATTLE_H_

/*
** winner name and id
** refresh every live
*/
t_uint	g_winner_id;
char	*g_winner_name;

/*
** next fork pid
*/
t_uint	g_pid;

/*
** battle.c
** important functions relative to the fight
*/
void	battle_begins(int, t_uchar *, t_champ *, t_cycle *);
void	reset_live(t_champ *);
void	remove_main_and_fork(t_champ *, t_champ *);
void	clean(t_champ *, t_cycle *, t_uchar *);

/*
** check.c
** check functions
** check nbr of champions alive
** check instructions to exec
** ...
*/
int	check_round(t_champ *, t_cycle *);
void	check_instructions(t_champ *, t_uchar *);
void	check_cycles(t_champ *, t_uchar *, t_cycle *);
void	exec_instructions(t_champ *, t_uchar *, t_cycle *);

/*
** dump.c
** dump feature
*/
void	convert_base(int, int);
void	dump_memory(t_champ *, t_cycle *, t_uchar *);

/*
** functs_*.c
** functions relative to the instructions
*/
void	live(t_uchar *, t_champ *);
void	load(t_uchar *, t_champ *);
void	store(t_uchar *, t_champ *);
void	add(t_uchar *, t_champ *);
void	sub(t_uchar *, t_champ *);
void	and(t_uchar *, t_champ *);
void	or(t_uchar *, t_champ *);
void	xor(t_uchar *, t_champ *);
void	jump(t_uchar *, t_champ *);
void	load_index(t_uchar *, t_champ *);
void	store_index(t_uchar *, t_champ *);
void	fork_corewar(t_uchar *, t_champ *);
void	long_load(t_uchar *, t_champ *);
void	long_load_index(t_uchar *, t_champ *);
void	long_fork(t_uchar *, t_champ *);
void	aff(t_uchar *, t_champ *);
int	exec_live(t_champ *, t_champ *);

/*
** gimme_value.c
** get value from memory
*/
int	gimme_param_value(t_champ *, t_cmd *, int, t_uchar *);
int	my_pow(int, int);
t_uchar	*new_adress(t_uchar *, t_uchar *);
int	gimme_reg_nbr(int);

/*
** convert.c
** convert value (char[] <-> int)
*/
int		convert_int(t_uchar *, int);
int		convert_int_instruction(t_uchar *, int, t_uchar *);
void		stock_convert_nbr(t_uchar *, t_uchar *, int);
int		convert_int_init(t_uchar *, int);

/*
** convert_negative.c
** same as convert.c but for negative numbers
*/
int	negative_convert_int(t_uchar *, int);
int	negative_convert_int_instruction(t_uchar *, int, t_uchar *);

/*
** gimme_instructions.c
** get instructions from memory
*/
int	specific_function(t_champ *, t_uchar *);
void	gimme_instruction(t_champ *, t_uchar *);

/*
** args.c
** get arguments / instructions from memory
*/
void		gimme_args_type(t_champ *, char *);
void		convert_dec_to_bin(int, char *);
void		gimme_args(t_champ *, t_uchar *);
t_uchar		*malloc_args(int);

#endif /* !BATTLE_H_ */
