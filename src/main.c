/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 04:14:02 by aconchit          #+#    #+#             */
/*   Updated: 2021/11/17 13:00:46 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
	Proj	= so_long
	Login	= aconchit
*/

void	ft_windowSize(t_window *window, char *map)
{
	int	index;

	(*window).x = 0;
	(*window).y = 0;
	index = 0;
	(*window).max_x = 550;
	(*window).max_y = 550;
	while (map[index] && map[index] != '\n')
	{
		(*window).x += 50;
		++index;
	}
	(*window).y += 50;
	while (map[index])
	{
		if (map[index] == '\n')
			(*window).y += 50;
		++index;
	}
}

void	ft_windowConnect(t_window *window)
{
	int	y;
	int	x;

	if (window->x > window->max_x)
		x = window->max_x;
	else
		x = window->x;
	if (window->y > window->max_y)
		y = window->max_y;
	else
		y = window->y;
	(*window).mlx = mlx_init();
	(*window).win = mlx_new_window(window->mlx, \
	x, y, "So_long!");
}

int	ft_so_long(t_window *window, char *map, int keycode)
{
	char	*l_map;

	ft_printFloor(window);
	if (window->x > window->max_x || window->y > window->max_y)
	{
		l_map = ft_focus(*window);
		ft_printImg(l_map, window, keycode);
		free(l_map);
	}
	else
		ft_printImg(map, window, keycode);
	return (0);
}

int	ft_key_hook(int keycode, t_window *window)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{
		mlx_clear_window(window->mlx, window->win);
		if (keycode == 0 || keycode == 1 || keycode == 13 || keycode == 2)
		{
			window = ft_movePlayer(window, keycode);
			ft_so_long(window, window->map, keycode);
		}
	}
	if (!ft_check_P(window->map))
		exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_window	window;
	void		*param;

	param = NULL;
	if (argc != 2)
		ft_close(1);
	window.map = ft_readMap(argv[1]);
	if (!window.map)
		ft_close(2);
	ft_windowSize(&window, window.map);
	if (!ft_pars(window.map, window))
		ft_close(2);
	ft_windowConnect(&window);
	ft_so_long(&window, window.map, -1);
	mlx_key_hook(window.win, ft_key_hook, &window);
	mlx_hook(window.win, 17, 0, ft_close_hook, &window);
	mlx_loop_hook(window.mlx, ft_render_next_frame, param);
	mlx_loop(window.mlx);
	return (0);
}
