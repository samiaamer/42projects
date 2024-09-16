#include "libft.h"

// This function concatenates two strings `s1` and `s2` and returns a new string.
char *ft_strjoin(char const *s1, char const *s2)
{
    char *s3; // Pointer to hold the concatenated string
    int i; // Index for `s1`
    int j; // Index for `s2`

    i = 0; // Initialize index for `s1`
    j = 0; // Initialize index for `s2`
    s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1); // Allocate memory for the new string
    if (s3 == NULL) // Check if memory allocation failed
        return (0); // Return NULL if allocation fails
    while (s1[i] != '\0') // Copy the first string
    {
        s3[i] = s1[i]; // Copy each character from `s1` to `s3`
        i++;
    }
    while (s2[j] != '\0') // Copy the second string
    {
        s3[i] = s2[j]; // Copy each character from `s2` to `s3`
        j++;
        i++;
    }
    s3[i] = '\0'; // Null-terminate the new string
    return (s3); // Return the concatenated string
}

