/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:50:10 by sabutale          #+#    #+#             */
/*   Updated: 2024/11/21 10:52:14 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*read_to_leftover(int fd, char *leftover, char *buffer);
char	*save_left(char *data);
char	*get_line1(char *data);
char	*ft_strjoin2(char const *s1, char const *s2);
char	*ft_strchr2(const char *s, int c);
size_t	ft_strlen2(const char *s);
size_t	ft_strlcpy2(char *dst, const char *src, size_t size);
char	*ft_strdup2(const char *s);

#endif
