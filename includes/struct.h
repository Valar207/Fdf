/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:01:58 by vrossi            #+#    #+#             */
/*   Updated: 2019/09/18 10:55:20 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# define HEIGHT	1440
# define WIDTH	2560

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			**map;
	int			**c_mapx;
	int			**c_mapy;
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			startx;
	int			starty;
	char		**tmp;
	int			count_col;
	int			count_line;
	int			i;
	int			j;
	int			k;
	float		z;
	int			size_cx;
	int			size_cy;
	int			color;
	int			c;
	int			d;
	void		*pt_img;
	char		*my_img;
	void		*pt_blackimg;
	char		*my_blackimg;
	float		tetax;
	float		tetay;
	float		tetaz;
	int			sw;
	int			ldx;
	int			ldy;
	int			lx;
	int			ly;
	int			ld;
	int			lxi;
	int			lyi;
	int			lx1;
	int			ly1;
	int			lx2;
	int			ly2;
	int			lx3;
	int			ly3;
}				t_env;

typedef struct	s_line
{
	int			dx;
	int			dy;
	int			x;
	int			y;
	int			d;
	int			xi;
	int			yi;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			x3;
	int			y3;
}				t_line;

int				nb_col(char *line, t_env *e);
int				nb_line(char *line, int fd);
int				**get_coord(char *file, t_env *c);
void			get_coord_bis(t_env *e, char *line);
void			ft_draw_line_x1(t_line *l, t_env *env);
void			ft_draw_line_y1(t_line *l, t_env *env);
void			ft_draw_line_x2(t_line *l, t_env *env);
void			ft_draw_line_y2(t_line *l, t_env *env);
void			ft_draw_line(t_line *l, t_env *env);
void			ft_fill_pix(t_env *e, int x, int y);
void			ft_parallele(t_env *e);
void			ft_parallele_bis(t_env *e, int i, int j);
void			ft_almost_iso(t_env *e, t_line *l);
void			make_iso(t_env *e, t_line *l);
void			trace_pt_bis(t_env *e, t_line *l, int i, int j);
void			trace_pt(t_env *e, t_line *l);
int				key_press(int keycode, t_env *e, t_line *l);
void			para_iso(t_env *e, t_line *l, int keycode);
void			sw(t_env *e, t_line *l);
void			zoom(t_env *e, int keycode);
void			move(t_env *e, int keycode);
void			altitude(t_env *e, int keycode);
void			rotate(t_env *e, int keycode);
void			background(t_env *e);
void			rotation_x(t_env *e);
void			rotation_y(t_env *e);
void			rotation_z(t_env *e);
void			color(t_env *e, int i, int j);
void			init_var(t_env *e);
int				check(int ac, char **av, t_env *e);
#endif
