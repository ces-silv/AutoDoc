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

void mamaIzq(){
    printf("Escribe las caracter%csticas del tejido mamario predominante (de la mama izquierda)\n\n", 161);
    getline(cin, UM.tejidoPredominIzq);

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


}