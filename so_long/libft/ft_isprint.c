/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:22:07 by maavalya          #+#    #+#             */
/*   Updated: 2024/01/19 13:22:09 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int num)
{
	return (num >= 32 && num < 127);
}

/*#include <ctype.h>
#include <stdio.h>
int main(void) {
	int n = '\t';
	printf("my function: %d,\n", ft_isprint(n));
	printf("original: %d\n", isprint(n));
}*/
