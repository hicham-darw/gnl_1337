/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:52:53 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/01 16:01:27 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char	*buffer;
	char	*line;
	char	*is_nl;

	if (fd < 0)
		return (NULL);
	if (!storage)
		storage = ft_strndup("", 1);
	buffer = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (1)
	{
		line = get_line_update_storage(&buffer, &storage, fd);	
//continue get_line update buffer;
	
	}
}
