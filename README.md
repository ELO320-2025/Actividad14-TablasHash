# Actividad14-TablasHash

# Actividad 14.1: Tabla Hash para Perfiles de Usuario

## Objetivo
Implementar una **tabla hash en C** para almacenar perfiles de usuario con nombre, email y contraseña.

Cada usuario se almacena usando el email como clave. Debes completar la función hash y probar la inserción y búsqueda de usuarios.

---

## Instrucciones

1. Completa el código TablasHash-parte1.c para implementar una función hash que determine en qué posición va cada usuario según su email.
2. Inserta varios usuarios de ejemplo usando la función `insertar()`.
3. Prueba la función `buscar()` ingresando distintos emails.

---


--- 

# Actividad 14.2: Manejo de colisiones en una tabla hash de mascotas

## Objetivo
Implementar una **tabla hash en C** para almacenar el registro de mascotas de una clínica veterinaria. El hash se basa en la primera letra del nombre.

---

## Instrucciones
1. Completa los ToDo del código TablasHash-parte2.c
2. Observa que se agregaron más mascotas con nombres que generan colisiones (misma letra inicial).
3. El programa muestra mensajes cuando ocurre una colisión.

---

# Cambios recientes

- Parte 1 ahora almacena perfiles de usuario (nombre, email, contraseña) y busca por email.
- Parte 2 incluye más ejemplos de colisiones al insertar mascotas con la misma letra inicial.