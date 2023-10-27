#include <iostream>
#include <string>
using namespace std;

void menu();
void menuPacientes();
void infoMed();

void infoMed(){
    int opcion;
    printf("REGISTRO DE INFORMES M%CDICOS\n", 144); //É en ASCII
    printf("1.A%cadir nuevo diagn%cstico y prescripci%cn.\n", 164, 162, 162);
    cout << "2. Ver informes anteriores del paciente." << endl;
    printf("5. Regresar al men%c principal.\n", 163);
    cout << "  --->"; cin >> opcion;

    switch(opcion){
        case 1: //Añadir la lógica para agregar un nuevo diagnóstico y prescripción
            break;
        case 2: //Añadir la lógica para ver informes médicos anteriores de un paciente
            break;
        case 3: 
            system("clear || cls");
            menu();
        default: 
            printf("\nOpci%cn no v%clida. Por favor, elija una opci%cn dentro del rango de n%cmeros permitidos.\n", 162, 160, 162, 163);
            //ó, á y ú en ASCII
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("clear || cls");
            infoMed();
    }
}

void menuPacientes(){
    int opcion;
    cout << "REGISTRO DE PACIENTES" << endl;
    printf("1. A%cadir paciente.\n", 164);
    cout << "2. Editar paciente." << endl;
    cout << "3. Ver lista de pacientes." << endl;
    cout << "4. Eliminar paciente." << endl;
    printf("5. Regresar al men%c principal.\n", 163);
    cout << "  --->"; cin >> opcion;

    switch(opcion){
        case 1: //Añadir la lógica para agregar un nuevo paciente
            break;
        
        case 2: //Hacer el menú de qué es lo que se va a editar
            break;
        
        case 3: //Añadir la lógica para ver lista de pacientes
            break;

        case 4: //Añadir la lógica para eliminar paciente
            break;
        
        case 5: 
            system("clear || cls");
            menu();

        default:
            printf("\nOpci%cn no v%clida. Por favor, elija una opci%cn dentro del rango de n%cmeros permitidos.\n", 162, 160, 162, 163);
                //ó, á y ú en ASCII
                system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
                system("clear || cls");
                menuPacientes();
    }
}

void menu(){
    int opcion;

    printf("BIENVENIDO AL MEN%c GENERAL \n", 233); //Ú en ASCII
    printf("1. Men%c de pacientes.\n", 163); //ú en ASCII
    cout << "2. Ver las citas programadas. " << endl;
    printf("3. A%cadir una nueva prescripci%cn y diagn%cstico.\n", 164, 162, 162); //ñ y ó en ASCII
    printf("4. Men%c de informes m%cdicos.\n", 163, 130); //ú y é en ASCII
    cout << "5. Salir del programa." << endl;
    cout << "  --->"; cin >> opcion;

    switch (opcion) {
            case 1:
                system("clear || cls");
                menuPacientes();
                break;
            case 2:
                // Lógica para "Ver las citas programadas."
                // Agregar tu lógica aquí
                break;
            case 3:
                // Lógica para "Añadir una nueva prescripción y diagnóstico."
                // Agregar tu lógica aquí
                break;
            case 4:
                system("clear || cls");
                infoMed();
                break;
            case 5: 
                cout << "\nSaliendo del programa..." << endl;
                break;
            default:
                printf("\nOpci%cn no v%clida. Por favor, elija una opci%cn dentro del rango de n%cmeros permitidos.\n", 162, 160, 162, 163);
                //ó, á y ú en ASCII
                system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
                system("clear || cls");
                menu();
        }

}

int main(){
    menu();
    return 0;
    }