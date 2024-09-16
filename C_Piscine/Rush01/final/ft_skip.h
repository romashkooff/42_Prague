/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 00:32:04 by asagymba          #+#    #+#             */
/*   Updated: 2024/08/18 00:44:23 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SKIP_H
# define FT_SKIP_H

/**
 * Skips whitespaces in str.
 * @param str	A string to skip whitespaces in.
 */
void	ft_skip_ws(const char **str);

/**
 * Skips digits in str.
 * @param str	A string to skip digits in.
 */
void	ft_skip_digits(const char **str);

#endif	/* FT_SKIP_WS_H */
