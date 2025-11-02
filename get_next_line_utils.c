/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:01:31 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/01 16:01:13 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (i < len)
		ptr = (char *)malloc(sizeof(char) * (i + 1));
	else
		ptr = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (s[i] && i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*get_line_update_storage(char **buffer, char **storage, int fd)
{
	int	bytes_read;
	char	*line;
	char	*is_nl;
	char	*tmp;

	if (!buffer || !*buffer || !storage || !*storage)
		return (NULL);
	bytes_read = read(fd, *buffer, BUFF_SIZE);
	if (bytes_read > 0)
	{
		*buffer[bytes_read] = '\0';
		if (ft_strchr(*storage, '\n'))
		{
			is_nl = ft_strchr(*storage, '\n');
			line = ft_strndup(*storage, (is_nl - (*storage) + 1));
			tmp = ft_strndup((*storage) + (is_nl - (*storage)) + 1, ft_strlen((*storage) + (is_nl - (*storage)) + 1));
			free(*storage);
			*storage = (char *)malloc(sizeof(char) * (ft_strlen(tmp) + ft_strlen(*buffer) + 1));
			if (!storage)
			{
				free(*buffer);
				return (NULL);
			}
			ft_memset(*storage, 0, ft_strlen(tmp) + ft_strlen(*buffer) + 1);
			ft_strncat(*storage, tmp, ft_strlen(tmp));
			ft_strncat(*storage, *buffer, ft_strlen(*buffer));
			return (line);
		}

		
	}
	else if (bytes_read == 0)
		return (NULL);
}
