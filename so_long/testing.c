/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <maavalya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:14:42 by maavalya          #+#    #+#             */
/*   Updated: 2024/05/07 16:24:05 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	final_ret(int **visited, char **grid, t_dimens dim)
{
	int	i;
	int	j;

	i = 0;
	while (i < dim.row)
	{
		j = 0;
		while (j < dim.col)
		{
			if (grid[i][j] == 'C' && !visited[i][j])
			{
				free_visited(visited, dim);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	initialize_dim(t_new_dim *new_dim, t_dimens dim)
{
	new_dim->exit_reachable = 0;
	new_dim->has_collectibles = 0;
	new_dim->row = -1;
	new_dim->col = -1;
	new_dim->dim = dim;
}

void	initialize_new_dim(t_dimens dim, t_new_dim *new_dim, char **grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < dim.row)
	{
		j = 0;
		while (j < dim.col)
		{
			if (grid[i][j] == 'P')
			{
				new_dim->row = i;
				new_dim->col = j;
				return ;
			}
			j++;
		}
		if (new_dim->row != -1)
			return ;
		i++;
	}
}

int	can_reach_exit_and_collectibles(char **grid, t_dimens dim)
{
	int			**visited;
	t_new_dim	new_dim;

	visited = allocate_visited(dim.row, dim.col);
	initialize_dim(&new_dim, dim);
	initialize_new_dim(dim, &new_dim, grid);
	if (new_dim.row != -1 && new_dim.col != -1)
		dfs(grid, visited, new_dim, &new_dim);
	if (!new_dim.exit_reachable)
	{
		free_visited(visited, dim);
		return (0);
	}
	if (final_ret(visited, grid, dim) == 0)
		return (0);
	free_visited(visited, dim);
	return (1);
}

int	parsing(char **map, t_dimens dim)
{
	int	res;

	res = can_reach_exit_and_collectibles(map, dim);
	if (res)
		printf("Valid path.\n");
	else
	{
		printf("Error\nNo valid path.\n");
		freeing(map, dim);
		exit(1);
	}
	return (res);
}
