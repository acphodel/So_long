/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:43:15 by maavalya          #+#    #+#             */
/*   Updated: 2024/01/25 15:43:17 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>

int main () {
	const char str[] = "https://wwwtutorialspoint.com";
	const char ch = '.';
	char *ret;

	ret = ft_strchr(str, ch);

	printf("String after |%c| is - |%s|\n", ch, ret);

	return(0);
}*/
