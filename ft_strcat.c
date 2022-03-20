/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasi-moh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:46:15 by fasi-moh          #+#    #+#             */
/*   Updated: 2021/11/26 12:46:18 by fasi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;
	char			*tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(dest) + ft_strlen(src) + 2));
	if (!tmp)
		return (NULL);
	while (dest[i] != '\0')
	{
		tmp[i] = dest[i];
		i++;
	}
	j = 0;
	tmp[i] = ' ';
	i++;
	while (src[j] != '\0')
	{
		tmp[i] = src[j];
		i++;
		j++;
	}
	free(dest);
	tmp[i] = '\0';
	return (tmp);
}
