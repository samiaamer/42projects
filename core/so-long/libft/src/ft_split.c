/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:59:33 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/17 11:59:50 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	count_word(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*allocate_mem(const char *start, size_t length)
{
	char	*substr;

	substr = (char *)malloc(length + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, start, length + 1);
	substr[length] = '\0';
	return (substr);
}

static int	split_words(char const *s, char c, char **res)
{
	int			i;
	const char	*start;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			res[i] = allocate_mem(start, s - start);
			if (!res[i])
			{
				while (i > 0)
					free(res[--i]);
				free(res);
				return (-1);
			}
			i++;
		}
		else
			s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		total_words;
	int		words_extracted;

	if (!s)
		return (NULL);
	total_words = count_word(s, c);
	res = (char **)malloc((total_words + 1) * 8);
	if (!res)
		return (NULL);
	words_extracted = split_words(s, c, res);
	res[words_extracted] = NULL;
	return (res);
}

/*
int	main(void)
{
	char	**result;
	char	str[] = "apple,banana,cherry";
	char	delimiter;
	int		i;

	delimiter = ',';
	i = 0;
	result = ft_split(str, delimiter);
	if (result)
	{
		while (result[i])
		{
			printf("%s\n", result[i]);
			free(result[i]);
			i++;
		}
		free(result);
	}
	return (0);
}
*/
