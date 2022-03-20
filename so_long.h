/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasi-moh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:46:59 by fasi-moh          #+#    #+#             */
/*   Updated: 2021/11/24 18:47:00 by fasi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "mlx/mlx.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_struct
{
	char		**map;
	void		*mlx;
	void		*win;
	void		*i_p1;
	void		*i_collect;
	void		*i_exit;
	void		*wall;
	void		*floor;
	int			nb_char;
	int			line;
	int			collec;
	int			player;
	int			exit;
	int			cmoove;
}		t_struct;

void		write_error_arg(int ac, char **av, int file);
void		free_str(char **str);
void		write_error_game(int error, t_struct game, char **str);
void		write_error_map(int error, char **str);
void		check_wall(char **str, int nb_line);
void		check_line_len(char **str, int nb_line, int lenstr);
void		check_line_first_end(char **str, int nb_line);
void		free_end(t_struct game);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strchr(const char *s, int c);
char		**ft_split(char *str, char c);
char		*ft_strcat(char *dest, char *src);
char		*ft_strdup(const char *s);
char		*ft_strjoin_free(char *s1, char *s2);
int			ft_strlen(const char *s);
int			nb_line_map(char **str);
int			boucle(char **stock, int fd, int ret);
int			get_next_line(int fd, char **line);
int			mouse_hook(t_struct *game);
int			keyboard_touch(int keycode, t_struct *game);
void		put_collectible_on_map(t_struct game);
void		put_exit_on_map(t_struct game);
void		put_player_on_map(t_struct game);
void		put_floor_on_map(t_struct game);
void		put_wall_on_map(t_struct game);
void		aff_struct(t_struct pos);
t_struct	check_cpe(char **str, int nb_line, t_struct pos);
t_struct	ft_init(t_struct pos);
t_struct	recup_map(int fd);
t_struct	manage_texture(t_struct game);
t_struct	start_window(t_struct game);
t_struct	touch_d(t_struct game);
t_struct	touch_a(t_struct game);
t_struct	touch_w(t_struct game);
t_struct	touch_s(t_struct game);
t_struct	do_moove_s(t_struct game);
t_struct	do_moove_w(t_struct game);
t_struct	do_moove_a(t_struct game);
t_struct	do_moove_d(t_struct game);

#endif