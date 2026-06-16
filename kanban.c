#include <stdio.h>
#include "tareas.h"

void mostrarTablero(Tarea tareas[], int numTareas) {
    int i, estado;

    if (numTareas == 0) {
        printf("\nNo hay tareas registradas.\n");
        return;
    }

    char* nombres[] = {"PENDIENTES", "EN PROGRESO", "FINALIZADAS"};

    // Se recorre cada estado (0, 1, 2) y se imprimen las tareas que le corresponden.
    // Asi el tablero siempre aparece en el orden correcto sin importar como esten guardadas.
    for (estado = 0; estado <= 2; estado++) {
        printf("\n=================================\n");
        printf("  %s\n", nombres[estado]);
        printf("=================================\n");

        int hay = 0;
        for (i = 0; i < numTareas; i++) {
            if (tareas[i].estado == estado) {
                printf("  [%d] %s  (%s)\n", tareas[i].codigo, tareas[i].titulo,
                       tareas[i].responsable);
                hay = 1;
            }
        }
        if (!hay) {
            printf("  (sin tareas)\n");
        }
    }
    printf("\n");
}

// El estado avanza en ciclo: Pendiente(0) -> En Progreso(1) -> Finalizada(2) -> Pendiente(0)
// El operador % 3 hace que despues del 2 vuelva al 0 automaticamente.
int cambiarEstado(Tarea tareas[], int numTareas, int codigo) {
    int i;
    for (i = 0; i < numTareas; i++) {
        if (tareas[i].codigo == codigo) {
            int estadoAnterior = tareas[i].estado;
            tareas[i].estado = (tareas[i].estado + 1) % 3;

            char* estados[] = {"Pendiente", "En Progreso", "Finalizada"};
            printf("Tarea [%d] movida de '%s' a '%s'.\n",
                   codigo, estados[estadoAnterior], estados[tareas[i].estado]);
            return 1;
        }
    }
    printf("No se encontro ninguna tarea con codigo %d.\n", codigo);
    return 0;
}
