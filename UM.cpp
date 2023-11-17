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
void saveToFile(const UltMamas& UM);

void mamaIzq(){
    bool tejidoPredominIzq = false;
    string opc;

    while(tejidoPredominIzq == false){
        cout << "~ULTRASONIDO DE MAMAS~\n\n";
        printf("Escribe las caracter%csticas del tejido mamario predominante (de la mama izquierda)\n", 161);
        getline(cin, UM.tejidoPredominIzq);

        printf("\n\nDescripciones espec%cficas - Cuadrantes en los que est%c distribuido el tejido\n", 161, 160);
        printf("  - Cuadrante 1\n");
        getline(cin, UM.cuadrante1Izq);
        printf("  - Cuadrante 2\n");
        getline(cin, UM.cuadrante2Izq);
        printf("  - Cuadrante 3\n");
        getline(cin, UM.cuadrante3Izq);
        printf("  - Cuadrante 4\n");
        getline(cin, UM.cuadrante4Izq);

        printf("\n\n%cHa ingresado todo correctamente? Si es as%c, presione S o ingrese cualquier otra letra para ingresarlo nuevamente.\n", 168, 161);
        cin >> opc;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(opc == "S" || opc == "s"){
            tejidoPredominIzq = true;
        }
        system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
        system("clear || cls");
    }
}

void mamaDer(){
    bool tejidoPredominDer = false;
    string opc;

    while(tejidoPredominDer == false){
        cout << "~ULTRASONIDO DE MAMAS~\n\n";
        printf("Escribe las caracter%csticas del tejido mamario predominante (de la mama derecha)\n", 161);
        getline(cin, UM.tejidoPredominDer);

        printf("\n\nDescripciones espec%cficas - Cuadrantes en los que est%c distribuido el tejido\n", 161, 160);
        printf("  - Cuadrante 1\n");
        getline(cin, UM.cuadrante1Der);
        printf("  - Cuadrante 2\n");
        getline(cin, UM.cuadrante2Der);
        printf("  - Cuadrante 3\n");
        getline(cin, UM.cuadrante3Der);
        printf("  - Cuadrante 4\n");
        getline(cin, UM.cuadrante4Der);

        printf("\n\n%cHa ingresado todo correctamente? Si es as%c, presione S o ingrese cualquier otra letra para ingresarlo nuevamente.\n", 168, 161);
        cin >> opc;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(opc == "S" || opc == "s"){
            tejidoPredominDer = true;
        }
        system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
        system("clear || cls");
    }
}

void lesionMamaIzq(){
    UM.lesionesMamaIzq = false;
    string lesionesMamaIzq;
    while (UM.lesionesMamaIzq == false){
        cout << "~ULTRASONIDO DE MAMAS~\n\n";
        printf("Ingrese las medidas del quiste izquierdo - Recuerda que en el documento se mostrar%c de la siguiente manera: A x B x C\n\n", 233, 160);
        cout << "Medida A:" << endl;
        while(!(cin >> UM.xQuisteIzq) || cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            printf("ERROR - No ingresaste un n%cmero, int%cntelo otra vez\n", 163, 130);
            printf("Medida A:\n");
        }
        cout << "Medida B:" << endl;
        while(!(cin >> UM.yQuisteIzq) || cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            printf("ERROR - No ingresaste un n%cmero, int%cntelo otra vez\n", 163, 130);
            printf("Medida B:\n");
        }
        cout << "Medida C:" << endl;
        while(!(cin >> UM.zQuisteIzq) || cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            printf("ERROR - No ingresaste un n%cmero, int%cntelo otra vez\n", 163, 130);
            printf("Medida C:\n");
        }
        
        printf("\n%cTiene las medidas correctas?\n", 168);
        cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato." << endl;
        cin >> lesionesMamaIzq;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if ( (lesionesMamaIzq == "S") || (lesionesMamaIzq == "s")){
                UM.lesionesMamaIzq = true;
            }
        system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
        system("cls || clear");
    }
}

void lesionMamaDer(){
    UM.lesionesMamaDer = false;
    string lesionesMamaDer;
    while (UM.lesionesMamaDer == false){
        cout << "~ULTRASONIDO DE MAMAS~\n\n";
        printf("Ingrese las medidas del quiste derecho - Recuerda que en el documento se mostrar%c de la siguiente manera: A x B x C\n\n", 233, 160);
        cout << "Medida A:" << endl;
        while(!(cin >> UM.xQuisteDer) || cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            printf("ERROR - No ingresaste un n%cmero, int%cntelo otra vez\n", 163, 130);
            printf("Medida A:\n");
        }
        cout << "Medida B:" << endl;
        while(!(cin >> UM.yQuisteDer) || cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            printf("ERROR - No ingresaste un n%cmero, int%cntelo otra vez\n", 163, 130);
            printf("Medida B:\n");
        }
        cout << "Medida C:" << endl;
        while(!(cin >> UM.zQuisteDer) || cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            printf("ERROR - No ingresaste un n%cmero, int%cntelo otra vez\n", 163, 130);
            printf("Medida C:\n");
        }
        
        printf("\n%cTiene las medidas correctas?\n", 168);
        cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato." << endl;
        cin >> lesionesMamaDer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if ( (lesionesMamaDer == "S") || (lesionesMamaDer == "s")){
                UM.lesionesMamaDer = true;
            }
        system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
        system("cls || clear");
    }
}

void lesionesMamas(){
    int opc;
    cout << "~ULTRASONIDO DE MAMAS~\n\n";
    printf("%cAlguna de las mamas tiene lesiones?\n", 168);
    printf("1. S%clo la mama izquierda.\n", 162);
    printf("2. S%clo la mama derecha.\n", 162);
    printf("3. Ambas.\n");
    printf("4. Ninguna.\n");
    cout << " ---> "; cin >> opc;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch(opc){
        case 1: system("clear || cls"); lesionMamaIzq(); break;
        case 2: system("clear || cls"); lesionMamaDer(); break;
        case 3: system("clear || cls"); lesionMamaIzq(); lesionMamaDer(); break;
        case 4: system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s"); system("clear || cls"); break;
        default: 
            printf("ERROR - No ingresaste un n%cmero v%clido, int%cntelo otra vez\n", 163, 160, 130);
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("clear || cls");
            lesionesMamas(); 
            break;
    }
}

void conclusionesGen(){
    bool conclusionesGen = false;
    string opc;

    do {
        cout << "~ULTRASONIDO DE MAMAS~\n\n";
        cout << "Ingrese sus conclusiones generales del procedimiento." << endl;
        getline(cin, UM.conclusionesGen);
        printf("\n%cHa ingresado todo correctamente? Si es as%c, presione S o ingrese cualquier otra letra para ingresarlo nuevamente.\n", 168, 161);
        cin >> opc;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(opc == "S" || opc == "s"){
            conclusionesGen = true;
        }
        system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
        system("clear || cls");

    } while (conclusionesGen == false);
}

void BIRADS(){
    cout << "~ULTRASONIDO DE MAMAS~\n\n";
    cout << "Breast Imaging-Reporting and Data System (BI-RADS)" << endl;
    printf("Escala de 0 a 5. Ingrese el n%cmero correspondiente seg%cn las normas internacionales.\n", 163, 163);
    cout << " ---> ";
    cin >> UM.BIRADS;

    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("clear || cls");
        printf("ERROR - No ingresaste un n%cmero, int%cntelo otra vez\n\n", 163, 130);
        BIRADS();
    }
    else if (UM.BIRADS < 0 || UM.BIRADS > 5)
    {   
        system("clear || cls");
        printf("\nERROR - No ingresaste un n%cmero dentro del rango solicitado, int%cntelo otra vez.\n\n", 163, 130);
        BIRADS();
    }
        
}

void saveToFile(const UltMamas& UM) {
    ofstream UltrasonidoMamas("ultrasonido_mamas.txt");

    if (UltrasonidoMamas.is_open()) {
        UltrasonidoMamas << "Tejido Predominante Izquierdo: " << UM.tejidoPredominIzq << "\n";
        UltrasonidoMamas << "Cuadrantes Izquierdos:\n";
        UltrasonidoMamas << "  - Cuadrante 1: " << UM.cuadrante1Izq << "\n";
        UltrasonidoMamas << "  - Cuadrante 2: " << UM.cuadrante2Izq << "\n";
        UltrasonidoMamas << "  - Cuadrante 3: " << UM.cuadrante3Izq << "\n";
        UltrasonidoMamas << "  - Cuadrante 4: " << UM.cuadrante4Izq << "\n\n";

        UltrasonidoMamas << "Tejido Predominante Derecho: " << UM.tejidoPredominDer << "\n";
        UltrasonidoMamas << "Cuadrantes Derechos:\n";
        UltrasonidoMamas << "  - Cuadrante 1: " << UM.cuadrante1Der << "\n";
        UltrasonidoMamas << "  - Cuadrante 2: " << UM.cuadrante2Der << "\n";
        UltrasonidoMamas << "  - Cuadrante 3: " << UM.cuadrante3Der << "\n";
        UltrasonidoMamas << "  - Cuadrante 4: " << UM.cuadrante4Der << "\n\n";

        if(UM.lesionesMamaIzq == true){
            UltrasonidoMamas << "Lesiones Mama Izquierda (A x B x C): " << UM.xQuisteIzq << " x " << UM.yQuisteIzq << " x " << UM.zQuisteIzq << "\n\n";
        }
        if(UM.lesionesMamaDer == true){
            UltrasonidoMamas << "Lesiones Mama Derecha (A x B x C): " << UM.xQuisteDer << " x " << UM.yQuisteDer << " x " << UM.zQuisteDer << "\n\n";
        }

        UltrasonidoMamas << "Conclusiones Generales: " << UM.conclusionesGen << "\n";
        UltrasonidoMamas << "BIRADS: " << UM.BIRADS << "\n";

        UltrasonidoMamas.close();
        cout << "La informacion se ha guardado correctamente en el archivo 'ultrasonido_mamas.txt'.\n";
    } else {
        cout << "Error al abrir el archivo para escritura.\n";
    }
}

int main(){

    mamaIzq();
    mamaDer();
    lesionesMamas();
    conclusionesGen();
    BIRADS();
    saveToFile(UM);

    return 0;
}
