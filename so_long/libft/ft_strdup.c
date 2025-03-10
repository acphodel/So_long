/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:11:26 by maavalya          #+#    #+#             */
/*   Updated: 2023/10/22 15:11:27 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (src[size] != '\0')
		size++;
	dest = (char *)malloc((size) * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char *str;
	char *dest;

	str = "hello, world";
	dest = strdup(str);
	printf("%s\n", dest);
	dest = ft_strdup(str);
	printf("%s", dest);
}*/
