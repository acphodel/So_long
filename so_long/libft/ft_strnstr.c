/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:55:41 by maavalya          #+#    #+#             */
/*   Updated: 2024/01/25 17:55:42 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!len && !str)
		return (0);
	if (to_find == str || !to_find[0])
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		while (str[i + j] == to_find[j]
			&& str[i + j] != '\0' && i + j < len)
			j++;
		if ((unsigned char)to_find[j] == '\0')
		{
			return ((char *)str + i);
		}
		j = 0;
		i++;
	}
	return (0);
}

/*#include <stdio.h>
int main(void) {
	char *searchingFor = "stackd";
	char *in = "la da\ndoo a da\nnow here comes the stack\nok there it was.\n";
	printf("found: %s\n", ft_strnstr(in, searchingFor, 50) ? "yes" : "no");
	return 0;
}*/
