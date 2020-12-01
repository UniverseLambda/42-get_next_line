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

#include <stdlib.h>

#include "get_next_line.h"

/*
** Reads the next unsigned char from fd. This method uses an internal static
** buffer to store the chars it reads from fd. The internal buffer size
** is BUFFER_SIZE.
**
** @return the next unsigned char from fd if any; -1 if it reaches the end of
** file of the fd; -2 if an error occured.
**
** @see man read(2)
** @see BUFFER_SIZE
*/

int		read_char(int fd)
{
	static t_static_buff	buffer = {.size = 0, .fd = -1};
	unsigned char			c;

	if (buffer.fd != fd)
	{
		buffer.size = 0;
		buffer.fd = fd;
	}
	if (buffer.index >= buffer.size)
	{
		buffer.index = 0;
		buffer.size = read(fd, buffer.content, BUFFER_SIZE);
		if (buffer.size == 0)
			return (-1);
		if (buffer.size == -1)
			return (-2);
	}
	c = (unsigned char)(buffer.content[buffer.index]);
	++(buffer.index);
	return ((int)c);
}

int		get_next_line(int fd, char **line)
{
	t_buff	*content;
	int		c;
	char	*result;

	if (BUFFER_SIZE == 0 || line == NULL)
		return (-1);
	if ((content = create_buffer()) == NULL)
		return (-1);
	while ((c = read_char(fd)) >= 0)
	{
		if (c == '\n')
			break ;
		if (!write_char_buffer(content, c))
		{
			c = -2;
			break ;
		}
	}
	if ((result = merge_buffer(content)) == NULL)
		c = -2;
	destroy_buffer(content);
	*line = result;
	if (c == -2 || (c == -1))
		return (c + 1);
	return (1);
}
