/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   focus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:27:52 by aconchit          #+#    #+#             */
/*   Updated: 2021/11/16 19:54:26 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_focus_y(t_player player, t_window window)
{
	int	y;
	int	index;

	index = 0;
	y = 0;
	player.y -= 5;
	while (y < player.y && y < (window.y / 50) - 11)
	{
		while (*window.map && *window.map != '\n')
		{
			++window.map;
			++index;
		}
		if (*window.map)
		{
			++window.map;
			++index;
		}
		++y;
	}
	return (index);
}

char	*ft_focus_x(t_window window, t_player player, char *map)
{
	int			index;
	int			x;
	int			y;

	index = 0;
	y = 0;
	while (y++ != window.max_y / 50)
	{
		x = 0;
		if (player.x > 5 && player.x < (window.x / 50) - 5 \
		&& window.x > window.max_x)
			window.map += player.x - 5;
		else if (player.x >= (window.x / 50) - 5 && window.x > window.max_x)
			window.map += player.x - (5 + (player.x - ((window.x / 50) - 6)));
		while (x++ < window.max_x / 50 && *(window.map) != '\n')
			map[index++] = *(window.map++);
		map[index++] = '\n';
		while (*window.map && *window.map != '\n')
			++window.map;
		if (*window.map)
			++window.map;
	}
	map[index] = '\0';
	return (map);
}

char	*ft_focus(t_window window)
{
	char		*map;
	t_player	player;

	map = (char *)malloc(sizeof(char) * (window.x * window.y));
	player = ft_findPlayer(&window);
	window.map += ft_focus_y(player, window);
	map = ft_focus_x(window, player, map);
	return (map);
}
