#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tamaño de la tabla hash
#define TABLE_SIZE 20
#define NAME_LENGTH 50
#define EMAIL_LENGTH 50
#define PASS_LENGTH 50

// Estructura para cada perfil de usuario
typedef struct {
    char nombre[NAME_LENGTH];
    char email[EMAIL_LENGTH];
    char password[PASS_LENGTH];
} Usuario;

// Estructura de la tabla hash
typedef struct {
    Usuario *tabla[TABLE_SIZE];
} TablaHash;

// Función hash 
int hashFuncion(const char *email) {
    //TO DO: completa la función hash para retornar el índice en el arreglo que corresponde a cada email
    //Idea 1: puedes usar la función strlen(email) para obtener la longitud del email 
    //Idea 2: puedes sumar el valor ASCII de cada caracter del email para obtener un número
    return 0;
}

// Inicializa la tabla
void inicializarTabla(TablaHash *hash) {
    for (int i = 0; i < TABLE_SIZE; i++)
        hash->tabla[i] = NULL;
}

// Inserta un usuario en la tabla
void insertar(TablaHash *hash, const char *nombre, const char *email, const char *password) {
    int index = hashFuncion(email);

    Usuario *nuevo = malloc(sizeof(Usuario));
    strcpy(nuevo->nombre, nombre);
    strcpy(nuevo->email, email);
    strcpy(nuevo->password, password);

    // En esta versión simple no hay manejo de colisiones
    hash->tabla[index] = nuevo;
}

// Busca un usuario por email y devuelve un puntero al usuario
Usuario* buscar(TablaHash *hash, const char *email) {
    int index = hashFuncion(email);
    if (hash->tabla[index] != NULL && strcmp(hash->tabla[index]->email, email) == 0)
        return hash->tabla[index];
    return NULL; // No encontrado
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

    // Insertar usuarios de ejemplo
    insertar(&hash, "Juan Perez", "juan@mail.com", "pass123");
    insertar(&hash, "Ana Lopez", "ana@mail.com", "qwerty");

    // Solicitar búsqueda de usuario
    char email[EMAIL_LENGTH];
    printf("Ingrese el email del usuario a buscar: ");
    scanf("%49s", email);

    Usuario *usuario = buscar(&hash, email);
    if (usuario != NULL) {
        printf("Usuario encontrado!\n");
        printf("Nombre: %s\n", usuario->nombre);
        printf("Email: %s\n", usuario->email);
        printf("Password: %s\n", usuario->password);
    } else {
        printf("Usuario no encontrado en la tabla.\n");
    }

    liberarTabla(&hash);
    return 0;
}
