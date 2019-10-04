/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:18:17 by vrossi            #+#    #+#             */
/*   Updated: 2019/09/18 11:40:46 by vrossi           ###   ########.fr       */
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

int		check(int ac, char **av, t_env *e)
{
	if (ac != 2)
	{
		write(2, "usage: ./fdf [target_file.fdf]\n", 31);
		exit(0);
	}
	if ((ft_strncmp(av[1], "/dev/zero", 9) == 0) || \
			ft_strncmp(av[1], "/dev/random", 11) == 0)
	{
		ft_putstr("error\n");
		exit(EXIT_FAILURE);
	}
	if (!get_coord(av[1], e))
	{
		ft_putstr("error\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_env	*e;
	t_line	*l;

	if (!(e = (t_env *)ft_memalloc(sizeof(t_env))))
		return (0);
	if (!(l = (t_line *)ft_memalloc(sizeof(t_line))))
		return (0);
	check(ac, av, e);
	init_var(e);
	ft_parallele(e);
	trace_pt(e, l);
	mlx_put_image_to_window(e->mlx, e->win, e->pt_img, 0, 0);
	mlx_string_put(e->mlx, e->win, 25, 25, 0xFFFFFFFF, "< | > : altitude     \
			A | W | S | D : move        UP | DOWN : rotate up-down        \
			LEFT | RIGHT : rotate sides          I | P : change view       \
			Z | X : rotate z          + | - : zoom          R : reset");
	mlx_hook(e->win, 2, 0, key_press, e);
	mlx_loop(e->mlx);
	return (0);
}
