/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:14:57 by jados-sa          #+#    #+#             */
/*   Updated: 2025/01/03 21:40:36 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_buff(char *remaining, char *cup_buffer)
{
	char	*temp;

	temp = ft_strjoin(remaining, cup_buffer);
	if (!temp)
	{
		free(remaining);
		return (NULL);
	}
	free(remaining);
	return (temp);
}

char	*read_line(int fd, char *readed)
{
	char	*cup_buffer;
	int		bytes_read;

	if (!readed)
		readed = ft_calloc(1, 1);
	cup_buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!cup_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(cup_buffer);
			free(readed);
			return (NULL);
		}
		cup_buffer[bytes_read] = '\0';
		readed = join_buff(readed, cup_buffer);
		if (ft_strchr(readed, '\n'))
			break ;
	}
	free(cup_buffer);
	return (readed);
}

char	*get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str || !str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(line, str, i + 2);
	return (line);
}

char	*get_remaining(char *str)
{
	char	*remaining;
	int		i;
	int		len;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	len = ft_strlen(str + i + 1);
	remaining = ft_calloc(len + 1, sizeof(char));
	if (!remaining)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(remaining, str + i + 1, len + 1);
	free(str);
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = get_remaining(buffer);
	return (line);
}
