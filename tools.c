/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:41:55 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/21 21:27:23 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		add_thread(t_juul *all)
{
	all->a = all->zx + all->prev_a;
	all->b = all->zy + all->prev_b;
}

t_juul		*square_juul(t_juul *all)
{
	double tmp;
	
	tmp = (all->a * all->a) - (all->b * all->b);
	all->zy = 2 * all->a * all->b;
	all->zx = tmp;
	add_thread(all);
	return (all);
}

void    put_pixel_img(t_env *j, int x, int y, int color)
{
    t_env *e;
    int hex;

    e = j;
    if (x < WIDTH && y < HEIGHT)
    {
        hex = mlx_get_color_value(e->mlx, color);
        ft_memcpy(e->image_ptr + 4 * WIDTH * y + x * 4, &hex, sizeof(int));
    }
}

void		find_julia_ab(t_juul *all, t_env *e)
{
	all->a = ((double)(all->x - (WIDTH / 2)) /
			(double)(WIDTH / 4) * e->events->zoom + e->events->xshift);
	all->b = ((double)(all->y - (HEIGHT / 2)) /
			(double)(HEIGHT / 4) * e->events->zoom + e->events->yshift);
	all->n = 0;
}

void		add_julia_ab(t_juul *all, t_env *e)
{
	t_juul	*j;

	j = all;
	j->prev_a = e->events->julia_a;
	j->prev_b = e->events->julia_b;
}