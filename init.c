/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:41:49 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/16 17:04:42 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env   *init_env(void)
{
    t_env *e;

    if (!(e = (t_env *)malloc(sizeof(t_env)))
        exit(1);
    if (!(e->man = (t_man *)malloc(sizeof(t_man)))
        exit(1);
    if (!(e->events = (t_events *)malloc(sizeof(t_events)))
        exit(1);
    if (!(e->threads = (t_threads *)malloc(sizeof(t_threads))
        exit(1);
    e->iteration = 100;
    e->frac = 0;
    e->maxiter = 300;
    e->man->color = 256;
    e->events->colorshift = 150;
    e->events->zoom = 1;
    e->events->yshift = 0;
    e->events->xshift = 0;
    return (e);
}

void    ft_exit(t_env *all)
{
    free(all->threads);
    free(all->events);
    free(all->man);
    free(all);
    exit(1);
}

int     ft_printusage(void)
{
    ft_putstr("NOT VALID");
    ft_putstr("Correct Usage: ./frac mandelbrot");
    exit(1);
}