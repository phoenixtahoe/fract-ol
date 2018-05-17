/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:41:55 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/16 16:43:26 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    put_pixel_img(t_env *julia, int x, int y, int color)
{
    t_env *e;
    int hex;

    e = j;
    if (x < WIDTH && y < HEIGHT)
    {
        mlx_get_color_value(e->mlx, color);
        ft_memcpy(e->image + 4 * WITDH * x * y * 4, &hex, sizeof(int));
    }
}