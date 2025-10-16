# Actividad14-TablasHash

# Actividad 14.1: Función Hash para Códigos EAN-13

## Objetivo
Implementar una **tabla hash en C** para almacenar los patrones binarios que representan los dígitos del estándar **EAN-13**.

Cada patrón tiene 7 bits y representa un dígito (0–9).  
Tu tarea será completar las funciones y probar la búsqueda de los códigos.

---

## Instrucciones

1. Completa el código act14-1.c para generar una función hash que determine en qué posición va cada código
2. Agrega todas las codificaciones posibles (izquierda impar, izquierda par y derecha) con la función `insertar()`.
4. Prueba las función `buscar()` con varios códigos.

---

## 🔢 Tabla de Códigos EAN-13

| Dígito | Izquierda Impar | Izquierda Par | Derecha  |
|:-------:|:---------------:|:-------------:|:--------:|
| 0 | 0001101 | 0100111 | 1110010 |
| 1 | 0011001 | 0110011 | 1100110 |
| 2 | 0010011 | 0011011 | 1101100 |
| 3 | 0111101 | 0100001 | 1000010 |
| 4 | 0100011 | 0011101 | 1011100 |
| 5 | 0110001 | 0111001 | 1001110 |
| 6 | 0101111 | 0000101 | 1010000 |
| 7 | 0111011 | 0010001 | 1000100 |
| 8 | 0110111 | 0001001 | 1001000 |
| 9 | 0001011 | 0010111 | 1110100 |

--- 

# Actividad 14.2: Manejo de colisiones de una tabla hash de mascotas

## Objetivo
Implementar una **tabla hash en C con manejo de colisiones** para almacenar el registro de mascotas de una clínica veterinaria.

---

## Instrucciones

1. Completa los ToDo del código act14-2.c