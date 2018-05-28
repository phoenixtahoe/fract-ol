/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:41:49 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/27 19:24:05 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env   *init_env(void)
{
    t_env *e;

    if (!(e = (t_env *)malloc(sizeof(t_env))))
        exit(1);
    if (!(e->man = (t_man *)malloc(sizeof(t_man))))
        exit(1);
    if (!(e->events = (t_events *)malloc(sizeof(t_events))))
        exit(1);
	e->events->julia_a = -.73;
	e->events->julia_b = -.19;
    e->iteration = 50;
    e->fract = 0;
    e->maxiter = 300;
    e->man->color = 22;
    e->events->colorshift = 100;
    e->events->zoom = 1;
    e->events->yshift = 0;
    e->events->xshift = 0;
    return (e);
}