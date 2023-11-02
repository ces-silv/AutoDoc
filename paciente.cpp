//Librerias
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <limits>
#include <sstream>
#include "estructuras.h"

using namespace std;

const string archivoPacientes = "pacientes.txt";

// Funcion para convertir una cadena a mayusculas

string convertirMayus(const string& str){
    string resultado = str;
    for(char& c : resultado){
        c = toupper(c);
    }
    return resultado;
}

void guardarRegistro(const registroP& paciente){
    ofstream archivo(archivoPacientes, ios :: app );
    if (archivo.is_open())
    {
        archivo << paciente.cedula << ',' << paciente.nombre << ',' << paciente.fechas.nacimiento.dia << '/'
                << paciente.fechas.nacimiento.mes << '/' << paciente.fechas.nacimiento.anio << ','
                << paciente.fechas.realizacion.dia << '/' << paciente.fechas.realizacion.mes << '/'
                << paciente.fechas.realizacion.anio << ',' << paciente.peso << ',' << paciente.altura << ',' << paciente.num_celular << '\n';
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    } 
}
void cargarRegistroDesdeLinea(const string& linea, registroP& paciente) {
    stringstream ss(linea);
    string cedula, nombre, fechaNacimiento, fechaRealizacion, peso, altura, numCelular;
    getline(ss, cedula, ',');
    getline(ss, nombre, ',');
    getline(ss, fechaNacimiento, ',');
    getline(ss, fechaRealizacion, ',');
    getline(ss, peso, ',');
    getline(ss, altura, ',');
    getline(ss, numCelular);

    paciente.cedula = cedula;
    paciente.nombre = nombre;
    
    string token;

    stringstream fechaNacStream(fechaNacimiento);
    getline(fechaNacStream, token, '/');
    paciente.fechas.nacimiento.dia = stoi(token);
    getline(fechaNacStream, token, '/');
    paciente.fechas.nacimiento.mes = stoi(token);
    getline(fechaNacStream, token, '/');
    paciente.fechas.nacimiento.anio = stoi(token);

    stringstream fechaRealStream(fechaRealizacion);
    getline(fechaRealStream, token, '/');
    paciente.fechas.realizacion.dia = stoi(token);
    getline(fechaRealStream, token, '/');
    paciente.fechas.realizacion.mes = stoi(token);
    getline(fechaRealStream, token, '/');
    paciente.fechas.realizacion.anio = stoi(token);


    stringstream pesoStream(peso);
    pesoStream >> paciente.peso;

    stringstream alturaStream(altura);
    alturaStream >> paciente.altura;

    stringstream numCelularStream(numCelular);
    numCelularStream >> paciente.num_celular;
}



void crearPaciente(){
    registroP paciente;

    system("clear || cls");
    printf("--------MEN%C DE PACIENTES--------\n", 163);

    printf("C%cdula del paciente: ", 144);
    cin >> paciente.cedula;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    paciente.cedula = convertirMayus(paciente.cedula);
    
    cout << "Nombre del paciente: ";
    getline(cin, paciente.nombre);
    paciente.nombre = convertirMayus(paciente.nombre);

    printf("Fecha de nacimiento (d%ca/mes/a%co): \n", 214, 164);
    printf("D%ca: ", 214);
    cin >> paciente.fechas.nacimiento.dia;
    printf("Mes: ");
    cin >> paciente.fechas.nacimiento.mes;
    printf("A%co: ", 164);
    cin >> paciente.fechas.nacimiento.anio;

    printf("Fecha de realizaci%cn (d%ca/mes/a%co): \n", 162, 214, 164);
    printf("D%ca: ", 214);
    cin >> paciente.fechas.realizacion.dia;
    printf("Mes: ");
    cin >> paciente.fechas.realizacion.mes;
    printf("A%co: ", 164);
    cin >> paciente.fechas.realizacion.anio;

    cout << "Peso del paciente (lb): ";
    cin >> paciente.peso;

    cout << "Altura del paciente (cm): ";
    cin >> paciente.altura;

    printf("N%cmero de tel%cfono: ", 163, 144);
    cin >> paciente.num_celular;

    guardarRegistro(paciente);
    cout << "Paciente creado y guardado exitosamente." << endl;

}

bool buscarPacientes(const string& cedulaONombre) {
    ifstream archivo(archivoPacientes);
    if (archivo.is_open()) {
        string linea;
        bool encontrado = false;

        // Convierte la entrada a mayúsculas
        string cedulaONombreMayus = convertirMayus(cedulaONombre);

        while (getline(archivo, linea)) {
            registroP paciente;
            cargarRegistroDesdeLinea(linea, paciente);

            // Convierte el nombre del paciente a mayúsculas para la comparación
            string nombreMayus = convertirMayus(paciente.nombre);

            if (paciente.cedula == cedulaONombreMayus || nombreMayus == cedulaONombreMayus) {
                // Muestra la información del paciente encontrado

                system("clear || cls");
                printf("--------MEN%C DE PACIENTES--------\n", 163);
                cout << "Paciente encontrado:" << endl;
                cout << "Cédula: " << paciente.cedula << endl;
                cout << "Nombre: " << paciente.nombre << endl;
                cout << "Fecha de nacimiento: " << paciente.fechas.nacimiento.dia << "/" << paciente.fechas.nacimiento.mes << "/" << paciente.fechas.nacimiento.anio << endl;
                cout << "Fecha de realización: " << paciente.fechas.realizacion.dia << "/" << paciente.fechas.realizacion.mes << "/" << paciente.fechas.realizacion.anio << endl;
                cout << "Peso: " << paciente.peso << " lb" << endl;
                cout << "Altura: " << paciente.altura << " cm" << endl;
                cout << "Número de teléfono: " << paciente.num_celular << endl;

                encontrado = true;
            }
        }

        archivo.close();

        if (!encontrado) {
            cout << "Paciente no encontrado." << endl;
            system("clear || cls");
            printf("--------MEN%C DE PACIENTES--------\n", 163);
        }

        return encontrado;
    } else {
        cout << "No se pudo abrir el archivo para lectura." << endl;
        return false;
    }
}

void listarPacientes() {
    ifstream archivo(archivoPacientes);
    if (archivo.is_open()) {
        system("clear || cls");
        printf("--------MEN%C DE PACIENTES--------\n", 163);
        cout << "Lista de pacientes:" << endl;
        cout << "----------------------------------------" << endl;

        string linea;
        int contador = 1;

        while (getline(archivo, linea)) {
            registroP paciente;
            cargarRegistroDesdeLinea(linea, paciente);

            cout << "Paciente " << contador << ":" << endl;
            cout << "Cédula: " << paciente.cedula << endl;
            cout << "Nombre: " << paciente.nombre << endl;
            cout << "Fecha de nacimiento: " << paciente.fechas.nacimiento.dia << "/" << paciente.fechas.nacimiento.mes << "/" << paciente.fechas.nacimiento.anio << endl;
            cout << "Fecha de realización: " << paciente.fechas.realizacion.dia << "/" << paciente.fechas.realizacion.mes << "/" << paciente.fechas.realizacion.anio << endl;
            cout << "Peso: " << paciente.peso << " lb" << endl;
            cout << "Altura: " << paciente.altura << " cm" << endl;
            cout << "Número de teléfono: " << paciente.num_celular << endl;

            cout << "----------------------------------------" << endl;
            contador++;
        }

        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para lectura." << endl;
    }
}


void actualizarPaciente() {
    system("clear || cls");
    printf("--------MEN%C DE PACIENTES--------\n", 163);

    string cedulaONombre;
    cin.ignore();  // Limpiar el búfer del teclado
    cout << "Ingrese la cédula o nombre del paciente a actualizar: ";
    getline(cin, cedulaONombre);  // Leer toda la línea, permitiendo espacios en blanco
    cedulaONombre = convertirMayus(cedulaONombre);

    ifstream archivo(archivoPacientes);
    ofstream archivoTemp("temp.txt");

    if (archivo.is_open() && archivoTemp.is_open()) {
        string linea;
        bool encontrado = false;

        while (getline(archivo, linea)) {
            registroP paciente;
            cargarRegistroDesdeLinea(linea, paciente);
            string cedulaEncontrada = paciente.cedula;
            string nombreEncontrado = convertirMayus(paciente.nombre);

            if (cedulaEncontrada == cedulaONombre || nombreEncontrado == cedulaONombre) {
                cout << "Paciente encontrado:" << endl;
                cout << "Cédula: " << paciente.cedula << endl;
                cout << "Nombre: " << paciente.nombre << endl;
                cout << "Fecha de nacimiento: " << paciente.fechas.nacimiento.dia << "/" << paciente.fechas.nacimiento.mes << "/" << paciente.fechas.nacimiento.anio << endl;
                cout << "Fecha de realización: " << paciente.fechas.realizacion.dia << "/" << paciente.fechas.realizacion.mes << "/" << paciente.fechas.realizacion.anio << endl;
                cout << "Peso: " << paciente.peso << " lb" << endl;
                cout << "Altura: " << paciente.altura << " cm" << endl;
                cout << "Número de teléfono: " << paciente.num_celular << endl;

                // Realiza la actualización del dato seleccionado
                int opcion;
                do {
                    cout << "¿Qué dato desea actualizar?" << endl;
                    cout << "1. Nombre" << endl;
                    cout << "2. Fecha de nacimiento" << endl;
                    cout << "3. Fecha de realización" << endl;
                    cout << "4. Peso" << endl;
                    cout << "5. Altura" << endl;
                    cout << "6. Número de teléfono" << endl;
                    cout << "7. Finalizar actualización" << endl;
                    cout << "Elija una opción: ";
                    cin >> opcion;

                    switch (opcion) {
                        case 1:
                            cout << "Nuevo nombre del paciente: ";
                            cin.ignore();
                            getline(cin, paciente.nombre);
                            break;
                        case 2:
                            cout << "Nueva fecha de nacimiento (día mes año): ";
                            cin >> paciente.fechas.nacimiento.dia >> paciente.fechas.nacimiento.mes >> paciente.fechas.nacimiento.anio;
                            break;
                        case 3:
                            cout << "Nueva fecha de realización (día mes año): ";
                            cin >> paciente.fechas.realizacion.dia >> paciente.fechas.realizacion.mes >> paciente.fechas.realizacion.anio;
                            break;
                        case 4:
                            cout << "Nuevo peso del paciente: ";
                            cin >> paciente.peso;
                            break;
                        case 5:
                            cout << "Nueva altura del paciente: ";
                            cin >> paciente.altura;
                            break;
                        case 6:
                            cout << "Nuevo número de teléfono del paciente";
                            cin >> paciente.num_celular;
                            break;
                        case 7:
                            break;  // Finaliza la actualización
                        default:
                            cout << "Opción no válida. Por favor, elija una opción válida." << endl;
                            break;
                    }
                } while (opcion != 7);

                archivoTemp << paciente.cedula << ',' << paciente.nombre << ',' << paciente.fechas.nacimiento.dia << '/'
                        << paciente.fechas.nacimiento.mes << '/' << paciente.fechas.nacimiento.anio << ','
                        << paciente.fechas.realizacion.dia << '/' << paciente.fechas.realizacion.mes << '/'
                        << paciente.fechas.realizacion.anio << ',' << paciente.peso << ',' << paciente.altura << ',' << paciente.num_celular << '\n';

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
    system("clear || cls");
    printf("--------MEN%C DE PACIENTES--------\n", 163);

    string cedulaONombre;
    cin.ignore();  // Limpiar el búfer del teclado
    cout << "Ingrese la cédula o nombre del paciente a eliminar: ";
    getline(cin, cedulaONombre);  // Leer toda la línea, permitiendo espacios en blanco
    cedulaONombre = convertirMayus(cedulaONombre);

    ifstream archivo(archivoPacientes);
    ofstream archivoTemp("temp.txt");

    if (archivo.is_open() && archivoTemp.is_open()) {
        string linea;
        bool encontrado = false;

        while (getline(archivo, linea)) {
            registroP paciente;
            cargarRegistroDesdeLinea(linea, paciente);
            string cedulaEncontrada = paciente.cedula;
            string nombreEncontrado = convertirMayus(paciente.nombre);

            if (cedulaEncontrada == cedulaONombre || nombreEncontrado == cedulaONombre) {
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
    string cedulaONombreABuscar;  // Variable para almacenar la cédula o nombre a buscar

    do {
        #ifdef _WIN32
            system("pause");
        #endif

        system(" read -p 'Presiona Enter para continuar...' -n 1 -s");
        system("clear || cls");
        printf("--------MEN%C DE PACIENTES--------\n", 163);
        cout << "Menú de la clínica:" << endl;
        cout << "1. Crear paciente" << endl;
        cout << "2. Listar pacientes" << endl;
        cout << "3. Buscar paciente" << endl;
        cout << "4. Actualizar paciente" << endl;
        cout << "5. Eliminar paciente" << endl;
        cout << "6. Salir" << endl;
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
                cin.ignore();  // Limpiar el búfer del teclado
                cout << "Ingrese la cédula o nombre del paciente a buscar: ";
                getline(cin, cedulaONombreABuscar);  // Leer toda la línea, permitiendo espacios en blanco
                buscarPacientes(cedulaONombreABuscar);
                break;
            case 4:
                actualizarPaciente();
                break;
            case 5:
                eliminarPaciente();
                break;
            case 6:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                system("clear || cls");
                printf("--------MEN%C DE PACIENTES--------", 163);

                cout << "Opción no válida. Intente de nuevo." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (opcion != 6);

    return 0;
}