//Librerias
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <limits>
#include <sstream>
#include "3_estructuras.h"

using namespace std;

const string archivoPacientes = "pacientes.txt";

//Función para convertir cadenas a mayúsculas
string convertirMayus(const string& str){
    string resultado = str;
    for(char& c : resultado){
        c = toupper(c);
    }
    return resultado;
}

//Función de restricción de fechas no válidas
bool esFechaValida(int dia, int mes, int anio) {
    if (mes < 1 || mes > 12) {
        return false; // El mes debe estar entre 1 y 12.
    }
    if (dia < 1) {
        return false; // El día debe ser mayor o igual a 1.
    }
    if (mes == 2) {
        if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
            return dia <= 29; // Febrero tiene 29 días en años bisiestos.
        } else {
            return dia <= 28; // Febrero tiene 28 días en años no bisiestos.
        }
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return dia <= 30; // Abril, junio, septiembre y noviembre tienen 30 días.
    } else {
        return dia <= 31; // Los demás meses tienen 31 días.
    }
}

//Función para guardar archivos en registro
void guardarRegistro(const registroP& paciente) {
    ofstream archivo(archivoPacientes, ios::app);
    if (archivo.is_open()) {
        archivo << paciente.cedula << ',' << paciente.nombrePaciente.primerNombre << ' ' << paciente.nombrePaciente.segundoNombre
                << ' ' << paciente.nombrePaciente.primerApellido << ' ' << paciente.nombrePaciente.segundoApellido << ','
                << paciente.fechas.nacimiento.dia << '/' << paciente.fechas.nacimiento.mes << '/' << paciente.fechas.nacimiento.anio << ','
                << paciente.peso << ',' << paciente.altura << ',' << paciente.num_celular << '\n';
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }
}

void cargarRegistroDesdeLinea(const string& linea, registroP& paciente) {
    stringstream ss(linea);
    string cedula, nombre, fechaNacimiento, peso, altura, numCelular;
    getline(ss, cedula, ',');
    getline(ss, nombre, ',');
    getline(ss, fechaNacimiento, ',');
    getline(ss, peso, ',');
    getline(ss, altura, ',');
    getline(ss, numCelular);

    paciente.cedula = cedula;

    string token;

    stringstream nombreStream(nombre);
    getline(nombreStream, token, ' ');
    paciente.nombrePaciente.primerNombre = token;
    getline(nombreStream, token, ' ');
    paciente.nombrePaciente.segundoNombre = token;
    getline(nombreStream, token, ' ');
    paciente.nombrePaciente.primerApellido = token;
    getline(nombreStream, token, ' ');
    paciente.nombrePaciente.segundoApellido = token;

    stringstream fechaNacStream(fechaNacimiento);
    getline(fechaNacStream, token, '/');
    paciente.fechas.nacimiento.dia = stoi(token);
    getline(fechaNacStream, token, '/');
    paciente.fechas.nacimiento.mes = stoi(token);
    getline(fechaNacStream, token, '/');
    paciente.fechas.nacimiento.anio = stoi(token);

    stringstream pesoStream(peso);
    pesoStream >> paciente.peso;

    stringstream alturaStream(altura);
    alturaStream >> paciente.altura;

    stringstream numCelularStream(numCelular);
    numCelularStream >> paciente.num_celular;
}


void crearPaciente() {
    registroP paciente;

    system("clear || cls");
    printf("--------MEN%C DE PACIENTES--------\n", 163);

    printf("C%cdula del paciente: ", 130);
    cin >> paciente.cedula;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    paciente.cedula = convertirMayus(paciente.cedula);

    cout << "Primer nombre del paciente: ";
    cin >> paciente.nombrePaciente.primerNombre;
    paciente.nombrePaciente.primerNombre = convertirMayus(paciente.nombrePaciente.primerNombre);

    cout << "Segundo nombre del paciente: ";
    cin >> paciente.nombrePaciente.segundoNombre;
    paciente.nombrePaciente.segundoNombre = convertirMayus(paciente.nombrePaciente.segundoNombre);

    cout << "Primer apellido del paciente: ";
    cin >> paciente.nombrePaciente.primerApellido;
    paciente.nombrePaciente.primerApellido = convertirMayus(paciente.nombrePaciente.primerApellido);

    cout << "Segundo apellido del paciente: ";
    cin >> paciente.nombrePaciente.segundoApellido;
    paciente.nombrePaciente.segundoApellido = convertirMayus(paciente.nombrePaciente.segundoApellido);

    do {
        printf("Fecha de nacimiento (d%ca/mes/a%co): \n", 214, 164);
        printf("D%ca: ", 214);
        cin >> paciente.fechas.nacimiento.dia;
        printf("Mes: ");
        cin >> paciente.fechas.nacimiento.mes;
        printf("A%co: ", 164);
        cin >> paciente.fechas.nacimiento.anio;
    } while (!esFechaValida(paciente.fechas.nacimiento.dia, paciente.fechas.nacimiento.mes, paciente.fechas.nacimiento.anio));

    cout << "Peso del paciente (lb): ";
    cin >> paciente.peso;

    cout << "Altura del paciente (cm): ";
    cin >> paciente.altura;

    cout << "Número de teléfono del paciente: ";
    cin >> paciente.num_celular;

    guardarRegistro(paciente);
    cout << "Paciente creado y guardado exitosamente." << endl;
}

void buscarPacientes(){
    system("clear || cls");
    printf("--------MEN%C DE PACIENTES--------\n", 163);

    string cedulaONombreInput;  // Variable local para almacenar la entrada del usuario

    do {
        cin.ignore();  // Limpiar el búfer del teclado
        cout << "Ingrese la cédula o nombre del paciente a buscar (o 'v' para volver al menú principal): ";
        getline(cin, cedulaONombreInput);  // Leer toda la línea, permitiendo espacios en blanco

        if (cedulaONombreInput == "v" || cedulaONombreInput == "V") {
            break;  // Salir del bucle si el usuario quiere volver al menú principal
        }

        ifstream archivo(archivoPacientes);
        if (archivo.is_open()) {
            string linea;
            bool encontrado = false;

            // Convierte la entrada a mayúsculas
            string cedulaONombreMayus = convertirMayus(cedulaONombreInput);

            while (getline(archivo, linea)) {
                registroP paciente;
                cargarRegistroDesdeLinea(linea, paciente);

                // Convierte los nombres y apellidos del paciente a mayúsculas para la comparación
                string nombreCompletoMayus = convertirMayus(
                    paciente.nombrePaciente.primerNombre + ' ' +
                    paciente.nombrePaciente.segundoNombre + ' ' +
                    paciente.nombrePaciente.primerApellido + ' ' +
                    paciente.nombrePaciente.segundoApellido
                );

                // Verifica si la entrada coincide con cualquier parte del nombre o la cédula del paciente
                if (nombreCompletoMayus.find(cedulaONombreMayus) != string::npos ||
                    convertirMayus(paciente.cedula).find(cedulaONombreMayus) != string::npos) {
                    // Muestra la información del paciente encontrado
                    if (!encontrado) {
                        system("clear || cls");
                        printf("--------MEN%C DE PACIENTES--------\n", 163);
                        cout << "Pacientes encontrados:" << endl;
                    }
                    cout << "Cédula: " << paciente.cedula << endl;
                    cout << "Nombre: " << paciente.nombrePaciente.primerNombre << ' ' << paciente.nombrePaciente.segundoNombre << ' ' << paciente.nombrePaciente.primerApellido << ' ' << paciente.nombrePaciente.segundoApellido << endl;
                    cout << "Fecha de nacimiento: " << paciente.fechas.nacimiento.dia << "/" << paciente.fechas.nacimiento.mes << "/" << paciente.fechas.nacimiento.anio << endl;
                    cout << "Peso: " << paciente.peso << " lb" << endl;
                    cout << "Altura: " << paciente.altura << " cm" << endl;
                    cout << "Número de teléfono: " << paciente.num_celular << endl;

                    cout << "----------------------------------------" << endl;
                    encontrado = true;
                }
            }

            archivo.close();

            if (!encontrado) {
                cout << "Pacientes no encontrados." << endl;
                system("clear || cls");
                printf("--------MEN%C DE PACIENTES--------\n", 163);
            }
        } else {
            cout << "No se pudo abrir el archivo para lectura." << endl;
        }
    } while (true);
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
            cout << "Nombre: " << paciente.nombrePaciente.primerNombre << ' ' << paciente.nombrePaciente.segundoNombre << ' ' << paciente.nombrePaciente.primerApellido << ' ' << paciente.nombrePaciente.segundoApellido << endl;
            cout << "Fecha de nacimiento: " << paciente.fechas.nacimiento.dia << "/" << paciente.fechas.nacimiento.mes << "/" << paciente.fechas.nacimiento.anio << endl;
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

            // Convierte los nombres y apellidos del paciente a mayúsculas para la comparación
            string primerNombreMayus = convertirMayus(paciente.nombrePaciente.primerNombre);
            string segundoNombreMayus = convertirMayus(paciente.nombrePaciente.segundoNombre);
            string primerApellidoMayus = convertirMayus(paciente.nombrePaciente.primerApellido);
            string segundoApellidoMayus = convertirMayus(paciente.nombrePaciente.segundoApellido);

            if (cedulaEncontrada == cedulaONombre ||
                primerNombreMayus.find(cedulaONombre) != string::npos ||
                segundoNombreMayus.find(cedulaONombre) != string::npos ||
                primerApellidoMayus.find(cedulaONombre) != string::npos ||
                segundoApellidoMayus.find(cedulaONombre) != string::npos) {
                encontrado = true;
                system("cls || clear");
                cout << "Paciente encontrado:" << endl;
                cout << "Cédula: " << paciente.cedula << endl;
                cout << "Nombre: " << paciente.nombrePaciente.primerNombre << ' ' << paciente.nombrePaciente.segundoNombre << ' ' << paciente.nombrePaciente.primerApellido << ' ' << paciente.nombrePaciente.segundoApellido << endl;
                cout << "Fecha de nacimiento: " << paciente.fechas.nacimiento.dia << "/" << paciente.fechas.nacimiento.mes << "/" << paciente.fechas.nacimiento.anio << endl;
                cout << "Peso: " << paciente.peso << " lb" << endl;
                cout << "Altura: " << paciente.altura << " cm" << endl;
                cout << "Número de teléfono: " << paciente.num_celular << endl;

                // Realiza la actualización del dato seleccionado
                int opcion;
                do {
                    cout << "¿Qué dato desea actualizar?" << endl;
                    cout << "1. Nombre" << endl;
                    cout << "2. Fecha de nacimiento" << endl;
                    cout << "3. Peso" << endl;
                    cout << "4. Altura" << endl;
                    cout << "5. Número de teléfono" << endl;
                    cout << "6. Finalizar actualización" << endl;
                    cout << "Elija una opción: ";
                    cin >> opcion;

                    switch (opcion) {
                        case 1:
                            cout << "Nuevo nombre del paciente: ";
                            cin.ignore();
                            getline(cin, paciente.nombrePaciente.primerNombre);
                            cout << "Nuevo segundo nombre del paciente: ";
                            getline(cin, paciente.nombrePaciente.segundoNombre);
                            cout << "Nuevo primer apellido del paciente: ";
                            getline(cin, paciente.nombrePaciente.primerApellido);
                            cout << "Nuevo segundo apellido del paciente: ";
                            getline(cin, paciente.nombrePaciente.segundoApellido);
                            break;
                        case 2:
                            do {
                                cout << "Nueva fecha de nacimiento (día mes año): ";
                                cin >> paciente.fechas.nacimiento.dia >> paciente.fechas.nacimiento.mes >> paciente.fechas.nacimiento.anio;
                            } while (!esFechaValida(paciente.fechas.nacimiento.dia, paciente.fechas.nacimiento.mes, paciente.fechas.nacimiento.anio));
                            break;
                        case 3:
                            cout << "Nuevo peso del paciente: ";
                            cin >> paciente.peso;
                            break;
                        case 4:
                            cout << "Nueva altura del paciente: ";
                            cin >> paciente.altura;
                            break;
                        case 5:
                            cout << "Nuevo número de teléfono del paciente";
                            cin >> paciente.num_celular;
                            break;
                        case 6:
                            break;  // Finaliza la actualización
                        default:
                            cout << "Opción no válida. Por favor, elija una opción válida." << endl;
                            break;
                    }
                } while (opcion != 7);

                archivoTemp << paciente.cedula << ',' << paciente.nombrePaciente.primerNombre << ' ' << paciente.nombrePaciente.segundoNombre << ' ' << paciente.nombrePaciente.primerApellido << ' ' << paciente.nombrePaciente.segundoApellido << ',' << paciente.fechas.nacimiento.dia << '/'
                        << paciente.fechas.nacimiento.mes << '/' << paciente.fechas.nacimiento.anio << ','
                        << paciente.peso << ',' << paciente.altura << ',' << paciente.num_celular << '\n';
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
        bool eliminado = false; // Variable para rastrear si el paciente se ha eliminado

        while (getline(archivo, linea)) {
            registroP paciente;
            cargarRegistroDesdeLinea(linea, paciente);
            string cedulaEncontrada = paciente.cedula;

            // Convierte los nombres y apellidos del paciente a mayúsculas para la comparación
            string primerNombreMayus = convertirMayus(paciente.nombrePaciente.primerNombre);
            string segundoNombreMayus = convertirMayus(paciente.nombrePaciente.segundoNombre);
            string primerApellidoMayus = convertirMayus(paciente.nombrePaciente.primerApellido);
            string segundoApellidoMayus = convertirMayus(paciente.nombrePaciente.segundoApellido);

            if (cedulaEncontrada == cedulaONombre ||
                primerNombreMayus.find(cedulaONombre) != string::npos ||
                segundoNombreMayus.find(cedulaONombre) != string::npos ||
                primerApellidoMayus.find(cedulaONombre) != string::npos ||
                segundoApellidoMayus.find(cedulaONombre) != string::npos) {
                encontrado = true;

                cout << "Paciente encontrado:" << endl;
                cout << "Cédula: " << paciente.cedula << endl;
                cout << "Nombre: " << paciente.nombrePaciente.primerNombre << ' ' << paciente.nombrePaciente.segundoNombre << ' ' << paciente.nombrePaciente.primerApellido << ' ' << paciente.nombrePaciente.segundoApellido << endl;
                cout << "Fecha de nacimiento: " << paciente.fechas.nacimiento.dia << "/" << paciente.fechas.nacimiento.mes << "/" << paciente.fechas.nacimiento.anio << endl;
                cout << "Peso: " << paciente.peso << " lb" << endl;
                cout << "Altura: " << paciente.altura << " cm" << endl;
                cout << "Número de teléfono: " << paciente.num_celular << endl;

                // Pregunta si está seguro de eliminar al paciente
                char confirmacion;
                cout << "¿Está seguro de eliminar a este paciente? (S/N): ";
                cin >> confirmacion;
                if (toupper(confirmacion) == 'S') {
                    // No copiamos la línea en el archivo temporal, lo que efectivamente elimina el paciente
                    eliminado = true;
                } else {
                    cout << "Operación cancelada. El paciente no ha sido eliminado." << endl;
                    archivoTemp << linea << endl;
                }
            } else {
                archivoTemp << linea << endl;
            }
        }

        archivo.close();
        archivoTemp.close();

        if (encontrado && eliminado) {
            remove(archivoPacientes.c_str());
            rename("temp.txt", archivoPacientes.c_str());
            cout << "Paciente eliminado exitosamente." << endl;
        } else if (!encontrado) {
            cout << "Paciente no encontrado." << endl;
        }
    } else {
        cout << "No se pudo abrir el archivo para lectura o escritura." << endl;
    }
}

// void mainPacientes
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
        cout << "6. Volver Menu Principal" << endl;
        cout << "Elija una opción: ";

    while (!(cin >> opcion) || cin.peek() != '\n' || opcion < 1 || opcion > 6) {
        cout << "Entrada inválida. Por favor, ingrese un número entero del 1 al 6: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
        switch (opcion) {
            case 1:
                crearPaciente();
                break;
            case 2:
                listarPacientes();
                break;
            case 3:
                buscarPacientes();//cedulaONombreABuscar);
                break;
            case 4:
                actualizarPaciente();
                break;
            case 5:
                eliminarPaciente();
                break;
            case 6:
                break;
            default:
                system("clear || cls");
                printf("--------MEN%C DE PACIENTES--------", 163);
                cout << endl;
                cout << "Opción no válida. Intente de nuevo." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (opcion != 6);

}