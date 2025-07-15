/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyakici <hyakici@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:03:07 by hyakici           #+#    #+#             */
/*   Updated: 2025/07/15 18:59:25 by hyakici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static void	ft_tolower(char *c)
{
	while (c && *c)
	{
		if (*c >= 'A' && *c <= 'Z')
			*c += ' ';
		c++;
	}
}

static void	data_init(t_fractol *fractl)
{
	fractl->f_iterations = MAX_ITERATION;
	fractl->hypothenus = 4;
	fractl->shift_lr = 0;
	fractl->shift_ud = 0;
	fractl->f_zoom = 1;
}

static void	fractal_initializer(t_fractol *fract, char *name)
{
	fract->f_connection = mlx_init();
	fract->f_window = mlx_new_window(fract->f_connection, WIDTH, HEIGHT, name);
	if (!fract->f_window)
	{
		mlx_destroy_display(fract->f_connection);
		free(fract->f_connection);
		return ;
	}
	fract->img.img_ptr = mlx_new_image(fract->f_connection, WIDTH, HEIGHT);
	if (!fract->img.img_ptr)
	{
		mlx_destroy_window(fract->f_connection, fract->f_window);
		mlx_destroy_display(fract->f_connection);
		free(fract->f_connection);
		return ;
	}
	fract->img.pixel_ptr = mlx_get_data_addr(fract->img.img_ptr,
			&fract->img.bitperpixel, &fract->img.size_line, &fract->img.endian);
	fractal_events(fract);
	data_init(fract);
}

static void	params_error(void)
{
	write(2, ERR_L1, 38);
	write(2, ERR_L2, 46);
	write(2, ERR_L3, 57);
}

int	main(int argc, char **argv)
{
	t_fractol	frctl;

	ft_tolower(argv[1]);
	if (((argc == 2 || argc == 4) && !ft_strcmp(argv[1], "julia")))
	{
		frctl.name = 'J';
		frctl.julia_r = ft_atod(argv[2]);
		frctl.julia_img = ft_atod(argv[3]);
		fractal_initializer(&frctl, argv[1]);
		fractal_render(&frctl);
		mlx_loop(frctl.f_connection);
	}
	else if ((argc == 2 && !ft_strcmp(argv[1], "mandelbrot")))
	{
		fractal_initializer(&frctl, argv[1]);
		fractal_render(&frctl);
		mlx_loop(frctl.f_connection);
	}
	else
	{
		params_error();
		exit(1);
	}
}
