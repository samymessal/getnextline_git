/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:33:46 by zel-kass          #+#    #+#             */
/*   Updated: 2022/05/27 17:16:52 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_stash_san(char *stash, char *buf, int ret)
{
	int		i;
	int		j;
	char	*line;

	i = ft_strchr(stash, ret);
	printf("\nindex strchr: %d\n", i);
	j = -1;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (++j <= i && stash[j])
		line[j] = stash[j];
	line[j] = '\0';
	// if (ret == 0)
	// 	return (stash);
	j = 0;
	while (stash[i + 1])
		buf[j++] = stash[++i];
	ft_bzero(&buf[j]);
	free(stash);
	return (line);
}

char	*get_next_line(int fd)
{
	int			ret;
	char		*line;
	char		*stash;
	static char	buf[BUFFER_SIZE + 1];

	ret = 1;
	stash = NULL;
	stash = ft_strjoin(stash, buf);
	//printf("stash_avant: %s\nbuff_avant: %s\nret_avant: %d\n", stash, buf, ret);
	while (ret && !ft_strchr(buf, ret))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		//printf("stash_pendant: %s\nbuff_pendant: %s\nret_pendant: %d\n", stash, buf, ret);
		if (ret == 0)
			return (ft_stash_san(stash, buf, ret));
		stash = ft_strjoin(stash, buf);
		//printf("%s\n", stash);
	}
	//printf("stash_apres: %s\nbuff_apres: %s\nret_apres: %d\n", stash, buf, ret);
	// if (ret < BUFFER_SIZE)
	// {
	// 	return (stash);
	// }
	line = ft_stash_san(stash, buf, ret);
	//printf("line: %s\n", line);
	return (line);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
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