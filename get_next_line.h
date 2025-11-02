/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:09:26 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/02 19:00:56 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 50
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strndup(const char *s, size_t len);

#endif
