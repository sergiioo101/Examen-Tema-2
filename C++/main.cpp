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

// Declaración de la función mostrarEstudiante
void mostrarEstudiante(const Estudiante& estudiante) {
    cout << "Nombre: " << estudiante.nombre << endl;
    cout << "Edad: " << estudiante.edad << endl;
    cout << "Promedio: " << estudiante.promedio << endl;
    mostrarMaterias(estudiante);
    mostrarAsistencias(estudiante);
}

int main() {
    // Ejemplo de uso:
    // Crear un objeto Estudiante
    Estudiante estudiante1;
    estudiante1.nombre = "Juan";
    estudiante1.edad = 20;
    estudiante1.promedio = 8.5;

    char opcion;

    do {
        try {
            // Mostrar menú
            cout << "\n1. Agregar materia\n";
            cout << "2. Eliminar materia\n";
            cout << "3. Registrar asistencia\n";
            cout << "4. Mostrar información del estudiante\n";
            cout << "0. Salir\n";
            cout << "Ingrese la opción: ";
            cin >> opcion;

            switch (opcion) {
                case '1': {
                    string nuevaMateria;
                    cout << "Ingrese la nueva materia: ";
                    cin >> nuevaMateria;
                    agregarMateria(estudiante1, nuevaMateria);
                    break;
                }
                case '2': {
                    string materiaEliminar;
                    cout << "Ingrese la materia a eliminar: ";
                    cin >> materiaEliminar;
                    eliminarMateria(estudiante1, materiaEliminar);
                    break;
                }
                case '3': {
                    string fecha, materia, estado;
                    cout << "Ingrese la fecha de asistencia (formato YYYY-MM-DD): ";
                    cin >> fecha;
                    cout << "Ingrese la materia: ";
                    cin >> materia;
                    cout << "Ingrese el estado (asistió, falta, tardanza): ";
                    cin >> estado;
                    registrarAsistencia(estudiante1, fecha, materia, estado);
                    break;
                }
                case '4':
                    mostrarEstudiante(estudiante1);
                    break;
                case '0':
                    cout << "Saliendo del programa.\n";
                    break;
                default:
                    cout << "Opción no válida. Intente de nuevo.\n";
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    } while (opcion != '0');

    return 0;
}