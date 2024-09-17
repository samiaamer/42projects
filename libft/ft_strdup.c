/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:52:31 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/17 11:52:33 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function duplicates the string `s` by allocating memory and copying its contents.
char *ft_strdup(const char *s)
{
    size_t leng; // Variable to hold the length of the string
    char *new; // Pointer to hold the duplicated string

    leng = ft_strlen(s); // Get the length of the original string
    new = malloc(leng + 1); // Allocate memory for the new string
    if (!new) // Check if memory allocation failed
        return (0); // Return NULL if allocation fails
    ft_memcpy(new, s, leng + 1); // Copy the original string to the new string
    return (new); // Return the duplicated string
}

