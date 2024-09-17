/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:40:30 by sabutale          #+#    #+#             */
/*   Updated: 2024/09/17 11:40:32 by sabutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	tsize;
	void	*box;

	tsize = nmemb * size; // Calculate the total size needed
	box = malloc(tsize);// Allocate memory of size `tsize`
	if(box == NULL)// Check if memory allocation failed
		return (0);
	ft_memset (box, 0, tsize);// Set the allocated memory to 0
	return (box);// Return the pointer to the allocated memory
}
