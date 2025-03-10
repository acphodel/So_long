/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:02:23 by maavalya          #+#    #+#             */
/*   Updated: 2024/02/06 13:19:03 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_s(char *str, size_t *count)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		printf_c(*str, count);
		str++;
	}
}
