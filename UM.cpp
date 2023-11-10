#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include "estructuras.h"

using namespace std;

UltMamas UM;
void mamaIzq();
void mamaDer();
void lesionesMamas();
void conclusionesGen();
void BIRADS();

void mamaIzq(){
    string opc;

    do {
        printf("Escribe las caracter%csticas del tejido mamario predominante (de la mama izquierda)\n\n", 161);
        getline(cin, UM.tejidoPredominIzq);
        printf("\n%cHa ingresado todo correctamente? Si es as%c, presione S o ingrese cualquier otra letra para ingresarlo nuevamente.\n", 168, 161);
        cin >> opc;

        // Limpiar el búfer después de leer opc
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("clear || cls");

    } while (opc != "S");


    printf("\nDescripciones espec%cficas - Cuadrantes en los que est%c distribuido el tejido\n", 161, 160);
    printf("  - Cuadrante 1\n");
    while (!(cin >> UM.cuadrante1Izq) || cin.fail()) {
        cin.clear(); // Limpiar el flag de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta del usuario
        printf("ERROR - No ingresaste un n%cmero, int%cntelo otra vez\n", 163, 130);
        printf("  - Cuadrante 1\n");
    }
    printf("  - Cuadrante 2\n");
    while (!(cin >> UM.cuadrante2Izq) || cin.fail()) {
        cin.clear(); // Limpiar el flag de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta del usuario
        printf("ERROR - No ingresaste un n%cmero, int%cntelo otra vez\n", 163, 130);
        printf("  - Cuadrante 2\n");
    }
    printf("  - Cuadrante 3\n");
    while (!(cin >> UM.cuadrante3Izq) || cin.fail()) {
        cin.clear(); // Limpiar el flag de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta del usuario
        printf("ERROR - No ingresaste un n%cmero, int%cntelo otra vez\n", 163, 130);
        printf("  - Cuadrante 3\n");
    }
    printf("  - Cuadrante 4\n");
    while (!(cin >> UM.cuadrante4Izq) || cin.fail()) {
        cin.clear(); // Limpiar el flag de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta del usuario
        printf("ERROR - No ingresaste un n%cmero, int%cntelo otra vez\n", 163, 130);
        printf("  - Cuadrante 4\n");
    }
}

void mamaDer(){
    string opc;

    do {
        printf("Escribe las caracter%csticas del tejido mamario predominante (de la mama derecha)\n\n", 161);
        getline(cin, UM.tejidoPredominDer);
        printf("\n%cHa ingresado todo correctamente? Si es as%c, presione S o ingrese cualquier otra letra para ingresarlo nuevamente.\n", 168, 161);
        cin >> opc;

        // Limpiar el búfer después de leer opc
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("clear || cls");

    } while (opc != "S");


    printf("\nDescripciones espec%cficas - Cuadrantes en los que est%c distribuido el tejido\n", 161, 160);
    printf("  - Cuadrante 1\n");
    while (!(cin >> UM.cuadrante1Der) || cin.fail()) {
        cin.clear(); // Limpiar el flag de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta del usuario
        printf("ERROR - No ingresaste un n%cmero, int%cntelo otra vez\n", 163, 130);
        printf("  - Cuadrante 1\n");
    }
    printf("  - Cuadrante 2\n");
    while (!(cin >> UM.cuadrante2Der) || cin.fail()) {
        cin.clear(); // Limpiar el flag de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta del usuario
        printf("ERROR - No ingresaste un n%cmero, int%cntelo otra vez\n", 163, 130);
        printf("  - Cuadrante 2\n");
    }
    printf("  - Cuadrante 3\n");
    while (!(cin >> UM.cuadrante3Der) || cin.fail()) {
        cin.clear(); // Limpiar el flag de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta del usuario
        printf("ERROR - No ingresaste un n%cmero, int%cntelo otra vez\n", 163, 130);
        printf("  - Cuadrante 3\n");
    }
    printf("  - Cuadrante 4\n");
    while (!(cin >> UM.cuadrante4Der) || cin.fail()) {
        cin.clear(); // Limpiar el flag de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta del usuario
        printf("ERROR - No ingresaste un n%cmero, int%cntelo otra vez\n", 163, 130);
        printf("  - Cuadrante 4\n");
    }
}

void lesionesMamas(){
    int opc;
    printf("%cAlguna de las mamas tiene lesiones?\n", 168);
    printf("1. S%clo la mama izquierda.\n", 162);
    printf("2. S%clo la mama derecha.\n", 162);
    printf("3. Ambas.\n");
    printf("4. Ninguna.\n");
    cout << " ---> "; cin >> opc;

    switch(opc){
        case 1: break;
        case 2: break;
        case 3: break;
        case 4: break;
        default: 
            printf("ERROR - No ingresaste un n%cmero v%clido, int%cntelo otra vez\n", 163, 160, 130);
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("clear || cls");
            lesionesMamas(); 
            break;
    }
}

void conclusionesGen(){
    string opc;

    do {
        cout << "Ingrese sus conclusiones generales del procedimiento." << endl;
        getline(cin, UM.conclusionesGen);
        printf("\n%cHa ingresado todo correctamente? Si es as%c, presione S o ingrese cualquier otra letra para ingresarlo nuevamente.\n", 168, 161);
        cin >> opc;

        // Limpiar el búfer después de leer opc
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("clear || cls");

    } while (opc != "S");
}

void BIRADS(){
    cout << "Breast Imaging-Reporting and Data System (BI-RADS)" << endl;
    printf("Escala de 0 a 5. Ingrese el n%cmero correspondiente seg%cn las normas internacionales.\n", 163, 163);
    cout << " ---> ";
    cin >> UM.BIRADS;

    while (UM.BIRADS < 0 || UM.BIRADS > 5)
    {
        printf("\nERROR - No ingresaste un n%cmero dentro del rango solicitado, int%cntelo otra vez.\n", 163, 130);
        BIRADS();
    }
        
}

int main(){

    /*Ultrasonido de mamas*/
    cout << "~ULTRASONIDO DE MAMAS~" << endl;

    /*Inicio - Tejido predominante*/
    mamaIzq();
    system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
    system("clear || cls");
    cin.ignore();
    mamaDer();
    system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
    system("clear || cls");
    cin.ignore();
    lesionesMamas();
    system("clear || cls");
    cin.ignore();
    conclusionesGen();
    cin.ignore();
    BIRADS();

    return 0;
}