/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyakici <hyakici@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:03:07 by hyakici           #+#    #+#             */
/*   Updated: 2025/07/11 11:03:09 by hyakici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	data_init(t_fractol *fractl)
{
	fractl->f_iterations = MAX_ITERATION;
	fractl->hypothenus = 4;
	fractl->shift_lr = 0;
}

void	fractal_initializer(t_fractol *fract, char *name)
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
	printf("S = %f\n", fract->shift_lr);
	data_init(fract);
}

int	main(int argc, char **argv)
{
	t_fractol	frctl;

	if ((argc == 2 && !ft_strcmp(argv[1], "Mandelbrot")) || (argc == 4
			&& !ft_strcmp(argv[1], "Julia")))
	{
		fractal_initializer(&frctl, argv[1]);
		fractal_render(&frctl);
		mlx_loop(frctl.f_connection);
	}
	else
	{
		exit(1);
	}
}
