#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned char	*d;
	const unsigned char	*s;

	i = 0;
	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
int	main()
{
	char	src[] = "samia amer";
	char	dest[20];
	ft_memcpy(dest, src, 11);
	printf("destenation %s", dest);
	return(0);
}*/
