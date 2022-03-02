/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:32:44 by aconchit          #+#    #+#             */
/*   Updated: 2021/11/17 13:00:31 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_render_next_frame(t_window window, void *param)
{
	void	*item;

	if (window.x)
		item = param;
	return (1);
}

t_player	ft_findPlayer(t_window *window)
{
	int			x;
	int			y;
	int			index;
	t_player	player;

	y = 0;
	index = 0;
	player.x = 0;
	while (window->map[index])
	{
		x = 0;
		while (window->map[index] && window->map[index] != '\n')
		{
			if (window->map[index++] == 'P')
			{
				player.x = x;
				player.y = y;
				return (player);
			}
			++x;
		}
		++index;
		++y;
	}
	return (player);
}

/*
	|---------ft_readMap----------------|
	|	Используются для чтения карты	|
	|-----------------------------------|
*/

char	*ft_readMap(char *file)
{
	int		fd;
	char	*gnl;
	char	*map;

	if (!ft_strnstr(file, ".ber", ft_strlen(file)))
		return (0);
	fd = open(file, O_RDONLY);
	gnl = get_next_line(fd);
	map = ft_strdup("");
	while (gnl)
	{
		if (gnl)
		{
			map = ft_strjoin_2(map, gnl);
			free(gnl);
		}
		gnl = get_next_line(fd);
	}
	return (map);
}

int	ft_close_hook(int keycode, t_window *window)
{
	if (window->x)
		keycode = 0;
	exit(0);
	return (0);
}

/*
			ft_close function
	--------				------------
	|	Требуется для выхода из			|
	|	приложения.						|
	|	В зависимости от code будет		|
	|	выводиться определенная ошибка	|
	|-----------------------------------|
*/

void	ft_close(int code)
{
	if (code == 1)
	{
		write(2, "Error\nInvalid Argument\n", 23);
		exit(0);
	}
	if (code == 2)
	{
		write(2, "Error\nInvalid Map\n", 18);
		exit(0);
	}
}
