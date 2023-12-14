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

void eliminarMateria(Estudiante& estudiante, const string& materia) {
    auto it = find_if(estudiante.asistencias.begin(), estudiante.asistencias.end(),
                      [&materia](const Asistencia& asistencia) { return asistencia.materia == materia; });

    if (it != estudiante.asistencias.end()) {
        estudiante.asistencias.erase(it);
    } else {
        throw MateriaNoRegistrada();  // Lanzar excepción si la materia no está registrada
    }
}

void mostrarMaterias(const Estudiante& estudiante) {
    cout << "Materias inscritas:" << endl;
    for (const Asistencia& asistencia : estudiante.asistencias) {
        cout << "- " << asistencia.materia << endl;
    }
}

void registrarAsistencia(Estudiante& estudiante, const string& fecha, const string& materia, const string& estado) {
    // Validar el formato de la fecha
    if (fecha.size() != 10 || fecha[4] != '-' || fecha[7] != '-') {
        throw FormatoFechaInvalido();
    }

    estudiante.asistencias.push_back({fecha, materia, estado});
}

void mostrarAsistencias(const Estudiante& estudiante) {
    cout << "Asistencias de " << estudiante.nombre << ":" << endl;
    for (const Asistencia& asistencia : estudiante.asistencias) {
        cout << "Fecha: " << asistencia.fecha << ", Materia: " << asistencia.materia << ", Estado: " << asistencia.estado << endl;
    }
}