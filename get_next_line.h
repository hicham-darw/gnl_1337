/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:09:26 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/02 21:37:41 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 50
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strndup(const char *s, size_t len);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strncat(char *dest, const char *src, size_t len);

#endif
