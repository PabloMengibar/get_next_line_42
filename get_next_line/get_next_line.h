/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmengiba <pmengiba@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:09:13 by pmengiba          #+#    #+#             */
/*   Updated: 2025/01/23 14:24:14 by pmengiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

size_t	ft_strlen(char *s);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strchr(char *str, int c);
char	*ft_bulloc(int fd, char *s);
char	*get_next_line(int fd);
char	*ft_buffer(char *line);
char	*ft_set_line(char *str);

#endif
