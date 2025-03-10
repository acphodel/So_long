/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:46:12 by maavalya          #+#    #+#             */
/*   Updated: 2024/01/26 13:46:13 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	size_t			i;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		res = ft_calloc(1, sizeof(char));
		if (!res)
			return (NULL);
		return (res);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	return (res);
}

/*#include <stdio.h>
int main(void)
{
	const char *string = "aaabbbbbbaaaa";
	printf("%s ", ft_substr(string, 3, 5));
	return (0);
}*/