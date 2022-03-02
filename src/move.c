/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:22:25 by aconchit          #+#    #+#             */
/*   Updated: 2021/11/16 19:56:19 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_window	*ft_check_move(t_window *window, int player_index, int player_move)
{
	if (!ft_check_E(window->map))
		window->map[player_index] = 'E';
	else
		window->map[player_index] = '0';
	if (window->map[player_move] == 'E' && !ft_checkC(window->map))
		window->map[player_move] = 'E';
	else
		window->map[player_move] = 'P';
	return (window);
}

t_window	*ft_move(t_window *window, \
int player_index, int keycode, int *steps)
{
	int	up_down;

	up_down = (window->x / 50) + 1;
	if (keycode == 13 && window->map[player_index - up_down] != '1')
	{
		window = ft_check_move(window, player_index, player_index - up_down);
		++(*steps);
	}
	if (keycode == 1 && window->map[player_index + up_down] != '1')
	{
		window = ft_check_move(window, player_index, player_index + up_down);
		++(*steps);
	}
	if (keycode == 0 && window->map[player_index - 1] != '1')
	{
		window = ft_check_move(window, player_index, player_index - 1);
		++(*steps);
	}
	if (keycode == 2 && window->map[player_index + 1] != '1')
	{
		window = ft_check_move(window, player_index, player_index + 1);
		++(*steps);
	}
	return (window);
}

t_window	*ft_movePlayer(t_window *window, int keycode)
{
	t_player	player;
	int			player_index;
	static int	steps;

	if (keycode == -1)
		steps = 0;
	player.x = 0;
	player.y = 0;
	player = ft_findPlayer(window);
	player_index = player.x + (player.y * (window->x / 50 + 1));
	window = ft_move(window, player_index, keycode, &steps);
	printf("Steps:__%d__\n", steps);
	return (window);
}
