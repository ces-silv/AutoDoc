#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <vector>
#include "estructuras.h"

using namespace std;

UltMamas UM;
void mamaIzq();
void mamaDer();
void lesionesMamas();
void conclusionesGen();

void mamaIzq(){
    vector<string> tejidoPredominIzqVector;
    string opc;

    do {
        printf("Escribe las caracter%csticas del tejido mamario predominante (de la mama izquierda)\n\n", 161);
        getline(cin, UM.tejidoPredominIzq);
        tejidoPredominIzqVector.push_back(UM.tejidoPredominIzq); // Agrega la entrada al vector

        printf("\n%cHa ingresado todo correctamente? Si es as%c, presione S o ingrese cualquier otra letra para ingresarlo nuevamente.\n", 168, 161);
        cin >> opc;

        // Limpiar el búfer después de leer opc
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("clear || cls");

    } while (opc != "S" && opc != "s");

    /*cout << "Entradas almacenadas en el vector:\n";
    for (const string& entrada : tejidoPredominIzqVector) {
        cout << entrada << endl;
    }*/


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
    vector<string> tejidoPredominDerVector;
    string opc;

    do {
        printf("Escribe las caracter%csticas del tejido mamario predominante (de la mama izquierda)\n\n", 161);
        getline(cin, UM.tejidoPredominDer);
        tejidoPredominDerVector.push_back(UM.tejidoPredominDer); // Agrega la entrada al vector

        printf("\n%cHa ingresado todo correctamente? Si es as%c, presione S o ingrese cualquier otra letra para ingresarlo nuevamente.\n", 168, 161);
        cin >> opc;

        // Limpiar el búfer después de leer opc
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("clear || cls");

    } while (opc != "S" && opc != "s");


    printf("Escribe las caracter%csticas del tejido mamario predominante (de la mama derecha)\n\n", 161);
    getline(cin, UM.tejidoPredominDer);

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
    printf("%cAlguna de las mamas tiene lesiones?\n", 168);

}

void conclusionesGen(){
    vector<string> ConclusionesGenComp;
    string opc;

    do {
        cout << "Ingrese sus conclusiones generales del procedimiento." << endl;
        getline(cin, UM.conclusionesGen);
        ConclusionesGenComp.push_back(UM.conclusionesGen); // Agrega la entrada al vector

        printf("\n%cHa ingresado todo correctamente? Si es as%c, presione S o ingrese cualquier otra letra para ingresarlo nuevamente.\n", 168, 161);
        cin >> opc;

        // Limpiar el búfer después de leer opc
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("clear || cls");

    } while (opc != "S" && opc != "s");
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
    conclusionesGen();

    return 0;
}