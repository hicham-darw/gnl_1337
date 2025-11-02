/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:51:03 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/02 21:35:32 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_read_buffer(char (*buffer)[], int fd)
{
	int	bytes_read;

	if (!buffer || !*buffer)
		return (-1);
	bytes_read = read(fd, *buffer, BUFFER_SIZE);
	return (bytes_read);
}

char	*get_line_from_storage(char **storage, char *nl)
{
	char	*line;
	char	*tmp;
	char	*new_s;
	size_t	i;

	line = ft_strndup(*storage, (nl - (*storage)) + 1);
	if (!line)
	{
		free(*storage);
		return (NULL);
	}
	new_s = ((*storage) + (nl - *storage) + 1);
	i = 0;
	while (new_s[i])
		i++;
	tmp = ft_strndup(new_s, i);
	free(*storage);
	*storage = tmp;
	return (line);
}

int	append_buffer_to_storage(char **storage, char *buffer)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	while (*storage[i])
		i++;
	tmp = ft_strndup(*storage, i);
	free(*storage);
	j = 0;
	while (buffer[j])
		j++;
	*storage = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!*storage)
	{
		free(tmp);
		return (-1);
	}
	ft_strncat(*storage, tmp, i);
	free(tmp);
	ft_strncat(*storage, buffer, j);
	return (1);
}

char	*get_next_line(int fd)
{
	static char *storage = NULL;
	char	buffer[BUFFER_SIZE + 1];
	char	*line;
	char	*nl;

	if (fd < 0 || fd > 1024)
		return (NULL);
	if (!storage)
		storage = ft_strndup("", 0);
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	while (1)
	{
		nl = ft_strchr(storage, '\n');
		if (nl)
			return (get_line_from_storage(&storage, nl));
		if (ft_read_buffer(&buffer, fd) <= 0)
		{
			free(storage);	
			return (NULL);
		}
		if (append_buffer_to_storage(&storage, buffer) == 1)
			continue;
		else 
			return (NULL);
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
	}
	return (NULL);
}

#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int fd = open("tst.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (42);
	}
	char	*line;
	while ((line = get_next_line(fd)))
	{
		printf("line: >|%s|<\n", line);
		free(line);
	}
}
