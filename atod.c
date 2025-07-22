/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyakici <hyakici@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:17:44 by hyakici           #+#    #+#             */
/*   Updated: 2025/07/22 16:53:03 by hyakici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\r')
		return (1);
	if (c == '\n' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && i <= 2147483647)
	{
		i++;
	}
	return (i);
}

static int	is_negativ(char *nbr)
{
	while (nbr && *nbr && ft_isspace(*nbr))
		nbr++;
	if (*nbr == '-')
		return (1);
	return (0);
}

static int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	s;

	res = 0;
	s = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			s = s * -1;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9') && nptr[i])
		res = res * 10 + (nptr[i++] - '0');
	return (s * res);
}

double	ft_atod(char *nbr)
{
	double	res;
	int		i;
	double	j;
	int		sign;

	j = 1;
	sign = 1;
	if (!nbr)
		return (0);
	res = ft_atoi(nbr);
	if (is_negativ(nbr))
		sign = -1;
	while (*nbr && *nbr != '.')
		nbr++;
	if (*nbr == '.')
		nbr++;
	i = ft_strlen(nbr);
	while (i-- > 0)
		j *= 10;
	res += (double)ft_atoi(nbr) * sign / j;
	return (res);
}
