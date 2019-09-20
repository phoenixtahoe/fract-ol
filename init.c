/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:41:49 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/29 20:27:48 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env	*init(void)
{
	t_env *e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		exit(1);
	if (!(e->man = (t_man *)malloc(sizeof(t_man))))
		exit(1);
	if (!(e->events = (t_events *)malloc(sizeof(t_events))))
		exit(1);
	if (!(e->juul = (t_juul *)malloc(sizeof(t_juul))))
		exit(1);
	if (!(e->burn = (t_burn *)malloc(sizeof(t_burn))))
		exit(1);
	e->burn->ab = .0;
	e->burn->ba = .0;
	e->juul->ab = -.73;
	e->juul->ba = -.19;
	e->iteration = 50;
	e->fract = 0;
	e->man->color = 22;
	e->events->zoom = 1;
	e->events->shifty = 0;
	e->events->shiftx = 0;
	return (e);
}
