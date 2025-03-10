/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <maavalya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:14:48 by maavalya          #+#    #+#             */
/*   Updated: 2024/05/11 12:23:20 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*trim_back(char const *s1, char const *set)
{
	char	*res;
	size_t	len;
	int		flag;
	int		i;

	flag = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	len = ft_strlen((char *)s1);
	while (len != 0)
	{
		if (check_sep(s1[len - 1], (char *)set) == 1)
			len--;
		else
			break ;
	}
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, (char *)s1, len + 1);
	return (res);
}

void	only_whitespace(char	*res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		if (!check_sep(res[i], "\n\t\v\f\r "))
			return ;
		i++;
	}
	free(res);
	ft_printf("Error\nOnly whitespaces in map");
	exit(1);
}
