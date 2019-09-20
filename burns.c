/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:21:19 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/28 21:08:50 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burns(t_env *e)
{
	e->burn->x = -1;
	while (e->burn->x++ != WIDTH)
	{
		e->burn->y = -1;
		while (e->burn->y++ != HEIGHT)
		{
			burns_scale(e);
			while (e->burn->n != e->iteration && e->burn->realx * e->burn->realx
			+ e->burn->realy * e->burn->realy <= 4.0)
				burns_square(e->burn);
			e->burn->n == e->iteration ? pixel_img(e, e->burn->x, e->burn->y, 0)
			: pixel_img(e, e->burn->x, e->burn->y, e->burn->n * e->man->color);
		}
	}
	mlx_put_image_to_window(e->mlx, e->window, e->image, 0, 0);
}

t_burn	*burns_square(t_burn *e)
{
	e->prev_a = e->realx;
	e->realx = e->realx * e->realx - e->realy * e->realy + e->a;
	e->realy = 2 * fabs(e->realy * e->prev_a) + e->b;
	e->n += 1;
	return (e);
}

void	burns_scale(t_env *e)
{
	e->burn->a = ((double)(e->burn->x - (WIDTH / 2)) /
			(double)(WIDTH / 4) * e->events->zoom + e->events->shiftx);
	e->burn->b = ((double)(e->burn->y - (HEIGHT / 2)) /
			(double)(HEIGHT / 4) * e->events->zoom + e->events->shifty);
	e->burn->realx = e->burn->ab;
	e->burn->realy = e->burn->ba;
	e->burn->n = 0;
}
