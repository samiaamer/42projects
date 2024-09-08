#include "libft.h"

char *strdup(const char *s)
{
	size_t	leng;
	char	new;

	leng = ft_strlen(s);
	new = malloc(leng + 1);
	if(new == '\0')
		return (0);
	ft_memcpy(new, s, leng + 1);
	return(new);
}
