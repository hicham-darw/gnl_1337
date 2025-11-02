/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:51:03 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/02 19:13:18 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_read_buffer(char **buffer, int fd)
{
	int	bytes_read;

	if (!buffer || !*buffer)
		return (-1);
	bytes_read = read(fd, *buffer, BUFFER_SIZE);

}

char	*get_next_line(int fd)
{
	static char *storage = NULL;
	char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || fd > 1024)
		return (NULL);
	if (!storage)
		storage = ft_strndup("", 0);
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	while (1)
	{
		if (ft_read_buffer(&buffer, fd) <= 0)
		{
		
			return (NULL);
		}
		if (append_buffer_get_line(&storage, buffer) == 1)

	
	}
	return (NULL);
}

int	main()
{
	get_next_line(1);
}
