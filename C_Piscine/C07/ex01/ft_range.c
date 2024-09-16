/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:20:15 by oromashk          #+#    #+#             */
/*   Updated: 2024/08/19 21:09:01 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	size;
	int	i;

	if (min >= max)
		return (0);
	size = max - min;
	i = 0;
	arr = (int *)malloc(size * sizeof(int));
	while (size != 0)
	{
		arr[i] = min + i;
		size--;
		i++;
	}
	return (arr);
}

// int	main(void)
// {
// 	ft_range(1, 5);
// }
