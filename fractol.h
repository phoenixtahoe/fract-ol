/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:05:51 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/28 20:31:49 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800
# define PI 3.14159265359

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>

typedef struct		s_juul
{
	double			ab;
	double			ba;
	double			a;
	double			b;
	double			prev_a;
	double			prev_b;
	double			realx;
	double			realy;
	int				x;
	int				y;
	int				n;
}					t_juul;

typedef struct		s_burn
{
	double			a;
	double			b;
	double			ba;
	double			ab;
	double			prev_a;
	double			prev_b;
	double			realx;
	double			realy;
	int				x;
	int				y;
	int				n;
}					t_burn;

typedef struct		s_man
{
	double			prev_a;
	double			prev_b;
	double			y;
	double			x;
	double			a;
	double			b;
	double			realx;
	double			realy;
	int				color;
	int				n;
}					t_man;

typedef struct		s_events
{
	double			zoom;
	double			shifty;
	double			shiftx;
}					t_events;

typedef struct		s_env
{
	t_man			*man;
	t_events		*events;
	t_juul			*juul;
	t_burn			*burn;
	void			*mlx;
	void			*image;
	void			*window;
	int				endian;
	int				sl;
	int				bpp;
	int				fract;
	int				iteration;
	int				maxiter;
}					t_env;

t_env				*init(void);
void				ft_exit(t_env *all);
int					keyhook(int key, t_env *e);
int					keys(int key, t_env *all);
int					motion_hook(int x, int y, t_env *all);
int					mouse_hook(int btn, int x, int y, t_env *all);
void				pixel_img(t_env *e, int x, int y, int color);
int					fractols(char *str, t_env *e);
int					draw(t_env *e);
void				man_scale(t_env *e);
void				mandelbrot(t_env *e);
t_man				*square_mandel(t_man *man);
t_juul				*square_juul(t_juul *all);
void				juul(t_env *e);
void				juul_scale(t_env *e);
void				burns_scale(t_env *e);
void				burns(t_env *e);
t_burn				*burns_square(t_burn *e);

#endif
