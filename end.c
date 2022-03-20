/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasi-moh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:15:35 by fasi-moh          #+#    #+#             */
/*   Updated: 2021/11/28 16:15:37 by fasi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mouse_hook(t_struct *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->i_p1);
	mlx_destroy_image(game->mlx, game->i_collect);
	mlx_destroy_image(game->mlx, game->i_exit);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
	return (0);
}

int	keyboard_touch(int keycode, t_struct *game)
{
	if (keycode == 65307)
	{
		free_end(*game);
		exit(EXIT_FAILURE);
	}
	if (keycode == 100)
		*game = do_moove_d(*game);
	if (keycode == 97)
		*game = do_moove_a(*game);
	if (keycode == 119)
		*game = do_moove_w(*game);
	if (keycode == 115)
		*game = do_moove_s(*game);
	return (0);
}

void	free_end(t_struct game)
{
	int	i;

	i = 0;
	while (game.map[i])
		free(game.map[i++]);
	free(game.map);
	mlx_destroy_image(game.mlx, game.wall);
	mlx_destroy_image(game.mlx, game.i_p1);
	mlx_destroy_image(game.mlx, game.i_collect);
	mlx_destroy_image(game.mlx, game.i_exit);
	mlx_destroy_image(game.mlx, game.floor);
	mlx_destroy_window(game.mlx, game.win);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
}
