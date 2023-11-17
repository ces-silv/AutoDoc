#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <limits>
#include "3_estructuras.h"

using namespace std;

UltMamas UM;
void mamaIzq(UltMamas &UM);
void mamaDer(UltMamas &UM);
void lesionesMamas(UltMamas &UM);
void lesionMamaIzq(UltMamas &UM);
void lesionMamaDer(UltMamas &UM);
void conclusionesGen(UltMamas &UM);
void BIRADS(UltMamas &UM);
void asignarProcedimientoAPaciente(UltMamas &UM);
void guardarInformacionEnArchivo(const UltMamas &UM);


void mamaIzq(UltMamas &UM){
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

void mamaDer(UltMamas &UM){
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

void lesionMamaIzq(UltMamas &UM){
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

void lesionMamaDer(UltMamas &UM){
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

void lesionesMamas(UltMamas &UM){
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

void conclusionesGen(UltMamas &UM){
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

void BIRADS(UltMamas &UM){
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

void asignarProcedimientoAPaciente(UltMamas &UM) {
    cout << "Ingrese la cedula del paciente: ";
    cin >> UM.Paciente.cedula;

    // Abrir el archivo de pacientes para lectura
    ifstream pacientesFile("pacientes.txt");
    if (!pacientesFile.is_open()) {
        cerr << "Error al abrir el archivo de pacientes." << endl;
        exit(EXIT_FAILURE);
    }

    // Buscar al paciente por cedula y cargar su información
    string line;
    while (getline(pacientesFile, line)) {
        if (line.find(UM.Paciente.cedula) == 0) {
            // Suponiendo que la estructura del archivo de pacientes es: cedula,primerNombre,segundoNombre,primerApellido,segundoApellido,altura,peso,num_celular,nacimiento.dia,nacimiento.mes,nacimiento.anio
            stringstream ss(line);
            string token;
            getline(ss, token, ','); // cedula
            getline(ss, UM.Paciente.nombrePaciente.primerNombre, ',');
            getline(ss, UM.Paciente.nombrePaciente.segundoNombre, ',');
            getline(ss, UM.Paciente.nombrePaciente.primerApellido, ',');
            getline(ss, UM.Paciente.nombrePaciente.segundoApellido, ',');
            ss >> UM.Paciente.altura;
            ss.ignore(1, ',');
            ss >> UM.Paciente.peso;
            ss.ignore(1, ',');
            getline(ss, UM.Paciente.num_celular, ',');
            ss >> UM.Paciente.fechas.nacimiento.dia;
            ss.ignore(1, ',');
            ss >> UM.Paciente.fechas.nacimiento.mes;
            ss.ignore(1, ',');
            ss >> UM.Paciente.fechas.nacimiento.anio;

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

void guardarInformacionEnArchivo(const UltMamas &UM) {
    ofstream archivo("ultrasonidoMamas.txt");

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para escritura." << endl;
        exit(EXIT_FAILURE);
    }

    // Guardar la información en el archivo
    archivo << "Cedula del paciente: " << UM.Paciente.cedula << endl;
    archivo << "Nombre del paciente: " << UM.Paciente.nombrePaciente.primerNombre << " " << UM.Paciente.nombrePaciente.segundoNombre
    << " " << UM.Paciente.nombrePaciente.primerApellido << " " << UM.Paciente.nombrePaciente.segundoApellido << "\n\n";

    archivo << "Tejido predominante (mama izquierda): " << UM.tejidoPredominIzq << endl;
    archivo << "Cuadrantes izquierdos: " << endl;
    archivo << " - Cuadrante 1: " << UM.cuadrante1Izq << endl;
    archivo << " - Cuadrante 2: " << UM.cuadrante2Izq << endl;
    archivo << " - Cuadrante 3: " << UM.cuadrante3Izq << endl; 
    archivo << " - Cuadrante 4: " << UM.cuadrante4Izq << "\n\n";

    archivo << "Tejido predominante (mama derecha): " << UM.tejidoPredominDer << endl;
    archivo << "Cuadrantes derechos: " << endl;
    archivo << " - Cuadrante 1: " << UM.cuadrante1Der << endl;
    archivo << " - Cuadrante 2: " << UM.cuadrante2Der << endl;
    archivo << " - Cuadrante 3: " << UM.cuadrante3Der << endl; 
    archivo << " - Cuadrante 4: " << UM.cuadrante4Der << "\n\n";

    if (UM.lesionesMamaIzq == true) {
        archivo << "Lesiones en mama izquierda: Sí" << endl;
        archivo << "Medidas del quiste izquierdo (A x B x C): " << UM.xQuisteIzq << " x " << UM.yQuisteIzq << " x " << UM.zQuisteIzq << endl;
    } else {
        archivo << "Lesiones en mama izquierda: No" << endl;
    }
    if (UM.lesionesMamaDer == true) {
        archivo << "Lesiones en mama derecha: Sí" << endl;
        archivo << "Medidas del quiste derecho (A x B x C): " << UM.xQuisteIzq << " x " << UM.yQuisteIzq << " x " << UM.zQuisteIzq << endl;
    } else {
        archivo << "Lesiones en mama derecha: No" << endl;
    }

    archivo << "Conclusiones generales: " << UM.conclusionesGen << endl;
    archivo << "BI-RADS: " << UM.BIRADS << endl;
    archivo << "Fecha de realizacion: " << UM.Paciente.fechas.realizacion.dia << "/" << UM.Paciente.fechas.realizacion.mes << "/" << UM.Paciente.fechas.realizacion.anio << endl;

    // Agrega el resto de la información que desees guardar

    archivo.close();
    cout << "La informacion se ha guardado correctamente en el archivo 'ultrasonidoMamas.txt'.\n";
}

int main(){
    UltMamas UM;
    asignarProcedimientoAPaciente(UM);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    mamaIzq(UM);
    mamaDer(UM);
    lesionesMamas(UM);
    conclusionesGen(UM);
    BIRADS(UM);

    // Guardar la información en un archivo
    guardarInformacionEnArchivo(UM);

    return 0;
}