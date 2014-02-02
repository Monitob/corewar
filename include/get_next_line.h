/*
** get_next_line.h for get_next_line in /home/ninon_s//Dropbox/Epitech/current/get_next_line/include
**
** Made by simon ninon
** Login   <ninon_s@epitech.net>
**
** Started on  Wed Jan  2 23:08:02 2013 simon ninon
** Last update Thu Jan  3 11:58:20 2013 simon ninon
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# define MAX_READ	1000

/*
** get_next_line.c
*/
char	*get_next_line(int fd);
char	*read_the_fd(int fd, char **fd_buffer);
char	*gimme_good_line(char **fd_buffer);

/*
** buffer.c
*/
int	check_buffer(char *read_buffer);
char	*stock_in_buffer(char *fd_buffer, char *read_buffer);
char	*modif_buffer(char *fd_buffer, int i);

#endif /* !GET_NEXT_LINE_H_ */
