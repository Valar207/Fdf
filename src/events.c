/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:18:17 by vrossi            #+#    #+#             */
/*   Updated: 2019/09/18 11:28:36 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "libft/libft.h"
#include "../includes/struct.h"
#include "../includes/keyboard_code.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void	sw(t_env *e, t_line *l)
{
	if (e->sw == 1)
	{
		make_iso(e, l);
	}
	else
	{
		ft_parallele(e);
		trace_pt(e, l);
	}
}

void	para_iso(t_env *e, t_line *l, int keycode)
{
	if (keycode == P)
	{
		mlx_destroy_image(e->mlx, e->pt_img);
		e->pt_img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
		e->sw = 0;
		ft_parallele(e);
		trace_pt(e, l);
		mlx_put_image_to_window(e->mlx, e->win, e->pt_img, 0, 0);
	}
	else if (keycode == I)
	{
		mlx_destroy_image(e->mlx, e->pt_img);
		e->pt_img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
		e->sw = 1;
		make_iso(e, l);
		mlx_put_image_to_window(e->mlx, e->win, e->pt_img, 0, 0);
	}
}

int		key_press(int keycode, t_env *e, t_line *l)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		free(e);
		free(l);
		exit(1);
	}
	altitude(e, keycode);
	move(e, keycode);
	zoom(e, keycode);
	rotate(e, keycode);
	mlx_destroy_image(e->mlx, e->pt_img);
	e->pt_img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	sw(e, l);
	para_iso(e, l, keycode);
	mlx_put_image_to_window(e->mlx, e->win, e->pt_img, 0, 0);
	mlx_string_put(e->mlx, e->win, 25, 25, 0xFFFFFFFF, "< | > : altitude     \
			A | W | S | D : move        UP | DOWN : rotate up-down        \
			LEFT | RIGHT : rotate sides          I | P : change view       \
			Z | X : rotate z          + | - : zoom          R : reset");
	return (0);
}
