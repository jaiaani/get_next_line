#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	total_len;
	int		i;
	int		j;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(sizeof(char) * (total_len + 1));
	if (!s1 || !s2 || !join )
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	return (join);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)s;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (str + i);
		i++;
	}
	if (c == '\0')
		return (str + i);
	return (NULL);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	src_l;

	i = 0;
	src_l = ft_strlen(src);
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_l);
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	size_t	tsize;
	void	*space;
	unsigned char	*s;

	if (nelem == 0 || elsize == 0)
		return (malloc(0));
	tsize = nelem * elsize;
	if (tsize / elsize != nelem)
		return (NULL);
	space = malloc(tsize);
	if (!space)
		return (NULL);
	s = (unsigned char *)space;
	while (tsize--)
		*s++ = '\0';	
	return (space);
}
