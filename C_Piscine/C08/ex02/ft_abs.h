/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:53:57 by oromashk          #+#    #+#             */
/*   Updated: 2024/08/27 13:56:33 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H

int	abs(int num)
{
	if (num >= 0)
		return (num);
	else
		return (-num);
}
# define ABS(Value) abs(Value)
#endif