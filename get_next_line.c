/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:49:13 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/25 13:49:14 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

#include "get_next_line.h"

int		read_char(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static ssize_t	buffer_size = 0;
	char			c;
	ssize_t			i;

	if (buffer_size == 0)
	{
		buffer_size = read(fd, buffer, BUFFER_SIZE);
		if (buffer_size == 0)
			return (-1);
		if (buffer_size == -1)
			return (-2);
	}
	c = buffer[0];
	i = 0;
	--buffer_size;
	while (i < buffer_size)
	{
		buffer[i] = buffer[i + 1];
		++i;
	}
	return (c);
}

int		get_next_line(int fd, char **line)
{
	t_buff		content;
	int			c;
	char		*result;

	init_buffer(&content);
	while ((c = read_char(fd)) >= 0)
	{
		if (c == '\n')
			break ;
		if (!write_char_buffer(&content, c))
		{
			c = -2;
			break ;
		}
	}
	if ((result = merge_buffer(&content)) == NULL)
		c = -2;
	destroy_buffer(&content);
	if (c != '\n')
		return (c + 1);
	*line = result;
	return (1);
}
