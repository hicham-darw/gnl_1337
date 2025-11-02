/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:54:45 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/02 19:10:59 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
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

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
