#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <limits>
#include <sstream>
#include <ctime>
#include "1_estructuras.h"

using namespace std;

// Función para ingresar datos de diagnóstico desde el usuario
diagnostico ingresarDatosDiagnostico() {
    diagnostico diag;
    system("clear || cls");
    // Obtener la cédula del paciente y validarla
    do {
        cout << "Ingrese la cedula del paciente: ";
        cin >> diag.Paciente.cedula;

        if (!obtenerInfoPaciente(diag.Paciente.cedula, diag.Paciente)) {
            cout << "La cédula no existe en el registro. Ingrese una cédula válida." << endl;
        } else {
            // Mostrar la información del paciente
            cout << "Información del Paciente:" << endl;
            cout << "Cédula: " << diag.Paciente.cedula << endl;
            cout << "Nombre: " << diag.Paciente.nombrePaciente.primerNombre << ' ' << diag.Paciente.nombrePaciente.segundoNombre << ' ' << diag.Paciente.nombrePaciente.primerApellido << ' ' << diag.Paciente.nombrePaciente.segundoApellido << endl;
            cout << "Fecha de nacimiento: " << diag.Paciente.fechas.nacimiento.dia << "/" << diag.Paciente.fechas.nacimiento.mes << "/" << diag.Paciente.fechas.nacimiento.anio << endl;
            cout << "Peso: " << diag.Paciente.peso << " lb" << endl;
            cout << "Altura: " << diag.Paciente.altura << " cm" << endl;
            cout << "Número de teléfono: " << diag.Paciente.num_celular << endl;
        }

    } while (!obtenerInfoPaciente(diag.Paciente.cedula, diag.Paciente));
    // Solicitar datos al usuario
    cout << "Ingrese el diagnóstico: ";
    cin.ignore(); // Ignorar el salto de línea pendiente
    getline(cin, diag.diagnostico);

    cout << "Ingrese las recomendaciones médicas: ";
    getline(cin, diag.recomenMedicas);

    cout << "Ingrese el costo de la consulta: $ ";
    cin >> diag.costoConsulta;
    // Obtener la fecha actual
    time_t tiempoActual = time(nullptr);
    tm* tiempoLocal = localtime(&tiempoActual);

    // Asignar la fecha actual al diagnóstico
    diag.realizacion.realizacion.dia = tiempoLocal->tm_mday;
    diag.realizacion.realizacion.mes = tiempoLocal->tm_mon + 1; // tm_mon está en el rango 0-11
    diag.realizacion.realizacion.anio = tiempoLocal->tm_year + 1900; // tm_year es el año desde 1900
    return diag;
}


// Función para ingresar datos de prescripción desde el usuario
prescripcion ingresarDatosPrescripcion() {
    prescripcion presc;

    // Obtener la cédula del paciente y validarla
    do {
        cout << "Ingrese la cedula del paciente: ";
        cin >> presc.Paciente.cedula;

        if (!obtenerInfoPaciente(presc.Paciente.cedula, presc.Paciente)) {
            cout << "La cédula no existe en el registro. Ingrese una cédula válida." << endl;
        } else {
            // Mostrar la información del paciente
            cout << "Información del Paciente:" << endl;
            cout << "Cédula: " << presc.Paciente.cedula << endl;
            cout << "Nombre: " << presc.Paciente.nombrePaciente.primerNombre << ' ' << presc.Paciente.nombrePaciente.segundoNombre << ' ' << presc.Paciente.nombrePaciente.primerApellido << ' ' << presc.Paciente.nombrePaciente.segundoApellido << endl;
            cout << "Fecha de nacimiento: " << presc.Paciente.fechas.nacimiento.dia << "/" << presc.Paciente.fechas.nacimiento.mes << "/" << presc.Paciente.fechas.nacimiento.anio << endl;
            cout << "Peso: " << presc.Paciente.peso << " lb" << endl;
            cout << "Altura: " << presc.Paciente.altura << " cm" << endl;
            cout << "Número de teléfono: " << presc.Paciente.num_celular << endl;
        }

    } while (!obtenerInfoPaciente(presc.Paciente.cedula, presc.Paciente));
    // Solicitar datos al usuario
    cout << "Ingrese el nombre del medicamento: ";
    cin.ignore();
    getline(cin, presc.nombreMed);
    cout << "Ingrese la dosis de la prescripción: ";
    cin.ignore(); // Ignorar el salto de línea pendiente
    getline(cin, presc.dosis);

    cout << "Ingrese la cantidad de la prescripción: ";
    getline(cin, presc.cantidad);

    return presc;
}

// Función para guardar datos en el archivo "diagnosticos.txt"
void guardarDiagnostico(const diagnostico& diag) {
    ofstream archivo("diagnosticos.txt", ios::app);

    if (archivo.is_open()) {
        // Escribir datos en el archivo
        archivo << "Cedula: " << diag.Paciente.cedula << endl;
        archivo << "Diagnostico: " << diag.diagnostico << endl;
        archivo << "Recomendaciones Medicas: " << diag.recomenMedicas << endl;
        archivo << "Costo Consulta: $ " << diag.costoConsulta << endl;
        archivo << "Fecha de Realizacion: " << diag.realizacion.realizacion.dia << "/" << diag.realizacion.realizacion.mes << "/" << diag.realizacion.realizacion.anio << endl;
        archivo << "----------------------------------------" << endl;

        // Cerrar el archivo
        archivo.close();
    } else {
        cout << "Error al abrir el archivo 'diagnosticos.txt'" << endl;
    }
}

// Función para guardar datos en el archivo "prescripciones.txt"
void guardarPrescripcion(const prescripcion& presc) {
    ofstream archivo("prescripciones.txt", ios::app);

    if (archivo.is_open()) {
        // Escribir datos en el archivo
        archivo << "Cedula: " << presc.Paciente.cedula << endl;
        archivo << "Nombre del medicamento: " << presc.nombreMed << endl;
        archivo << "Dosis: " << presc.dosis << endl;
        archivo << "Cantidad: " << presc.cantidad << endl;
        archivo << "----------------------------------------" << endl;

        // Cerrar el archivo
        archivo.close();
    } else {
        cout << "Error al abrir el archivo 'prescripciones.txt'" << endl;
    }
}


// Función para mostrar diagnósticos y prescripciones anteriores
void mostrarDiagnosticosYPrescripciones(const string& cedula) {
    ifstream archivoDiagnosticos("diagnosticos.txt");
    ifstream archivoPrescripciones("prescripciones.txt");

    if (archivoDiagnosticos.is_open() && archivoPrescripciones.is_open()) {
        string lineaDiagnostico, lineaPrescripcion;
        bool diagnosticoEncontrado = false;
        bool prescripcionEncontrada = false;
        system("clear || cls");
        cout << "Diagnosticos y Prescripciones anteriores para la cédula " << cedula << ":" << endl;
        cout << endl;
        // Mostrar diagnósticos anteriores
        cout << "------------------------------------" << endl;
        cout << "Diagnosticos anteriores:" << endl;
        while (getline(archivoDiagnosticos, lineaDiagnostico)) {
            if (lineaDiagnostico.find("Cedula: " + cedula) != string::npos) {
                diagnosticoEncontrado = true;
                cout << lineaDiagnostico << endl;
                cout << endl;

                // Leer líneas adicionales del diagnóstico
                for (int i = 0; i < 4; ++i) {
                    getline(archivoDiagnosticos, lineaDiagnostico);
                    cout << lineaDiagnostico << endl;
                }
            }
        }

        if (!diagnosticoEncontrado) {
            cout << "No hay diagnósticos anteriores para la cédula " << cedula << "." << endl;
        }

        // Mostrar prescripciones anteriores
        cout << "------------------------------------" << endl;
        cout << "Prescripciones anteriores:" << endl;
        while (getline(archivoPrescripciones, lineaPrescripcion)) {
            if (lineaPrescripcion.find("Cedula: " + cedula) != string::npos) {
                prescripcionEncontrada = true;
                cout << lineaPrescripcion << endl;

                // Leer líneas adicionales de la prescripción
                for (int i = 0; i < 3; ++i) {
                    getline(archivoPrescripciones, lineaPrescripcion);
                    cout << lineaPrescripcion << endl;
                    cout << endl;
                }
            }
        }

        if (!prescripcionEncontrada) {
            cout << "No hay prescripciones anteriores para la cédula " << cedula << "." << endl;
        }

        archivoDiagnosticos.close();
        archivoPrescripciones.close();
    } else {
        cout << "No se pudieron abrir los archivos de diagnósticos y prescripciones para lectura." << endl;
    }
}

void diagPres() {
    int opcion;

    do {
        printf("Seleccione una opci%cn:\n", 162);
        printf("1. Ingresar diagn%cstico\n", 162);
        printf("2. Ingresar prescripci%cn\n", 162);
        printf("3. Mostrar diagn%csticos y prescripciones anteriores\n", 162);  // Nueva opción
        printf("Elija una opci%cn: ", 162);
        
        while (!(cin >> opcion) || cin.peek() != '\n' || opcion < 1 || opcion > 3) {
            printf("Entrada inv%clida. Por favor, ingrese 1, 2 o 3: ", 160);
            std::cin.clear();
            std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        }

        switch (opcion) {
            case 1: {
                diagnostico nuevoDiagnostico = ingresarDatosDiagnostico();
                guardarDiagnostico(nuevoDiagnostico);
                printf("Diagn%cstico guardado exitosamente.\n", 162);
                break;
            }
            case 2: {
                prescripcion nuevaPrescripcion = ingresarDatosPrescripcion();
                guardarPrescripcion(nuevaPrescripcion);
                printf("Prescripci%cn guardada exitosamente.\n", 162);
                break;
            }
            case 3: {
                string cedula;
                bool cedulaValida = false;
                registroP paciente;

                // Solicitar la cédula hasta que sea válida
                while (!cedulaValida) {
                    printf("Ingrese la c%cdula del paciente para mostrar diagn%csticos y prescripciones anteriores: ", 130, 162);
                    cin >> cedula;

                    if (obtenerInfoPaciente(cedula, paciente)) {
                        cedulaValida = true;
                    } else {
                        printf("La c%cdula no existe en el registro. Ingrese una c%cdula v%clida.\n", 130, 130, 160);
                    }
                }

                mostrarDiagnosticosYPrescripciones(cedula);
                break;
            }
            default:
                printf("Opci%cn no v%clida.\n", 162, 160);
        }

        // Preguntar si el usuario desea volver al menú principal
        char respuesta;
        printf("%cDesea volver al men%c principal (S/N): ", 168, 163);
        cin >> respuesta;
        
        if (toupper(respuesta) != 'S') {
            break; // Salir del bucle si la respuesta no es 'S' (ignora mayúsculas/minúsculas)
        }

    } while (true);
}