/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:54:33 by maavalya          #+#    #+#             */
/*   Updated: 2024/02/07 16:26:15 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_di(int n, size_t *count)
{
	if (n == -2147483648)
	{
		printf_s("-2147483648", count);
		return ;
	}
	if (n < 0)
	{
		printf_c('-', count);
		n *= -1;
	}
	if (n >= 10)
	{
		printf_di(n / 10, count);
		printf_di(n % 10, count);
	}
	else
		printf_c(n + 48, count);
}

void	printf_u(unsigned int n, size_t *count)
{
	if (n >= 10)
	{
		printf_di(n / 10, count);
		printf_di(n % 10, count);
	}
	else
		printf_c(n + 48, count);
}
