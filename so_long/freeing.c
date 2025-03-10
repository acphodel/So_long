/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <maavalya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:14:17 by maavalya          #+#    #+#             */
/*   Updated: 2024/05/07 16:24:26 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_visited(int **visited, t_dimens dim)
{
	int	i;

	i = 0;
	while (i < dim.row)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

int	**allocate_visited(int rows, int cols)
{
	int	**visited;
	int	i;

	i = 0;
	visited = (int **)malloc(sizeof(int *) * rows);
	while (i < rows)
	{
		visited[i] = (int *)calloc(cols, sizeof(int));
		i++;
	}
	return (visited);
}

void	check(char **map, t_dimens obj, int flag)
{
	if (flag == 1)
	{
		ft_printf("%s", "Error\nMap is not rectangular");
		freeing(map, obj);
		exit(1);
	}
}
