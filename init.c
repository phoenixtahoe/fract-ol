/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:41:49 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/21 21:08:23 by pdavid           ###   ########.fr       */
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
    if (!(e->thread = (t_thread *)malloc(sizeof(t_thread))))
        exit(1);
	e->events->julia_a = -.73;
	e->events->julia_b = -.19;
    e->iteration = 100;
    e->fract = 0;
    e->maxiter = 300;
    e->man->color = 524288;
    e->events->colorshift = 150;
    e->events->zoom = 1;
    e->events->yshift = 0;
    e->events->xshift = 0;
    return (e);
}

t_juul		*environment_cpy(t_env *j)
{
	t_juul	*e;

	e = (t_juul *)malloc(sizeof(t_juul));
	if (j->fract == 2)
	{
		e->prev_a = j->events->julia_a;
		e->prev_b = j->events->julia_b;
	}
	return (e);
}

void    ft_exit(t_env *all)
{
    free(all->thread);
    free(all->events);
    free(all->man);
    free(all);
    exit(1);
}