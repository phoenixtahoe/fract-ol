#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1280
# define HEIGHT 720
# define THREAD 1

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

typedef struct  s_tools
{
    int i;
    int x;
    int y;
    char *line;
}               t_tools;

typedef struct s_thread
{
    pthread_t   thread[1];
}              t_thread

tpyedef struct  s_env
{
    t_thread    *thread;
    void        mlx;
    void        interation;
}               t_env;