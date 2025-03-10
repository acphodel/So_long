/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:54:03 by maavalya          #+#    #+#             */
/*   Updated: 2024/01/25 13:54:04 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dest);
}

/*#include <stdio.h>
int main(void)
{
	const char src[50] = "https://www.tutorialspoint.com";
	char dest[50] = "Heloooo!!";
	printf("Before memcpy dest = %s\n", dest);
	ft_memcpy(dest, src, 50+1);
	printf("After memcpy dest = %s\n", dest);
}*/
