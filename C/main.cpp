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