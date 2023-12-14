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

int main() {
    // Ejemplo de uso:
    // Crear un objeto Estudiante
    struct Estudiante estudiante1 = { "Juan", 20, 8.5, {}, 0 };

    char opcion;

    do {
        // Mostrar menú
        printf("\n1. Agregar materia\n");
        printf("2. Eliminar materia\n");
        printf("3. Registrar asistencia\n");
        printf("4. Mostrar información del estudiante\n");
        printf("0. Salir\n");
        printf("Ingrese la opción: ");
        scanf(" %c", &opcion);

        switch (opcion) {
            case '1': {
                char nuevaMateria[50];
                printf("Ingrese la nueva materia: ");
                scanf("%s", nuevaMateria);
                agregarMateria(&estudiante1, nuevaMateria);
                break;
            }
            case '2': {
                char materiaEliminar[50];
                printf("Ingrese la materia a eliminar: ");
                scanf("%s", materiaEliminar);
                eliminarMateria(&estudiante1, materiaEliminar);
                break;
            }
            case '3': {
                char fecha[11], materia[50], estado[10];
                printf("Ingrese la fecha de asistencia (formato YYYY-MM-DD): ");
                scanf("%s", fecha);
                printf("Ingrese la materia: ");
                scanf("%s", materia);
                printf("Ingrese el estado (asistió, falta, tardanza): ");
                scanf("%s", estado);
                registrarAsistencia(&estudiante1, fecha, materia, estado);
                break;
            }
            case '4':
                mostrarEstudiante(&estudiante1);
                break;
            case '0':
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != '0');

    return 0;
}