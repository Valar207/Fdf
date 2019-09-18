/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:18:17 by vrossi            #+#    #+#             */
/*   Updated: 2019/09/17 14:52:06 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"

void	color(t_env *e, int i, int j)
{
	if (e->count_col > 100)
	{
		if (e->map[i][j] < 1)
			e->color = 0xFF807400;
		else if (e->map[i][j] >= 1 && e->map[i][j] <= 25)
			e->color = 0x1AB00000;
		else if (e->map[i][j] >= 25 && e->map[i][j] <= 70)
			e->color = 0x1676C100;
		else if (e->map[i][j] >= 70 && e->map[i][j] <= 1000)
			e->color = 0xFFFFFF00;
	}
	else
	{
		if (e->map[i][j] < 0)
			e->color = 0x795D3200;
		if (e->map[i][j] == 0)
			e->color = 0xD1D79B00;
		if (e->map[i][j] > 0 && e->map[i][j] <= 5)
			e->color = 0xEEEEEF00;
		if (e->map[i][j] > 5 && e->map[i][j] <= 10)
			e->color = 0x6CA2F900;
		if (e->map[i][j] > 10)
			e->color = 0x2766FE00;
	}
}
