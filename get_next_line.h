/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:02:27 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/18 14:02:29 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef MAX_FD
#  define MAX_FD 1024 
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "../libft/libft.h"

void	free_static_buffer(void);
char	*get_next_line(int fd);

#endif

