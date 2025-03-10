/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <maavalya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:14:35 by maavalya          #+#    #+#             */
/*   Updated: 2024/05/07 16:29:01 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_new_dim(t_dimens	*new_dim, t_dimens info)
{
	new_dim->row = info.player_x;
	new_dim->col = info.player_x;
}

void	freeing(char **map, t_dimens dim)
{
	int	i;

	i = 0;
	while (i < dim.row)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

t_dimens	flood_fill(char **map, t_dimens new_dim,
			t_dimens info, t_coll *count)
{
	if (map[new_dim.row][new_dim.col] != '1')
	{
		if (map[new_dim.row][new_dim.col] == 'C')
			count->coll_count--;
		if (map[new_dim.row][new_dim.col] == 'V')
		{
			ft_printf("%s", "YOU LOSE");
			freeing(map, info);
			exit(0);
		}
		if (map[new_dim.row][new_dim.col] == 'E' && count->coll_count == 0)
		{
			ft_printf("%s", "YOU WON");
			freeing(map, info);
			exit(0);
		}
		map[info.player_x][info.player_y] = '0';
		info.player_x = new_dim.row;
		info.player_y = new_dim.col;
		map[info.player_x][info.player_y] = 'P';
		map[info.exit_x][info.exit_y] = 'E';
		info.count++;
	}
	return (info);
}

t_dimens	moving(char **map, t_dimens info, char c, t_coll *count)
{
	t_dimens	new_dim;

	init_new_dim(&new_dim, info);
	if (c == 'w')
	{
		new_dim.row = info.player_x - 1;
		new_dim.col = info.player_y;
	}
	else if (c == 's')
	{
		new_dim.row = info.player_x + 1;
		new_dim.col = info.player_y;
	}
	else if (c == 'a')
	{
		new_dim.row = info.player_x;
		new_dim.col = info.player_y - 1;
	}
	else if (c == 'd')
	{
		new_dim.row = info.player_x;
		new_dim.col = info.player_y + 1;
	}
	info = flood_fill(map, new_dim, info, count);
	return (info);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	valid(argv[1]);
	return (0);
}
