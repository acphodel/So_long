/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_anim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <maavalya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:14:25 by maavalya          #+#    #+#             */
/*   Updated: 2024/05/05 17:14:26 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coin_change(t_key_data *data)
{
	static int	i = 0;

	if (i % 20 == 0)
		data->coin = data->temp_for_coin;
	if (i % 40 == 0)
		data->coin = data->other_coin;
	i++;
}

int	frame(t_key_data *data)
{
	char	*res;

	coin_change(data);
	mlx_clear_window(data->mlx, data->win);
	draw_map(data, data->dim);
	mlx_string_put(data->mlx, data->win, 0, 10,
		0xFFFFFF, "the number of moves = ");
	res = ft_itoa((data->dim).count);
	mlx_string_put(data->mlx, data->win, 225, 10, 0xFFFFFF, res);
	free(res);
	return (0);
}
