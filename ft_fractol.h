

#ifndef FT_FRACTOL_H
#define FT_FRACTOL_H

#include <stdlib.h>
#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define HEIGHT 800
#define WIDTH 800


typedef struct s_img
{
	void *img_ptr;
	char *pixel_ptr;
	int	bitperpixel;
	int endian;
	int	size_line;
}			t_img;



typedef struct s_fractol
{
	void *f_connection;
	void *f_window;
	t_img	img;
}			t_fractol;



int	ft_strcmp(const char *s1, const char *s2);




#endif
