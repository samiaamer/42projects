#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
  int length;
  char  *newstr;
  int i;

  length = ft_strlen(s);
  i = 0;
  newstr = malloc(length + 1);
  if (!newstr)
    return (NULL);
  if (!s || f)
    return (NULL);
  while (s[i] != '\0')
  {
    newstr[i] = f(i, s[i]);
    i++;
  }
  newstr[length] = '\0';
  return(newstr)
}