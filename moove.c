/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasi-moh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:15:55 by fasi-moh          #+#    #+#             */
/*   Updated: 2021/11/28 16:15:56 by fasi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_struct	do_moove_d(t_struct game)
{
	game.line = 0;
	while (game.map[game.line])
	{
		game.nb_char = 0;
		while (game.map[game.line][game.nb_char])
		{
			if (game.map[game.line][game.nb_char] == 'P')
			{
				if (game.map[game.line][game.nb_char + 1] == '1')
					return (game);
				if (game.map[game.line][game.nb_char + 1] == 'E' &&
						game.collec != 0)
					return (game);
				game = touch_d(game);
				return (game);
			}
			game.nb_char++;
		}
		game.line++;
	}
	return (game);
}

t_struct	do_moove_a(t_struct game)
{
	game.line = 0;
	while (game.map[game.line])
	{
		game.nb_char = 0;
		while (game.map[game.line][game.nb_char])
		{
			if (game.map[game.line][game.nb_char] == 'P')
			{
				if (game.map[game.line][game.nb_char - 1] == '1')
					return (game);
				if (game.map[game.line][game.nb_char - 1] == 'E'
						&& game.collec != 0)
					return (game);
				game = touch_a(game);
				return (game);
			}
			game.nb_char++;
		}
		game.line++;
	}
	return (game);
}

t_struct	do_moove_w(t_struct game)
{
	game.line = 0;
	while (game.map[game.line])
	{
		game.nb_char = 0;
		while (game.map[game.line][game.nb_char])
		{
			if (game.map[game.line][game.nb_char] == 'P')
			{
				if (game.map[game.line - 1][game.nb_char] == '1')
					return (game);
				if (game.map[game.line - 1][game.nb_char] == 'E'
						&& game.collec != 0)
					return (game);
				game = touch_w(game);
				return (game);
			}
			game.nb_char++;
		}
		game.line++;
	}
	return (game);
}

t_struct	do_moove_s(t_struct game)
{
	game.line = 0;
	while (game.map[game.line])
	{
		game.nb_char = 0;
		while (game.map[game.line][game.nb_char])
		{
			if (game.map[game.line][game.nb_char] == 'P')
			{
				if (game.map[game.line + 1][game.nb_char] == '1')
					return (game);
				if (game.map[game.line + 1][game.nb_char] == 'E'
						&& game.collec != 0)
					return (game);
				game = touch_s(game);
				return (game);
			}
			game.nb_char++;
		}
		game.line++;
	}
	return (game);
}
