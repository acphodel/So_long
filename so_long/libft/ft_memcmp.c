/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:43:45 by maavalya          #+#    #+#             */
/*   Updated: 2024/01/25 17:43:46 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *) str1;
	p2 = (unsigned char *) str2;
	if (n == 0)
		return (0);
	while (n > 1 && (*p1 == *p2))
	{
		p1++;
		p2++;
		n--;
	}
	return ((int)(*p1 - *p2));
}

/*#include <stdio.h>
#include <string.h>

int main () {
	char str1[15];
	char str2[15];
	int ret;

	memcpy(str1, "abcdef", 6);
	memcpy(str2, "ABCDEF", 6);

	ret = ft_memcmp(str1, str2, 5);

	if(ret > 0) {
		printf("str2 is less than str1");
	} else if(ret < 0) {
		printf("str1 is less than str2");
	} else {
		printf("str1 is equal to str2");
	}

	return(0);
}*/
