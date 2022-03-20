/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasi-moh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:22:10 by fasi-moh          #+#    #+#             */
/*   Updated: 2021/11/24 20:22:12 by fasi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

int	boucle(char **stock, int fd, int ret)
{
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	if (!ft_strchr(*stock, '\n'))
		ret = read(fd, buff, BUFFER_SIZE);
	while (!ft_strchr(*stock, '\n') && ret)
	{
		buff[ret] = '\0';
		*stock = ft_strjoin_free(*stock, buff);
		if (!ft_strchr(*stock, '\n'))
			ret = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	static char	*stock = NULL;
	int			i;
	char		*tmp;

	ret = 0;
	i = 0;
	if (!line || BUFFER_SIZE < 1 || read(fd, NULL, 0) == -1)
		return (-1);
	if (!stock)
		stock = calloc(1, 1);
	boucle(&stock, fd, ret);
	while (stock[i] && stock[i] != '\n')
		i++;
	tmp = stock;
	*line = ft_substr(stock, 0, i);
	if (stock[i] == '\n')
		stock = ft_strdup(stock + i + 1);
	else
		stock = NULL;
	free(tmp);
	if ((stock == NULL) && !ret)
		return (0);
	else
		return (1);
}
