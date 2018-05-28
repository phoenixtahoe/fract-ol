/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:21:19 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/27 20:39:17 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			burns(t_env *j)
{
	int			hex;
	int		n;
	t_burn		*e;

	e = (t_pheen *)malloc(sizeof(t_pheen));
	e->x = -1;
	while (e->x++ != WIDTH)
	{
		e->y = -1;
		while (e->y++ != HEIGHT)
		{
			burns_scale(e, j);
			e->realx = 0;
			e->realy = 0;
			n = 0;
			while (++n != j->iteration && e->realx * e->realx + e->realy * e->realy <= 4.0)
					burns_square(e);
			n == j->iteration ? put_pixel_img(j, e->x, e->y, 0)
					: put_pixel_img(j, e->x, e->y, n * j->man->color);
		}
	}
	free(e);
	mlx_put_image_to_window(j->mlx, j->window, j->image, 0, 0);
}

void		burns_scale(t_burn *e, t_env *j)
{
	e->a = ((double)(e->x - (WIDTH / 2)) /
			(double)(WIDTH / 4) * j->events->zoom + j->events->xshift);
	e->b = ((double)(e->y - (HEIGHT / 2)) /
			(double)(HEIGHT / 4) * j->events->zoom + j->events->yshift);
}

void	burns_square(t_pheen *e)
{
	e->prev_a = e->realx;
	e->realx = e->realx * e->realx - e->realy * e->realy + e->a;
	e->realy = 2 * fabs(e->realy * e->prev_a) + e->b;
	e->n += 1;
}