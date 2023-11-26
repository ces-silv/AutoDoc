#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

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
    if (fecha.anio >= stoi(fechaActual.substr(6, 4))) {
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
        printf("Introduzca el d%ca: ", 161);
        cin >> fecha.dia;

        cout << "Introduzca el mes: ";
        cin >> fecha.mes;

        printf("Introduzca el a%co: ", 164);
        cin >> fecha.anio;

        // Validar el número de días según el mes y años bisiestos
        if (fecha.mes < 1 || fecha.mes > 12 || fecha.dia < 1 || (fecha.mes == 2 && ((esBisiesto(fecha.anio) && fecha.dia > 29) || (!esBisiesto(fecha.anio) && fecha.dia > 28))) || ((fecha.mes == 4 || fecha.mes == 6 || fecha.mes == 9 || fecha.mes == 11) && fecha.dia > 30) || ((fecha.mes == 1 || fecha.mes == 3 || fecha.mes == 5 || fecha.mes == 7 || fecha.mes == 8 || fecha.mes == 10 || fecha.mes == 12) && fecha.dia > 31)) {
            printf("La fecha proporcionada no es v%clida. Int%cntelo de nuevo.\n", 160, 130);
        } else if (!esFechaFutura(fecha)) {
            printf("La fecha proporcionada no es v%clida. Int%cntelo de nuevo.\n", 160, 130);
        }

    } while (fecha.mes < 1 || fecha.mes > 12 || fecha.dia < 1 || (fecha.mes == 2 && ((esBisiesto(fecha.anio) && fecha.dia > 29) || (!esBisiesto(fecha.anio) && fecha.dia > 28))) || ((fecha.mes == 4 || fecha.mes == 6 || fecha.mes == 9 || fecha.mes == 11) && fecha.dia > 30) || ((fecha.mes == 1 || fecha.mes == 3 || fecha.mes == 5 || fecha.mes == 7 || fecha.mes == 8 || fecha.mes == 10 || fecha.mes == 12) && fecha.dia > 31) || !esFechaFutura(fecha));

    return fecha;
}

// Método para programar una cita
void programarCita() {
    system("clear || cls");
    string cedula;
    registroP paciente;

    // Solicitar la cédula del paciente y validarla
    do {
        printf("Introduzca la c%cdula del paciente: ", 130);
        cin >> cedula;

        if (!obtenerInfoPaciente(cedula, paciente)) {
            printf("La c%cdula no existe en el registro. Introduzca una c%cdula v%clida.\n", 130, 130, 160);
        }
    } while (!obtenerInfoPaciente(cedula, paciente));

    // Mostrar la información del paciente
    printf("\nInformaci%cn del Paciente:\n", 162);
    printf("C%cdula: ", 130); cout << paciente.cedula << endl;
    cout << "Nombre: " << paciente.nombrePaciente.primerNombre << ' ' << paciente.nombrePaciente.segundoNombre << ' ' << paciente.nombrePaciente.primerApellido << ' ' << paciente.nombrePaciente.segundoApellido << endl;
    cout << "Fecha de nacimiento: " << paciente.fechas.nacimiento.dia << "/" << paciente.fechas.nacimiento.mes << "/" << paciente.fechas.nacimiento.anio << endl;
    cout << "Peso: " << paciente.peso << " lb" << endl;
    cout << "Altura: " << paciente.altura << " cm" << endl;
    printf("N%cmero de tel%cfono: ", 163, 130); cout << paciente.num_celular << endl;
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

        printf("Cita programada con %cxito.\n", 130);
        archivoCitas.close();
    } else {
        cout << "Error: No se pudo abrir el archivo de citas programadas." << endl;
    }
}

// Método para mostrar las citas programadas
void mostrarCitasProgramadas() {
    system("clear || cls");
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