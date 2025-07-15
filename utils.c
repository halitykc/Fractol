/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyakici <hyakici@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:03:49 by hyakici           #+#    #+#             */
/*   Updated: 2025/07/15 19:40:02 by hyakici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

double	ft_scale(double unscaled, double newmin, double newmax, double oldmax)
{
	return ((newmax - newmin) * (unscaled - 0) / (oldmax - 0) + newmin);
}

t_coordinate	sumcomplex(t_coordinate z1, t_coordinate z2)
{
	t_coordinate	result;

	result.real = z1.real + z2.real;
	result.imaginary = z1.imaginary + z2.imaginary;
	return (result);
}

t_coordinate	sqr_number(t_coordinate z)
{
	t_coordinate	result;

	result.real = (z.real * z.real) - (z.imaginary * z.imaginary);
	result.imaginary = 2 * z.imaginary * z.real;
	return (result);
}

int	is_double(char *arg1, char *arg2)
{
	int	i;

	i = 0;
	if (!arg1 || !arg2)
		return (1);
	while (arg1[i])
	{
		if ((arg1[i] >= '0' && arg1[i] <= '9') || arg1[i] == '.'
			|| (arg1[i] == '-' || arg1[i] == '+'))
			i++;
		else
			return (0);
	}
	i = 0;
	while (arg2[i])
	{
		if ((arg2[i] >= '0' && arg2[i] <= '9') || arg2[i] == '.'
			|| (arg1[i] == '-' || arg1[i] == '+'))
			i++;
		else
			return (0);
	}
	return (1);
}
