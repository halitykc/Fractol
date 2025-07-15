/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyakici <hyakici@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:03:27 by hyakici           #+#    #+#             */
/*   Updated: 2025/07/15 15:11:39 by hyakici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_put_pixel(int x, int y, t_img *frct, int color)
{
	int	offset;

	offset = (y * frct->size_line) + (x * (frct->bitperpixel / 8));
	*(unsigned int *)(offset + frct->pixel_ptr) = color;
}

void	render_calculations_julia(int x, int y, t_fractol *fractol)
{
	t_coordinate	z;
	t_coordinate	c;
	int				i;
	int				color;

	i = -1;
	c.real = fractol->julia_r;
	c.imaginary = fractol->julia_img;
	z.real = ft_scale(x, SCALE_MIN, SCALE_MAX, WIDTH) * fractol->f_zoom
		+ fractol->shift_lr;
	z.imaginary = ft_scale(y, SCALE_MAX, SCALE_MIN, HEIGHT) * fractol->f_zoom
		+ fractol->shift_ud;
	while (++i < fractol->f_iterations)
	{
		z = sumcomplex(sqr_number(z), c);
		if ((z.real * z.real) + (z.imaginary
				* z.imaginary) > fractol->hypothenus)
		{
			color = ft_scale(i, 0x000000, 0xffffff, fractol->f_iterations);
			ft_put_pixel(x, y, &fractol->img, color);
			return ;
		}
	}
	ft_put_pixel(x, y, &fractol->img, 0x000001);
}

void	render_calculations_mandel(int x, int y, t_fractol *fractol)
{
	t_coordinate	z;
	t_coordinate	c;
	int				i;
	int				color;

	i = -1;
	z.real = 0.0;
	z.imaginary = 0.0;
	c.real = ft_scale(x, SCALE_MIN, SCALE_MAX, WIDTH) * fractol->f_zoom
		+ fractol->shift_lr;
	c.imaginary = ft_scale(y, SCALE_MAX, SCALE_MIN, HEIGHT) * fractol->f_zoom
		+ fractol->shift_ud;
	while (++i < fractol->f_iterations)
	{
		z = sumcomplex(sqr_number(z), c);
		if ((z.real * z.real) + (z.imaginary
				* z.imaginary) > fractol->hypothenus)
		{
			color = ft_scale(i, 0x000000, 0xffffff, fractol->f_iterations);
			ft_put_pixel(x, y, &fractol->img, color);
			return ;
		}
	}
	ft_put_pixel(x, y, &fractol->img, 0x000001);
}

void	fractal_render(t_fractol *frctl)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (frctl->name == 'J')
				render_calculations_julia(x, y, frctl);
			else
				render_calculations_mandel(x, y, frctl);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(frctl->f_connection, frctl->f_window,
		frctl->img.img_ptr, 0, 0);
}
