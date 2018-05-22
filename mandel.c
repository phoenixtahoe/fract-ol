/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:52:39 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/21 17:56:53 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    man_scale(t_env *e)
{
    e->man->a = ((double)(e->man->x - (WIDTH / 2)) /
    (double)(WIDTH / 4) * e->events->zoom + e->events->yshift);
    e->man->b = ((double)(e->man->y - (WIDTH / 2)) /
    (double)(WIDTH / 4) * e->events->zoom + e->events->xshift);
    e->man->prev_a = e->man->a;
    e->man->prev_b = e->man->b;
}

void		mandelbrot(t_env *j)
{
	int		n;
	t_env	*e;
	int		hex;

	e = j;
	e->man->x = -1;
	while (e->man->x++ != WIDTH)
	{
		e->man->y = -1;
		while (e->man->y++ != HEIGHT)
		{
			man_scale(e);
			n = 0;
			while (++n != e->iteration &&
				(sqrt((e->man->a * e->man->a) + (e->man->b * e->man->b)) < 3.0))
			{
				square(e->man);
				e->man->a = e->man->zx + e->man->prev_a;
				e->man->b = e->man->zy + e->man->prev_b;
			}
			e->iteration == n ? put_pixel_img(e, e->man->x, e->man->y, 0) :
				put_pixel_img(e, e->man->x, e->man->y, n * e->man->color);
		}
	}
	mlx_put_image_to_window(e->mlx, e->window, e->image, 0, 0);
}

t_man   *square(t_man *man)
{
    double tmp;

    tmp = (man->a * man->a) - (man->b * man->b);
    man->zx = tmp;
    man->zy = 2 * man->a * man->b;
    return (man);
}