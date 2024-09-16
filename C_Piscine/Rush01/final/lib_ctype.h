/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ctype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 00:13:27 by asagymba          #+#    #+#             */
/*   Updated: 2024/08/18 00:17:34 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Of course not all functions/constants from <ctype.h> are implemented here,
 * only those that this project needs. */
#ifndef LIB_CTYPE_H
# define LIB_CTYPE_H

/**
 * Checks, if character is a whitespace or not ($ man 3 isspace).
 * @param c	A character.
 * @return	1, if yes;
 * 		0 otherwise.
 */
int	ft_isspace(int c);

/**
 * Checks, if character is a digit or not.
 * @param c	A character.
 * @return	1, if yes;
 * 		0 otherwise.
 */
int	ft_isdigit(int c);

#endif	/* LIB_CTYPE_H */
