/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyakici <hyakici@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:07:27 by hyakici           #+#    #+#             */
/*   Updated: 2025/07/22 14:08:26 by hyakici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*c;

	if (!dest && !src)
		return (dest);
	p = (unsigned char *)dest;
	c = (unsigned char *)src;
	while (n--)
	{
		*p++ = *c++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;

	ptr = malloc(ft_strlen(s) + 1);
	if (!ptr)
		return (0);
	ft_memcpy(ptr, s, ft_strlen(s) + 1);
	return (ptr);
}
