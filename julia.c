/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:07:46 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/27 17:53:57 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	juul(t_env *j)
{
	t_env *e;
	t_juul *all;
	
	e = j;
	all = (t_juul *)malloc(sizeof(t_juul));
	all->x = -1;
	while (all->x++ != WIDTH)
	{
		all->y = -1;
		while (all->y++ != WIDTH)
		{
			juul_scale(all, e);
			while(++all->n != e->iteration && (sqrt((all->a * all->a)
					+ (all->b * all->b)) < 2.0))
					square_juul(all);
			all->n == e->iteration ? put_pixel_img(e, all->x, all->y, 0)
					: put_pixel_img(e, all->x, all->y, all->n * e->man->color);
		}
	}
	free(all);
	mlx_put_image_to_window(e->mlx, e->window, e->image, 0, 0);
}

t_juul		*square_juul(t_juul *all)
{
	double tmp;
	
	tmp = (all->a * all->a) - (all->b * all->b);
	all->zy = 2 * all->a * all->b;
	all->zx = tmp;
	all->a = all->zx + all->prev_a;
	all->b = all->zy + all->prev_b;
	return (all);
}

void		juul_scale(t_juul *all, t_env *e)
{
	t_juul	*j;
	
	j = all;
	j->prev_a = e->events->julia_a;
	j->prev_b = e->events->julia_b;
	all->a = ((double)(all->x - (WIDTH / 2)) /
			(double)(WIDTH / 4) * e->events->zoom + e->events->xshift);
	all->b = ((double)(all->y - (HEIGHT / 2)) /
			(double)(HEIGHT / 4) * e->events->zoom + e->events->yshift);
	all->n = 0;
}