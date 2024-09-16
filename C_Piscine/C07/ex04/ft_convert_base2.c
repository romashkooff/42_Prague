/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:45:15 by oromashk          #+#    #+#             */
/*   Updated: 2024/08/26 19:37:10 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include <stdlib.h>

int		str_len(char *base);
int		char_to_value(char c, char *base);
int		base_check(char *base);
int		ft_atoi_base(char *str, char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	get_num_len(int nbr, char *base)
{
	int	len;
	int	base_len;

	len = 0;
	if (nbr < 0)
	{
		len = 1;
	}
	base_len = str_len(base);
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}
