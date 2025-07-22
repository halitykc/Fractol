/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyakici <hyakici@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:04:37 by hyakici           #+#    #+#             */
/*   Updated: 2025/07/22 14:07:00 by hyakici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

static int	ft_set_control(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	alen;

	if ((!s || !len) || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		alen = ft_strlen(s) - start;
	else
		alen = len;
	sub = malloc(alen + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start] && i < ft_strlen(s) && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (ft_set_control(set, s1[i]))
		i++;
	while (ft_set_control(set, s1[j]))
		j--;
	ptr = ft_substr(s1, i, (j - i + 1));
	return (ptr);
}
