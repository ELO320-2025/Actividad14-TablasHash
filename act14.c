#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10 // Modifica este valor para 10 dígitos con 3 codificaciones  posibles
#define CODE_LENGTH 8  // 7 bits + '\0'

// Estructura para cada entrada en la tabla
typedef struct {
    char codigo[CODE_LENGTH]; // Ej: "0001101"
    int digito;               // Ej: 0
} Entrada;

// Estructura de la tabla hash
typedef struct {
    Entrada *tabla[TABLE_SIZE];
} TablaHash;

// Función hash 
int hashFuncion(const char *codigo) {
    //TO DO: completa la función hash para retornar el índice en el arreglo que corresponde a cada código
    return 0;
}

// Inicializa la tabla
void inicializarTabla(TablaHash *hash) {
    for (int i = 0; i < TABLE_SIZE; i++)
        hash->tabla[i] = NULL;
}

// Inserta una entrada en la tabla
void insertar(TablaHash *hash, const char *codigo, int digito) {
    int index = hashFuncion(codigo);

    Entrada *nuevo = malloc(sizeof(Entrada));
    strcpy(nuevo->codigo, codigo);
    nuevo->digito = digito;

    // En esta versión simple no hay manejo de colisiones
    hash->tabla[index] = nuevo;
}

// Busca un código en la tabla y devuelve el dígito correspondiente
int buscar(TablaHash *hash, const char *codigo) {
    int index = hashFuncion(codigo);
    if (hash->tabla[index] != NULL && strcmp(hash->tabla[index]->codigo, codigo) == 0)
        return hash->tabla[index]->digito;
    return -1; // No encontrado
}

// Libera la memoria
void liberarTabla(TablaHash *hash) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash->tabla[i] != NULL)
            free(hash->tabla[i]);
    }
}

int main() {
    TablaHash hash;
    inicializarTabla(&hash);

    // Códigos EAN-13 de ejemplo
    insertar(&hash, "0001101", 0);  // Ejemplo de codificación izquierda-impar
    insertar(&hash, "0011001", 1);
    insertar(&hash, "0010011", 2);
    insertar(&hash, "0111101", 3);
    //TO DO: insertar los otros dígitos

    // Búsqueda de códigos
    char codigo[CODE_LENGTH];
    printf("Ingrese un código binario EAN-13 (7 bits): ");
    scanf("%7s", codigo);

    int digito = buscar(&hash, codigo);
    if (digito != -1)
        printf("El código %s corresponde al dígito %d\n", codigo, digito);
    else
        printf("Código no encontrado en la tabla.\n");

    liberarTabla(&hash);
    return 0;
}
