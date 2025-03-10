/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:23:12 by maavalya          #+#    #+#             */
/*   Updated: 2023/10/15 10:23:13 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	size_src;
	size_t	size_dest;
	size_t	i;
	size_t	j;

	i = 0;
	size_src = ft_strlen(src);
	if (!dest && size == 0)
		return (size_src);
	size_dest = ft_strlen(dest);
	j = size_dest;
	if (size <= size_dest)
		return (size_src + size);
	while (src[i] != '\0' && i < size - size_dest - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (size_src + size_dest);
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{
	char dest[20] = "Born to code";
	char src[] = "1337 42";
	char dest1[20] = "Born to code";
	char src1[] = "1337 42";
	printf("%u\n",ft_strlcat(dest,src,5));
	printf("%lu",strlcat(dest1,src1,5));
}*/
