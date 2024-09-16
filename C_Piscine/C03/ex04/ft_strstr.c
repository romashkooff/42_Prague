/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oromashk <oromashk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 20:01:31 by oromashk          #+#    #+#             */
/*   Updated: 2024/08/13 12:37:32 by oromashk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	char	*temp_ptr;
	int		temp;

	i = 0;
	j = 0;
	temp = 0;
	if (to_find[j] == '\0')
		return (str);
	while (str[i] != '\0' && to_find[j] != '\0')
	{
		temp_ptr = str + temp;
		while ((str[i] == to_find[j]) || to_find[j] == '\0')
		{
			if (to_find[j] == '\0')
				return (temp_ptr);
			i++;
			j++;
		}
		temp++;
		i = temp;
		j = 0;
	}
	return (0);
}

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;

// 	s1 = "42 1337 Network 2021 piscine Benguerir Khouribga";
// 	s2 = "piscine";
// 	ft_strstr(s1, s2);
// }
