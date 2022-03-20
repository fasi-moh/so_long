/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasi-moh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:59:41 by fasi-moh          #+#    #+#             */
/*   Updated: 2021/11/27 16:59:43 by fasi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_error_map(int error, char **str)
{	
	if (error == 1)
	{
		free_str(str);
		printf("Error, WRONG SIZE OF THE MAP.\n");
		exit(1);
	}
	else if (error == 2)
	{
		free_str(str);
		printf("Error, in the first wall of the map.\n");
		exit(1);
	}
	else if (error == 3)
	{
		free_str(str);
		printf("Error, in the last wall of the map.\n");
		exit(1);
	}
	else if (error == 4)
	{
		free_str(str);
		printf("Error, you need to close the map with wall.\n");
		exit(1);
	}
}

void	write_error_game(int error, t_struct game, char **str)
{
	if (error == 1)
	{
		free_str(str);
		printf("Error, the map is not valid = wrong element.\n");
		exit(1);
	}
	else if (error == 2)
	{
		if (game.player > 1)
		{
			free_str(str);
			printf("Error, we have more than 1 player.\n");
			exit(1);
		}
		else if (game.exit < 1 || game.collec < 1 || game.player < 1)
		{
			free_str(str);
			printf("Error, one element of the game is missing.\n");
			exit(1);
		}
	}
}

void	write_error_arg(int ac, char **av, int file)
{
	int	i;

	(void)ac;
	i = 0;
	if (file == -1)
	{
		printf("Error, enter a valid file.\n");
		exit(1);
	}
	i = ft_strlen(av[1]);
	i--;
	if (av[1][i] != 'r' || av[1][i - 1] != 'e' || av[1][i - 2] != 'b' ||
		av[1][i - 3] != '.')
	{
		printf("Error, the map is not a .ber map.\n");
		exit(1);
	}
	return ;
}

void	free_str(char **str)
{
	int	line;

	line = 0;
	while (str[line])
	{
		free(str[line]);
		line++;
	}
	free(str);
}
