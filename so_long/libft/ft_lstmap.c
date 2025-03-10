/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:22:14 by maavalya          #+#    #+#             */
/*   Updated: 2024/02/01 16:22:16 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*new;

	if (!del || ! f)
		return (NULL);
	res = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst -> content));
		if (!new)
		{
			while (res)
			{
				new = res;
				(*del)(res->content);
				free(res);
				res = new;
			}
			return (NULL);
		}
		ft_lstadd_back(&res, new);
		lst = lst -> next;
	}
	return (res);
}
