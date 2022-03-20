/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasi-moh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:59:51 by fasi-moh          #+#    #+#             */
/*   Updated: 2021/11/24 17:59:53 by fasi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_wall_on_map(t_struct game)
{
	game.line = 0;
	game.nb_char = 0;
	while (game.map[game.line])
	{
		while (game.map[game.line][game.nb_char])
		{
			if (game.map[game.line][game.nb_char] == '1')
				mlx_put_image_to_window(game.mlx, game.win, game.wall,
					game.nb_char * 64, game.line * 64);
			game.nb_char++;
		}
		game.nb_char = 0;
		game.line++;
	}
}

void	put_floor_on_map(t_struct game)
{
	game.line = 0;
	game.nb_char = 0;
	while (game.map[game.line])
	{
		while (game.map[game.line][game.nb_char])
		{
			if (game.map[game.line][game.nb_char] == '0')
				mlx_put_image_to_window(game.mlx, game.win, game.floor,
					game.nb_char * 64, game.line * 64);
			game.nb_char++;
		}
		game.nb_char = 0;
		game.line++;
	}
}

void	put_player_on_map(t_struct game)
{
	game.line = 0;
	game.nb_char = 0;
	while (game.map[game.line])
	{
		while (game.map[game.line][game.nb_char])
		{
			if (game.map[game.line][game.nb_char] == 'P')
				mlx_put_image_to_window(game.mlx, game.win, game.i_p1,
					game.nb_char * 64, game.line * 64);
			game.nb_char++;
		}
		game.nb_char = 0;
		game.line++;
	}
}

void	put_exit_on_map(t_struct game)
{
	game.line = 0;
	game.nb_char = 0;
	while (game.map[game.line])
	{
		while (game.map[game.line][game.nb_char])
		{
			if (game.map[game.line][game.nb_char] == 'E')
				mlx_put_image_to_window(game.mlx, game.win, game.i_exit,
					game.nb_char * 64, game.line * 64);
			game.nb_char++;
		}
		game.nb_char = 0;
		game.line++;
	}
}

void	put_collectible_on_map(t_struct game)
{
	game.line = 0;
	game.nb_char = 0;
	while (game.map[game.line])
	{
		while (game.map[game.line][game.nb_char])
		{
			if (game.map[game.line][game.nb_char] == 'C')
				mlx_put_image_to_window(game.mlx, game.win, game.i_collect,
					game.nb_char * 64, game.line * 64);
			game.nb_char++;
		}
		game.nb_char = 0;
		game.line++;
	}
}
