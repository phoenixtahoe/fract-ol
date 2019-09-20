/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:07:46 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/28 20:15:05 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		juul(t_env *e)
{
	e->juul->x = -1;
	while (e->juul->x++ != WIDTH)
	{
		e->juul->y = -1;
		while (e->juul->y++ != HEIGHT)
		{
			juul_scale(e);
			while (++e->juul->n != e->iteration &&
				e->juul->b * e->juul->b + e->juul->a * e->juul->a <= 4.0)
				square_juul(e->juul);
			e->juul->n == e->iteration ? pixel_img(e, e->juul->x, e->juul->y, 0)
			: pixel_img(e, e->juul->x, e->juul->y, e->juul->n * e->man->color);
		}
	}
	mlx_put_image_to_window(e->mlx, e->window, e->image, 0, 0);
}

t_juul		*square_juul(t_juul *e)
{
	e->realy = 2 * e->a * e->b;
	e->realx = (e->a * e->a) - (e->b * e->b);
	e->a = e->realx + e->prev_a;
	e->b = e->realy + e->prev_b;
	return (e);
}

void		juul_scale(t_env *e)
{
	e->juul->prev_a = e->juul->ab;
	e->juul->prev_b = e->juul->ba;
	e->juul->a = ((double)(e->juul->x - (WIDTH / 2)) /
			(double)(WIDTH / 4) * e->events->zoom + e->events->shiftx);
	e->juul->b = ((double)(e->juul->y - (HEIGHT / 2)) /
			(double)(HEIGHT / 4) * e->events->zoom + e->events->shifty);
	e->juul->n = 0;
}
