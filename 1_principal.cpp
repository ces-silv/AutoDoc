#include "2_login.cpp"
#include "5_menu.cpp"
#include <iostream>

using namespace std;

void menus();

int main(){

    login();

    menus();

    return 0;
}


void menus(){

    int opc;

    cout << "~Menu Principal - Clinica Medica Esperanza~" << endl;
    cout << "     ~ Hola Dr. Carlos Silva ~\n" << endl;
    cout << "Ingrese la opcion que desee\n" << endl;
    cout << "1. Ver Registro Pacientes" << endl;
    cout << "2. Revisar Informes Medicos" << endl;
    cout << "3. Crear Archivos Procedimientos" << endl;
    cout <<" 4. Crear o ver citas agendadas" << endl;
    cout << "4. Salir" << endl;
    cin >> opc;

    switch (opc){
    case 1:
        mainPacientes();
        system("cls");
        menus();
        break;
    
    case 2:
        system("cls");
        infoMed();
        system("cls");
        menus();
        break;

    case 3:
        procedimientos();
        menus();
        break;

    case 4:  
        agenda();
        menus();
        break;

    case 5:
        cout << "Vuelva Pronto Dr. Carlos Silva :D" << endl;
    default:
        system("cls");
        cout << "Doctor, por favor ingrese una opcion entre el 1 al 4 - Recuerde que solo esas opciones son admitidas.\n" << endl;
        menus();
        break;
    }
}