/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasi-moh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:44:00 by fasi-moh          #+#    #+#             */
/*   Updated: 2021/11/25 13:44:02 by fasi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	nb_line_map(char **str)
{
	int	nb_line;

	nb_line = 0;
	while (str[nb_line])
		nb_line++;
	return (nb_line);
}

t_struct	recup_map(int fd)
{
	t_struct	game;
	char		*map;
	char		*new_line;

	get_next_line(fd, &map);
	while (get_next_line(fd, &new_line) > 0)
	{
		map = ft_strcat(map, new_line);
		free(new_line);
	}
	map = ft_strcat(map, new_line);
	free(new_line);
	game.map = ft_split(map, ' ');
	free(map);
	game.line = nb_line_map(game.map);
	game.nb_char = ft_strlen(game.map[0]);
	check_line_len(game.map, game.line, game.nb_char);
	check_line_first_end(game.map, game.line - 1);
	check_wall(game.map, game.line - 1);
	game = check_cpe(game.map, game.line - 1, game);
	return (game);
}

int	main(int ac, char **av)
{
	t_struct	game;
	int			file;

	if (ac != 2)
		exit(1);
	file = open(av[1], O_RDONLY);
	write_error_arg(ac, av, file);
	game = recup_map(file);
	game = start_window(game);
	aff_struct(game);
	mlx_key_hook(game.win, keyboard_touch, &game);
	mlx_hook(game.win, 17, 1L << 17, mouse_hook, &game);
	mlx_loop(game.mlx);
}
