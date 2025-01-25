/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <sabutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:28:53 by sabutale          #+#    #+#             */
/*   Updated: 2025/01/25 13:41:21 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*read_to_leftover(int fd, char *leftover, char *buffer)
{
	char	*temp;
	ssize_t	bytes_read;

	bytes_read = 0;
	while (!ft_strchr(leftover, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(leftover, buffer);
		if (!temp)
			return (NULL);
		free(leftover);
		leftover = temp;
	}
	free(buffer);
	if (bytes_read < 0)
	{
		free(leftover);
		return (NULL);
	}
	return (leftover);
}

char	*get_line1(char *data)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!data || !data[0])
		return (NULL);
	while (data[i] && data[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	ft_strlcpy(line, data, i + 2);
	return (line);
}

char	*save_left(char *data)
{
	size_t	i;
	size_t	len;
	char	*left;

	i = 0;
	while (data[i] && data[i] != '\n')
		i++;
	if (!data[i])
	{
		free(data);
		return (NULL);
	}
	len = ft_strlen(data + i + 1);
	left = malloc(len + 1);
	if (!left)
		return (NULL);
	ft_strlcpy(left, data + i + 1, len + 1);
	free(data);
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!leftover)
		leftover = ft_strdup("");
	if (!leftover)
		return (NULL);
	leftover = read_to_leftover(fd, leftover, buffer);
	if (!leftover)
		return (NULL);
	line = get_line1(leftover);
	leftover = save_left(leftover);
	return (line);
}