
#include "libft.h"


/*ft_split is a function that takes a string and splits it into smaller strings based on a delimiter character. 
For example, if you have a string like "apple,banana,cherry" and you use a comma as the delimiter, 
ft_split will return an array of strings ["apple", "banana", "cherry"].*/


/* It goes through the string and counts the number of words by checking 
when it encounters a non-delimiter character after a delimiter or 
the start of the string.*/
int count_word(char const *s, char c)//count how many words are in the string 
{
  int count;
  int i;

  count = 0;
  i = 0;
  while (s[i] == c)// Skip delimiter characters at the beginning
    i++;
  while (s[i] != '\0')// Loop through the string
  {
    if (s[i] != c)// Found the start of a word
    {
      count++; // Increase the word count
      while (s[i] != '\0' && s[i] != c)// Skip until the end of the word
        i++;
    }
    else
      i++;// Skip the delimiter character
  }
  return count;// Return the number of words found
}


/* It uses malloc to create enough space for the word and then copies the word from the original string into this space.
 It also adds a null terminator to mark the end of the string.*/
static char *allocate_mem(const char *start, size_t length)//allocate memory for the words and copy them into the malloc
{
  char *substr = (char *)malloc(length + 1);// Allocate memory for the substring
  if(substr)
  {
    ft_strlcpy(substr, start, length);// Copy the substring into the allocated memory
    substr[length] = '\0';// Null-terminate the substring
  }
  return (substr);// Return the allocated substring
}


/*It skips delimiters to find the start of each word.
It then finds the end of the word, allocates memory for it, and copies it into the array.
If memory allocation fails, it frees any previously allocated memory to avoid memory leaks.*/
static int split_words(char const *s, char c, char **res)//splits the string into individual words and stores them in an array. 
{
    int i;
    const char *start;// Pointer to mark the start of each word

    i = 0;
    while (*s)// Loop through the entire string
    {
        if (*s != c) // If not a delimiter, start of a word
        {
            start = s;// Mark the start of the word
            while (*s && *s != c)// Move to the end of the word
                s++;
            if (!(res[i++] = allocate_mem(start, s - start)))// Allocate and copy the word
            {
                while (i > 0)// Free previously allocated words if allocation fails
                    free(res[--i]);
                return (-1);// Return -1 to indicate failure
            }
        }
        else
          s++;// Skip delimiters
    }
    return (i);// Return the number of words successfully allocated
}


/*It calculates the number of words using count_word.
It allocates memory for an array of strings based on this number.
It calls split_words to fill this array with words.
If an error occurs, it frees the memory and returns NULL.*/
char **ft_split(char const *s, char c)
{
  char **res;// Pointer to hold the array of strings
  int total_words;// Number of words to be split from the string
  int words_extracted;// The actual count of words split successfully

  if (!s)// Check if the input string is NULL
    return (NULL);// Return NULL if there's no string to split
  total_words = count_word(s, c);// Count the number of words in the string
  res = (char **)malloc((total_words + 1) * 8);// Allocate memory for the array of strings
  if (!res)// Check if memory allocation failed
    return (NULL);
  words_extracted = split_words(s, c, res);// Split the string into words and store them in the array
  if (words_extracted < 0)// Check if there was an error in splitting
  {
    free(res);// Free the allocated memory
    return (NULL); // Return NULL if splitting failed
  }
  res[words_extracted] = NULL;// Set the last element of the array to NULL to mark the end
  return (res);// Return the array of strings
}

/*
int main()
{
    char **result;
    char str[] = "apple,banana,cherry";
    char delimiter = ',';
    int i = 0;

    result = ft_split(str, delimiter);
    if (result)
    {
        while (result[i])
        {
            printf("%s\n", result[i]);
            free(result[i]);
            i++;
        }
        free(result);
    }
    return 0;
}
*/