#include <stdio.h>
#include <string.h>
#include "tareas.h"

void mostrarMenu() {
    printf("\n======= SISTEMA KANBAN =======\n");
    printf("1. Registrar tarea\n");
    printf("2. Mostrar tablero\n");
    printf("3. Buscar por codigo\n");
    printf("4. Buscar por responsable\n");
    printf("5. Cambiar estado de tarea\n");
    printf("6. Eliminar tarea\n");
    printf("7. Estadisticas\n");
    printf("0. Salir\n");
    printf("Opcion: ");
}

int main() {
    // El arreglo de tareas se declara aqui en main y se pasa a las funciones.
    // No se usan variables globales, como lo pide el enunciado.
    Tarea tareas[MAX_TAREAS];
    int numTareas = 0;
    int opcion;
    int codigo;
    char nombre[MAX_TEXTO];


    do {
        mostrarMenu();
        scanf("%d", &opcion);
        getchar(); // limpia el '\n' que deja scanf antes de cualquier fgets

        switch (opcion) {
            case 1:
                // Se pasa &numTareas (direccion) para que la funcion pueda incrementarlo
                registrarTarea(tareas, &numTareas);
                break;

            case 2:
                mostrarTablero(tareas, numTareas);
                break;

            case 3:
                printf("Ingrese el codigo a buscar: ");
                scanf("%d", &codigo);
                buscarPorCodigo(tareas, numTareas, codigo);
                break;

            case 4:
                printf("Ingrese el nombre del responsable: ");
                fgets(nombre, MAX_TEXTO, stdin);
                nombre[strcspn(nombre, "\n")] = '\0';
                buscarPorResponsable(tareas, numTareas, nombre);
                break;

            case 5:
                printf("Ingrese el codigo de la tarea a mover: ");
                scanf("%d", &codigo);
                cambiarEstado(tareas, numTareas, codigo);
                break;

            case 6:
                printf("Ingrese el codigo de la tarea a eliminar: ");
                scanf("%d", &codigo);
                // Se pasa &numTareas porque eliminar reduce el contador
                eliminarTarea(tareas, &numTareas, codigo);
                break;

            case 7:
                mostrarEstadisticas(tareas, numTareas);
                break;

            case 0:
                printf("Fin de programa\n");
                break;

            default:
                printf("Opcion invalida.\n");
        }

    } while (opcion != 0);

    return 0;
}
