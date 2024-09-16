#include "libft.h"

// This function applies the function `f` to each character of the string `s`, along with its index,
// and creates a new string with the transformed characters.
char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    int length;
    char *newstr;
    int i;

    length = ft_strlen(s); // Get the length of the string
    i = 0;
    newstr = malloc(length + 1); // Allocate memory for the new string
    if (!newstr)
        return (NULL); // Return NULL if memory allocation fails

    if (!s || !f) // Check if the string or function pointer is NULL
        return (NULL); // Return NULL if either is NULL

    while (s[i] != '\0') // Apply the function `f` to each character of the string
    {
        newstr[i] = f(i, s[i]);
        i++;
    }
    newstr[i] = '\0'; // Null-terminate the new string
    return (newstr); // Return the new string with transformed characters
}
