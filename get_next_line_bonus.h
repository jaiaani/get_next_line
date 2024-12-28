#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# ifndef MAX_FD
#   define MAX_FD 1024 
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
void	*ft_calloc(size_t nelem, size_t elsize);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
char	*get_next_line(int fd);

#endif