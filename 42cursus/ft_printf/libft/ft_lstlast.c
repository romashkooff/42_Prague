/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romashko <romashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:27:24 by romashko          #+#    #+#             */
/*   Updated: 2024/09/26 13:55:42 by romashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp_ptr;

	if (lst == NULL)
		return (NULL);
	temp_ptr = lst;
	while (temp_ptr->next != NULL)
	{
		temp_ptr = temp_ptr->next;
	}
	return (temp_ptr);
}
