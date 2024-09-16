/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:25:12 by oromashk          #+#    #+#             */
/*   Updated: 2024/08/10 15:12:10 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int		buffer_for_div;
	int		buffer_for_mod;

	buffer_for_div = *a / *b;
	buffer_for_mod = *a % *b;
	*a = buffer_for_div;
	*b = buffer_for_mod;
}

// int main()
// {
// 	int a;
// 	int b;

// 	a = 5;
// 	b = 2;
// 	ft_ultimate_div_mod(&a, &b);
// 	printf("%d", b);
// }
