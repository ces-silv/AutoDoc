#include <iostream>
#include <limits>
#include <windows.h>
#include "1_estructuras.h"

using namespace std;


int main(){
    SetConsoleOutputCP(CP_UTF8);
    login();
    menuPrincipal();
    return 0;
}

void regresarMenuPrincipal(){
    string opc;
    printf("¿Deseas regresar al menú principal? Escribe S para confirmar o presiona cualquier letra para salir del programa.\n");
    getline(cin, opc);
    if (opc == "S" || opc == "s") {
        system("clear || cls"); 
        menuPrincipal();
    } else {
        cout << "\nVuelva Pronto Dr. Carlos Silva :D" << endl;
        exit(0);
    }
}

void Procedimientos(){
    int opcion;
    cout << "PROCEDIMIENTOS" << endl;
    cout << "1. Ultrasonido transvaginal." << endl;
    printf("2. Ultrasonido pélvico.\n");
    cout << "3. Ultrasonido de mamas." << endl;
    cout << "4. Seguimiento de embarazo." << endl;
    printf("5. Regresar al menú principal.\n");
    cout << "  --->"; cin >> opcion;

    switch (opcion)
    {
    case 1: system("clear || cls"); UT();
        break;
    case 2: system("clear || cls"); UP();
        break;
    case 3: system("clear || cls"); UM();
        break;
    case 4: system("clear || cls"); SE();
        break;
    case 5:
        system("clear || cls");
        menuPrincipal();
        break;
    default:
        printf("Opción no válida. Por favor, elija una opción dentro del rango de números permitidos.\n");
        //ó, á y ú en ASCII
        system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
        system("clear || cls");
        Procedimientos();
        break;
    }
}

void menuPrincipal(){
    int opc;

    printf("~MENÚ PRINCIPAL - CLÍNICA MÉDICA ESPERANZA~\n");
    cout << "     ~ Hola Dr. Carlos Silva ~\n" << endl;
    printf("Ingrese la opción que desee\n\n");
    printf(" 1. Ver Registro de Pacientes y su expendiente médico\n");
    cout << " 2. Agenda con citas programadas" << endl;
    cout << " 3. Crear Archivos Procedimientos" << endl;
    printf(" 4. Crear y ver diagnósticos y prescripciones\n");
    cout << " 5. Salir" << endl << endl;
    cout << "---> "; cin >> opc;

    switch (opc){
    case 1: mainPacientes();
        break;
    
    case 2: system("clear || cls"); agenda();
        break;

    case 3: system("clear || cls"); Procedimientos();
        break;

    case 4: system("clear || cls"); diagPres(); regresarMenuPrincipal();
        break;

    case 5:    
        cout << "Vuelva Pronto Dr. Carlos Silva :D" << endl;
        break;

    default:
        system("cls || clear");
        printf("Doctor, por favor ingrese una opción entre el 1 al 4 - Recuerde que sólo esas opciones son admitidas.\n\n");
        menuPrincipal();
        break;
    }
}


// Método principal
void agenda() {
    int opcion;

    do {
        // Mostrar menú
        cout << "AGENDA" << endl;
        cout << "1. Programar cita" << endl;
        cout << "2. Ver citas programadas" << endl;
        cout << "3. Regresar al menú principal" << endl;
        cout << "4. Salir" << endl;
        printf("Seleccione una opción: ");
        cin >> opcion;

        switch (opcion) {
            case 1:
                programarCita();
                break;
            case 2:
                mostrarCitasProgramadas();
                break;
            case 3: system("clear || cls"); menuPrincipal();
                break;
            case 4:
                printf("Saliendo del programa. ¡Hasta luego!\n");
                break;
            default:
                printf("Opción no válida. Inténtelo de nuevo.\n");
                break;
        }

    } while (opcion != 3);
}

void mainPacientes() {
    int opcion;
    string cedulaONombreABuscar;  // Variable para almacenar la cédula o nombre a buscar

    do {
        #ifdef _WIN32
            system("pause");
        #endif

        system(" read -p 'Presiona Enter para continuar...' -n 1 -s");
        system("clear || cls");
        printf("--------MENÚ DE PACIENTES--------\n");
        printf("Menú de la clínica:\n");
        cout << "1. Crear paciente" << endl;
        cout << "2. Listar pacientes" << endl;
        cout << "3. Buscar paciente" << endl;
        cout << "4. Actualizar paciente" << endl;
        cout << "5. Eliminar paciente" << endl;
        cout << "6. Volver al Menú Principal" << endl;
        printf("Elija una opción: ");

    while (!(cin >> opcion) || cin.peek() != '\n' || opcion < 1 || opcion > 6) {
        printf("Entrada inválida. Por favor, ingrese un número entero del 1 al 6: ");
        std::cin.clear();
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
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
            case 6: system("clear || cls"); menuPrincipal();
                break;
            default:
                system("clear || cls");
                printf("--------MENÚ DE PACIENTES--------");
                cout << endl;
                printf("Opción no válida. Inténtelo de nuevo.\n");
                std::cin.clear();
                std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        }
    } while (opcion != 6);

}