/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:43:33 by maavalya          #+#    #+#             */
/*   Updated: 2024/01/26 12:43:34 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_min(long long num, long long size)
{
	return (size >= INT_MAX || num >= INT_MAX);
}

static int	check_neg(long long num, long long size)
{
	return (((size < 0) & (num != 0)) || ((num < 0) && (size != 0)));
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*res;

	if (check_min(num, size) || check_neg(num, size))
		return (NULL);
	res = malloc(size * num);
	if (!res)
		return (NULL);
	ft_bzero(res, num * size);
	return (res);
}
