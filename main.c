/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:41:44 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/16 17:07:45 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     ft_spliter(char *str, t_env *e)
{
    if (e->fract == 0)
    {
        if (ft_strequ("mandelbrot", str))
        {
            frac = 1;
        }
        draw(e);
    }
    else
    {
        ft_print_usage();
        exit(1);
    }
    return (0);
}

int     draw(t_env *e)
{
    mlx_clear_window(e->mlx, e->window);
    if (e->frac == 1)
    {
        mandelbrot(e);
        controls(e);
    }
    return (0);
}

int     main(int ac, char **av)
{
    t_env e;

   e = init_env();
   e->mlx = mlx_init();
   e->window = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Frac");
   e->image = mlx_new_image(e->mlx, WIDTH, HEIGHT);
   e->image_ptr = mlx_get_data_addr(e->image, &(e->bpp), &(e->sl), &(e->endian));
   ft_spliter(av[1], e);
   	mlx_hook(e->window, 4, 0, mouse_hook, e);
	mlx_hook(e->window, 2, 0, key_down, e);
	mlx_hook(e->window, 5, 0, mouse_unhook, e);
	mlx_hook(e->window, 6, 0, motion_hook, e);
	mlx_loop(e->mlx);
    return (0); 
}