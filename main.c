/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:41:44 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/27 19:01:49 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			main(int ac, char **av)
{
	t_env	*e;

	e = init_env();
	e->mlx = mlx_init();
	e->window = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Fractol");
	e->image = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->image_ptr = mlx_get_data_addr(e->image,
		&(e->bpp), &(e->sl), &(e->endian));
	fractols(av[1], e);
	mlx_hook(e->window, 4, 0, mouse_hook, e);
	mlx_hook(e->window, 2, 0, keyhook, e);
	mlx_hook(e->window, 6, 0, motion_hook, e);
	mlx_loop(e->mlx);
	return (0);
}