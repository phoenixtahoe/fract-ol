/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:41:55 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/27 18:17:03 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int			fractols(char *str, t_env *e)
{
	if (e->fract == 0)
	{
		if (ft_strequ("mandelbrot", str))
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

int			draw(t_env *e)
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
		ft_putstr("Usage: ./fractol [Mandelbrot] [juul] [pheen]\n");
		exit(1);
	}
	return (0);
}

void    ft_exit(t_env *all)
{
    free(all->events);
    free(all->man);
    free(all);
    exit(1);
}