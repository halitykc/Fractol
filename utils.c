/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyakici <hyakici@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:03:49 by hyakici           #+#    #+#             */
/*   Updated: 2025/07/22 12:54:30 by hyakici          ###   ########.fr       */
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

int	is_double(char *s)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (!s || !s[i])
		return (1);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] == '.')
		{
			if (++dot > 1)
				return (0);
		}
		else if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (!(i == 1 && dot == 1));
}
