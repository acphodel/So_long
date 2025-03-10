/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:59:28 by maavalya          #+#    #+#             */
/*   Updated: 2024/01/18 13:59:30 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int num)
{
	if ((num >= '0' && num <= '9')
		|| (num >= 65 && num <= 90) || (num >= 97 && num <= 122))
		return (1);
	else
		return (0);
}

/*#include <ctype.h>
#include <stdio.h>
int main(void) {
	int n = 'A';
	printf("my function: %d,\n", ft_isalnum(n));
	printf("original: %d\n", isalnum(n));
}*/
