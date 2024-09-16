/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:19:50 by oromashk          #+#    #+#             */
/*   Updated: 2024/08/10 18:55:00 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
// #include <stdio.h>

void	ft_ft(int *nbr)
{
	int	a;

	a = 42;
	*nbr = a;
}

// int	main(void)
// {
// 	int nbr;
// 	char str[20];

// 	ft_ft(&nbr);
// 	printf("%d", nbr);
// 	sprintf(str, "%d", nbr);
// 	write(1, &str, 2);
// }