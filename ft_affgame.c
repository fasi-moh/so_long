/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affgame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasi-moh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:59:51 by fasi-moh          #+#    #+#             */
/*   Updated: 2021/11/24 17:59:53 by fasi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	aff_struct(t_struct pos)
{
	put_wall_on_map(pos);
	put_collectible_on_map(pos);
	put_floor_on_map(pos);
	put_player_on_map(pos);
	put_exit_on_map(pos);
}

t_struct	manage_texture(t_struct game)
{
	int	pixels;

	pixels = 64;
	game.wall = mlx_xpm_file_to_image (game.mlx,
			"./textures/wall-64t.xpm", &pixels, &pixels);
	game.floor = mlx_xpm_file_to_image (game.mlx,
			"./textures/bottom-64.xpm", &pixels, &pixels);
	game.i_collect = mlx_xpm_file_to_image (game.mlx,
			"./textures/collectible-64.xpm", &pixels, &pixels);
	game.i_exit = mlx_xpm_file_to_image (game.mlx,
			"./textures/exit-64.xpm", &pixels, &pixels);
	game.i_p1 = mlx_xpm_file_to_image (game.mlx,
			"./textures/player-64.xpm", &pixels, &pixels);
	return (game);
}

t_struct	start_window(t_struct game)
{
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.nb_char * 64,
			game.line * 64, "so_long");
	game = manage_texture(game);
	return (game);
}
