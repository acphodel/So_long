/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:57:49 by maavalya          #+#    #+#             */
/*   Updated: 2024/01/25 15:57:51 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (char) c)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>

int main () {
	const char str[] = "https://www.tutorialspoint.com";
	const char ch = '.';
	char *ret;

	ret = ft_strrchr(str, ch);

	printf("String after |%c| is - |%s|\n", ch, ret);

	return(0);
}*/
