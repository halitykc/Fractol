

#ifndef FT_FRACTOL_H
#define FT_FRACTOL_H

#include <stdlib.h>
#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define HEIGHT 800
#define WIDTH 800
#define SCALE_MAX 2
#define SCALE_MIN -2
#define MAX_ITERATION 42

typedef struct s_coordinate
{
	double	real;
	double	imaginary;
}				t_coordinate;


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
	int	f_iterations;
	int	hypothenus;
}			t_fractol;



int	ft_strcmp(const char *s1, const char *s2);
void	fractal_render(t_fractol *frctl);
double	ft_scale(double unscaled, double newmin, double newmax,double oldmax);
t_coordinate	sumcomplex(t_coordinate z1,t_coordinate z2);
t_coordinate	sqr_number(t_coordinate z);




#endif
