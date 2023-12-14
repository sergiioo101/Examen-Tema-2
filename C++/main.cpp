#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Definición de la estructura Asistencia
struct Asistencia {
    string fecha;
    string materia;
    string estado; // Puede ser "asistió", "falta" o "tardanza"
};

// Excepción personalizada para errores de formato de fecha
class FormatoFechaInvalido : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Formato de fecha inválido.";
    }
};

// Excepción personalizada para materias no registradas
class MateriaNoRegistrada : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Materia no registrada.";
    }
};

// Definición de la estructura Estudiante
struct Estudiante {
    string nombre;
    int edad;
    float promedio;
    vector<Asistencia> asistencias; // Vector de asistencias del estudiante
};

// Declaración de funciones
void agregarMateria(Estudiante& estudiante, const string& materia);
void eliminarMateria(Estudiante& estudiante, const string& materia);
void mostrarMaterias(const Estudiante& estudiante);
void registrarAsistencia(Estudiante& estudiante, const string& fecha, const string& materia, const string& estado);
void mostrarAsistencias(const Estudiante& estudiante);
void mostrarEstudiante(const Estudiante& estudiante);

// Implementación de funciones
void agregarMateria(Estudiante& estudiante, const string& materia) {
    estudiante.asistencias.push_back({ "", materia, "" });  // Simplemente agregamos una asistencia con la materia
}