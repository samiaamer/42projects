#include "libfr.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int	len_s1;
	int	len_s2;
	char	*s3;
	int	totalSize;
	int	i;
	int	j;

	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	totalSize = len_s1 + len_s2;
	s3 = malloc(totalSize+ 1);
	if (s3 == NULL)
		return (0);
	while (s1 != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2 != '\0')
	{
		s3[i] = s2[j];
		j++;
		i++;
	}
	s3[i] = '\0';
	return(s3);
}
