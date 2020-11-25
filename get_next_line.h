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

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct		s_bblock
{
	struct s_bblock	*prev;
	struct s_bblock	*next;
	char			data[BUFFER_SIZE];
}					t_bblock;

typedef struct
{
	int				content_size;
	int				buff_size;
	t_bblock		block;
}					t_buff;

int			get_next_line(int fd, char **line);

void		init_buffer(t_buff *buff);
int			write_char_buffer(t_buff *buff, char c);
char		*merge_buffer(t_buff *buff);
void		destroy_buffer(t_buff *buff);

#endif
