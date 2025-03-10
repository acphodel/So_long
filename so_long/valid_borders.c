/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <maavalya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:14:50 by maavalya          #+#    #+#             */
/*   Updated: 2024/05/07 16:23:52 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	short2(t_coll count)
{
	if (count.player_count != 1
		|| count.exit_count != 1 || count.coll_count < 1)
	{
		ft_printf("Error\nWrong number of coll");
		return (1);
	}
	return (0);
}

t_dimens	shortage_check_borders(t_coll *count, t_dimens obj, char c)
{
	if (c == 'E')
	{
		count->exit_count++;
		obj.exit_x = count->index_row;
		obj.exit_y = count->index_col;
	}
	else if (c == 'C')
		count->coll_count++;
	else if (c == 'P')
	{
		count->player_count++;
		obj.player_x = count->index_row;
		obj.player_y = count->index_col;
	}
	return (obj);
}

t_dimens	check_borders(char **map, t_dimens obj, t_coll *count)
{
	while (++count->index_row < obj.row)
	{
		count->index_col = -1;
		while (++count->index_col < obj.col)
		{
			obj = shortage_check_borders(count, obj,
					map[count->index_row][count->index_col]);
			if ((map[0][count->index_col] != '1'
				|| map[count->index_row][0] != '1')
				|| ((!map[count->index_row + 1]
				|| !map[count->index_row][count->index_col + 1])
				&& map[count->index_row][count->index_col] != '1'))
			{
				ft_printf("%s", "Error\nMap border isn't filled.");
				freeing(map, obj);
				exit (1);
			}
		}
	}
	if (short2(*count) == 1)
	{
		freeing(map, obj);
		exit (1);
	}
	return (obj);
}
