/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:04:52 by aconchit          #+#    #+#             */
/*   Updated: 2021/11/16 19:47:03 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_checkC(char *map)
{
	while (*map)
	{
		if (*map == 'C')
			return (1);
		++map;
	}
	return (0);
}

int	ft_check_E(char *map)
{
	while (*map)
	{
		if (*map == 'E')
			return (1);
		++map;
	}
	return (0);
}

int	ft_check_P(char *map)
{
	while (*map)
	{
		if (*map == 'P')
			return (1);
		++map;
	}
	return (0);
}
