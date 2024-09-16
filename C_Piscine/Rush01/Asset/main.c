/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 00:04:33 by asagymba          #+#    #+#             */
/*   Updated: 2024/08/18 01:35:34 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_check_input.h"
#include "lib_string.h"
#include "ft_count_words.h"
#include "ft_prepare_possible_values.h"

#define ERROR_MSG	"Error\n"

#define INVALID_ARGS	1

int	main(int argc, char **argv)
{
	int		args_side_cnt;
	char	***possible_values;

	if (!(argc > 1) || !ft_check_input(*(++argv)))
	{
		write(1, ERROR_MSG, ft_strlen(ERROR_MSG));
		return (INVALID_ARGS);
	}
	args_side_cnt = (ft_count_words(*argv) / 4);
	possible_values = ft_prepare_possible_values(args_side_cnt, *argv);
	return (0);
}
