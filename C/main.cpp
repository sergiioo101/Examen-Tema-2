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