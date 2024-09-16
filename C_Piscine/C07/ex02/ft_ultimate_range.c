/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:01:38 by oromashk          #+#    #+#             */
/*   Updated: 2024/08/20 16:23:03 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	size;
	int	i;

	*range = NULL;
	if (min >= max)
		return (0);
	size = max - min;
	arr = (int *)malloc(size * sizeof(int));
	if (arr == NULL)
		return (-1);
	i = 0;
	while (size != 0)
	{
		arr[i] = min + i;
		size--;
		i++;
	}
	*range = arr;
	return (i);
}

// int	main(void)
// {
// 	int	**range;

// 	ft_ultimate_range(range, 10, 5);
// }
