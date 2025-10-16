#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_TABLA 26 // una entrada por cada letra del alfabeto

typedef struct Mascota {
    char tipo[20];
    char nombre[20];
} Mascota;

// Tabla hash de punteros (memoria dinámica)
Mascota *tabla[TAM_TABLA];

// TODO 1: Implementar una función hash que reciba el nombre y devuelva un índice entre 0 y 25
int hashInicial(const char *nombre) {
    // Pista: usa toupper(nombre[0]) y réstale 'A'
    // toupper(char) convierte a mayúscula
    return 0; // reemplazar
}

// TODO 2: Implementar función para insertar una nueva mascota
// La función debe crear memoria dinámica y guardarla en la posición correspondiente
void insertarMascota(const char *nombre, const char *tipo) {
    int indice = hashInicial(nombre);

    // Validar índice
    if (indice < 0 || indice >= TAM_TABLA) {
        printf("Nombre inválido: %s\n", nombre);
        return;
    }

    // Verificar si la posición ya está ocupada
    if (tabla[indice] != NULL) {
        printf("Colisión detectada en letra %c: %s ya ocupado por %s\n",
               'A' + indice, nombre, tabla[indice]->nombre);
        return;
    }

    // TODO 2.1: Asignar memoria para la nueva mascota
    // TODO 2.2: Copiar los valores de nombre y tipo
    // TODO 2.3: Guardar el puntero en la tabla

    printf("Insertado: %s (%s) en índice %d\n", nombre, tipo, indice);
}

// TODO 3: Implementar función para buscar una mascota por nombre
Mascota *buscarMascota(const char *nombre) {
    int indice = hashInicial(nombre);
    if (indice < 0 || indice >= TAM_TABLA) return NULL;

    // TODO: Verificar si la posición está ocupada y comparar los nombres
    return NULL; // reemplazar
}

// TODO 4: Liberar memoria de todas las mascotas de la tabla
void liberarTabla() {
    for (int i = 0; i < TAM_TABLA; i++) {
        // TODO: si hay una mascota en la posición i, liberar la memoria
    }
}

int main() {
    // Inicializar tabla
    for (int i = 0; i < TAM_TABLA; i++) tabla[i] = NULL;

    // Insertar algunas mascotas
    insertarMascota("Milo", "Perro");
    insertarMascota("Luna", "Gato");
    insertarMascota("Nemo", "Pez");
    insertarMascota("Copito", "Conejo");
    insertarMascota("Max", "Perro"); // posible colisión con Milo

    printf("\nBuscando mascotas:\n");

    // TODO 5: Buscar y mostrar al menos dos mascotas
    // Ejemplo:
    // Mascota *resultado = buscarMascota("Luna");
    // if (resultado != NULL)
    //     printf("Encontrado: %s (%s)\n", resultado->nombre, resultado->tipo);
    // else
    //     printf("Mascota no encontrada\n");

    liberarTabla();
    return 0;
}
