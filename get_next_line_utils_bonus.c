/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:54:45 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/23 20:35:10 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	ptr = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	while (*s && *s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
	{
		p = (char *)s;
		return (p);
	}
	return (NULL);
}

char	*ft_get_line(char **storage, char **buffer, int fd)
{
	char	*new_line;
	int		bytes_read;

	while (1)
	{
		new_line = ft_strchr(*storage, '\n');
		if (new_line)
			return (get_line_from_storage(storage, *buffer, new_line));
		bytes_read = ft_read_buffer(buffer, fd);
		if (bytes_read < 0)
		{
			free(*buffer);
			free(*storage);
			return (NULL);
		}
		else if (bytes_read == 0)
			return (last_line_in_storage(storage, *buffer));
		if (append_buffer_to_storage(storage, *buffer, bytes_read) == 1)
			continue ;
		free(*storage);
		free(*buffer);
		return (NULL);
	}
	return (NULL);
}

char	*ft_strncat(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	if (!dest || !src)
		return (NULL);
	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j] && j < len)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

void	*ft_memalloc(size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc(size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
		ptr[i++] = '\0';
	return (ptr);
}
