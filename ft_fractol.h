/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyakici <hyakici@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:32:14 by hyakici           #+#    #+#             */
/*   Updated: 2025/07/11 11:32:19 by hyakici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define HEIGHT 800
# define WIDTH 800
# define SCALE_MAX 2
# define SCALE_MIN -2
# define MAX_ITERATION 2

typedef struct s_coordinate
{
	double		real;
	double		imaginary;
}				t_coordinate;

typedef struct s_img
{
	void		*img_ptr;
	char		*pixel_ptr;
	int			bitperpixel;
	int			endian;
	int			size_line;
}				t_img;

typedef struct s_fractol
{
	void		*f_connection;
	void		*f_window;
	t_img		img;
	int			f_iterations;
	int			hypothenus;
	double		shift_lr;
	double		shift_ud;
}				t_fractol;

int				ft_strcmp(const char *s1, const char *s2);
void			fractal_render(t_fractol *frctl);
double			ft_scale(double unscaled, double newmin, double newmax,
					double oldmax);
t_coordinate	sumcomplex(t_coordinate z1, t_coordinate z2);
t_coordinate	sqr_number(t_coordinate z);

void			fractal_events(t_fractol *fractol);

#endif
