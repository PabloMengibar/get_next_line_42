#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1  // Leer un carácter por vez

// Función para leer una línea del archivo
char *read_line(int fd) {
    char *line = malloc(BUFFER_SIZE);  // Inicializamos con un espacio para un solo carácter
    if (!line) return NULL;  // Verificar si hubo error al asignar memoria

    size_t len = 0;
    char ch;
    size_t i = 0;
    // Leemos un carácter a la vez
    while (read(fd, &ch, 1) > 0) {
        if (ch == '\n')  // Si encontramos un salto de línea, terminamos
            break;
        // Aumentamos el tamaño del buffer y añadimos el nuevo carácter
        line[len] = ch;
        len++;
        // Asignamos más memoria para el siguiente carácter
        char *tmp = malloc(len + 1);
        if (!tmp) {
            free(line);
            return NULL; 
        }
        // Copiar los caracteres previamente almacenados en el nuevo buffer
        while ( i < len) {
            tmp[i] = line[i];
            i++;
        }

        free(line);  // Liberamos la memoria anterior
        line = tmp;  // Actualizamos el puntero con el nuevo bloque de memoria
    }

    if (len == 0 && ch != '\n') {
        free(line);
        return NULL;
    }

    line[len] = '\0';
    return line;  // Retornar la línea leída
}

// Función get_next_line para leer el archivo línea por línea
char *get_next_line(int fd) {
    static int last_fd = -1;  // Guardamos el descriptor de archivo
    if (fd != last_fd) {      // Si el descriptor de archivo cambia, reiniciamos
        last_fd = fd;
    }
    return read_line(fd);
}

int main(void) {
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1) 
        return 1;
    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("Línea leída: %s\n", line);
        free(line);
    }
    close(fd);
    return 0;
}

