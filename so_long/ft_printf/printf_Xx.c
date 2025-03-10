/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_Xx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:27:22 by maavalya          #+#    #+#             */
/*   Updated: 2024/02/07 16:27:23 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_p(void *arg, size_t *count)
{
	char				*str;
	unsigned long long	num;

	num = (unsigned long long)arg;
	printf_s("0x", count);
	str = change_base(num, HEX_LOW);
	printf_s(str, count);
	free(str);
}

void	printf_x(unsigned int num, size_t *count)
{
	char	*str;

	str = change_base(num, HEX_LOW);
	printf_s(str, count);
	free(str);
}

void	printf_upx(unsigned int num, size_t *count)
{
	char	*str;

	str = change_base(num, HEX_UP);
	printf_s(str, count);
	free(str);
}
