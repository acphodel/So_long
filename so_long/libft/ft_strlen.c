/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:06:53 by maavalya          #+#    #+#             */
/*   Updated: 2024/01/09 15:06:54 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{
	char str[] = "123456789a";
	printf("%d\n", ft_strlen(str));
	char str1[] = "123456789a";
	printf("%lu", strlen(str1));
}*/
