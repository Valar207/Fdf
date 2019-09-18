/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:13:37 by vrossi            #+#    #+#             */
/*   Updated: 2019/09/17 14:13:05 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include <math.h>

void	rotation_z(t_env *e)
{
	int		i;
	int		j;
	int		old_y;
	int		old_x;

	i = 0;
	j = 0;
	while (i < e->count_line)
	{
		while (j < e->count_col)
		{
			old_y = e->c_mapy[i][j] - e->starty;
			old_x = e->c_mapx[i][j] - e->startx;
			e->c_mapx[i][j] = old_x * cos(e->tetaz) + old_y * \
							sin(e->tetaz) - e->startx;
			e->c_mapy[i][j] = -old_x * sin(e->tetaz) + old_y * \
							cos(e->tetaz) - e->starty;
			j++;
		}
		j = 0;
		i++;
	}
}

void	rotation_x(t_env *e)
{
	int		i;
	int		j;
	int		old_y;

	i = 0;
	j = 0;
	while (i < e->count_line)
	{
		while (j < e->count_col)
		{
			old_y = e->c_mapy[i][j] - e->starty;
			e->c_mapy[i][j] = old_y * cos(e->tetax) + e->map[i][j] * \
							sin(e->tetax) + e->starty;
			j++;
		}
		j = 0;
		i++;
	}
}

void	rotation_y(t_env *e)
{
	int		i;
	int		j;
	int		old_x;

	i = 0;
	j = 0;
	while (i < e->count_line)
	{
		while (j < e->count_col)
		{
			old_x = e->c_mapx[i][j] - e->startx;
			e->c_mapx[i][j] = old_x * cos(e->tetay) + e->map[i][j] * \
							sin(e->tetay) + e->startx;
			j++;
		}
		j = 0;
		i++;
	}
}
