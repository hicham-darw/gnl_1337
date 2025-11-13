/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <hel-hamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:09:26 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/13 15:59:53 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# define MAX_FD 1024

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strndup(const char *s, size_t len);
char	*ft_strchr(const char *s, int c);
void	*ft_memalloc(size_t size);
char	*ft_strncat(char *dest, const char *src, size_t len);
char	*ft_get_line(char **storage, char **buffer, int fd);
int		ft_read_buffer(char **buffer, int fd);
int		append_buffer_to_storage(char **storage, char *buffer, size_t br);
char	*get_line_from_storage(char **storage, char *buffer, char *new_line);
char	*last_line_in_storage(char **storage, char *buffer);

#endif
