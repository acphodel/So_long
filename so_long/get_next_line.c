/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:20:55 by maavalya          #+#    #+#             */
/*   Updated: 2024/02/09 15:20:57 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*refresh_buff(char *old_buff)
{
	char	*new_buff;
	int		i;
	int		j;

	i = 0;
	while (old_buff[i] && old_buff[i] != '\n')
		i++;
	if (!old_buff[i])
	{
		free(old_buff);
		return (NULL);
	}
	new_buff = ft_calloc(ft_strlen(old_buff) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (old_buff[i])
		new_buff[j++] = old_buff[i++];
	free(old_buff);
	return (new_buff);
}

char	*free_join(char *dest, char*src)
{
	char	*temp;

	temp = ft_strjoin(dest, src);
	free(dest);
	return (temp);
}

char	*get_line(char *buffer)
{
	char	*res;
	int		size;

	size = 0;
	if (!buffer[size])
		return (NULL);
	while (buffer[size] && buffer[size] != '\n')
		size++;
	res = ft_calloc(size + 2, sizeof(char));
	size = 0;
	while (buffer[size] && buffer[size] != '\n')
	{
		res[size] = buffer[size];
		size++;
	}
	if (buffer[size] && buffer[size] == '\n')
		res[size++] = '\n';
	return (res);
}

char	*read_fd(int fd, char *res)
{
	char	*temp;
	int		rd;

	if (!res)
		res = ft_calloc(1, 1);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	rd = 1;
	while (rd > 0 && !ft_strchr(temp, '\n'))
	{
		rd = read(fd, temp, BUFFER_SIZE);
		if (rd == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[rd] = 0;
		res = free_join(res, temp);
	}
	free(temp);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	line = NULL;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = read_fd(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = refresh_buff(buffer);
	return (line);
}
