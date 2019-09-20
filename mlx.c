/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:11:47 by pdavid            #+#    #+#             */
/*   Updated: 2018/12/17 15:52:33 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int btn, int x, int y, t_env *e)
{
	if (btn == 5)
		e->events->zoom -= (e->events->zoom / 10);
	if (btn == 4)
		e->events->zoom += (e->events->zoom / 10);
	draw(e);
	return (0);
}

int		motion_hook(int x, int y, t_env *e)
{
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		if (e->fract == 2)
		{
			e->juul->ab = ((double)x / (WIDTH));
			e->juul->ba = ((double)y / (WIDTH));
			if (e->juul->ab > 2.0)
				e->juul->ab = e->juul->ab - 2.0;
			if (e->juul->ba > 2.0)
				e->juul->ba = e->juul->ba - 2.0;
		}
		draw(e);
	}
	return (0);
}

int		keys(int key, t_env *all)
{
	double	zoom;

	zoom = all->events->zoom;
	if (key == 53)
		exit(1);
	if (key == 13)
		all->events->zoom -= (zoom / 10);
	if (key == 1)
		all->events->zoom += (zoom / 10);
	if (key == 125)
		all->events->shifty += .01 * zoom * 2;
	if (key == 126)
		all->events->shifty -= .01 * zoom * 2;
	if (key == 124)
		all->events->shiftx += .01 * zoom * 2;
	if (key == 123)
		all->events->shiftx -= .01 * zoom * 2;
	return (0);
}

int		keyhook(int key, t_env *e)
{
	if (key == 116)
		e->iteration += 20;
	if (key == 121 && e->iteration > 20)
		e->iteration -= 20;
	if (key == 115 && e->man->color <= 99999999)
		e->man->color *= 2;
	if (key == 119 && e->man->color > 10)
		e->man->color /= 2;
	keys(key, e);
	draw(e);
	return (0);
}
