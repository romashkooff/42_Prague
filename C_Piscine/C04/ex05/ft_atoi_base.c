/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:02:28 by oromashk          #+#    #+#             */
/*   Updated: 2024/08/18 18:42:35 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int	str_len(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	char_to_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	base_check(char *base)
{
	int		i;
	int		j;
	char	temp;

	if (str_len(base) <= 1)
	{
		return (0);
	}
	i = 0;
	while (i <= str_len(base))
	{
		temp = base[i];
		j = i;
		while (j <= str_len(base) && base[j] != '\0')
		{
			if (temp == base[j + 1] || temp == '-' || temp == '+')
				return (0);
			if ((temp >= 9 && temp <= 13) || temp == ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	res;

	if (base_check(base) == 0)
		return (0);
	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] != '\0')
	{
		if (char_to_value(str[i], base) == -1)
			break ;
		res = res * str_len(base) + char_to_value(str[i], base);
		i++;
	}
	return (sign * res);
}
