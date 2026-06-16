#ifndef TAREAS_H
#define TAREAS_H

#define MAX_TAREAS 50
#define MAX_TEXTO 100

// Estados posibles de una tarea
#define PENDIENTE   0
#define EN_PROGRESO 1
#define FINALIZADA  2

// Estructura principal de tarea
typedef struct {
    int codigo;
    char titulo[MAX_TEXTO];
    char responsable[MAX_TEXTO];
    int prioridad;  // 0=Alta, 1=Media, 2=Baja
    int estado;     // 0=Pendiente, 1=En Progreso, 2=Finalizada
} Tarea;

// Prototipos de funciones de cada modulo

// Modulo 2 - Registro y eliminacion
int registrarTarea(Tarea tareas[], int *numTareas);
int eliminarTarea(Tarea tareas[], int *numTareas, int codigo);

// Modulo 3 - Busquedas
void buscarPorCodigo(Tarea tareas[], int numTareas, int codigo);
void buscarPorResponsable(Tarea tareas[], int numTareas, char nombre[]);

// Modulo 4 - Kanban
void mostrarTablero(Tarea tareas[], int numTareas);
int cambiarEstado(Tarea tareas[], int numTareas, int codigo);

// Modulo 5 - Estadisticas
void mostrarEstadisticas(Tarea tareas[], int numTareas);

// Modulo 6 - Menu
void mostrarMenu();

#endif
