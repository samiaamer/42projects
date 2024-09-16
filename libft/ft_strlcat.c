/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:11:24 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/02 18:47:43 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function appends the string `src` to the end of `dst` up to `size - 1` characters.
// It ensures that the result is null-terminated and returns the total length of the string that would have been created if `size` had been sufficiently large.
size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t j;
    size_t src_len;
    size_t dst_len;

    i = 0;
    j = 0;
    src_len = ft_strlen(src); // Length of the source string
    dst_len = ft_strlen(dst); // Length of the destination string

    if (size == 0 || dst_len >= size) // Check if there's no space to append
        return (src_len + size); // Return the total length that would be needed

    i = dst_len; // Start appending from the end of the destination string
    while (src[j] && j < size - dst_len - 1) // Append characters from `src` to `dst` while there's space
    {
        dst[i] = src[j];
        i++;
        j++;
    }
    dst[i] = '\0'; // Null-terminate the result
    return (src_len + dst_len); // Return the total length of the concatenated string
}

/*Appends a string to a buffer, ensuring null termination and avoiding overflow.*/
