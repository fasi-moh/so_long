/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasi-moh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:24:11 by fasi-moh          #+#    #+#             */
/*   Updated: 2021/11/24 12:50:49 by fasi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <string.h>

void	check_wall(char **str, int nb_line)
{
	int	iterator;
	int	cara;

	iterator = 1;
	while (iterator < nb_line)
	{
		cara = strlen(str[iterator]) - 1;
		if (str[iterator][0] != '1' || str[iterator][cara] != '1')
			write_error_map(4, str);
		iterator++;
	}
}

t_struct	ft_init(t_struct pos)
{
	pos.cmoove = 0;
	pos.player = 0;
	pos.collec = 0;
	pos.exit = 0;
	return (pos);
}

t_struct	check_cpe(char **str, int nb, t_struct pos)
{
	int	c;

	c = 0;
	pos = ft_init(pos);
	while (nb > 0)
	{
		while (str[nb][c])
		{
			if (str[nb][c] == 'P')
				pos.player++;
			else if (str[nb][c] == 'C')
				pos.collec++;
			else if (str[nb][c] == 'E')
				pos.exit++;
			if (str[nb][c] != 'P' && str[nb][c] != 'E' && str[nb][c] != 'C'
			&& str[nb][c] != '1' && str[nb][c] != '0')
				write_error_game(1, pos, str);
			c++;
		}
		c = 0;
		nb--;
	}
	write_error_game(2, pos, str);
	printf("la map est valide\n");
	return (pos);
}

void	check_line_len(char **str, int nb_line, int lenstr)
{
	int	iterator;
	int	nb_cara;

	iterator = 0;
	while (iterator < nb_line)
	{
		nb_cara = strlen(str[iterator]);
		if (nb_cara != lenstr)
			write_error_map(1, str);
		iterator++;
	}
}

void	check_line_first_end(char **str, int nb_line)
{
	int	iterator;

	iterator = 0;
	while (str[0][iterator])
	{
		if (str[0][iterator] != '1')
			write_error_map(2, str);
		iterator++;
	}
	iterator = 0;
	while (str[nb_line][iterator])
	{
		if (str[nb_line][iterator] != '1')
			write_error_map(3, str);
		iterator++;
	}
}
