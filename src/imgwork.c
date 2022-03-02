/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgwork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:53:24 by aconchit          #+#    #+#             */
/*   Updated: 2021/11/17 13:05:54 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	*ft_player_side(t_window *window, int keycode)
{
	void	*img;
	int		height;
	int		widht;

	if (keycode == -1 || keycode == 13)
		img = mlx_xpm_file_to_image(window->mlx, \
		"assets/img_PU.xpm", &height, &widht);
	if (keycode == 0)
		img = mlx_xpm_file_to_image(window->mlx, \
		"assets/img_PL.xpm", &height, &widht);
	if (keycode == 1)
		img = mlx_xpm_file_to_image(window->mlx, \
		"assets/img_PD.xpm", &height, &widht);
	if (keycode == 2)
		img = mlx_xpm_file_to_image(window->mlx, \
		"assets/img_PR.xpm", &height, &widht);
	return (img);
}

void	*ft_createTexture(void *img, char texture, \
t_window *window, int keycode)
{
	int	height;
	int	widht;

	if (texture == '1')
		img = mlx_xpm_file_to_image(window->mlx, \
		"assets/img_1.xpm", &height, &widht);
	else if (texture == 'C')
		img = mlx_xpm_file_to_image(window->mlx, \
		"assets/img_C.xpm", &height, &widht);
	else if (texture == 'E' && !ft_checkC(window->map))
		img = mlx_xpm_file_to_image(window->mlx, \
		"assets/img_E.xpm", &height, &widht);
	else if (texture == 'P')
		img = ft_player_side(window, keycode);
	else
		img = mlx_xpm_file_to_image(window->mlx, \
		"assets/img_0.xpm", &height, &widht);
	return (img);
}

void	ft_printFloor(t_window *window)
{
	int		x;
	int		y;
	int		height;
	int		widht;
	void	*img;

	y = 0;
	img = mlx_xpm_file_to_image(window->mlx, \
	"assets/img_0.xpm", &height, &widht);
	while (y != window->max_y && y != window->y)
	{
		x = 0;
		while (x != window->max_x && x != window->x)
		{
			mlx_put_image_to_window(window->mlx, window->win, img, x, y);
			x += 50;
		}
		y += 50;
	}
}

void	ft_printImg(char *map, t_window *window, int keycode)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (y < window->max_y && y < window->y)
	{
		x = 0;
		while (x < window->max_x && x < window->x)
		{
			img = ft_createTexture(img, *map, window, keycode);
			mlx_put_image_to_window(window->mlx, window->win, img, x, y);
			x += 50;
			++map;
		}
		++map;
		y += 50;
	}
}
