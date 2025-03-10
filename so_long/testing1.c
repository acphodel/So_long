/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <maavalya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:14:45 by maavalya          #+#    #+#             */
/*   Updated: 2024/05/07 14:46:34 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_move(char **grid, int **visited, t_new_dim new_dim, t_dimens dim)
{
	return (new_dim.row >= 0 && new_dim.row < dim.row
		&& new_dim.col >= 0 && new_dim.col < dim.col
		&& !visited[new_dim.row][new_dim.col]
		&& grid[new_dim.row][new_dim.col] != '1');
}

void	initialize_moves(int **moves)
{
	moves[0][0] = -1;
	moves[0][1] = 0;
	moves[1][0] = 1;
	moves[1][1] = 0;
	moves[2][0] = 0;
	moves[2][1] = -1;
	moves[3][0] = 0;
	moves[3][1] = 1;
}

void	free_moves(int **moves)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		free(moves[i]);
		i++;
	}
	free(moves);
}

void	visit_cell(char **grid, int **visited,
	t_new_dim new_pos, t_new_dim *gamestate)
{
	visited[new_pos.row][new_pos.col] = 1;
	if (grid[new_pos.row][new_pos.col] == 'E')
		gamestate->exit_reachable = 1;
	else if (grid[new_pos.row][new_pos.col] == 'C')
		gamestate->has_collectibles = 1;
}

void	dfs(char **grid, int **visited, t_new_dim new_pos, t_new_dim *gamestate)
{
	int			**moves;
	int			i;
	t_new_dim	new_dim;

	moves = (int **)malloc(sizeof(int *) * 5);
	i = 0;
	while (i < 5)
	{
		moves[i] = (int *)malloc(sizeof(int) * 3);
		i++;
	}
	visit_cell(grid, visited, new_pos, gamestate);
	initialize_moves(moves);
	i = 0;
	while (i < 4)
	{
		new_dim.row = new_pos.row + moves[i][0];
		new_dim.col = new_pos.col + moves[i][1];
		if (is_valid_move(grid, visited, new_dim, new_pos.dim))
			dfs(grid, visited, new_dim, gamestate);
		i++;
	}
	free_moves(moves);
}
