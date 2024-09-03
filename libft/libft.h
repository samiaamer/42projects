/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:31:03 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/03 11:56:35 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stdlib.h>

int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_tolower(int c);
int	ft_toupper(int c);
int	ft_atoi(const char *nptr);
char 	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void    *ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void* dest, const void* src, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
