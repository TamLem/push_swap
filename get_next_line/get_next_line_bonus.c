/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:40:09 by tlemma            #+#    #+#             */
/*   Updated: 2021/10/28 16:05:13 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	buf_scroll(char *buf, size_t i)
{
	size_t	n;

	n = 0;
	while (buf[n] != '\0')
	{
		if (buf[n + i] == '\0')
		{
			while (buf[n] != '\0')
				buf[n++] = '\0';
			break ;
		}
		buf[n] = buf[n + i];
		n++;
	}
}

void	ft_free(char **to_free)
{
	if (*to_free != NULL)
	{
		free(*to_free);
		*to_free = NULL;
	}
}

char	*get_buf(int fd)
{
	ssize_t		n;
	static char	*buf[10240];

	n = 0;
	if (fd < 0 || fd > 10240 || BUFFER_SIZE < 1)
		return (NULL);
	if (buf[fd] == NULL)
	{
		buf[fd] = malloc(BUFFER_SIZE + 1);
		buf[fd][0] = '\0';
	}
	if (*buf[fd] == '\0')
	{
		n = read(fd, buf[fd], BUFFER_SIZE);
		if (n <= 0 && buf[fd] != NULL)
		{
			ft_free(&buf[fd]);
			return (NULL);
		}
		buf[fd][n] = '\0';
	}
	return (buf[fd]);
}

char	*get_next_line(int fd)
{
	char	*line;
	int		i;
	char	*buf;
	char	*temp;

	line = NULL;
	while (1)
	{
		i = 0;
		buf = get_buf(fd);
		if (buf == NULL)
			return (line);
		while (buf[i] != '\n' && buf[i + 1] != '\0')
			i++;
		temp = ft_substr(buf, 0, i + 1);
		buf_scroll(buf, i + 1);
		if (temp[i] == '\n')
		{
			line = ft_strjoin(line, temp);
			return (line);
		}
		line = ft_strjoin(line, temp);
	}
	return (line);
}
