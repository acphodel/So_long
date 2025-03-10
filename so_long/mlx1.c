/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <maavalya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:14:33 by maavalya          #+#    #+#             */
/*   Updated: 2024/05/07 15:58:00 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	shorten(t_key_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->wall, x * data->size, y * data->size);
	else if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->door, x * data->size, y * data->size);
	else if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->coin, x * data->size, y * data->size);
	else if (data->map[y][x] == 'V')
		mlx_put_image_to_window(data->mlx, data->win,
			data->vilain, x * data->size, y * data->size);
}

void	draw_map(t_key_data *data, t_dimens dim)
{
	int	x;
	int	y;

	y = 0;
	mlx_clear_window(data->mlx, data->win);
	while (y < dim.row)
	{
		x = 0;
		while (x < dim.col)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->img_grass,
				x * 60, y * 60);
			mlx_put_image_to_window(data->mlx, data->win, data->temp,
				dim.player_y * 60, dim.player_x * 60);
			shorten(data, x, y);
			x++;
		}
		y++;
	}
}

void	destroy(t_key_data *data)
{
	mlx_destroy_image(data->mlx, data->coin);
	mlx_destroy_image(data->mlx, data->img_grass);
	mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->door);
	mlx_destroy_image(data->mlx, data->vilain);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
}
