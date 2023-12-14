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