/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 00:09:28 by asagymba          #+#    #+#             */
/*   Updated: 2024/08/18 01:01:44 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_INPUT_H
# define FT_CHECK_INPUT_H

/**
 * Checks, if all characters in "input" are whitespaces or digits,
 * if square root of count of arguments exists
 * (since all maps are squares: 1x1, 2x2, etc.),
 * and if we have at least two 1's in arguments.
 * @param input	A string to check characters of.
 * @return	1, if all characters are ok;
 * 		0 otherwise.
 */
int	ft_check_input(const char *input);

#endif	/* FT_CHECK_INPUT_H */
