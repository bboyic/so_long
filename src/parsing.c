/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:21:20 by aconchit          #+#    #+#             */
/*   Updated: 2021/11/17 13:22:59 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_right_int(char *map)
{
	int	right_x;

	right_x = 0;
	while (*map && *map != '\n')
	{
		++right_x;
		++map;
	}
	return (right_x);
}

int	ft_check_xy(char *map)
{
	int	x;
	int	right_x;
	int	y;

	y = 0;
	right_x = ft_right_int(map);
	while (*map)
	{
		x = 0;
		while (*map && *map != '\n')
		{
			++x;
			++map;
		}
		++y;
		if (*map)
			++map;
		if (x != right_x)
			return (0);
	}
	if (y < 2)
		return (0);
	return (y);
}

int	ft_check_sprit_1(char *map, int gy)
{
	int	x;
	int	y;

	y = 0;
	while (*map)
	{
		x = 0;
		while (*map && *map != '\n')
		{
			if ((y == 0 || y == gy - 1) && *map != '1')
				return (0);
			if (x == 0 && *map != '1')
				return (0);
			++x;
			++map;
		}
		++y;
		if (*map)
			++map;
	}
	return (1);
}

int	ft_check_sprites(char *map)
{
	int	p;
	int	c;
	int	e;

	p = 0;
	c = 0;
	e = 0;
	while (*map)
	{
		if (*map == 'P')
			++p;
		else if (*map == 'C')
			++c;
		else if (*map == 'E')
			++e;
		else if (*map != '1' && *map != '0' && *map != '\n')
			return (0);
		++map;
	}
	if (p != 1 || c < 1 || e != 1)
		return (0);
	return (1);
}

int	ft_pars(char *map, t_window window)
{
	int	y;

	y = ft_check_xy(map);
	if (window.y / 50 != y)
		return (0);
	if (!y)
		return (0);
	if (!ft_check_sprit_1(map, y))
		return (0);
	if (!ft_check_sprites(map))
		return (0);
	return (1);
}
