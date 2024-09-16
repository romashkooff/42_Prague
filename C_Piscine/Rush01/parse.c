/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlyshchu <hlyshchu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:41:29 by hlyshchu          #+#    #+#             */
/*   Updated: 2024/08/17 22:14:43 by hlyshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_error(void)
{
	write(1, "Error\n", 6);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

void	ft_free_array(int **array, int size)
{
	for (int i = 0; i < size; i++)
		free(array[i]);
	free(array);
}

int	**ft_parse(char *str, int *side_out)
{
	int	len;
	int	side;
	int	**array;
	int	i;
	int	j;

	if (!*str)
	{
		ft_error();
		return (NULL);
	}
	len = ft_strlen(str);
	side = ft_sqrt((len + 1) / 2);
	if (side == 0)
	{
		ft_error();
		return (NULL);
	}
	array = (int **)malloc(4 * sizeof(int *));
	if (!array)
	{
		ft_error();
		return (NULL);
	}
	i = 0;
	while (i < 4)
	{
		array[i] = (int *)malloc(side * sizeof(int));
		if (!array[i])
		{
			ft_error();
			ft_free_array(array, i);
			return (NULL);
		}
		j = 0;
		while (j < side)
		{
			while (*str == ' ')
				str++;
			if (*str < '0' || *str > '9')
			{
				ft_error();
				ft_free_array(array, 4);
				return (NULL);
			}
			array[i][j] = *str - '0';
			str++;
			j++;
		}
		i++;
	}
	*side_out = side;
	return (array);
}

int	main(void)
{
	char	*str;
	int		side;
	int		**result;

	str = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	result = ft_parse(str, &side);
	if (result)
	{
		// Print the 2D array
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < side; j++)
				printf("%d ", result[i][j]);
			printf("\n");
		}
		// Free the allocated memory
		ft_free_array(result, 4);
	}
	return (0);
}
