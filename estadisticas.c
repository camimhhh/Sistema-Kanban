#include <stdio.h>
#include "tareas.h"

void mostrarEstadisticas(Tarea tareas[], int numTareas) {
    int pendientes = 0, enProgreso = 0, finalizadas = 0;
    int i;

    for (i = 0; i < numTareas; i++) {
        if (tareas[i].estado == PENDIENTE)        pendientes++;
        else if (tareas[i].estado == EN_PROGRESO)  enProgreso++;
        else                                        finalizadas++;
    }

    // Se hace el cast a float antes de dividir para no obtener division entera.
    // Si numTareas es 0 se evita la division para no causar un error en ejecucion.
    float porcentaje = 0.0;
    if (numTareas > 0) {
        porcentaje = (float)finalizadas / numTareas * 100.0;
    }

    printf("\n========= ESTADISTICAS =========\n");
    printf("Total de tareas:     %d\n", numTareas);
    printf("Pendientes:          %d\n", pendientes);
    printf("En Progreso:         %d\n", enProgreso);
    printf("Finalizadas:         %d\n", finalizadas);
    printf("Completado:          %.1f%%\n", porcentaje);
    printf("================================\n");
}
