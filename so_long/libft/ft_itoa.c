/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:53:22 by maavalya          #+#    #+#             */
/*   Updated: 2024/01/31 15:53:24 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*result(char *str, long int len, unsigned int n)
{
	while (n)
	{
		str[len--] = n % 10 + 48;
		n /= 10;
	}
	return (str);
}

static long int	len_n(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*res;
	long int		len;
	unsigned int	num;

	len = len_n(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len--] = '\0';
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		num = -1 * n;
		res[0] = '-';
	}
	else
		num = n;
	res = result(res, len, num);
	return (res);
}

/*#include <stdio.h>
int main(void)
{
	int n = 2147483647;
	printf("%s", ft_itoa(n));
}*/