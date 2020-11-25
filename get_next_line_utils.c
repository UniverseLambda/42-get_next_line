/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:49:18 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/25 13:49:19 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "get_next_line.h"

void			init_buffer(t_buff *buff)
{
	buff->content_size = 0;
	buff->buff_size = BUFFER_SIZE;
	buff->block.prev = NULL;
	buff->block.next = NULL;
}

static t_bblock	*get_or_extend_buffer(t_buff *buff, size_t index)
{
	t_bblock *previous;
	size_t i;

	i = 0;
	previous = &(buff->block);
	while (previous->next != NULL && i < index)
	{
		previous = previous->next;
	}
	if (i == index)
		return (previous);
	previous->next = malloc(sizeof(t_bblock));
	return (previous->next);
}

int				write_char_buffer(t_buff *buff, char c)
{
	const int	index = buff->content_size / buff->buff_size;
	t_bblock	*elem;

	elem = get_or_extend_buff(buff, index);
	if (elem == NULL)
		return (0);
	((char *)elem->data)[buff->content_size % buff->buff_size] = c;
	buff->content_size++;
	return (1);
}

char			*merge_buffer(t_buff *buff)
{
	char		*merged;
	int			index;
	t_bblock	*block;
	int			last_block;

	merged = malloc(buff->content_size + 1);
	if (merged == NULL)
		return (NULL);
	block = &(buff->block);
	last_block = 0;
	index = 0;
	while (index < buff->content_size)
	{
		if (index / buff->buff_size != last_block)
		{
			block = block->next;
			++last_block;
		}
		merged[index] = ((char *)block->data)[index % buff->buff_size];
		++index;
	}
	merged[index] = 0;
	return (merged);
}

void			destroy_buffer(t_buff *buff)
{
	t_bblock *next_block;
	t_bblock *tmp;
	
	next_block = buff->block.next;
	while (next_block != NULL)
	{
		tmp = next_block;
		next_block = next_block->next;
		free(tmp);
	}
}