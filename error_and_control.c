/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyakici <hyakici@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:56:40 by hyakici           #+#    #+#             */
/*   Updated: 2025/07/22 14:26:15 by hyakici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include <stdio.h>

int	ft_control(int ac, char **av)
{
	if (ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
		return (MANDEL);
	if (ac == 2 && !ft_strcmp(av[1], "julia"))
		return (JULIA);
	av[2] = ft_strtrim(av[2], " ");
	av[3] = ft_strtrim(av[3], " ");
	if (ac == 4 && !ft_strcmp(av[1], "julia") && is_double(av[2])
		&& is_double(av[3]))
		return (JULIA);
	return (0);
}

void	params_error(void)
{
	write(2, ERR_L1, 38);
	write(2, ERR_L2, 46);
	write(2, ERR_L3, 57);
}
