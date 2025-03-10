/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:41:51 by maavalya          #+#    #+#             */
/*   Updated: 2023/10/14 14:41:52 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (src[n] != '\0')
		n++;
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (n);
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{
	char src[] ="Afhfnfgnnun";
	char dest[] = "Azganun";
	char src1[] ="Afhfnfgnnun";
	char dest1[] = "Azganun";
	printf("%u | %s \n", ft_strlcpy(dest,src,3),dest);
	printf("%lu | %s", strlcpy(dest1, src1, 3),dest);
}*/
