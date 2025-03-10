/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_shortage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <maavalya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:14:53 by maavalya          #+#    #+#             */
/*   Updated: 2024/05/11 12:22:44 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_fd(int fd)
{
	if (fd == -1)
	{
		ft_printf("%s", "Error\nInvalid filename!");
		exit (1);
	}
}

void	buff_validation(char **map, t_dimens map_dim)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(map[i][j] == 'V' || map[i][j] == 'E'
				|| map[i][j] == 'C' || map[i][j] == 'P'
				|| map[i][j] == '1' || map[i][j] == '0'
				|| map[i][j] == '\n' || map[i][j] == '\0'))
			{
				ft_printf("%s ", "Error\nInvalid map");
				freeing(map, map_dim);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int	filling(t_dimens map_dim, char **map)
{
	t_coll	count;

	count.index_row = -1;
	count.player_count = 0;
	count.exit_count = 0;
	count.coll_count = 0;
	map_dim.count = 0;
	buff_validation(map, map_dim);
	map_dim = check_borders(map, map_dim, &count);
	parsing(map, map_dim);
	map_graphic(map, map_dim, &count);
	return (0);
}

void	cut_map(char **map)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (map[i])
	{
		j = 0;
		temp = map[i];
		map[i] = trim_back(map[i], "\n\t\v\f\r ");
		free(temp);
		i++;
	}
}

t_dimens	valid_map(char **map)
{
	int			size;
	t_dimens	obj;
	int			flag;

	size = 0;
	obj.col = 0;
	obj.row = -1;
	flag = 0;
	while (map[++obj.row])
	{
		while (map[obj.row][size])
			size++;
		if (obj.row == 0)
			obj.col = size;
		else if (obj.col != size)
			flag = 1;
	}
	check(map, obj, flag);
	return (obj);
}
