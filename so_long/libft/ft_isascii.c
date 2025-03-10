/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:19:21 by maavalya          #+#    #+#             */
/*   Updated: 2024/01/19 13:19:22 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int num)
{
	return (num >= 0 && num < 128);
}

/*#include <ctype.h>
#include <stdio.h>
int main(void)
{
	int n = 10;
	printf("my function: %d,\n",ft_isascii(n));
	printf("original: %d\n", isascii(n));
}*/
