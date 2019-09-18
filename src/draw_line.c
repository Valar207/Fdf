/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:30:49 by vrossi            #+#    #+#             */
/*   Updated: 2019/09/17 14:55:31 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../includes/struct.h"
#include "../includes/keyboard_code.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_draw_line_x1(t_line *l, t_env *e)
{
	l->x = l->x1;
	l->dx = l->x2 - l->x1;
	l->dy = l->y2 - l->y1;
	l->yi = 1;
	if (l->dy < 0)
	{
		l->yi = -1;
		l->dy = -(l->dy);
	}
	l->d = 2 * l->dy - l->dx;
	l->y = l->y1;
	while (l->x < l->x2)
	{
		ft_fill_pix(e, l->x, l->y);
		if (l->d > 0)
		{
			l->y = l->y + l->yi;
			l->d = l->d - 2 * l->dx;
		}
		l->d = l->d + 2 * l->dy;
		(l->x)++;
	}
}

void	ft_draw_line_x2(t_line *l, t_env *e)
{
	l->x = l->x2;
	l->dx = l->x1 - l->x2;
	l->dy = l->y1 - l->y2;
	l->yi = 1;
	if (l->dy < 0)
	{
		l->yi = -1;
		l->dy = -(l->dy);
	}
	l->d = 2 * l->dy - l->dx;
	l->y = l->y2;
	while (l->x < l->x1)
	{
		ft_fill_pix(e, l->x, l->y);
		if (l->d > 0)
		{
			l->y = l->y + l->yi;
			l->d = l->d - 2 * l->dx;
		}
		l->d = l->d + 2 * l->dy;
		(l->x)++;
	}
}

void	ft_draw_line_y1(t_line *l, t_env *e)
{
	l->y = l->y1;
	l->dx = l->x2 - l->x1;
	l->dy = l->y2 - l->y1;
	l->xi = 1;
	if (l->dx < 0)
	{
		l->xi = -1;
		l->dx = -(l->dx);
	}
	l->d = 2 * l->dx - l->dy;
	l->x = l->x1;
	while (l->y < l->y2)
	{
		ft_fill_pix(e, l->x, l->y);
		if (l->d > 0)
		{
			l->x = l->x + l->xi;
			l->d = l->d - 2 * l->dy;
		}
		l->d = l->d + 2 * l->dx;
		(l->y)++;
	}
}

void	ft_draw_line_y2(t_line *l, t_env *e)
{
	l->y = l->y2;
	l->dx = l->x1 - l->x2;
	l->dy = l->y1 - l->y2;
	l->xi = 1;
	if (l->dx < 0)
	{
		l->xi = -1;
		l->dx = -(l->dx);
	}
	l->d = 2 * l->dx - l->dy;
	l->x = l->x2;
	while (l->y < l->y1)
	{
		ft_fill_pix(e, l->x, l->y);
		if (l->d > 0)
		{
			l->x = l->x + l->xi;
			l->d = l->d - 2 * l->dy;
		}
		l->d = l->d + 2 * l->dx;
		(l->y)++;
	}
}

void	ft_draw_line(t_line *l, t_env *e)
{
	if (abs(l->y2 - l->y1) < abs(l->x2 - l->x1))
	{
		if (l->x1 > l->x2)
			ft_draw_line_x2(l, e);
		else
			ft_draw_line_x1(l, e);
	}
	else
	{
		if (l->y1 > l->y2)
			ft_draw_line_y2(l, e);
		else
			ft_draw_line_y1(l, e);
	}
}
