/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:35:46 by maavalya          #+#    #+#             */
/*   Updated: 2023/10/14 17:35:48 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (((unsigned char) s1[i] - (unsigned char) s2[i]));
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{
	char s1[] = "ab";
	char s2[] = "abcdrtfhn";
	char s11[] = "ab";
	char s21[] = "abcdrtfhn";
	printf("%d\n", ft_strncmp(s1, s2,20));
	printf("%d\n", strncmp(s11, s21, 20));

}*/