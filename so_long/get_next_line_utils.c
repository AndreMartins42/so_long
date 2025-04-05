/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmendes <anmendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:39:49 by anmendes          #+#    #+#             */
/*   Updated: 2025/02/01 10:46:04 by anmendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *s)
{
	char	*cpy;
	int		len_s;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen((char *)s);
	cpy = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, (char *)s, len_s + 1);
	return (cpy);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strlcat(char *dst, char *src, int size)
{
	int	len_s;
	int	len_d;
	int	i;
	int	j;

	len_s = ft_strlen(src);
	len_d = ft_strlen(dst);
	i = len_d;
	j = 0;
	if (size <= len_d)
		return (len_s + size);
	while (src[j] && i < size - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (len_s + len_d);
}

int	ft_strlcpy(char *dst, char *src, int size)
{
	int	i;
	int	len_src;

	len_src = ft_strlen(src);
	if (dst == NULL || src == NULL)
		return (0);
	if (size == 0)
		return (len_src);
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		len_s1;
	int		len_s2;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (new == NULL)
		return (free(s1), NULL);
	ft_strlcpy(new, s1, len_s1 + 1);
	ft_strlcat(new, s2, len_s1 + len_s2 + 1);
	return (new);
}
