#include <cstdio>
#include <cstring>

// Definición de la estructura Asistencia
struct Asistencia {
    char fecha[11];
    char materia[50];
    char estado[10]; // Puede ser "asistió", "falta" o "tardanza"
};

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
    struct Asistencia asistencias[100]; // Array de asistencias del estudiante
    int numAsistencias; // Número actual de asistencias
};

// Declaración de funciones
void agregarMateria(struct Estudiante* estudiante, const char* materia);
void eliminarMateria(struct Estudiante* estudiante, const char* materia);
void mostrarMaterias(const struct Estudiante* estudiante);
void registrarAsistencia(struct Estudiante* estudiante, const char* fecha, const char* materia, const char* estado);
void mostrarAsistencias(const struct Estudiante* estudiante);
void mostrarEstudiante(const struct Estudiante* estudiante);

// Implementación de funciones
void agregarMateria(struct Estudiante* estudiante, const char* materia) {
    // Simplemente agregamos una asistencia con la materia
    strcpy(estudiante->asistencias[estudiante->numAsistencias].materia, materia);
    estudiante->numAsistencias++;
}

void eliminarMateria(struct Estudiante* estudiante, const char* materia) {
    int i;
    for (i = 0; i < estudiante->numAsistencias; i++) {
        if (strcmp(estudiante->asistencias[i].materia, materia) == 0) {
            // Mover las asistencias restantes hacia atrás para llenar el espacio eliminado
            for (int j = i; j < estudiante->numAsistencias - 1; j++) {
                estudiante->asistencias[j] = estudiante->asistencias[j + 1];
            }
            estudiante->numAsistencias--;
            return;
        }
    }

    // Mostrar un mensaje si la materia no está registrada
    fprintf(stderr, "Error: Materia no registrada.\n");
}

void mostrarMaterias(const struct Estudiante* estudiante) {
    printf("Materias inscritas:\n");
    for (int i = 0; i < estudiante->numAsistencias; i++) {
        printf("- %s\n", estudiante->asistencias[i].materia);
    }
}

void registrarAsistencia(struct Estudiante* estudiante, const char* fecha, const char* materia, const char* estado) {
    // Asumimos que hay suficiente espacio en el array de asistencias
    strcpy(estudiante->asistencias[estudiante->numAsistencias].fecha, fecha);
    strcpy(estudiante->asistencias[estudiante->numAsistencias].materia, materia);
    strcpy(estudiante->asistencias[estudiante->numAsistencias].estado, estado);
    estudiante->numAsistencias++;
}

void mostrarAsistencias(const struct Estudiante* estudiante) {
    printf("Asistencias de %s:\n", estudiante->nombre);
    for (int i = 0; i < estudiante->numAsistencias; i++) {
        printf("Fecha: %s, Materia: %s, Estado: %s\n",
               estudiante->asistencias[i].fecha,
               estudiante->asistencias[i].materia,
               estudiante->asistencias[i].estado);
    }
}

// Declaración de la función mostrarEstudiante
void mostrarEstudiante(const struct Estudiante* estudiante) {
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Edad: %d\n", estudiante->edad);
    printf("Promedio: %.2f\n", estudiante->promedio);
    mostrarMaterias(estudiante);
    mostrarAsistencias(estudiante);
}