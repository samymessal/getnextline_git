/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:10:47 by smessal           #+#    #+#             */
/*   Updated: 2022/05/30 20:03:17 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_stash_san(char *stash, char *buf)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	j = 0;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (j < i && stash[j])
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	j = 0;
	while (stash[i] && buf[j])
		buf[j++] = stash[i++];
	buf[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	int			ret;
	char		*line;
	char		*stash;
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	ret = BUFFER_SIZE;
	stash = NULL;
	stash = ft_strjoin(stash, buf[fd]);
	while (ret == BUFFER_SIZE && !ft_strchr(buf[fd]))
	{
		ret = read(fd, buf[fd], BUFFER_SIZE);
		if (ret == -1)
			return (free(stash), NULL);
		buf[fd][ret] = '\0';
		if (ret == 0 && !stash[0])
			return (free(stash), NULL);
		stash = ft_strjoin(stash, buf[fd]);
	}
	line = ft_stash_san(stash, buf[fd]);
	return (free(stash), line);
}
