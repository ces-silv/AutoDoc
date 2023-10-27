#include <iostream>
#include <fstream>
using namespace std;

struct fechaMain {
    int dia;
    int mes;
    int anio;
};

struct F_Especiales {
    fechaMain nacimiento;
    fechaMain realizacion;
};

struct F_Seguimiento {
    fechaMain seguimiento;
};

struct registroP {
    string cedula;
    string nombre;
    F_Especiales fechas;
    float peso;
    float altura;
};

const string archivoPacientes = "pacientes.txt";

void guardarRegistroEnArchivo(const registroP& paciente) {
    ofstream archivo(archivoPacientes, ios::app);
    if (archivo.is_open()) {
        archivo << paciente.cedula << ',' << paciente.nombre << ',' << paciente.fechas.nacimiento.dia << '/'
                << paciente.fechas.nacimiento.mes << '/' << paciente.fechas.nacimiento.anio << ','
                << paciente.fechas.realizacion.dia << '/' << paciente.fechas.realizacion.mes << '/'
                << paciente.fechas.realizacion.anio << ',' << paciente.peso << ',' << paciente.altura << '\n';
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para escritura." << endl;
    }
}

void crearPaciente() {
    registroP paciente;
    cout << "Cédula del paciente: ";
    cin >> paciente.cedula;
    cout << "Nombre del paciente: ";
    cin >> paciente.nombre;
    cout << "Fecha de nacimiento (dia mes año): ";
    cin >> paciente.fechas.nacimiento.dia >> paciente.fechas.nacimiento.mes >> paciente.fechas.nacimiento.anio;
    cout << "Fecha de realización (dia mes año): ";
    cin >> paciente.fechas.realizacion.dia >> paciente.fechas.realizacion.mes >> paciente.fechas.realizacion.anio;
    cout << "Peso del paciente: ";
    cin >> paciente.peso;
    cout << "Altura del paciente: ";
    cin >> paciente.altura;
    guardarRegistroEnArchivo(paciente);
    cout << "Paciente creado y guardado exitosamente." << endl;
}

void listarPacientes() {
    ifstream archivo(archivoPacientes);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para lectura." << endl;
    }
}

void actualizarPaciente() {
    string cedulaBuscada;
    cout << "Cédula del paciente a actualizar: ";
    cin >> cedulaBuscada;

    ifstream archivo(archivoPacientes);
    ofstream archivoTemp("temp.txt");

    if (archivo.is_open() && archivoTemp.is_open()) {
        string linea;
        bool encontrado = false;

        while (getline(archivo, linea)) {
            string cedulaEncontrada = linea.substr(0, linea.find(','));
            if (cedulaEncontrada == cedulaBuscada) {
                registroP paciente;
                paciente.cedula = cedulaEncontrada;
                cout << "Nuevo nombre del paciente: ";
                cin >> paciente.nombre;
                cout << "Nueva fecha de nacimiento (dia mes año): ";
                cin >> paciente.fechas.nacimiento.dia >> paciente.fechas.nacimiento.mes >> paciente.fechas.nacimiento.anio;
                cout << "Nueva fecha de realización (dia mes año): ";
                cin >> paciente.fechas.realizacion.dia >> paciente.fechas.realizacion.mes >> paciente.fechas.realizacion.anio;
                cout << "Nuevo peso del paciente: ";
                cin >> paciente.peso;
                cout << "Nueva altura del paciente: ";
                cin >> paciente.altura;
                guardarRegistroEnArchivo(paciente);
                encontrado = true;
            } else {
                archivoTemp << linea << endl;
            }
        }

        archivo.close();
        archivoTemp.close();

        if (encontrado) {
            remove(archivoPacientes.c_str());
            rename("temp.txt", archivoPacientes.c_str());
            cout << "Paciente actualizado exitosamente." << endl;
        } else {
            cout << "Paciente no encontrado." << endl;
        }
    } else {
        cout << "No se pudo abrir el archivo para lectura o escritura." << endl;
    }
}

void eliminarPaciente() {
    string cedulaBuscada;
    cout << "Cédula del paciente a eliminar: ";
    cin >> cedulaBuscada;

    ifstream archivo(archivoPacientes);
    ofstream archivoTemp("temp.txt");

    if (archivo.is_open() && archivoTemp.is_open()) {
        string linea;
        bool encontrado = false;

        while (getline(archivo, linea)) {
            string cedulaEncontrada = linea.substr(0, linea.find(','));
            if (cedulaEncontrada == cedulaBuscada) {
                encontrado = true;
            } else {
                archivoTemp << linea << endl;
            }
        }

        archivo.close();
        archivoTemp.close();

        if (encontrado) {
            remove(archivoPacientes.c_str());
            rename("temp.txt", archivoPacientes.c_str());
            cout << "Paciente eliminado exitosamente." << endl;
        } else {
            cout << "Paciente no encontrado." << endl;
        }
    } else {
        cout << "No se pudo abrir el archivo para lectura o escritura." << endl;
    }
}

int main() {
    int opcion;
    do {
        cout << "Menú de la clínica:" << endl;
        cout << "1. Crear paciente" << endl;
        cout << "2. Listar pacientes" << endl;
        cout << "3. Actualizar paciente" << endl;
        cout << "4. Eliminar paciente" << endl;
        cout << "5. Salir" << endl;
        cout << "Elija una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                crearPaciente();
                break;
            case 2:
                listarPacientes();
                break;
            case 3:
                actualizarPaciente();
                break;
            case 4:
                eliminarPaciente();
                break;
            case 5:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);

    return 0;
}
