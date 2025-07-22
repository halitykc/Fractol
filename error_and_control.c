/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyakici <hyakici@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:56:40 by hyakici           #+#    #+#             */
/*   Updated: 2025/07/22 15:49:14 by hyakici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include <ctype.h>
#include <stdio.h>

void	ft_trim_inplace(char **str)
{
	char	*start;
	char	*end;

	if (!str || !*str)
		return ;
	start = *str;
	while (ft_isspace((unsigned char)*start))
		start++;
	end = start;
	while (*end)
		end++;
	end--;
	while (end > start && ft_isspace((unsigned char)*end))
		end--;
	*(end + 1) = '\0';
	*str = start;
}

int	ft_control(int ac, char **av)
{
	if (ac >= 2 && ac <= 4)
	{
		if (ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
			return (MANDEL);
		if (ac > 2 && !ft_strcmp(av[1], "mandelbrot"))
			return (0);
		if (ac == 2 && !ft_strcmp(av[1], "julia"))
			return (JULIA);
		if (ac == 3 && !ft_strcmp(av[1], "julia"))
			return (0);
		ft_trim_inplace(&av[3]);
		ft_trim_inplace(&av[2]);
		if ((ac == 4) && !ft_strcmp(av[1], "julia") && is_double(av[2])
			&& is_double(av[3]))
			return (JULIA);
	}
	return (0);
}

void	params_error(void)
{
	write(2, ERR_L1, 38);
	write(2, ERR_L2, 46);
	write(2, ERR_L3, 57);
}
