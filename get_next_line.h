/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:49:33 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/25 13:49:34 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stddef.h>
# include <unistd.h>

typedef struct		s_bblock
{
	struct s_bblock	*next;
	char			data[BUFFER_SIZE];
}					t_bblock;

typedef struct		s_buff
{
	size_t			content_size;
	size_t			buff_size;
	t_bblock		block;
}					t_buff;

typedef struct		s_static_buff
{
	char			content[BUFFER_SIZE];
	ssize_t			index;
	ssize_t			size;
	int				fd;
}					t_static_buff;

int					get_next_line(int fd, char **line);

t_buff				*create_buffer();
int					write_char_buffer(t_buff *buff, char c);
char				*merge_buffer(t_buff *buff);
void				destroy_buffer(t_buff *buff);

#endif
