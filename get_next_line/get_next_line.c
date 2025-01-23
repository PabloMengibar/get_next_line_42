/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmengiba <pmengiba@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:09:17 by pmengiba          #+#    #+#             */
/*   Updated: 2025/01/23 14:28:37 by pmengiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_lilloc(int i)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * (i + 2));
	if (!new)
		return (NULL);
	return (new);
}

void	ft_copy_line(char *new, char *s, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		new[j] = s[j];
		j++;
	}
	if (s[i] == '\n')
	{
		new[j] = '\n';
		j++;
	}
	new[j] = '\0';
}

char	*ft_set_line(char *s)
{
	char	*new;
	int		i;

	i = 0;
	if (s[i] == 0)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	new = ft_lilloc(i);
	if (!new)
		return (NULL);
	ft_copy_line(new, s, i);
	return (new);
}

char	*ft_buffer(char *line)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_bulloc(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_set_line(buffer);
	buffer = ft_buffer(buffer);
	return (line);
}
