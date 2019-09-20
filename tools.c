/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:41:55 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/28 21:04:46 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_img(t_env *e, int x, int y, int color)
{
	void	*i;
	int		hex;

	if (x < WIDTH && y < HEIGHT)
	{
		i = mlx_get_data_addr(e->image, &(e->bpp), &(e->sl), &(e->endian));
		hex = mlx_get_color_value(e->mlx, color);
		ft_memcpy(i + 4 * WIDTH * y + x * 4, &hex, sizeof(int));
	}
}

int		fractols(char *str, t_env *e)
{
	if (e->fract == 0)
	{
		if (ft_strequ("mandelbro", str))
			e->fract = 1;
		if (ft_strequ("juul", str))
			e->fract = 2;
		if (ft_strequ("burns", str))
			e->fract = 3;
		draw(e);
	}
	return (0);
}

void	options(t_env *e)
{
	mlx_string_put(e->mlx, e->window, 0,
		0, 0xFFFFFF, "Iterations! [+ PAGEUP] [- PAGEDOWN]");
	mlx_string_put(e->mlx, e->window, 0,
		20, 0xFFFFFF, "Change color! [+ Home] [- End]");
	mlx_string_put(e->mlx, e->window, 0,
		40, 0xFFFFFF, "Zoom! [+ W] [-S]");
	mlx_string_put(e->mlx, e->window, 0,
		60, 0xFFFFFF, "Move! [< ^ v >]");
}

int		draw(t_env *e)
{
	mlx_clear_window(e->mlx, e->window);
	if (e->fract == 1)
	{
		mandelbrot(e);
		options(e);
	}
	if (e->fract == 2)
	{
		juul(e);
		options(e);
	}
	if (e->fract == 3)
	{
		burns(e);
		options(e);
	}
	if (e->fract == 0)
	{
		ft_putstr("Usage: ./fractol [mandelbro] [juul] [burns]\n");
		exit(1);
	}
	return (0);
}

void	ft_exit(t_env *all)
{
	free(all->events);
	free(all->juul);
	free(all->burn);
	free(all->man);
	free(all);
	exit(1);
}
