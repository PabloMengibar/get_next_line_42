/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmengiba <pmengiba@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:29:14 by pmengiba          #+#    #+#             */
/*   Updated: 2025/01/13 19:49:13 by pmengiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char    *get_next_line(int fd);
char    *ft_strdup(char *s);
size_t    ft_strlen(char *s);
char    *ft_substr(char *s, unsigned int start, size_t len);
char    *ft_strjoin(char *s1, char *s2);
void    fill_str(char *res, char *s1, char *s2);

#endif