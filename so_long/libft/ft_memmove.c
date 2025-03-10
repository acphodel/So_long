/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:10:40 by maavalya          #+#    #+#             */
/*   Updated: 2024/01/25 14:10:41 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	int	i;

	if (!str1 && !str2)
		return (NULL);
	if (str1 > str2)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(unsigned char *)(str1 + i) = *(unsigned char *)(str2 + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*(unsigned char *)(str1 + i) = *(unsigned char *)(str2 + i);
			i++;
		}
	}
	return (str1);
}

/*#include <stdio.h>
#include <string.h>

int main () {
	char dest[] = "oldaaaa";
	const char src[]  = "newstring";

	printf("Before memmove dest = %s, src = %s\n", dest, src);
	ft_memmove(dest, src, 5);
	printf("After memmove dest = %s, src = %s\n", dest, src);

	return(0);
}*/
