#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "6_paciente.cpp"

using namespace std;

bool obtenerInfoPaciente(const string& cedula, registroP& paciente) {
    ifstream archivoPacientes("pacientes.txt");

    if (archivoPacientes.is_open()) {
        string linea;
        while (getline(archivoPacientes, linea)) {
            registroP pacienteTemp;
            cargarRegistroDesdeLinea(linea, pacienteTemp);

            if (pacienteTemp.cedula == cedula) {
                paciente = pacienteTemp;
                archivoPacientes.close();
                return true; // La cédula existe en el archivo
            }
        }
        archivoPacientes.close();
    } else {
        cout << "Error al abrir el archivo 'pacientes.txt'" << endl;
    }

    return false; // La cédula no existe en el archivo
}

// Método para obtener la fecha actual
string obtenerFechaActual() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    // Crear un string con la fecha actual
    string fecha = to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year);
    return fecha;
}

// Método para validar si un año es bisiesto
bool esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

// Método para validar si una fecha es futura
bool esFechaFutura(const fechaMain& fecha) {
    // Obtener la fecha actual
    string fechaActual = obtenerFechaActual();

    // Comparar la fecha actual con la fecha proporcionada
    if (fecha.anio > stoi(fechaActual.substr(6, 4))) {
        return true;
    } else if (fecha.anio == stoi(fechaActual.substr(6, 4)) && fecha.mes > stoi(fechaActual.substr(3, 2))) {
        return true;
    } else if (fecha.anio == stoi(fechaActual.substr(6, 4)) && fecha.mes == stoi(fechaActual.substr(3, 2)) && fecha.dia > stoi(fechaActual.substr(0, 2))) {
        return true;
    }

    return false;
}

// Método para obtener y validar una fecha
fechaMain obtenerFecha() {
    fechaMain fecha;
    do {
        cout << "Introduzca el día: ";
        cin >> fecha.dia;

        cout << "Introduzca el mes: ";
        cin >> fecha.mes;

        cout << "Introduzca el año: ";
        cin >> fecha.anio;

        // Validar el número de días según el mes y años bisiestos
        if (fecha.mes < 1 || fecha.mes > 12 || fecha.dia < 1 || (fecha.mes == 2 && ((esBisiesto(fecha.anio) && fecha.dia > 29) || (!esBisiesto(fecha.anio) && fecha.dia > 28))) || ((fecha.mes == 4 || fecha.mes == 6 || fecha.mes == 9 || fecha.mes == 11) && fecha.dia > 30) || ((fecha.mes == 1 || fecha.mes == 3 || fecha.mes == 5 || fecha.mes == 7 || fecha.mes == 8 || fecha.mes == 10 || fecha.mes == 12) && fecha.dia > 31)) {
            cout << "La fecha proporcionada no es válida. Inténtelo de nuevo." << endl;
        } else if (!esFechaFutura(fecha)) {
            cout << "La fecha proporcionada no es válida. Debe ser en el futuro. Inténtelo de nuevo." << endl;
        }

    } while (fecha.mes < 1 || fecha.mes > 12 || fecha.dia < 1 || (fecha.mes == 2 && ((esBisiesto(fecha.anio) && fecha.dia > 29) || (!esBisiesto(fecha.anio) && fecha.dia > 28))) || ((fecha.mes == 4 || fecha.mes == 6 || fecha.mes == 9 || fecha.mes == 11) && fecha.dia > 30) || ((fecha.mes == 1 || fecha.mes == 3 || fecha.mes == 5 || fecha.mes == 7 || fecha.mes == 8 || fecha.mes == 10 || fecha.mes == 12) && fecha.dia > 31) || !esFechaFutura(fecha));

    return fecha;
}

// Método para programar una cita
void programarCita() {
    string cedula;
    registroP paciente;

    // Solicitar la cédula del paciente y validarla
    do {
        cout << "Introduzca la cédula del paciente: ";
        cin >> cedula;

        if (!obtenerInfoPaciente(cedula, paciente)) {
            cout << "La cédula no existe en el registro. Introduzca una cédula válida." << endl;
        }
    } while (!obtenerInfoPaciente(cedula, paciente));

    // Mostrar la información del paciente
    system("clear || cls");
    cout << "Información del Paciente:" << endl;
    cout << "Cédula: " << paciente.cedula << endl;
    cout << "Nombre: " << paciente.nombrePaciente.primerNombre << ' ' << paciente.nombrePaciente.segundoNombre << ' ' << paciente.nombrePaciente.primerApellido << ' ' << paciente.nombrePaciente.segundoApellido << endl;
    cout << "Fecha de nacimiento: " << paciente.fechas.nacimiento.dia << "/" << paciente.fechas.nacimiento.mes << "/" << paciente.fechas.nacimiento.anio << endl;
    cout << "Peso: " << paciente.peso << " lb" << endl;
    cout << "Altura: " << paciente.altura << " cm" << endl;
    cout << "Número de teléfono: " << paciente.num_celular << endl;
    cout << endl;

    // Solicitar la fecha de seguimiento hasta que sea válida
    fechaMain fechaSeguimiento = obtenerFecha();

    // Solicitar el procedimiento
    string procedimiento;
    cout << "Introduzca el procedimiento de la cita: ";
    cin.ignore(); // Limpiar el buffer del teclado
    getline(cin, procedimiento);

    // Guardar la cita en el archivo de citas programadas
    ofstream archivoCitas("citasProgramadas.txt", ios::app);
    if (archivoCitas.is_open()) {
        archivoCitas << "Cédula: " << cedula << endl;
        archivoCitas << "Nombre: " << paciente.nombrePaciente.primerNombre << ' ' << paciente.nombrePaciente.segundoNombre << ' ' << paciente.nombrePaciente.primerApellido << ' ' << paciente.nombrePaciente.segundoApellido << endl;
        archivoCitas << "Fecha de seguimiento: " << fechaSeguimiento.dia << "/" << fechaSeguimiento.mes << "/" << fechaSeguimiento.anio << endl;
        archivoCitas << "Procedimiento: " << procedimiento << endl;
        archivoCitas << "-------------------------------------------------------" << endl;

        cout << "Cita programada con éxito." << endl;
        archivoCitas.close();
    } else {
        cout << "Error: No se pudo abrir el archivo de citas programadas." << endl;
    }
}

// Método para mostrar las citas programadas
void mostrarCitasProgramadas() {
    ifstream archivoCitas("citasProgramadas.txt");
    if (archivoCitas.is_open()) {
        string linea;
        while (getline(archivoCitas, linea)) {
            cout << linea << endl;
        }
        archivoCitas.close();
    } else {
        cout << "Error: No se pudo abrir el archivo de citas programadas." << endl;
    }
}

// Método principal
int main() {
    int opcion;

    do {
        // Mostrar menú
        cout << "Menú:" << endl;
        cout << "1. Programar cita" << endl;
        cout << "2. Ver citas programadas" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                programarCita();
                break;
            case 2:
                mostrarCitasProgramadas();
                break;
            case 3:
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opción no válida. Inténtelo de nuevo." << endl;
                break;
        }

    } while (opcion != 3);

    return 0;
}