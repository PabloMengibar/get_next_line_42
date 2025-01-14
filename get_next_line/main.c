/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmengiba <pmengiba@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:55:19 by pmengiba          #+#    #+#             */
/*   Updated: 2025/01/14 15:29:16 by pmengiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
