/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyakici <hyakici@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:04:28 by hyakici           #+#    #+#             */
/*   Updated: 2025/07/15 18:23:24 by hyakici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static int	cls_win(t_fractol *fract)
{
	mlx_destroy_image(fract->f_connection, fract->img.img_ptr);
	mlx_destroy_window(fract->f_connection, fract->f_window);
	mlx_destroy_display(fract->f_connection);
	free(fract->f_connection);
	exit(0);
}

static int	key_events(int keysym, t_fractol *fractol)
{
	if (keysym == XK_Escape)
		cls_win(fractol);
	else if (keysym == XK_Right)
		fractol->shift_lr -= 0.1 * fractol->f_zoom;
	else if (keysym == XK_Left)
		fractol->shift_lr += 0.1 * fractol->f_zoom;
	else if (keysym == XK_Up)
		fractol->shift_ud -= 0.1 * fractol->f_zoom;
	else if (keysym == XK_Down)
		fractol->shift_ud += 0.1 * fractol->f_zoom;
	else if (keysym == XK_4)
		fractol->f_iterations += 1;
	else if (keysym == XK_5)
		fractol->f_iterations -= 1;
	fractal_render(fractol);
	return (0);
}

static int	zoom(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == 5)
		fractol->f_zoom *= 1.03;
	else if (button == 4)
		fractol->f_zoom /= 1.03;
	fractal_render(fractol);
	return (0);
}

void	fractal_events(t_fractol *fractol)
{
	mlx_hook(fractol->f_window, KeyPress, KeyPressMask, key_events, fractol);
	mlx_hook(fractol->f_window, ButtonPress, ButtonPress, zoom, fractol);
	mlx_hook(fractol->f_window, DestroyNotify, StructureNotifyMask, cls_win,
		fractol);
}
