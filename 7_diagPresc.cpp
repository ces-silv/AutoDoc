#include <iostream>
#include <fstream>
#include "3_estructuras.h"

using namespace std;

registroP ingresarDatosPaciente() {
    registroP paciente;
    cout << "Ingrese la cedula del paciente: ";
    cin >> paciente.cedula;
    return paciente;
}

// Función para ingresar datos de diagnóstico desde el usuario
diagnostico ingresarDatosDiagnostico(const registroP& paciente) {
    diagnostico diag;

    // Asignar el paciente
    diag.Paciente = paciente;

    // Solicitar datos al usuario
    cout << "Ingrese el diagnóstico: ";
    cin.ignore(); // Ignorar el salto de línea pendiente
    getline(cin, diag.diagnostico);

    cout << "Ingrese las recomendaciones médicas: ";
    getline(cin, diag.recomenMedicas);

    cout << "Ingrese el costo de la consulta: ";
    cin >> diag.costoConsulta;

    // Solicitar fecha de realización
    cout << "Ingrese la fecha de realización (dd mm aaaa): ";
    cin >> diag.realizacion.realizacion.dia >> diag.realizacion.realizacion.mes >> diag.realizacion.realizacion.anio;

    return diag;
}

// Función para ingresar datos de prescripción desde el usuario
prescripcion ingresarDatosPrescripcion(const registroP& paciente) {
    prescripcion presc;

    // Asignar el paciente
    presc.Paciente = paciente;

    // Solicitar datos al usuario
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
        archivo << "Costo Consulta: " << diag.costoConsulta << endl;
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
        archivo << "Dosis: " << presc.dosis << endl;
        archivo << "Cantidad: " << presc.cantidad << endl;

        archivo << "----------------------------------------" << endl;

        // Cerrar el archivo
        archivo.close();
    } else {
        cout << "Error al abrir el archivo 'prescripciones.txt'" << endl;
    }
}

int main() {
    // Ingresar datos del paciente
    registroP paciente = ingresarDatosPaciente();

    // Ingresar datos del diagnóstico
    diagnostico nuevoDiagnostico = ingresarDatosDiagnostico(paciente);

    // Ingresar datos de la prescripción
    prescripcion nuevaPrescripcion = ingresarDatosPrescripcion(paciente);

    // Guardar diagnóstico y prescripción en archivos
    guardarDiagnostico(nuevoDiagnostico);
    guardarPrescripcion(nuevaPrescripcion);

    return 0;
}