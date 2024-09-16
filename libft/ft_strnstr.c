#include "libft.h"

// This function locates the first occurrence of the substring `needle` in the string `haystack`, up to `len` characters.
// It returns a pointer to the beginning of the found substring, or NULL if `needle` is not found.
char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;
    size_t j;

    i = 0;
    if (needle[0] == '\0') // If `needle` is an empty string
        return ((char *)haystack); // Return a pointer to the beginning of `haystack`
    while (haystack[i] && i < len)
    {
        if (i + ft_strlen(needle) > len) // Check if there is enough space left for `needle`
            return (0); // Return NULL if not enough space
        j = 0;
        while (needle[j] && haystack[i + j] == needle[j] && i + j < len)
            j++;
        if (needle[j] == '\0') // If the whole `needle` is found
            return ((char *)(haystack + i)); // Return a pointer to the beginning of `needle` in `haystack`
        i++;
    }
    return (0); // Return NULL if `needle` is not found
}

