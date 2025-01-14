/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmengiba <pmengiba@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:32:59 by pmengiba          #+#    #+#             */
/*   Updated: 2025/01/14 15:31:40 by pmengiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_set_line(char *line_buffer)
{
	char	*remainder;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == '\0')
		return (NULL);
	remainder = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*remainder == 0)
	{
		free(remainder);
		remainder = NULL;
	}
	line_buffer[i + 1] = 0;
	return (remainder);
}

static char	*ft_concat_remainder(char *remainder, char *buffer, ssize_t bytes)
{
	char	*tmp;

	if (!remainder)
		remainder = ft_strdup("");
	buffer[bytes] = 0;
	tmp = remainder;
	remainder = ft_strjoin(tmp, buffer);
	free(tmp);
	return (remainder);
}

static char	*ft_fill_line(int fd, char *remainder, char *buffer)
{
	ssize_t	bytes;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(remainder);
			return (NULL);
		}
		else if (bytes == 0)
			break ;
		remainder = ft_concat_remainder(remainder, buffer, bytes);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (remainder);
}

static char	*ft_create_buffer(void)
{
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		*buffer;

	buffer = ft_create_buffer();
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(remainder);
		free(buffer);
		remainder = NULL;
		buffer = NULL;
		return (NULL);
	}
	line = ft_fill_line(fd, remainder, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	remainder = ft_set_line(line);
	return (line);
}
