/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:56:55 by maavalya          #+#    #+#             */
/*   Updated: 2024/01/25 14:56:57 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (ch + 32);
	else
		return (ch);
}

/*#include <stdio.h>
#include <ctype.h>
int main()
{
	char c, result;
	c = 'M';
	result = tolower(c);
	printf("tolower(%c) = %c\n", c, result);

	c = 'm';
	result = tolower(c);
	printf("tolower(%c) = %c\n", c, result);

	c = '+';
	result = tolower(c);
	printf("tolower(%c) = %c\n", c, result);

	return 0;
}*/
