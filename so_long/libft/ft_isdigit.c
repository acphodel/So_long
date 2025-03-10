/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:56:02 by maavalya          #+#    #+#             */
/*   Updated: 2024/01/18 13:56:03 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int num)
{
	if (num >= '0' && num <= '9')
		return (1);
	else
		return (0);
}

/*#include <ctype.h>
#include <stdio.h>
int main(void) {
	int n = '9';
	printf("my function: %d,\n", ft_isdigit(n));
	printf("original: %d\n", isdigit(n));
}*/
