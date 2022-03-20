/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toucha_s_d_w.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasi-moh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:05:01 by fasi-moh          #+#    #+#             */
/*   Updated: 2021/11/28 16:05:16 by fasi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_struct	touch_d(t_struct game)
{
	if (game.map[game.line][game.nb_char + 1] == 'C')
		game.collec--;
	if (game.map[game.line][game.nb_char + 1] == 'E'
			&& game.collec == 0)
	{
		game.cmoove++;
		printf("nb_move === %d\n", game.cmoove);
		printf("END OF THE GAME");
		free_end(game);
		exit(0);
	}
	game.map[game.line][game.nb_char] = '0';
	game.map[game.line][game.nb_char + 1] = 'P';
	aff_struct(game);
	game.cmoove++;
	printf("nb_move === %d\n", game.cmoove);
	return (game);
}

t_struct	touch_a(t_struct game)
{
	if (game.map[game.line][game.nb_char - 1] == 'C')
		game.collec--;
	if (game.map[game.line][game.nb_char - 1] == 'E'
			&& game.collec == 0)
	{
		game.cmoove++;
		printf("nb_move === %d\n", game.cmoove);
		printf("END OF THE GAME");
		free_end(game);
		exit(0);
	}
	game.map[game.line][game.nb_char] = '0';
	game.map[game.line][game.nb_char - 1] = 'P';
	aff_struct(game);
	game.cmoove++;
	printf("nb_move === %d\n", game.cmoove);
	return (game);
}

t_struct	touch_w(t_struct game)
{
	if (game.map[game.line - 1][game.nb_char] == 'C')
		game.collec--;
	if (game.map[game.line - 1][game.nb_char] == 'E'
			&& game.collec == 0)
	{
		game.cmoove++;
		printf("nb_move === %d\n", game.cmoove);
		printf("END OF THE GAME");
		free_end(game);
		exit(0);
	}
	game.map[game.line][game.nb_char] = '0';
	game.map[game.line - 1][game.nb_char] = 'P';
	aff_struct(game);
	game.cmoove++;
	printf("nb_move === %d\n", game.cmoove);
	return (game);
}

t_struct	touch_s(t_struct game)
{
	if (game.map[game.line + 1][game.nb_char] == 'C')
		game.collec--;
	if (game.map[game.line + 1][game.nb_char] == 'E'
			&& game.collec == 0)
	{
		game.cmoove++;
		printf("nb_move === %d\n", game.cmoove);
		printf("END OF THE GAME");
		free_end(game);
		exit(0);
	}
	game.map[game.line][game.nb_char] = '0';
	game.map[game.line + 1][game.nb_char] = 'P';
	aff_struct(game);
	game.cmoove++;
	printf("nb_move === %d\n", game.cmoove);
	return (game);
}
