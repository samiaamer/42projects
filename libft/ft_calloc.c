#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	tsize;
	void	*box;

	tsize = nmemb * size;
	box = malloc(tsize);
	if(box == '\0')
		return (0);
	ft_memset (box, 0, tsize);
	return (box);
}
