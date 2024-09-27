/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romashko <romashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:40:50 by romashko          #+#    #+#             */
/*   Updated: 2024/09/27 14:45:21 by romashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp_ptr;

	temp_ptr = lst;
	while (temp_ptr != NULL)
	{
		f(temp_ptr->content);
		temp_ptr = temp_ptr->next;
	}
}
