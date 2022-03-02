/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:21:52 by aconchit          #+#    #+#             */
/*   Updated: 2021/11/17 17:24:39 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define	MAIN_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"
# include <string.h>
# include <errno.h>

typedef struct s_window
{
	char	*map;
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		max_x;
	int		max_y;
}	t_window;

typedef struct s_player
{
	int	x;
	int	y;
	int	steps;
}	t_player;

/*
------|imgwork.c|------
|Работа с изображением|
-----------------------
*/
void		*ft_player_side(t_window *window, int );
void		*ft_createTexture(void *img, char texture, \
t_window *window, int keycode);
void		ft_printFloor(t_window *window);
void		ft_printImg(char *map, t_window *window, int keycode);

int			ft_checkC(char *map);
int			ft_check_E(char *map);
int			ft_check_P(char *map);

t_window	*ft_check_move(t_window *window, int player_index, int player_move);
t_window	*ft_move(t_window *window, \
int player_index, int keycode, int *steps);
t_window	*ft_movePlayer(t_window *window, int keycode);

char		*ft_focus(t_window window);

void		ft_close(int code);
int			ft_close_hook(int keycode, t_window *window);
char		*ft_readMap(char *file);
int			ft_render_next_frame(t_window window, void *param);
t_player	ft_findPlayer(t_window *window);

t_player	ft_findPlayer(t_window *window);
int			ft_pars(char *map, t_window window);

#endif