/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:52:39 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/28 20:38:18 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandelbrot(t_env *e)
{
	e->man->x = -1;
	while (e->man->x++ != WIDTH)
	{
		e->man->y = -1;
		while (e->man->y++ != HEIGHT)
		{
			man_scale(e);
			e->man->n = 0;
			while (++e->man->n != e->iteration &&
			(sqrt((e->man->a * e->man->a) + (e->man->b * e->man->b)) < 3.0))
				square_mandel(e->man);
			e->iteration == e->man->n ? pixel_img(e, e->man->x, e->man->y, 0) :
			pixel_img(e, e->man->x, e->man->y, e->man->n * e->man->color);
		}
	}
	mlx_put_image_to_window(e->mlx, e->window, e->image, 0, 0);
}

t_man		*square_mandel(t_man *man)
{
	double tmp;

	tmp = (man->a * man->a) - (man->b * man->b);
	man->realx = tmp;
	man->realy = 2 * man->a * man->b;
	man->a = man->realx + man->prev_a;
	man->b = man->realy + man->prev_b;
	return (man);
}

void		man_scale(t_env *e)
{
	e->man->a = ((double)(e->man->x - (WIDTH / 2)) /
		(double)(WIDTH / 4) * e->events->zoom + e->events->shiftx);
	e->man->b = ((double)(e->man->y - (WIDTH / 2)) /
		(double)(WIDTH / 4) * e->events->zoom + e->events->shifty);
	e->man->prev_a = e->man->a;
	e->man->prev_b = e->man->b;
}
