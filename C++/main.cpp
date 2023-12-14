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