/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:11:47 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/27 20:38:16 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_hook(int btn, int x, int y, t_env *all)
{
	if (btn == 5)
		all->events->zoom -= (all->events->zoom / 10);
	if (btn == 4)
		all->events->zoom += (all->events->zoom / 10);
	draw(all);
	return (0);
}

int			motion_hook(int x, int y, t_env *all)
{
	
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		if (all->fract == 2)
		{
			all->events->julia_a = ((double)x / (WIDTH));
			all->events->julia_b = ((double)y / (WIDTH));
			if (all->events->julia_a > 2.0)
				all->events->julia_a = all->events->julia_b - 2.0;
			if (all->events->julia_b > 2.0)
				all->events->julia_b = all->events->julia_b - 2.0;
		}
		draw(all);
	}
	return (0);
}

int keyhook_down(int key, t_env *all)
{
    double  zoom;

    zoom = all->events->zoom;
    if (key == 53)
        exit (1);
    if (key == 13)
        all->events->zoom -= (zoom / 10);
    if (key == 1)
        all->events->zoom += (zoom / 10);
    if (key == 125)
        all->events->yshift += .01 * zoom * 2;
    if (key == 126)
        all->events->yshift -= .01 * zoom * 2;
    if (key == 124)
        all->events->xshift += .01 * zoom * 2;
    if (key == 123)
        all->events->xshift -= .01 * zoom * 2;
    return (0);
}

int keyhook(int key, t_env *e)
{
	if (key == 116)
		e->iteration += 10;
	if (key == 121 && e->iteration > 10)
		e->iteration -= 10;
	if (key == 115 && e->man->color <= 555745280)
		e->man->color *= 2;
	if (key == 119 && e->man->color > 100)
		e->man->color /= 5;
	keyhook_down(key, e);
	draw(e);
	return (0);
}


