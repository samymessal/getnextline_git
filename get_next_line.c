/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:51:19 by smessal           #+#    #+#             */
/*   Updated: 2022/05/29 23:52:15 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			ret;
	static char	stash[BUFFER_SIZE + 1];
	char		*buf;
	int			index;

	if (fd < 1 || !fd || fd > 900)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	ret = 1;
	index = 0;
	while (ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == 0)
		{
			if (buf)
				free(buf);
			return (stash);
		}
		ft_strjoin(stash, buf);
		index = ft_strchr(stash);
		//printf("\nret: %d\n", ret);
		if (index)
			return (ft_clean(stash, index));
	}
	return (stash);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	// printf("%d\n", fd);
	// int fd1 = open("test.txt", O_RDONLY);
	// printf("%d", fd1);
	char *str = get_next_line(fd);
	printf("%s", str);
	char *str2 = get_next_line(fd);
	printf("%s", str2);
	char *str3 = get_next_line(fd);
	printf("%s", str3);
	// char *str4 = get_next_line(fd);
	// printf("%s", str4);
	// char *str5 = get_next_line(fd);
	// printf("%s", str5);
	// char *str6 = get_next_line(fd);
	// printf("%s", str6);

	// char *line = get_next_line(fd);
	// printf("%s\n", line);
	return (0);
}