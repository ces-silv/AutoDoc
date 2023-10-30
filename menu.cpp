#include <iostream>
#include <string>
using namespace std;

void menu();
void menuPacientes();
void procedimientos();
void infoMed();

void procedimientos(){
    int opcion;
    cout << "PROCEDIMIENTOS" << endl;
    cout << "1. Ultrasonido transvaginal." << endl;
    printf("2. Ultrasonido p%clvico.\n", 130);
    cout << "3. Ultrasonido de mamas." << endl;
    cout << "4. Seguimiento de embarazo." << endl;
    printf("5. Regresar al men%c principal.\n", 163);
    cout << "  --->"; cin >> opcion;

    switch (opcion)
    {
    case 1:
        //Añadir el archivo de UT
        break;
    case 2:
        //Añadir el archivo de UP
        break;
    case 3:
        //Añadir el archivo de UM
        break;
    case 4:
        //Añadir el archivo de seguimEmb
        break;
    case 5:
        system("clear || cls");
        menu();
        break;
    default:
        printf("\nOpci%cn no v%clida. Por favor, elija una opci%cn dentro del rango de n%cmeros permitidos.\n", 162, 160, 162, 163);
        //ó, á y ú en ASCII
        system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
        system("clear || cls");
        procedimientos();
        break;
    }
}

void infoMed(){
    int opcion;
    printf("REGISTRO DE INFORMES M%CDICOS\n", 144); //É en ASCII
    printf("1. A%cadir nuevo diagn%cstico y prescripci%cn.\n", 164, 162, 162);
    cout << "2. Ver informes anteriores del paciente." << endl;
    printf("3. Regresar al men%c principal.\n", 163);
    cout << "  --->"; cin >> opcion;

    switch(opcion){
        case 1: //Añadir la lógica para agregar el archivo de nuevo diagnóstico y prescripción
            break;
        case 2: //Añadir la lógica para ver el archivo de informes médicos anteriores de un paciente
            break;
        case 3: 
            system("clear || cls");
            menu();
            break;
        default: 
            printf("\nOpci%cn no v%clida. Por favor, elija una opci%cn dentro del rango de n%cmeros permitidos.\n", 162, 160, 162, 163);
            //ó, á y ú en ASCII
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("clear || cls");
            infoMed();
            break;
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
            break;

        default:
            printf("\nOpci%cn no v%clida. Por favor, elija una opci%cn dentro del rango de n%cmeros permitidos.\n", 162, 160, 162, 163);
                //ó, á y ú en ASCII
                system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
                system("clear || cls");
                menuPacientes();
                break;
    }
}

void menu(){
    int opcion;

    printf("BIENVENIDO AL MEN%c GENERAL \n", 233); //Ú en ASCII
    printf("1. Men%c de pacientes.\n", 163); //ú en ASCII
    cout << "2. Ver las citas programadas. " << endl;
    printf("3. Men%c de procedimientos.\n", 163);
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
                system("clear || cls");
                procedimientos();
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
                break;
        }

}

int main(){
    menu();
    return 0;
    }