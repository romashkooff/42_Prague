/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:23:46 by oromashk          #+#    #+#             */
/*   Updated: 2024/08/26 19:35:37 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	size_calculation(int size, char **strs, char *sep)
{
	int	i;
	int	str_len;

	i = 0;
	str_len = ft_strlen(sep) * (size - 1);
	while (i != size)
	{
		str_len += ft_strlen(strs[i]);
		i++;
	}
	return (str_len);
}

char	*strs_concatination(int size, char **strs, char *sep, char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i != size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			str[k++] = strs[i][j++];
		}
		j = 0;
		if (++i != size)
		{
			while (sep[j] != '\0')
				str[k++] = sep[j++];
		}
	}
	str[k] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		str_len;

	if (size == 0)
	{
		str = (char *)malloc(sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str_len = size_calculation(size, strs, sep) + 1;
	str = (char *)malloc(str_len);
	if (str == NULL)
		return (NULL);
	str = strs_concatination(size, strs, sep, str);
	return (str);
}

// int	main(void)
// {
// 	int		size;
// 	char	*strs[] = {"sdfg", "sdfgsdfg", "sdfgdsfg"};
// 	char	*sep;

// 	size = 3;
// 	sep = "!66";
// 	ft_strjoin(size, strs, sep);
// }
