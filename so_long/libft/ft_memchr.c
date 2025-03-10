/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:14:35 by maavalya          #+#    #+#             */
/*   Updated: 2024/01/25 17:14:36 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)str)[i] == (unsigned char)c)
			return (((unsigned char *)str) + i);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>

int main () {
	const char str[] = "https://www.tutorialspoint.com";
	const char ch = '.';
	char *ret;

	ret = memchr(str, ch, strlen(str));

	printf("String after |%c| is - |%s|\n", ch, ret);

	return(0);
}*/
