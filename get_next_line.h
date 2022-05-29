/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:34:36 by zel-kass          #+#    #+#             */
/*   Updated: 2022/05/29 23:20:45 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 1

#endif

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		ft_llen(char *str);
void	ft_strjoin(char *s1, char *s2);
int		ft_strchr(const char *str);
char	*ft_clean(char *str, int index);
int		ft_strlen(char *str);
void	ft_bzero(void *s);

#endif