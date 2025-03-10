/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:47:02 by maavalya          #+#    #+#             */
/*   Updated: 2024/01/31 14:47:13 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strings(char *str, char c)
{
	int	count;
	int	flag;

	flag = 1;
	count = 0;
	while (*str != '\0')
	{
		if (*str == c && flag == 0)
			flag = 1;
		if (*str != '\0' && *str != c && flag == 1)
		{
			count++;
			flag = 0;
		}
		str++;
	}
	return (count);
}

static int	ft_strlen_sep(char *str, char c)
{
	int	len;

	len = 0;
	while (*str != '\0' && *str != c)
	{
		len++;
		str++;
	}
	return (len);
}

static char	*ft_word(char *str, char c)
{
	int		len_word;
	int		i;
	char	*word;

	i = 0;
	len_word = ft_strlen_sep(str, c);
	word = (char *)malloc(sizeof(char) * len_word + 1);
	if (!word)
		return (NULL);
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		flag;
	int		i;

	i = 0;
	flag = 1;
	if (!s)
		return (NULL);
	res = (char **)malloc((count_strings((char *)s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (*s != '\0')
	{
		if (*s != '\0' && *s == c)
			flag = 1;
		if (*s != '\0' && flag == 1 && *s != c)
		{
			res[i] = ft_word((char *)s, c);
			flag = 0;
			i++;
		}
		s++;
	}
	res[i] = 0;
	return (res);
}

/*#include <stdio.h>
int main(void)
{
 char **split;
 split = ft_split("aaa\taa aa\taaa", ' ');
 for(int i = 0; split[i] != 0; i++)
 {
	 printf("%s\n", split[i]);
 }
}*/
