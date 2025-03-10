/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:54:46 by maavalya          #+#    #+#             */
/*   Updated: 2024/02/06 14:43:54 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
}

static void	*ft_calloc(size_t num, size_t size)
{
	void	*res;

	res = malloc(size * num);
	if (!res)
		return (NULL);
	ft_bzero(res, num * size);
	return (res);
}

static int	ft_num_len(unsigned long long num)
{
	size_t			len;
	unsigned int	base_len;

	len = 1;
	base_len = 16;
	while (num >= base_len)
	{
		num /= base_len;
		len++;
	}
	return (len);
}

char	*change_base(unsigned long long num, char *base)
{
	int		base_len;
	int		num_len;
	char	*str;

	base_len = 16;
	num_len = ft_num_len(num);
	str = ft_calloc((num_len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (num_len)
	{
		num_len--;
		str[num_len] = base[num % base_len];
		num /= base_len;
	}
	return (str);
}
