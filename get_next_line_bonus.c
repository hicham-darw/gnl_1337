/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:36:41 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/06 12:36:54 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	while ((*storage)[i])
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
	ft_memset(*storage, 0, (i + j + 1));
	ft_strncat(*storage, tmp, i);
	free(tmp);
	ft_strncat(*storage, buffer, j);
	return (1);
}

char	*last_line_in_storage(char **storage)
{
	char	*line;
	size_t	i;

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
	free(*storage);
	*storage = ft_strndup("", 0);
	return (line);
}

int	ft_read_buffer(char (*buffer)[], int fd)
{
	int	bytes_read;

	if (!buffer || !*buffer)
		return (-1);
	bytes_read = read(fd, *buffer, BUFFER_SIZE);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || fd > 1024)
		return (NULL);
	if (!storage)
		storage = ft_strndup("", 1);
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	return (ft_get_line(&storage, &buffer, fd));
}
