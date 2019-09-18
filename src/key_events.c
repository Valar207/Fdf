/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:18:17 by vrossi            #+#    #+#             */
/*   Updated: 2019/09/17 14:51:20 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/keyboard_code.h"

void	zoom(t_env *e, int keycode)
{
	if (keycode == PLUS)
	{
		e->size_cx += 1;
		e->size_cy += 1;
		e->startx += e->count_col / 2;
		e->starty += e->count_line / 2;
	}
	else if (keycode == MINUS)
	{
		if (e->size_cx == 2)
			return ;
		e->size_cx -= 1;
		e->size_cy -= 1;
		e->startx -= e->count_col / 2;
		e->starty -= e->count_line / 2;
	}
}

void	altitude(t_env *e, int keycode)
{
	if (keycode == 43)
		e->z -= 0.1;
	else if (keycode == 47)
		e->z += 0.1;
}

void	move(t_env *e, int keycode)
{
	if (keycode == D)
	{
		e->startx -= 15;
	}
	else if (keycode == A)
	{
		e->startx += 15;
	}
	else if (keycode == S)
	{
		e->starty -= 15;
	}
	else if (keycode == W)
	{
		e->starty += 15;
	}
}

void	rotate(t_env *e, int keycode)
{
	if (keycode == R)
	{
		e->startx = -WIDTH / 4;
		e->starty = -HEIGHT / 10;
		e->z = 0.2;
		e->size_cx = (WIDTH / e->count_col) / 2;
		e->size_cy = (WIDTH / e->count_col) / 2;
		e->tetax = 0;
		e->tetay = 0;
		e->tetaz = 0;
	}
	else if (keycode == Z)
		e->tetaz += 0.1;
	else if (keycode == X)
		e->tetaz -= 0.1;
	else if (keycode == UP_ARROW)
		e->tetax += 0.1;
	else if (keycode == DOWN_ARROW)
		e->tetax -= 0.1;
	else if (keycode == LEFT_ARROW)
		e->tetay += 0.1;
	else if (keycode == RIGHT_ARROW)
		e->tetay -= 0.1;
}
