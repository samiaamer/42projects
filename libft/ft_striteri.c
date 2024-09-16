#include "libft.h"

// This function applies the function `f` to each character of the string `s`, along with its index.
void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    unsigned int i;

    i = 0; // Initialize the index
    if (!s || !f) // Check if the string or function is NULL
        return; // Return if either is NULL
    while (s[i] != '\0') // Loop through the string
    {
        f(i, &s[i]); // Apply the function `f` to the character at index `i`
        i++; // Move to the next character
    }
}
