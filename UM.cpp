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
void lesionMamaIzq();
void lesionMamaDer();
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

void lesionMamaIzq(){
    UM.lesionesMamaIzq = false;
    string lesionesMamaIzq;
    while (UM.lesionesMamaIzq == false){
        printf("Ingrese las medidas del quiste izquierdo - Recuerda que en el documento se mostrar%c de la siguiente manera: A x B x C\n\n", 233, 160);
        cout << "Medida A:" << endl;
        cin >> UM.xQuisteIzq;
        cout << "Medida B:" << endl;
        cin >> UM.yQuisteIzq;
        cout << "Medida C:" << endl;
        cin >> UM.zQuisteIzq; 
        
        printf("%cTiene las medidas correctas?\n", 168);
        cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato.." << endl;
        cin >> lesionesMamaIzq;
            if ( (lesionesMamaIzq == "S") || (lesionesMamaIzq == "s")){
                UM.lesionesMamaIzq = true;
            }
        system("cls || clear");
    }
}

void lesionMamaDer(){
    UM.lesionesMamaDer = false;
    string lesionesMamaDer;
    while (UM.lesionesMamaDer == false){
        printf("Ingrese las medidas del quiste derecho - Recuerda que en el documento se mostrar%c de la siguiente manera: A x B x C\n\n", 233, 160);
        cout << "Medida A:" << endl;
        cin >> UM.xQuisteDer;
        cout << "Medida B:" << endl;
        cin >> UM.yQuisteDer;
        cout << "Medida C:" << endl;
        cin >> UM.zQuisteDer; 
        
        printf("%cTiene las medidas correctas?\n", 168);
        cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato.." << endl;
        cin >> lesionesMamaDer;
            if ( (lesionesMamaDer == "S") || (lesionesMamaDer == "s")){
                UM.lesionesMamaDer = true;
            }
        system("cls || clear");
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

    cin.ignore();

    switch(opc){
        case 1: system("clear || cls"); lesionMamaIzq(); break;
        case 2: system("clear || cls"); lesionMamaDer(); break;
        case 3: system("clear || cls"); lesionMamaIzq(); lesionMamaDer(); break;
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
    BIRADS();

    return 0;
}