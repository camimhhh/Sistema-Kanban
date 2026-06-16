#include <stdio.h>
#include <string.h>
#include "tareas.h"

char* textoEstado(int estado) {
    if (estado == PENDIENTE)   return "Pendiente";
    if (estado == EN_PROGRESO) return "En Progreso";
    return "Finalizada";
}

char* textoPrioridad(int prioridad) {
    if (prioridad == 0) return "Alta";
    if (prioridad == 1) return "Media";
    return "Baja";
}

void imprimirTarea(Tarea t) {
    printf("  Codigo:      %d\n", t.codigo);
    printf("  Titulo:      %s\n", t.titulo);
    printf("  Responsable: %s\n", t.responsable);
    printf("  Prioridad:   %s\n", textoPrioridad(t.prioridad));
    printf("  Estado:      %s\n", textoEstado(t.estado));
    printf("  ---------------\n");
}

void buscarPorCodigo(Tarea tareas[], int numTareas, int codigo) {
    int i, encontrado = 0;
    printf("\n--- Busqueda por codigo %d ---\n", codigo);
    for (i = 0; i < numTareas; i++) {
        if (tareas[i].codigo == codigo) {
            imprimirTarea(tareas[i]);
            encontrado = 1;
            break; // el codigo es unico, no tiene sentido seguir buscando
        }
    }
    if (!encontrado) {
        printf("No se encontro ninguna tarea con ese codigo.\n");
    }
}

void buscarPorResponsable(Tarea tareas[], int numTareas, char nombre[]) {
    int i, encontrado = 0;
    printf("\n--- Busqueda por responsable: %s ---\n", nombre);

    for (i = 0; i < numTareas; i++) {
        // strstr retorna un puntero si encuentra el texto, o NULL si no lo encuentra.
        // Esto permite buscar aunque el usuario escriba solo parte del nombre.
        if (strstr(tareas[i].responsable, nombre) != NULL) {
            imprimirTarea(tareas[i]);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("No se encontraron tareas para ese responsable.\n");
    }
}
