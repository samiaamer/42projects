#include "get_next_line.h"


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char *read_to_leftover(int fd, char *leftover)
{
  char  *buffer;
  char  *temp;
  ssize_t  bytes_read;

    if (!leftover)
        leftover = ft_strdup("");
  buffer = malloc(BUFFER_SIZE + 1);
  if (!buffer)
    return (NULL);
  bytes_read = read(fd, buffer, BUFFER_SIZE);
  
  while(!ft_strchr(leftover, '\n') && bytes_read > 0)
  {
      buffer[bytes_read] = '\0';
      temp = ft_strjoin(leftover, buffer);
      free(leftover);
      leftover = temp;
  }
  free(buffer);
  if (bytes_read < 0)
  {
    free(leftover);
    return(NULL);
  }
  return (leftover);
}

char  *get_line(char  *data)
{
  size_t i;
  char  *line;

  i = 0;
  if (!data || !data[0])
    return (NULL);
  while (data[i] && data[i] != '\n')
    i++;
  line = malloc(i + 2);
  if(!line)
    return (NULL);
  ft_strlcpy(line, data, i + 2);
  return (line);
}

char  *save_left(char *data)
{
  size_t i;
  size_t len;
  char *left;

  i = 0;
  while(data[i] && data[i] != '\n')
    i++;
  if(!data[i])
  {
    free(data);
    return (NULL);
  }
  len = ft_strlen(data + i + 1);
  left = malloc(len + 1);
  if(!left)
    return(NULL);
  ft_strlcpy(left, data + i + 1, len + 1);
  free(data);
  return (left);
}

char *get_next_line(int fd)
{
  static char *leftover;
  char  *line;

  if (fd < 0 || BUFFER_SIZE <= 0)
    return (0);
  leftover = read_to_leftover(fd, leftover);
  if (!leftover)
    return (0);
  line = get_line(leftover);
  leftover = save_left(leftover);
  return (line);
}
