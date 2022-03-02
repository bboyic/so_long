/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:09:36 by aconchit          #+#    #+#             */
/*   Updated: 2021/11/17 10:25:05 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	char	*temp;
	int		index;

	temp = (char *)s1;
	index = 0;
	cpy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!cpy)
		return (NULL);
	while (temp[index])
	{
		cpy[index] = temp[index];
		index++;
	}
	cpy[index] = '\0';
	return (cpy);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	dst_size;
	size_t	src_size;

	index = 0;
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (dstsize == 0)
		return (src_size);
	if (dstsize < dst_size)
		return (dstsize + src_size);
	while (src[index] && dstsize > (dst_size + index))
	{
		dst[dst_size + index] = src[index];
		index++;
	}
	if (dstsize == (dst_size + index) && index > 0)
		dst[dst_size + index - 1] = '\0';
	else if (*dst)
		dst[dst_size + index] = '\0';
	return (dst_size + src_size);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[index] != '\0' && index < size - 1)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin_2(char *s1, char *s2)
{
	int		size;
	char	*str;
	int		index;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	index = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, size + 1);
	free(s1);
	return (str);
}
