/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:45:56 by vrossi            #+#    #+#             */
/*   Updated: 2019/09/18 11:31:21 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../includes/struct.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int		nb_col(char *line, t_env *e)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	while (tmp[i])
		i++;
	ft_free_tab_char(tmp);
	if (e->count_col == 0)
		e->count_col = i;
	else if (e->count_col != i)
		return (0);
	return (1);
}

int		nb_line(char *line, int fd)
{
	int		i;
	int		ret;

	i = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		free(line);
		i++;
	}
	if (ret < 0)
		return (0);
	close(fd);
	ft_memdel((void **)&line);
	if (!i)
		return (0);
	return (i);
}

void	get_coord_bis(t_env *e, char *line)
{
	e->tmp = ft_strsplit(line, ' ');
	ft_memdel((void **)&line);
	e->j = 0;
	e->k = 0;
	if (!(e->map[e->i] = (int *)ft_memalloc(sizeof(int) * e->count_col)))
		return ;
	while (e->tmp[e->k])
		e->map[e->i][e->j++] = ft_atoi(e->tmp[e->k++]);
	e->i++;
	ft_free_tab_char(e->tmp);
}

int		**get_coord(char *file, t_env *e)
{
	char	*line;
	int		fd;

	e->count_col = 0;
	fd = open(file, O_DIRECTORY);
	if (fd == 3)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	e->count_line = nb_line(line, fd);
	fd = open(file, O_RDONLY);
	if (!(e->map = (int **)ft_memalloc(sizeof(int *) * e->count_line)))
		return (NULL);
	while (get_next_line(fd, &line))
	{
		if (!(nb_col(line, e)))
			return (0);
		get_coord_bis(e, line);
	}
	close(fd);
	ft_memdel((void **)&line);
	if (e->count_col == 0)
		return (0);
	return (e->map);
}
