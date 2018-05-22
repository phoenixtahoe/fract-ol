/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:07:46 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/21 21:22:43 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*julia1(void *j)
{
	t_env *e;
	t_juul *all;
	
	e = j;
	all = (t_juul *)malloc(sizeof(t_juul));
	all->x = 0;
	add_julia_ab(all, e);
	while (all->x++ != WIDTH / 2)
	{
		all->y = -1;
		while (all->y++ != WIDTH / 2)
		{
			find_julia_ab(all, e);
			while(++all->n != e->iteration && (sqrt((all->a * all->a)
					+ (all->b * all->b)) < 2.0))
					square_juul(all);
			all->n == e->iteration ? put_pixel_img(e, all->x, all->y, 0)
					: put_pixel_img(e, all->x, all->y, all->n * e->man->color);
		}
	}
	free(all);
	return (NULL);
}

void	*julia2(void *j)
{
	t_env *e;
	t_juul *all;
	
	e = j;
	all = (t_juul *)malloc(sizeof(t_juul));
	all->x = -1;
	add_julia_ab(all, e);
	while (all->x++ != WIDTH / 2)
	{
		all->y = WIDTH / 2;
		while (all->y++ != WIDTH / 2)
		{
			find_julia_ab(all, e);
			while(++all->n != e->iteration && (sqrt((all->a * all->a)
					+ (all->b * all->b)) < 2.0))
					square_juul(all);
			all->n == e->iteration ? put_pixel_img(e, all->x, all->y, 0)
					: put_pixel_img(e, all->x, all->y, all->n * e->man->color);
		}
	}
	free(all);
	return (NULL);
}

void	*julia3(void *j)
{
	t_env *e;
	t_juul *all;
	
	e = j;
	all = (t_juul *)malloc(sizeof(t_juul));
	all->x = WIDTH / 2;
	add_julia_ab(all, e);
	while (all->x++ != WIDTH / 2)
	{
		all->y = WIDTH / 2;
		while (all->y++ != WIDTH / 2)
		{
			find_julia_ab(all, e);
			while(++all->n != e->iteration && (sqrt((all->a * all->a)
					+ (all->b * all->b)) < 2.0))
					square_juul(all);
			all->n == e->iteration ? put_pixel_img(e, all->x, all->y, 0)
					: put_pixel_img(e, all->x, all->y, all->n * e->man->color);
		}
	}
	free(all);
	return (NULL);
}

void	*julia4(void *j)
{
	t_env *e;
	t_juul *all;
	
	e = j;
	all = (t_juul *)malloc(sizeof(t_juul));
	all->x = WIDTH / 2;
	add_julia_ab(all, e);
	while (all->x++ != WIDTH / 2)
	{
		all->y = 0;
		while (all->y++ != WIDTH / 2)
		{
			find_julia_ab(all, e);
			while(++all->n != e->iteration && (sqrt((all->a * all->a)
					+ (all->b * all->b)) < 2.0))
					square_juul(all);
			all->n == e->iteration ? put_pixel_img(e, all->x, all->y, 0)
					: put_pixel_img(e, all->x, all->y, all->n * e->man->color);
		}
	}
	free(all);
	return (NULL);
}

int		*thread_create(t_env *e)
{
	int i;
	
	i = 1;
	pthread_create(&e->thread->thread[1], NULL, julia1, e);
	pthread_create(&e->thread->thread[2], NULL, julia2, e);
	pthread_create(&e->thread->thread[3], NULL, julia3, e);
	pthread_create(&e->thread->thread[4], NULL, julia4, e);
	while (i != 4)
		i++;
		pthread_join(e->thread->thread[i], NULL);
	mlx_put_image_to_window(e->mlx, e->window, e->image, 0, 0);
	return (0);
}