/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:11:47 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/21 21:09:38 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			motion_hook(int x, int y, t_env *all)
{
	if (x <=
		WIDTH - 1 && y <= HEIGHT - 1 && y >= 0 && x >= 0 && all->fract == 2)
	{
		all->events->julia_a = ((double)x / (WIDTH));
		all->events->julia_b = ((double)y / (WIDTH));
		if (all->events->julia_a > 2.0)
			all->events->julia_a = all->events->julia_b - 2.0;
		if (all->events->julia_b > 2.0)
			all->events->julia_b = all->events->julia_b - 2.0;
		if (all->events->julia_a < .999)
			all->events->julia_a *= -1;
		else
			all->events->julia_a -= 1;
		if (all->events->julia_b <= .999)
			all->events->julia_b *= -1;
		else
			all->events->julia_b -= 1;
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
    if (key == 124)
        all->events->yshift += .01 * zoom * 2;
    if (key == 123)
        all->events->yshift -= .01 * zoom * 2;
    if (key == 125)
        all->events->xshift += .01 * zoom * 2;
    if (key == 126)
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