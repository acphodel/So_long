/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <maavalya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:05:14 by maavalya          #+#    #+#             */
/*   Updated: 2024/05/11 12:23:31 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct s_dim
{
	int	col;
	int	row;
	int	delete_me;
	int	player_x;
	int	player_y;
	int	exit_x;
	int	exit_y;
	int	count;
}	t_dimens;

typedef struct col_count
{
	int	exit_count;
	int	coll_count;
	int	player_count;
	int	index_row;
	int	index_col;
}	t_coll;

typedef struct data
{
	void		*mlx;
	void		*win;
	void		*img_grass;
	void		*player;
	void		*wall;
	void		*coin;
	void		*door;
	void		*vilain;
	void		*player_an;
	void		*temp;
	char		**map;
	int			frame;
	void		*other_coin;
	void		*temp_for_coin;
	int			size;
	t_dimens	dim;
	t_coll		count;
}	t_key_data;

typedef struct s_new_row
{
	int			row;
	int			col;
	int			exit_reachable;
	int			has_collectibles;
	t_dimens	dim;
}	t_new_dim;

t_dimens	flood_fill(char **map, t_dimens new_dim,
				t_dimens info, t_coll *count);
int			filling(t_dimens map_dim, char **map);
int			map_graphic(char **mpa, t_dimens dim, t_coll *count);
t_dimens	moving(char **map, t_dimens info, char c, t_coll *count);
void		print_map_two(char **map, t_dimens obj);
int			parsing(char **map, t_dimens dim);
int			valid(char *filename);
t_dimens	valid_map(char **map);
t_dimens	check_borders(char **map, t_dimens obj, t_coll *count);
char		**fill_map(char *buf, t_dimens obj);
void		freeing(char **map, t_dimens dim);
char		*get_next_line(int fd);
void		shorten(t_key_data *data, int x, int y);
void		draw_map(t_key_data *data, t_dimens dim);
void		destroy(t_key_data *data);
void		dfs(char **grid, int **visited, t_new_dim new_pos,
				t_new_dim *gamestate);
void		free_visited(int **visited, t_dimens dim);
int			**allocate_visited(int rows, int cols);
char		*trim_back(char const *s1, char const *set);
void		cut_map(char **map);
void		valid_fd(int fd);
int			frame(t_key_data *data);
void		check(char **map, t_dimens obj, int flag);
void		only_whitespace(char	*res);

#endif
