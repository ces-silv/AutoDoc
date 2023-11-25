#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <limits>
#include <sstream>
#include <ctime>
#include "6_paciente.cpp"

using namespace std;

informesMedicos Expediente;

void ingresarDatosInformesMed();
void asignarInformeMedAPaciente();

void asignarInformeMedAPaciente(){
    string cedulaPaciente;
    cout << "Ingrese la cedula del paciente: ";
    cin >> Expediente.Paciente.cedula;

    ifstream pacientesFile("pacientes.txt");
    if (!pacientesFile.is_open()) {
        cerr << "Error al abrir el archivo de pacientes." << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(pacientesFile, line)) {
        if (line.find(Expediente.Paciente.cedula) == 0) {
            // Suponiendo que la estructura del archivo de pacientes es: cedula,primerNombre,segundoNombre,primerApellido,segundoApellido,altura,peso,num_celular,nacimiento.dia,nacimiento.mes,nacimiento.anio
            stringstream ss(line);
            string token;

            getline(ss, token, ',');
            getline(ss, Expediente.Paciente.nombrePaciente.primerNombre, ' ');
            getline(ss, Expediente.Paciente.nombrePaciente.segundoNombre, ' ');
            ss >> Expediente.Paciente.nombrePaciente.primerApellido;
            ss.ignore();
            getline(ss, Expediente.Paciente.nombrePaciente.segundoApellido, ',');
            ss >> Expediente.Paciente.fechas.nacimiento.dia;
            ss.ignore(1, '/');
            ss >> Expediente.Paciente.fechas.nacimiento.mes;
            ss.ignore(1, '/');
            ss >> Expediente.Paciente.fechas.nacimiento.anio;
            ss.ignore(1, ',');
            ss >> Expediente.Paciente.peso;
            ss.ignore(1, ',');
            ss >> Expediente.Paciente.altura;
            ss.ignore(1, ',');
            getline(ss, Expediente.Paciente.num_celular);

            cout << "\nPaciente encontrado" << endl << endl;
            printf("C%cdula: ", 130); cout << Expediente.Paciente.cedula << endl;
            cout << "Nombre: " << Expediente.Paciente.nombrePaciente.primerNombre << ' ' << Expediente.Paciente.nombrePaciente.segundoNombre << ' ' << Expediente.Paciente.nombrePaciente.primerApellido << ' ' << Expediente.Paciente.nombrePaciente.segundoApellido << endl;
            cout << "Fecha de nacimiento: " << Expediente.Paciente.fechas.nacimiento.dia << "/" << Expediente.Paciente.fechas.nacimiento.mes << "/" << Expediente.Paciente.fechas.nacimiento.anio << endl;
            cout << "Peso: " << Expediente.Paciente.peso << " lb" << endl;
            cout << "Altura: " << Expediente.Paciente.altura << " cm" << endl;
            printf("N%cmero de tel%cfono: ", 163, 130); cout << Expediente.Paciente.num_celular << endl << endl;

            printf("%cEste es el paciente que estabas buscando? Si es as%c, presione S o ingrese cualquier otra letra para ingresarlo nuevamente.\n", 168, 161);
            cin >> cedulaPaciente;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if ( (cedulaPaciente == "S") || (cedulaPaciente == "s")){
                pacientesFile.close();
                return;
            } else{
                pacientesFile.close();
                system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
                system("clear || cls");
                asignarInformeMedAPaciente();
                return;
            }
        }
    }

    // Si llega aquí, no se encontró al paciente
    cerr << "Paciente no encontrado." << endl;
    pacientesFile.close();
    exit(EXIT_FAILURE);
}

void ingresarDatosInformesMed(){
    
}

int main(){
    informesMedicos Expediente;
    void asignarInformeMedAPaciente();
    return 0;
}