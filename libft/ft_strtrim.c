/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:03:56 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/12 14:03:58 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function trims characters specified in `set` from the beginning and end of the string `s1`.
// It returns a new string with the characters from `set` removed from both ends.
char *ft_strtrim(char const *s1, char const *set)
{
    int start;
    int end;
    char *new_str;
    int new_size;

    start = 0;
    end = ft_strlen(s1) - 1;

    if (!s1 || !set) // Check for null pointers
        return (NULL);

    // Move `start` index to the first character not in `set`
    while (s1[start] && ft_strchr(set, s1[start]))
        start++;

    // Move `end` index to the last character not in `set`
    while (end > start && ft_strchr(set, s1[end]))
        end--;

    new_size = end - start + 1; // Calculate the length of the new trimmed string
    new_str = malloc(new_size + 1); // Allocate memory for the new string
    if (!new_str)
        return (NULL);

    // Copy the trimmed substring to `new_str`
    ft_memcpy(new_str, &s1[start], new_size);
    new_str[new_size] = '\0'; // Null-terminate the new string

    return (new_str); // Return the trimmed string
}
