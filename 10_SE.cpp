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
    string fecha = to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/"  +  to_string(1900 + ltm->tm_year);

    return fecha;
}

    // Método para realizar el seguimiento del embarazo
    void realizarSeguimiento() {
        // Solicitar la cédula del paciente y validarla
        string cedula;
        registroP paciente;
        seguimEmb seguimiento;

        do {
            cout << "Introduzca la cédula del paciente: ";
            cin >> cedula;

            if (!obtenerInfoPaciente(cedula, paciente)) {
                cout << "La cédula no existe en el registro. Introduzca una cédula válida." << endl;
            } else {
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
            }

        } while (!obtenerInfoPaciente(cedula, paciente));
        string fechaActual = obtenerFechaActual();

        // Resto de la lógica para realizar el seguimiento del embarazo
        cout << "Introduza el peso de la madre: ";
        cin >> seguimiento.pesoMadre;
        cout << "Introduzca la presión arterial sistólica: ";
        cin >> seguimiento.presArtSisto;
        cout << "Introduzca la presión arterial diastólica: ";
        cin >> seguimiento.presArtDias;
        cout << "Introduzca las medidas Leopold: ";
        cin >> seguimiento.medidasLeopold;
        cout << "Introduzca las medidas de la circunferencia craneana del bebé: ";
        cin >> seguimiento.circunfCraneana;
        cout << "Introduzca el diámetro biparietal del bebé: ";
        cin >> seguimiento.diametBiparietal;
        cout << "Introduzca la circunferencia abdominal del bebé: ";
        cin >> seguimiento.circunfAbdominal;
        cout << "Introduzca el peso del bebé: ";
        cin >> seguimiento.pesoBebe;
        cout << "Introduzca la edad del bebé: ";
        cin >> seguimiento.edadBebe;
        cin.ignore(); 
        cout << "Redacte sus conclusiones y valoraciones: ";
        getline(cin, seguimiento.conclusionesGen);

        ofstream archivo("seguimientoEmbarazo.txt", ios::app);

        if (archivo.is_open()) {
            archivo << "Cédula: " << cedula << endl;
            archivo << "Nombre: " << paciente.nombrePaciente.primerNombre << ' ' << paciente.nombrePaciente.segundoNombre << ' ' << paciente.nombrePaciente.primerApellido << ' ' << paciente.nombrePaciente.segundoApellido << endl;
            archivo << "Peso de la madre: " << seguimiento.pesoMadre  << endl;
            archivo << "Presión arterial sistólica: " << seguimiento.presArtSisto << endl;
            archivo << "Presión arterial diastólica: " << seguimiento.presArtDias << endl;
            archivo << "Medidas Leopold: " << seguimiento.medidasLeopold << endl;
            archivo << "Circunferencia craneana del bebé: " << seguimiento.circunfCraneana << endl;
            archivo << "Diámetro biparietal del bebé: " << seguimiento.diametBiparietal << endl;
            archivo << "Circunferencia abdominal del bebé: " << seguimiento.circunfAbdominal << endl;
            archivo << "Peso del bebé: " << seguimiento.pesoBebe << endl;
            archivo << "Edad del bebé: " << seguimiento.edadBebe << endl;
            archivo << "Conclusiones y valoraciones: " << seguimiento.conclusionesGen << endl;
            archivo << "Fecha de realización: " << fechaActual << endl;
            archivo << "-------------------------------------------------------" << endl;

            cout << "Datos guardados en el archivo seguimientoEmbarazo.txt" << endl;
            archivo.close();
        } else {
            cout << "Error: No se pudo abrir el archivo." << endl;
        }
    };

int main() {
    seguimEmb seguimiento;
    realizarSeguimiento();
    return 0;
}