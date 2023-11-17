#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <limits>
#include "estructuras.h"

using namespace std;

UltMamas UM;
void mamaIzq(UltMamas &um);
void mamaDer(UltMamas &um);
void lesionesMamas(UltMamas &um);
void lesionMamaIzq(UltMamas &um);
void lesionMamaDer(UltMamas &um);
void conclusionesGen(UltMamas &um);
void BIRADS(UltMamas &um);


void mamaIzq(UltMamas &um){
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

void mamaDer(UltMamas &um){
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

void lesionMamaIzq(UltMamas &um){
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

void lesionMamaDer(UltMamas &um){
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

void lesionesMamas(UltMamas &um){
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
        case 1: system("clear || cls"); lesionMamaIzq(UM); break;
        case 2: system("clear || cls"); lesionMamaDer(UM); break;
        case 3: system("clear || cls"); lesionMamaIzq(UM); lesionMamaDer(UM); break;
        case 4: system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s"); system("clear || cls"); break;
        default: 
            printf("ERROR - No ingresaste un n%cmero v%clido, int%cntelo otra vez\n", 163, 160, 130);
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("clear || cls");
            lesionesMamas(UM); 
            break;
    }
}

void conclusionesGen(UltMamas &um){
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

void BIRADS(UltMamas &um){
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
        BIRADS(UM);
    }
    else if (UM.BIRADS < 0 || UM.BIRADS > 5)
    {   
        system("clear || cls");
        printf("\nERROR - No ingresaste un n%cmero dentro del rango solicitado, int%cntelo otra vez.\n\n", 163, 130);
        BIRADS(UM);
    }
        
}

void asignarProcedimientoAPaciente(UltMamas &um) {
    cout << "Ingrese la cedula del paciente: ";
    cin >> um.Paciente.cedula;

    // Abrir el archivo de pacientes para lectura
    ifstream pacientesFile("pacientes.txt");
    if (!pacientesFile.is_open()) {
        cerr << "Error al abrir el archivo de pacientes." << endl;
        exit(EXIT_FAILURE);
    }

    // Buscar al paciente por cedula y cargar su información
    string line;
    while (getline(pacientesFile, line)) {
        if (line.find(um.Paciente.cedula) == 0) {
            // Suponiendo que la estructura del archivo de pacientes es: cedula,primerNombre,segundoNombre,primerApellido,segundoApellido,altura,peso,num_celular,nacimiento.dia,nacimiento.mes,nacimiento.anio
            stringstream ss(line);
            string token;
            getline(ss, token, ','); // cedula
            getline(ss, um.Paciente.nombrePaciente.primerNombre, ',');
            getline(ss, um.Paciente.nombrePaciente.segundoNombre, ',');
            getline(ss, um.Paciente.nombrePaciente.primerApellido, ',');
            getline(ss, um.Paciente.nombrePaciente.segundoApellido, ',');
            ss >> um.Paciente.altura;
            ss.ignore(1, ',');
            ss >> um.Paciente.peso;
            ss.ignore(1, ',');
            getline(ss, um.Paciente.num_celular, ',');
            ss >> um.Paciente.fechas.nacimiento.dia;
            ss.ignore(1, ',');
            ss >> um.Paciente.fechas.nacimiento.mes;
            ss.ignore(1, ',');
            ss >> um.Paciente.fechas.nacimiento.anio;

            // Cerrar el archivo de pacientes
            pacientesFile.close();
            return;
        }
    }

    // Si llega aquí, no se encontró al paciente
    cerr << "Paciente no encontrado." << endl;
    pacientesFile.close();
    exit(EXIT_FAILURE);
}

void guardarInformacionEnArchivo(const UltMamas &um) {
    ofstream archivo("informacion_procedimiento.txt");

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para escritura." << endl;
        exit(EXIT_FAILURE);
    }

    // Guardar la información en el archivo
    archivo << "Cedula del paciente: " << um.Paciente.cedula << endl;
    archivo << "Tejido predominante (mama izquierda): " << um.tejidoPredominIzq << endl;
    archivo << "Cuadrantes (mama izquierda): " << um.cuadrante1Izq << ", " << um.cuadrante2Izq << ", " << um.cuadrante3Izq << ", " << um.cuadrante4Izq << endl;
    archivo << "Tejido predominante (mama derecha): " << um.tejidoPredominDer << endl;
    archivo << "Cuadrantes (mama derecha): " << um.cuadrante1Der << ", " << um.cuadrante2Der << ", " << um.cuadrante3Der << ", " << um.cuadrante4Der << endl;
    archivo << "Lesiones en mama izquierda: " << (um.lesionesMamaIzq ? "Sí" : "No") << endl;
    if (um.lesionesMamaIzq) {
        archivo << "Medidas del quiste izquierdo (A x B x C): " << um.xQuisteIzq << " x " << um.yQuisteIzq << " x " << um.zQuisteIzq << endl;
    }
    archivo << "Lesiones en mama derecha: " << (um.lesionesMamaDer ? "Sí" : "No") << endl;
    if (um.lesionesMamaDer) {
        archivo << "Medidas del quiste derecho (A x B x C): " << um.xQuisteDer << " x " << um.yQuisteDer << " x " << um.zQuisteDer << endl;
    }
    archivo << "Conclusiones generales: " << um.conclusionesGen << endl;
    archivo << "BI-RADS: " << um.BIRADS << endl;
    archivo << "Fecha de realizacion: " << um.Paciente.fechas.realizacion.dia << "/" << um.Paciente.fechas.realizacion.mes << "/" << um.Paciente.fechas.realizacion.anio << endl;

    // Agrega el resto de la información que desees guardar

    archivo.close();
}

int main(){
    UltMamas UM;
    asignarProcedimientoAPaciente(UM);
    mamaIzq(UM);
    mamaDer(UM);
    lesionesMamas(UM);
    conclusionesGen(UM);
    BIRADS(UM);

    // Guardar la información en un archivo
    guardarInformacionEnArchivo(UM);

    return 0;
}