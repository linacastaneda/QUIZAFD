#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* funcion que verifica si un caracter es mayuscula
   parametros:
   c: caracter a verificar
   retorna: 1 si es mayuscula A-Z, 0 en caso contrario */
int es_mayuscula(char c) {
    return c >= 'A' && c <= 'Z';
}

/* funcion que verifica si un caracter es minuscula o digito
   parametros:
   c: caracter a verificar
   retorna: 1 si es minuscula a-z o digito 0-9, 0 en caso contrario */
int es_minuscula_o_digito(char c) {
    return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

/* procesa una linea de texto

   parametros:
   linea: puntero a cadena con la linea a procesar

   variables internas:
   i: indice entero que recorre la cadena
   n: longitud de la cadena

   comportamiento:
   imprime tokens reconocidos por linea: INCR, SUMA, ID
   si encuentra un caracter no valido imprime NO ACEPTA y retorna 0
   retorna 1 en caso de exito
*/
int analizar_linea(char *linea) {
    int i = 0; /* indice actual */
    int n = strlen(linea); /* longitud de la linea */

    while (i < n) {
        /* ignorar espacios, saltos de linea y tabs */
        if (isspace(linea[i])) {
            i++;
            continue;
        }

        /* caso para suma (+) e incremento (++) */
        if (linea[i] == '+') {
            if (i + 1 < n && linea[i+1] == '+') {
                printf("INCR\n"); /* token incremento */
                i += 2; /* consumir los dos signos */
            } else {
                printf("SUMA\n"); /* token suma simple */
                i++; /* consumir un signo */
            }
            continue;
        }

        /* caso para identificador: empieza con mayuscula seguido
           de minusculas o digitos [A-Z][a-z0-9]* */
        if (es_mayuscula(linea[i])) {
            i++; /* consumir la letra inicial mayuscula */
            /* consumir todos los caracteres validos siguientes */
            while (i < n && es_minuscula_o_digito(linea[i])) {
                i++;
            }
            printf("ID\n"); /* token identificador */
            continue;
        }

        /* si no coincide con ninguna regla, no acepta */
        printf("NO ACEPTA\n");
        return 0; /* retorna error para detener el proceso */
    }
    return 1; /* exito */
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("uso: %s entrada.txt\n", argv[0]);
        return 1;
    }

    FILE *archivo = fopen(argv[1], "r");
    if (archivo == NULL) {
        printf("error: el archivo no existe\n");
        return 1;
    }

    char buffer[1024]; /* buffer para leer cada linea */
    /* leer el archivo linea por linea */
    while (fgets(buffer, sizeof(buffer), archivo)) {
        /* quitar el salto de linea al final si existe */
        buffer[strcspn(buffer, "\n")] = '\0';

        /* si la linea esta vacia saltarla */
        if (strlen(buffer) == 0) {
            continue;
        }
        /* procesar la linea */
        analizar_linea(buffer);
    }

    fclose(archivo); /* cerrar el archivo */
    return 0;
}