/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:11:47 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/16 19:14:58 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int keyhook_down(int key, t_env *all)
{
    double  zoom;

    zoom = all->events->zoom;
    if (key == 53)
        exit;
    if (key == 13)
        all->events->zoom -= (zoom / 10);
    if (key == 1)
        all->events->zoom += (zoom / 10);
    if (key == 125)
        all->events->yshift += .01 * zoom * 2;
    if (key == 126)
        all->events->yshift -= .01 * zoom * 2;
    if (key == 123)
        all->events->xshift += .01 * zoom * 2;
    if (key == 124)
        all->events->xshift -= .01 * zoom * 2;
    return (0);
}