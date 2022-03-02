/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:10:04 by aconchit          #+#    #+#             */
/*   Updated: 2021/11/17 10:25:23 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_search_nl(char *buff)
{
	while (*buff)
	{
		if (*buff == '\n')
			return (1);
		buff++;
	}
	return (0);
}

char	*ft_read_file(int fd, char *str)
{
	char	buff[BUFFER_SIZE + 1];
	int		rd;

	rd = 1;
	while (!ft_search_nl(buff) && rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd < 0)
			return (NULL);
		buff[rd] = '\0';
		str = ft_strjoin_2(str, buff);
	}
	return (str);
}

char	*ft_new_str(char *str)
{
	int		index;
	char	*new_str;

	index = 0;
	while (str[index] && str[index] != '\n')
		index++;
	if (str[index])
		index++;
	if (!str[index])
	{
		free(str);
		return (NULL);
	}
	new_str = ft_strdup(&str[index]);
	free(str);
	return (new_str);
}

char	*ft_res(char *str)
{
	char	*res;
	int		index;

	index = 0;
	if (!str[index])
		return (NULL);
	while (str[index] && str[index] != '\n')
		index++;
	res = (char *)malloc(sizeof(char) * (index + 2));
	if (!res)
		return (NULL);
	if (!str[index])
		res[index] = '\0';
	else
	{
		res[index] = '\n';
		res[index + 1] = '\0';
	}
	while (index >= 0)
	{
		res[index] = str[index];
		index--;
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read_file(fd, str);
	if (!str)
		return (NULL);
	res = ft_res(str);
	str = ft_new_str(str);
	return (res);
}
