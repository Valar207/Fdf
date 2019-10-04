/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:18:17 by vrossi            #+#    #+#             */
/*   Updated: 2019/09/17 14:47:18 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../minilibx/mlx.h"
#include "libft/libft.h"

void	ft_parallele_bis(t_env *e, int i, int j)
{
	int		x;
	int		y;

	if (!(e->c_mapx[i] = (int *)ft_memalloc(sizeof(int) * e->count_col + 1)))
		return ;
	if (!(e->c_mapy[i] = (int *)ft_memalloc(sizeof(int) * e->count_col + 1)))
		return ;
	x = e->c_mapx[i][j];
	y = e->c_mapy[i][j];
	while (j < e->count_col)
	{
		e->c_mapx[i][j] = e->x0;
		if (i != e->count_line)
		{
			if (e->map[i][j] != 0)
				e->c_mapy[i][j] = e->y0 - e->z * (e->map[i][j] + 1) * \
								e->size_cy / 2;
			else
				e->c_mapy[i][j] = e->y0;
		}
		e->x0 += e->size_cx;
		j++;
	}
}

void	ft_parallele(t_env *e)
{
	int		i;
	int		j;

	e->y0 = e->starty;
	e->x0 = e->startx;
	i = 0;
	j = 0;
	if (!(e->c_mapx = (int **)ft_memalloc(sizeof(int *) * e->count_line + 1)))
		return ;
	if (!(e->c_mapy = (int **)ft_memalloc(sizeof(int *) * e->count_line + 1)))
		return ;
	while (i < e->count_line)
	{
		ft_parallele_bis(e, i, j);
		e->x0 = e->startx;
		e->y0 = e->y0 + e->size_cy;
		j = 0;
		i++;
	}
	e->y0 = e->starty;
	rotation_x(e);
	rotation_y(e);
	rotation_z(e);
}

void	make_iso(t_env *e, t_line *l)
{
	int		i;
	int		j;
	int		ind;

	ft_parallele(e);
	i = 0;
	j = 0;
	ind = 0;
	while (i < e->count_line)
	{
		while (j < e->count_col)
		{
			e->c_mapx[i][j] = e->c_mapx[i][j] + i * e->size_cx;
			e->c_mapy[i][j] = e->c_mapy[i][j] - \
							((e->size_cx * i / 2) + (e->size_cx * j / 2));
			j++;
		}
		j = 0;
		i++;
	}
	trace_pt(e, l);
}

void	trace_pt_bis(t_env *e, t_line *l, int i, int j)
{
	while (j < e->count_col)
	{
		color(e, i, j);
		if (j != e->count_col - 1)
		{
			l->x1 = e->c_mapx[i][j];
			l->y1 = e->c_mapy[i][j];
			l->x2 = e->c_mapx[i][j + 1];
			l->y2 = e->c_mapy[i][j + 1];
			ft_draw_line(l, e);
		}
		if (i != e->count_line - 1)
		{
			l->x1 = e->c_mapx[i][j];
			l->y1 = e->c_mapy[i][j];
			l->x2 = e->c_mapx[i + 1][j];
			l->y2 = e->c_mapy[i + 1][j];
			ft_draw_line(l, e);
		}
		j++;
	}
}

void	trace_pt(t_env *e, t_line *l)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(l = (t_line *)ft_memalloc(sizeof(t_line))))
		return ;
	while (i < e->count_line)
	{
		trace_pt_bis(e, l, i, j);
		j = 0;
		i++;
	}
	ft_free_tab_int(e->c_mapx, e->count_line);
	ft_free_tab_int(e->c_mapy, e->count_line);
	free(l);
}
