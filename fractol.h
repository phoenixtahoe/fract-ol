#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800
# define THREAD 4

# define XVAL tools->x
# define YVAL tools->y
# define LINE tools->line
# define SHITMAP tools->shitmap
# define PI 3.14159265359

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>

typedef struct		s_man
{
	double			prev_a;
	double			prev_b;
	double			y;
	double			x;
	double			a;
	double			zx;
	double			zy;
	double			b;
	int				color;
}					t_man;

typedef struct		s_thread
{
	pthread_t		thread[4];
}					t_thread;

typedef struct		s_events
{
	int				pageup;
	int				pagedown;
	int				intial_x;
	int				intial_y;
	int				mouse;
	double			zoom;
	double			yshift;
	double			xshift;
	int				colorshift;
	double			julia_a;
	double			julia_b;
}					t_events;

typedef struct		s_env
{
	t_thread		*thread;
	t_man			*man;
	t_events		*events;
	void			*mlx;
	void			*image;
	void			*image_ptr;
	void			*window;
	int				endian;
	int				sl;
	int				bpp;
	int				fract;
	int				iteration;
	int				maxiter;
}					t_env;

typedef struct		s_juul
{
	double			a;
	double			b;
	double			prev_a;
	double			prev_b;
	double			zx;
	double			zy;
	int				x;
	int				y;
	int				n;
}					t_juul;

t_env   *init_env(void);
void    ft_exit(t_env *all);
int     ft_printusage(void);
int keyhook_down(int key, t_env *all);
int keyhook(int key, t_env *e);
int     ft_spliter(char *str, t_env *e);
int     draw(t_env *e);
void    man_scale(t_env *e);
void    mandelbro(t_env *j);
t_man   *square(t_man *man);
void		controls_helper(t_env *j);
void		add_thread(t_juul *all);
t_juul		*square_juul(t_juul *all);
void    put_pixel_img(t_env *j, int x, int y, int color);
void	*julia(void *j);
void	juul_scale(t_env *e, t_juul *all);
int		*thread_create(t_env *e);
void		add_julia_ab(t_juul *all, t_env *e);
void		find_julia_ab(t_juul *all, t_env *e);
t_juul		*environment_cpy(t_env *j);
int			motion_hook(int x, int y, t_env *all);

#endif