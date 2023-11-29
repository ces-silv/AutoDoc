//Librerias
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <limits>
#include <sstream>
#include <direct.h>  // Para _mkdir
#include <io.h>      // Para access
#include <windows.h>
#include "1_estructuras.h"

using namespace std;

const string archivoPacientes = "C:\\Users\\user\\OneDrive\\Escritorio\\AutoDoc\\pacientes.txt";

bool cedulaExiste(const string& cedula) {
    ifstream archivo(archivoPacientes);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            if (linea.find(cedula + ",") != string::npos) {
                return true; // La cédula ya existe.
            }
        }
        archivo.close();
    }
    return false; // La cédula no existe.
}

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
    string ruta = "C:\\Users\\user\\OneDrive\\Escritorio\\AutoDoc\\pacientes.txt";  // Ruta completa del archivo

    ofstream archivo(ruta, ios::app);
    if (archivo.is_open()) {
        archivo << paciente.cedula << ',' << paciente.nombrePaciente.primerNombre << ' ' << paciente.nombrePaciente.segundoNombre
                << ' ' << paciente.nombrePaciente.primerApellido << ' ' << paciente.nombrePaciente.segundoApellido << ','
                << paciente.fechas.nacimiento.dia << '/' << paciente.fechas.nacimiento.mes << '/' << paciente.fechas.nacimiento.anio << ','
                << paciente.peso << ',' << paciente.altura << ',' << paciente.num_celular << '\n';
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo en la ruta: " << ruta << endl;
    }
}


void crearPaciente() {
    registroP paciente;

    system("clear || cls");
    printf("--------MENÚ DE PACIENTES--------\n");

    printf("Cédula del paciente: ");
    cin >> paciente.cedula;
    //std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    paciente.cedula = convertirMayus(paciente.cedula);
    
    if (cedulaExiste(paciente.cedula)) {
    cout << "Error: Ya existe un paciente con esa cédula." << endl;
    return; // Salir de la función si la cédula ya está registrada.
}


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
        printf("Fecha de nacimiento (día/mes/año): \n");
        printf("Día: ");
        cin >> paciente.fechas.nacimiento.dia;
        printf("Mes: ");
        cin >> paciente.fechas.nacimiento.mes;
        printf("Año: ");
        cin >> paciente.fechas.nacimiento.anio;
    } while (!esFechaValida(paciente.fechas.nacimiento.dia, paciente.fechas.nacimiento.mes, paciente.fechas.nacimiento.anio));

    cout << "Peso del paciente (lb): ";
    cin >> paciente.peso;

    cout << "Altura del paciente (cm): ";
    cin >> paciente.altura;

    printf("Número de teléfono del paciente: ");
    cin >> paciente.num_celular;

   // Crea una carpeta con el número de la cédula del paciente
    string path = "C:/Users/user/OneDrive/Escritorio/AutoDoc/" + paciente.cedula; // Ajusta la ruta según necesites
    if (_access(path.c_str(), 0) != 0) {  // Verifica si la carpeta ya existe
        if (_mkdir(path.c_str()) != 0) {  // Intenta crear la carpeta
            cout << "No se pudo crear la carpeta para el paciente." << endl;
            return;  // Sale de la función si no se puede crear la carpeta
        }
    }

    // Nombres de las subcarpetas
    string subCarpetas[4] = {"UP", "UT", "SE", "UM"};

    // Crea las subcarpetas dentro de la carpeta del paciente
    for (const string& subCarpeta : subCarpetas) {
        string subCarpetaPath = path + "/"  + subCarpeta;
        if (_access(subCarpetaPath.c_str(), 0) != 0) {  // Verifica si la subcarpeta ya existe
            if (_mkdir(subCarpetaPath.c_str()) != 0) {  // Intenta crear la subcarpeta
                cout << "No se pudo crear la subcarpeta " << subCarpeta << " para el paciente." << endl;
            }
        }
    }

    guardarRegistro(paciente);
    cout << "Paciente creado y guardado exitosamente." << endl;
}

void buscarPacientes(){
    system("clear || cls");
    printf("--------MENÚ DE PACIENTES--------\n");

    string cedulaONombreInput;  // Variable local para almacenar la entrada del usuario

    do {
        cin.ignore();  // Limpiar el búfer del teclado
        printf("Ingrese la cédula o nombre del paciente a buscar (o 'v' para volver al menú principal): ");
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
                        printf("--------MENÚ DE PACIENTES--------\n");
                        cout << "Pacientes encontrados:" << endl;
                    }
                    printf("Cédula: "); cout << paciente.cedula << endl;
                    cout << "Nombre: " << paciente.nombrePaciente.primerNombre << ' ' << paciente.nombrePaciente.segundoNombre << ' ' << paciente.nombrePaciente.primerApellido << ' ' << paciente.nombrePaciente.segundoApellido << endl;
                    cout << "Fecha de nacimiento: " << paciente.fechas.nacimiento.dia << "/" << paciente.fechas.nacimiento.mes << "/" << paciente.fechas.nacimiento.anio << endl;
                    cout << "Peso: " << paciente.peso << " lb" << endl;
                    cout << "Altura: " << paciente.altura << " cm" << endl;
                    printf("Número de teléfono: "); cout << paciente.num_celular << endl;

                    cout << "----------------------------------------" << endl;
                    encontrado = true;
                }
            }

            archivo.close();

            if (!encontrado) {
                cout << "Pacientes no encontrados." << endl;
                system("clear || cls");
                printf("--------MENÚ DE PACIENTES--------\n");
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
        printf("--------MENÚ DE PACIENTES--------\n");
        cout << "Lista de pacientes:" << endl;
        cout << "----------------------------------------" << endl;

        string linea;
        int contador = 1;

        while (getline(archivo, linea)) {
            registroP paciente;
            cargarRegistroDesdeLinea(linea, paciente);

            cout << "Paciente " << contador << ":" << endl;
            printf("Cédula: "); cout << paciente.cedula << endl;
            cout << "Nombre: " << paciente.nombrePaciente.primerNombre << ' ' << paciente.nombrePaciente.segundoNombre << ' ' << paciente.nombrePaciente.primerApellido << ' ' << paciente.nombrePaciente.segundoApellido << endl;
            cout << "Fecha de nacimiento: " << paciente.fechas.nacimiento.dia << "/" << paciente.fechas.nacimiento.mes << "/" << paciente.fechas.nacimiento.anio << endl;
            cout << "Peso: " << paciente.peso << " lb" << endl;
            cout << "Altura: " << paciente.altura << " cm" << endl;
            printf("Número de teléfono: "); cout << paciente.num_celular << endl;

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
    printf("--------MENÚ DE PACIENTES--------\n");

    string cedulaONombre;
    cin.ignore();  // Limpiar el búfer del teclado
    printf("Ingrese la cédula o nombre del paciente a actualizar: ");
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
                cout << "Paciente encontrado:" << endl << endl;
                printf("Cédula: "); cout << paciente.cedula << endl;
                cout << "Nombre: " << paciente.nombrePaciente.primerNombre << ' ' << paciente.nombrePaciente.segundoNombre << ' ' << paciente.nombrePaciente.primerApellido << ' ' << paciente.nombrePaciente.segundoApellido << endl;
                cout << "Fecha de nacimiento: " << paciente.fechas.nacimiento.dia << "/" << paciente.fechas.nacimiento.mes << "/" << paciente.fechas.nacimiento.anio << endl;
                cout << "Peso: " << paciente.peso << " lb" << endl;
                cout << "Altura: " << paciente.altura << " cm" << endl;
                printf("Número de teléfono: "); cout << paciente.num_celular << endl;

                // Realiza la actualización del dato seleccionado
                int opcion;
                do {
                    printf("¿Qué dato desea actualizar?\n");
                    cout << "1. Nombre" << endl;
                    cout << "2. Fecha de nacimiento" << endl;
                    cout << "3. Peso" << endl;
                    cout << "4. Altura" << endl;
                    printf("5. Número de teléfono\n");
                    printf("6. Finalizar actualización");
                    printf("Elija una opción: ");
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
                                printf("Nueva fecha de nacimiento (día mes año): ");
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
                            printf("Nuevo número de teléfono del paciente");
                            cin >> paciente.num_celular;
                            break;
                        case 6:
                            break;  // Finaliza la actualización
                        default:
                            printf("Opción no válida. Por favor, elija una opción válida.\n");
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

void eliminarDirectorio(const string& path) {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile((path + "\\*").c_str(), &findFileData);

    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            string filePath = path + "\\" + findFileData.cFileName;
            if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                if (strcmp(findFileData.cFileName, ".") != 0 && strcmp(findFileData.cFileName, "..") != 0) {
                    eliminarDirectorio(filePath);
                }
            } else {
                DeleteFile(filePath.c_str());
            }
        } while (FindNextFile(hFind, &findFileData) != 0);
        FindClose(hFind);
    }

    RemoveDirectory(path.c_str());
}


void eliminarPaciente() {
    system("clear || cls");
    printf("--------MENÚ DE PACIENTES--------\n");
    // Obtén la cédula o nombre del paciente a eliminar
    string cedulaPaciente;
    printf("Ingrese la cédula del paciente a eliminar: ");
    cin >> cedulaPaciente;

    // Confirmación de la eliminación
    char confirmacion;
    printf("¿Está seguro de eliminar a este paciente (S/N)? "); 
    cin >> confirmacion;
    if (toupper(confirmacion) != 'S') {
        printf("Operación cancelada.\n");
        return;
    }

    // Define la ruta a la carpeta del paciente
    string carpetaPaciente = "C:/Users/user/OneDrive/Escritorio/AutoDoc/" + cedulaPaciente;

    // Elimina la carpeta del paciente
    eliminarDirectorio(carpetaPaciente);

    // Elimina la información del paciente del archivo pacientes.txt
    ifstream archivoIn(archivoPacientes);
    ofstream archivoOut("temp.txt");
    string linea;
    bool pacienteEncontrado = false;
    while (getline(archivoIn, linea)) {
        if (linea.find(cedulaPaciente) == string::npos) {
            archivoOut << linea << endl;
        } else {
            pacienteEncontrado = true;
        }
    }
    archivoIn.close();
    archivoOut.close();

    // Reemplaza el archivo original con el temporal si se encontró el paciente
    if (pacienteEncontrado) {
        remove(archivoPacientes.c_str());
        rename("temp.txt", archivoPacientes.c_str());
        cout << "Paciente eliminado exitosamente." << endl;
    } else {
        remove("temp.txt");
        cout << "Paciente no encontrado." << endl;
    }
}