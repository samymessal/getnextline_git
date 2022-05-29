/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:36:49 by zel-kass          #+#    #+#             */
/*   Updated: 2022/05/29 23:20:41 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_strjoin(char *s1, char *s2)
{
	int		i;
	size_t	len;

	len = ft_strlen(s1);
	i = -1;
	while (s2[++i])
	{
		s1[len] = s2[i];
		len++;
	}
	s1[len] = '\0';
}

int	ft_strchr(const char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

void	ft_bzero(void *s)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	while (ptr && ptr[i])
		ptr[i++] = '\0';
}

char	*ft_clean(char *str, int index)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	line = malloc(sizeof(char) * (index + 1));
	if (!line)
		return (NULL);
	while (str[i] && i <= index)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	while (str[i])
		str[j++] = str[i++];
	ft_bzero(&str[j]);
	return (line);
}