/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romashko <romashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:38:35 by romashko          #+#    #+#             */
/*   Updated: 2024/09/25 13:44:03 by romashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp_ptr;
	int		i;

	temp_ptr = lst;
	i = 0;
	while (temp_ptr != NULL)
	{
		temp_ptr = temp_ptr->next;
		i++;
	}
	return (i);
}
