/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:14:28 by maavalya          #+#    #+#             */
/*   Updated: 2025/03/21 06:01:13 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	shorten2(t_key_data *data)
{
	char	*res;

	ft_printf("%s%d%c", "the number of movements = ", (data->dim).count, '\n');
	mlx_clear_window(data->mlx, data->win);
	draw_map(data, data->dim);
	mlx_string_put(data->mlx, data->win, 0, 10,
		0xFFFFFF, "the number of moves = ");
	res = ft_itoa((data->dim).count);
	mlx_string_put(data->mlx, data->win, 225, 10, 0xFFFFFF, res);
	free(res);
}

int	key_hook(int keycode, t_key_data *data)
{
	printf("%d\n", keycode);
	if (keycode == 53)
	{
		destroy(data);
		freeing(data->map, data->dim);
		exit(0);
	}
	if (keycode == 0 || keycode == 123 || keycode == 97)
	{
		data->dim = moving(data->map, data->dim, 'a', &(data->count));
		data->temp = data->player_an;
	}
	else if (keycode == 13 || keycode == 126 || keycode == 119)
		data->dim = moving(data->map, data->dim, 'w', &(data->count));
	else if (keycode == 2 || keycode == 124 || keycode == 100)
	{
		data->dim = moving(data->map, data->dim, 'd', &(data->count));
		data->temp = data->player;
	}
	else if (keycode == 1 || keycode == 125 || keycode == 115)
		data->dim = moving(data->map, data->dim, 's', &(data->count));
	shorten2(data);
	return (0);
}

int	handle_close(t_key_data *data)
{
	destroy(data);
	freeing(data->map, data->dim);
	exit(0);
}

void	declaration(t_key_data *data, void*mlx)
{
	data->img_grass = mlx_xpm_file_to_image(mlx,
			"./textures/ocean1.xpm", &data->size, &data->size);
	data->wall = mlx_xpm_file_to_image(mlx,
			"./textures/coral1.xpm", &data->size, &data->size);
	data->player = mlx_xpm_file_to_image(mlx,
			"./textures/ariel1.xpm", &data->size, &data->size);
	data->temp = mlx_xpm_file_to_image(mlx,
			"./textures/ariel1.xpm", &data->size, &data->size);
	data->player_an = mlx_xpm_file_to_image(mlx,
			"./textures/ariel_reversed.xpm", &data->size, &data->size);
	data->coin = mlx_xpm_file_to_image(mlx,
			"./textures/coin2.xpm", &data->size, &data->size);
	data->temp_for_coin = mlx_xpm_file_to_image(mlx,
			"./textures/coin2.xpm", &data->size, &data->size);
	data->other_coin = mlx_xpm_file_to_image(mlx,
			"./textures/reversed_coin.xpm", &data->size, &data->size);
	data->door = mlx_xpm_file_to_image(mlx,
			"./textures/door3.xpm", &data->size, &data->size);
	data->vilain = mlx_xpm_file_to_image(mlx,
			"./textures/ursula.xpm", &data->size, &data->size);
}

int	map_graphic(char **map, t_dimens dim, t_coll *count)
{
	void		*mlx;
	void		*win;
	t_key_data	data;

	data.size = 60;
	mlx = mlx_init();
	win = mlx_new_window(mlx, dim.col * data.size, dim.row * data.size, "Map");
	data.mlx = mlx;
	data.win = win;
	data.map = map;
	data.dim = dim;
	data.count = *count;
	declaration(&data, mlx);
	draw_map(&data, dim);
	mlx_hook(win, 2, 1L << 0, key_hook, &data);
	mlx_loop_hook(mlx, &frame, &data);
	mlx_hook(win, 17, 0L, handle_close, &data);
	mlx_loop(mlx);
	destroy(&data);
	return (0);
}
