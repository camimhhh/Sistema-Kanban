#include <stdio.h>
#include <string.h>
#include "tareas.h"

// Recorre el arreglo buscando si ya hay una tarea con ese codigo.
// Retorna 1 si existe, 0 si no. Se usa antes de registrar.
int codigoExiste(Tarea tareas[], int numTareas, int codigo) {
    int i;
    for (i = 0; i < numTareas; i++) {
        if (tareas[i].codigo == codigo) {
            return 1;
        }
    }
    return 0;
}

// numTareas se recibe como puntero porque necesitamos modificarlo desde aqui.
// Si se pasara por valor, el cambio no se veria en main().
int registrarTarea(Tarea tareas[], int *numTareas) {
    if (*numTareas >= MAX_TAREAS) {
        printf("No hay espacio para mas tareas.\n");
        return 0;
    }

    Tarea nueva;

    printf("\n--- Registrar Tarea ---\n");

    printf("Codigo de tarea: ");
    scanf("%d", &nueva.codigo);
    getchar(); // scanf deja un '\n' en el buffer; getchar() lo consume para que fgets funcione bien despues

    if (codigoExiste(tareas, *numTareas, nueva.codigo)) {
        printf("Error: ya existe una tarea con ese codigo.\n");
        return 0;
    }

    printf("Titulo: ");
    fgets(nueva.titulo, MAX_TEXTO, stdin);
    nueva.titulo[strcspn(nueva.titulo, "\n")] = '\0'; // fgets incluye el '\n' al final; esto lo elimina

    if (strlen(nueva.titulo) == 0) {
        printf("Error: el titulo no puede estar vacio.\n");
        return 0;
    }

    printf("Responsable: ");
    fgets(nueva.responsable, MAX_TEXTO, stdin);
    nueva.responsable[strcspn(nueva.responsable, "\n")] = '\0';

    if (strlen(nueva.responsable) == 0) {
        printf("Error: el responsable no puede estar vacio.\n");
        return 0;
    }

    printf("Prioridad (0=Alta, 1=Media, 2=Baja): ");
    scanf("%d", &nueva.prioridad);

    if (nueva.prioridad < 0 || nueva.prioridad > 2) {
        printf("Prioridad invalida. Se asigna Media por defecto.\n");
        nueva.prioridad = 1;
    }

    nueva.estado = PENDIENTE; // toda tarea nueva empieza en pendiente

    // Se guarda la tarea en la siguiente posicion disponible del arreglo
    tareas[*numTareas] = nueva;
    (*numTareas)++;

    printf("Tarea registrada correctamente.\n");
    return 1;
}

int eliminarTarea(Tarea tareas[], int *numTareas, int codigo) {
    int i, pos = -1;

    // Buscar la posicion de la tarea con ese codigo
    for (i = 0; i < *numTareas; i++) {
        if (tareas[i].codigo == codigo) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("No se encontro ninguna tarea con codigo %d.\n", codigo);
        return 0;
    }

    // Para no dejar un hueco en el arreglo, se desplazan todas las tareas
    // que estan despues de la eliminada una posicion hacia atras
    for (i = pos; i < *numTareas - 1; i++) {
        tareas[i] = tareas[i + 1];
    }
    (*numTareas)--;

    printf("Tarea eliminada correctamente.\n");
    return 1;
}
