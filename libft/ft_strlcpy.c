/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:09:03 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/02 18:46:40 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function copies up to `size - 1` characters from `src` to `dst` and ensures `dst` is null-terminated.
// It returns the total length of the string `src` would have had if `size` had been large enough.
size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t i;

    i = 0;
    if (size == 0) // If size is 0, nothing is copied
        return (ft_strlen(src)); // Return the length of `src`

    while (i < size - 1 && src[i]) // Copy characters from `src` to `dst` while there is space
    {
        dst[i] = src[i];
        i++;
    }
    if (i < size) // Null-terminate `dst`
    {
        dst[i] = '\0';
    }
    return (ft_strlen(src)); // Return the length of `src`
}

/*Copies a string to a buffer, ensuring null termination and avoiding overflow.*/
