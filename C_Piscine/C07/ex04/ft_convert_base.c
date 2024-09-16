/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:45:18 by oromashk          #+#    #+#             */
/*   Updated: 2024/08/26 19:38:05 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include <stdlib.h>

int	get_num_len(int nbr, char *base);

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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		number;
	int		num_len;
	char	*result;
	int		i;

	if (!base_check(base_from) || !base_check(base_to))
		return (NULL);
	number = ft_atoi_base(nbr, base_from);
	num_len = get_num_len(number, base_to);
	result = (char *)malloc(sizeof(char) * (num_len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	if (number < 0)
	{
		result[i++] = '-';
		number = -number;
	}
	result[num_len] = '\0';
	while (num_len > i)
	{
		result[--num_len] = base_to[number % str_len(base_to)];
		number /= str_len(base_to);
	}
	return (result);
}
