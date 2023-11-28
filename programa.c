#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Verifica que se proporcione un nombre de archivo de entrada y salida
    if (argc != 3) {
        printf("Uso: %s archivo_entrada archivo_salida\n", argv[0]);
        return 1;
    }

    // Abre el archivo de entrada en modo lectura
    FILE *archivo_entrada = fopen(argv[1], "r");
    if (archivo_entrada == NULL) {
        perror("Error al abrir el archivo de entrada");
        return 1;
    }

    // Abre el archivo de salida en modo escritura
    FILE *archivo_salida = fopen(argv[2], "w");
    if (archivo_salida == NULL) {
        perror("Error al abrir el archivo de salida");
        fclose(archivo_entrada);
        return 1;
    }

    char linea[256];  // Tamaño máximo de una línea
    while (fgets(linea, sizeof(linea), archivo_entrada)) {
        // Busca líneas que comienzan con "--rain:"
        if (strstr(linea, "--rain:") == linea) {
            // Escribe la línea en el archivo de salida
            fprintf(archivo_salida, "%s", linea);
        }
    }

    // Cierra los archivos
    fclose(archivo_entrada);
    fclose(archivo_salida);

    printf("Proceso completado. Líneas con '--rain:' se han guardado en %s\n", argv[2]);
    return 0;
}