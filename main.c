/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:41:44 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/21 21:10:30 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			splitter(char *str, t_env *e)
{
	if (e->fract == 0)
	{
		if (ft_strequ("mandelbrot", str))
			e->fract = 1;
		if (ft_strequ("juul", str))
			e->fract = 2;
		draw(e);
	}
	return (0);
}

int			draw(t_env *e)
{
	mlx_clear_window(e->mlx, e->window);
	if (e->fract == 1)
	{
		mandelbrot(e);
	}
	if (e->fract == 2)
	{
		thread_create(e);
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_env	*e;

	e = init_env();
	e->mlx = mlx_init();
	e->window = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Fractol");
	e->image = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->image_ptr = mlx_get_data_addr(e->image,
		&(e->bpp), &(e->sl), &(e->endian));
	splitter(av[1], e);
	mlx_hook(e->window, 2, 0, keyhook, e);
	mlx_hook(e->window, 6, 0, motion_hook, e);
	mlx_loop(e->mlx);
	return (0);
}