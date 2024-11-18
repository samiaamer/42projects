#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h> 
//# include "libft.h"

char *get_next_line(int fd);
char *read_to_leftover(int fd, char *left);
char  *save_left(char *data);
char  *get_line(char  *data);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);

#endif
