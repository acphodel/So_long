/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:33:33 by maavalya          #+#    #+#             */
/*   Updated: 2024/01/25 13:33:36 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(str + i) = (unsigned char) c;
		i++;
	}
	return (str);
}

/*#include <stdio.h>
int main(void)
{
	char str[] = "AAAAAAA AAAA AAAA";
	char x = 'B';
	ft_memset(str + 8, x, 4);
	printf("%s ", str);
}*/
