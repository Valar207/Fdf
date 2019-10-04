/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:38:29 by vrossi            #+#    #+#             */
/*   Updated: 2019/09/18 10:32:45 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../minilibx/mlx.h"
#include "libft/libft.h"

void	init_var(t_env *e)
{
	int		bpp;
	int		s_l;
	int		endian;

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "FDF 42");
	e->pt_img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->my_img = mlx_get_data_addr(e->pt_img, &(bpp), &(s_l), &(endian));
	e->z = 0.2;
	e->size_cx = (WIDTH / e->count_col) / 2;
	e->size_cy = (WIDTH / e->count_col) / 2;
	e->color = 0xFF807400;
	e->startx = -WIDTH / 4;
	e->starty = -HEIGHT / 10;
	e->sw = 0;
	e->tetaz = 0;
	e->tetay = 0;
	e->tetax = 0;
	e->i = 0;
}
