/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <hel-hamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:51:03 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/13 13:10:43 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line_from_storage(char **storage, char *buffer, char *nl)
{
	char	*line;
	char	*tmp;
	char	*new_s;
	size_t	i;

	free(buffer);
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
	if (!tmp)
	{
		free(*storage);
		return (NULL);
	}
	free(*storage);
	*storage = tmp;
	return (line);
}

int	append_buffer_to_storage(char **storage, char *buffer, size_t bytes_read)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while ((*storage)[i])
		i++;
	tmp = ft_strndup(*storage, i);
	if (!tmp)
	{
		free(*storage);
		free(buffer);
		return (-1);
	}
	free(*storage);
	*storage = (char *)ft_memalloc(sizeof(char) * (i + bytes_read + 1));
	if (!*storage)
	{
		free(tmp);
		free(buffer);
		return (-1);
	}
	ft_strncat(*storage, tmp, i);
	free(tmp);
	ft_strncat(*storage, buffer, bytes_read);
	return (1);
}

char	*last_line_in_storage(char **storage, char *buffer)
{
	char	*line;
	size_t	i;

	free(buffer);
	if (!storage || !(*storage))
		return (NULL);
	if (!(**storage))
	{
		free(*storage);
		return (NULL);
	}
	i = 0;
	while ((*storage)[i])
		i++;
	line = ft_strndup(*storage, i);
	if (!line)
	{
		free(*storage);
		return (NULL);
	}
	free(*storage);
	*storage = ft_strndup("", 0);
	return (line);
}

int	ft_read_buffer(char **buffer, int fd)
{
	int	bytes_read;

	if (!buffer || !*buffer)
		return (-1);
	bytes_read = read(fd, *buffer, BUFFER_SIZE);
	if (bytes_read > 0)
		(*buffer)[bytes_read] = '\0';
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*buffer;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE == -1)
		return (NULL);
	if (!storage)
		storage = ft_strndup("", 1);
	if (!storage)
		return (NULL);
	buffer = (char *)ft_memalloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(storage);
		return (NULL);
	}
	return (ft_get_line(&storage, &buffer, fd));
}
