#include <iostream>
#include <string>
#include <fstream>
#include "6_paciente.cpp"

using namespace std;

bool obtenerInfoPaciente(const string& cedula, registroP& paciente) {
    ifstream archivoPacientes("pacientes.txt");

    if (archivoPacientes.is_open()) {
        string linea;
        while (getline(archivoPacientes, linea)) {
            registroP pacienteTemp;
            cargarRegistroDesdeLinea(linea, pacienteTemp);

            if (pacienteTemp.cedula == cedula) {
                paciente = pacienteTemp;
                archivoPacientes.close();
                return true; // La cédula existe en el archivo
            }
        }
        archivoPacientes.close();
    } else {
        cout << "Error al abrir el archivo 'pacientes.txt'" << endl;
    }

    return false; // La cédula no existe en el archivo
}

int main(){
    registroP paciente;
    UltPelv UP;
    string cedula;

    do {
            cout << "Introduzca la cédula del paciente: ";
            cin >> cedula;

            if (!obtenerInfoPaciente(cedula, paciente)) {
                cout << "La cédula no existe en el registro. Introduzca una cédula válida." << endl;
            } else {
                // Mostrar la información del paciente
                system("clear || cls");
                cout << "Información del Paciente:" << endl;
                cout << "Cédula: " << paciente.cedula << endl;
                cout << "Nombre: " << paciente.nombrePaciente.primerNombre << ' ' << paciente.nombrePaciente.segundoNombre << ' ' << paciente.nombrePaciente.primerApellido << ' ' << paciente.nombrePaciente.segundoApellido << endl;
                cout << "Fecha de nacimiento: " << paciente.fechas.nacimiento.dia << "/" << paciente.fechas.nacimiento.mes << "/" << paciente.fechas.nacimiento.anio << endl;
                cout << "Peso: " << paciente.peso << " lb" << endl;
                cout << "Altura: " << paciente.altura << " cm" << endl;
                cout << "Número de teléfono: " << paciente.num_celular << endl;
                cout << endl;
            }

        } while (!obtenerInfoPaciente(cedula, paciente));
    /* Ultrasonido Pelvico */

    printf("~ Ultrasonido P%clvico ~\n", 130);

    /* Inicio - Vejiga */
    
    cout << "Estado de las paredes de la Vejiga" << endl;
    cout << "1. Paredes Regulares." << endl;
    cout << "2. Paredes Engrosadas." << endl; // x
    cout << "3. Paredes con lesiones." << endl;
    cin >> UP.paredesVejiga;
    
    while ( (UP.paredesVejiga != 1) && (UP.paredesVejiga != 2) && (UP.paredesVejiga != 3) ){
            system("cls || clear");
            printf(" Error - Opci%cn no v%clida - Int%cntelo de nuevo\n", 162, 160, 130);
            printf("~ Ultrasonido P%clvico ~\n", 130);
            cout << "Estado de las paredes de la Vejiga" << endl;
            cout << "1. Paredes Regulares." << endl;
            cout << "2. Paredes Engrosadas." << endl; // x
            cout << "3. Paredes con lesiones." << endl;
            cin >> UP.paredesVejiga;        
        }

    int opcLesVej, cantQuiste, cantPolipos, engrosVeji;
    bool vejLesCompleto = false;
    bool estadoQuiste = false, estadoPolipos = false, estadoLesiones = false;
    string edit;

    switch (UP.paredesVejiga){
    case 1:
        system("cls || clear;");
        cout << "La paciente presenta Paredes Regulares - Guardado\n" << endl;
        cout << "Presione Enter para continuar" << endl;
        system("pause");
        system("cls || clear;");
        break;
    
    case 2:
        system("cls || clear;");
        cout << "Ingrese las medida del engrosamiento en mm" << endl;
        cin >> engrosVeji;
        cout << "Presione Enter para continuar" << endl;
        system("pause");
        system("cls || clear;");
        break;

    case 3:  
        while (vejLesCompleto == false){
        system("cls || clear");

        printf("%cQu%c lesiones presenta? - Si ya ingres%c la deseada NO la vuelva a ingresar al menos que desee editarla.\n", 168, 130, 162);
        cout << "1. Quiste";
        if (estadoQuiste == false){
            cout << " - Sin Info." << endl;
        } else{
            cout << " - Con Info." << endl;
        }

        cout << "2. Lesiones tumorales";  
        if (estadoLesiones == false){
            cout << " - Sin Info." << endl;
        } else{
            cout << " - Con Info." << endl;
        }
        
        printf("3. P%clipos\n", 162); // x * y
        if (estadoPolipos == false){
            cout << " - Sin Info." << endl;
        } else{
            cout << " - Con Info." << endl;
        }

        cout << "4. Salir\n" << endl;
        cout << "Recuerda que solamente tienes que Salir una vez hayas ingresado todos los datos." << endl;
        cin >> opcLesVej;

        system("cls || clear");
        
        switch (opcLesVej){
        case 1:
            if (estadoQuiste == false){
                
                printf("%cCu%cntos quistes vas a ingresar?\n", 168, 160);
                cin >> cantQuiste;
                system("cls || clear");

                for (int i = 0; i < cantQuiste; i++){
                    cout << "Ingrese la medida del quiste #" << i + 1 << " expresada en mm."<< endl;
                    printf("Recuerda que en el documento se mostrar%c de la siguiente manera: A x B x C\n\n", 160);
                    cout << "Medida A:" << endl;
                    cin >> UP.quisteX;
                    cout << "Medida B:" << endl;
                    cin >> UP.quisteY;
                    cout << "Medida C:" << endl;
                    cin >> UP.quisteZ;
                    cout << endl;
                }
                
                estadoQuiste = true;

                    printf("~ Presiona Enter para volver al men%c principal ~\n", 163);
                    system("pause");

            } else{
                printf("Ya agregaste informaci%cn sobre los quistes. %cDeseas cambiarla?\n", 162, 168);
                cout << "Ingresa S para editarla o cualquier otra letra para volver a ingresar el dato." << endl;
                cin >> edit;
                if ((edit == "S") || (edit == "s")){
                    printf("%cCu%cntos quistes vas a ingresar?\n", 168, 160);
                    cin >> cantQuiste; 
                    system("cls || clear");
                    for (int i = 0; i < cantQuiste; i++){
                        cout << "Ingrese la medida del quiste #" << i + 1 << " expresada en mm."<< endl; 
                        printf("Recuerda que en el documento se mostrar%c de la siguiente manera: A x B x C\n\n", 160);
                        cout << "Medida A:" << endl;
                        cin >> UP.quisteX;
                        cout << "Medida B:" << endl;
                        cin >> UP.quisteY;
                        cout << "Medida C:" << endl;
                        cin >> UP.quisteZ;
                        cout << endl;
                    }
                    printf("~ Presiona Enter para volver al men%c principal ~\n", 163);
                    system("pause");
                }
            }  
            break;
        
        case 2:
            if (estadoLesiones == false){
            
            estadoLesiones = true;
            } else{
                printf("Ya agregaste informaci%cn sobre las lesiones - Pulsa Enter para volver al Men%c Principal\n", 162, 163);
                system("pause");
            }
            
            break;

        case 3:
            if (estadoPolipos == false){
            
            printf("%cCu%cntos p%clipos vas a ingresar?\n", 168, 160, 162);
            cin >> cantPolipos;

            for (int i = 0; i < cantPolipos; i++){
                cout << "Ingrese la medida del polipo #" << i + 1<< endl;
                printf("Recuerda que en el documento se mostrar%c de la siguiente manera: A x B\n\n", 160);
                cout << "Medida A:" << endl;
                cin >> UP.polipoX;
                cout << "Medida B:" << endl;
                cin >> UP.polipoY;
            }

            estadoPolipos = true;
            printf("~ Presiona Enter para volver al men%c principal ~\n", 163);
            system("pause");

            } else{
                printf("Ya agregaste informaci%cn sobre los p%clipos. %cDeseas cambiarla?\n", 162, 162, 168);
                cout << "Ingresa S para editarla o cualquier otra letra para volver a ingresar el dato.." << endl;
                cin >> edit;
                if ((edit == "S") || (edit == "s")){
                    printf("%cCu%cntos p%clipos vas a ingresar?\n", 168, 160, 162);
                    cin >> cantPolipos; 
                    system("cls || clear");
                    for (int i = 0; i < cantPolipos; i++){
                        cout << "Ingrese la medida del polipo #" << i + 1 << " expresada en mm."<< endl; 
                        printf("Recuerda que en el documento se mostrar%c de la siguiente manera: A x B\n\n", 160);
                        cout << "Medida A:" << endl;
                        cin >> UP.polipoX;
                        cout << "Medida B:" << endl;
                        cin >> UP.polipoY;
                        cout << endl;
                    }
                    printf("~ Presiona Enter para volver al men%c principal ~\n", 163);
                    system("pause");
                }
            }
            break;

        case 4:
            vejLesCompleto = true;
            break;
        default:
            break;
        }
        }
        break;

    /*default:
        break; */
    }
    /* Final - Vejiga*/

    /* Inicio - Utero */
    bool posUteroComp = false;
    string estadoPosUt;

    while (posUteroComp == false){
        printf("%cCu%cl es la posici%cn del %ctero?\n", 168, 160, 162, 233);
        printf("1. En Anterversi%cn\n", 162);
        printf("2. En Retroversi%cn\n", 162);
        cin >> UP.posicionUtero;

        while ( (UP.posicionUtero != 1) && (UP.posicionUtero != 2)){
            system("cls || clear");
            printf("~ Opci%cn no v%clida - Ingrese una nueva ~\n", 162, 160);
            printf("%cCu%cl es la posici%cn del %ctero?\n", 168, 160, 162, 233);
            printf("1. En Anterversi%cn\n", 162);
            printf("2. En Retroversi%cn\n", 162);
            cin >> UP.posicionUtero;
        }
        
        if (UP.posicionUtero == 1){
            system("cls || clear");
            printf("Usted ha ingresado que el %ctero est%c en Anteversi%cn.\n\n", 233, 160, 162);
            printf("%cEst%c seguro de dejarlo de esta manera?\n", 168, 160);
            cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato." << endl;
            cin >> estadoPosUt;

            if ( (estadoPosUt == "S") || (estadoPosUt == "s")){
                posUteroComp = true;
            }
        } else{
            system("cls || clear");
            printf("Usted ha ingresado que el %ctero est%c en Retroversi%cn.\n\n", 233, 160, 162);
            printf("%cEst%c seguro de dejarlo de esta manera?\n", 168, 160);
            cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato." << endl;
            cin >> estadoPosUt;

            if ( (estadoPosUt == "S") || (estadoPosUt == "s")){
                posUteroComp = true;
            }
        }
        system("cls || clear");
    }
    
    bool estadoUteMed = false;
    string uteMedComp;

    while (estadoUteMed == false){
        printf("Ingrese las medidas del %ctero - Recuerda que en el documento se mostrar%c de la siguiente manera: A x B x C\n\n", 233, 160);
        cout << "Medida A:" << endl;
        cin >> UP.medidaUteroX;
        cout << "Medida B:" << endl;
        cin >> UP.medidaUteroY;
        cout << "Medida C:" << endl;
        cin >> UP.medidaUteroZ; 
        
        printf("%cTiene las medidas correctas?\n", 168);
        cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato.." << endl;
        cin >> uteMedComp;
            if ( (uteMedComp == "S") || (uteMedComp == "s")){
                estadoUteMed = true;
            }
        system("cls || clear");
    }

    bool estadoUteTam = false;
    string uteTamComp;

    while (estadoUteTam == false){  
        printf("%cCu%cl es el estado del %ctero seg%cn el tama%co?\n", 168, 160, 233, 163, 164);
        printf("1. %ctero Aumentado\n", 233);
        printf("2. %ctero Normal\n", 233);
        printf("3. %ctero Disminuido\n", 233);
        cin >> UP.segunTamanioUtero;
        
        while ( (UP.segunTamanioUtero != 1) && (UP.segunTamanioUtero != 2) && (UP.segunTamanioUtero != 3) ){
            system("cls || clear");
            printf(" Error - Opci%cn no v%clida - Int%cntelo de nuevo\n", 162, 160, 130);
            printf("%cCu%cl es el estado del %ctero seg%cn el tama%co?\n", 168, 160, 233, 163, 164);
            printf("1. %ctero Aumentado\n", 233);
            printf("2. %ctero Normal\n", 233);
            printf("3. %ctero Disminuido\n", 233);
            cin >> UP.segunTamanioUtero; 
        }
        printf("%cEst%c bien lo que ingres%c?\n", 168, 160, 162);
        cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato." << endl;
        cin >> uteTamComp;
            if ( (uteTamComp == "S") || (uteTamComp == "s")){
                estadoUteTam = true;
            }
        system("cls || clear");
    }

    bool estadoUteCont = false;
    string uteContComp;

    while (estadoUteCont == false){
        printf("%cC%cmo es el contorno del %ctero?\n", 168, 162, 233);
        cout << "1. Regulares" << endl;
        cout << "2. Irregulares" << endl;
        cin >> UP.contornoUtero;
        
        while ( (UP.contornoUtero != 1) && (UP.contornoUtero != 2) ){
            system("cls || clear");
            printf(" Error - Opci%cn no v%clida - Int%cntelo de nuevo\n", 162, 160, 130);  
            printf("%cC%cmo es el contorno del %ctero?\n", 168, 162, 233);
            cout << "1. Regulares" << endl;
            cout << "2. Irregulares" << endl;
            cin >> UP.contornoUtero; 
        }

        printf("\n%cEst%c seguro de dejar el dato as%c?\n", 168, 160, 161);
        cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato." << endl;
        cin >> uteContComp;
            if ( (uteContComp == "S") || (uteContComp == "s")){
                estadoUteCont = true;
            }
        system("cls || clear");
    }
    
    bool estadoMiomCont = false;
    string uteMioComp;

    while (estadoMiomCont == false){
        printf("%cC%cmo es el miometrio del %ctero?\n", 168, 162, 233);
        printf("1. Homog%cneo\n", 130);
        printf("2. Heterog%cneo\n", 130);
        cin >> UP.miometrioUtero;
        
        while ( (UP.miometrioUtero != 1) && (UP.miometrioUtero != 2) ){
            system("cls || clear");
            printf(" Error - Opci%cn no v%clida - Int%cntelo de nuevo\n", 162, 160, 130);  
            printf("%cC%cmo es el miometrio del %ctero?\n", 168, 162, 233);
            printf("1. Homog%cneo\n", 130);
            printf("2. Heterog%cneo\n", 130);
            cin >> UP.miometrioUtero; 
        }
        printf("\n%cEl dato del Miometrio que ingres%c es el correcto?\n", 168, 162);
        cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato." << endl;
        cin >> uteMioComp;
            if ( (uteMioComp == "S") || (uteMioComp == "s")){
                estadoMiomCont = true;
            }
        system("cls || clear");
    }

    /* Final - Utero */

    bool estadoHallUte = false;
    string uteHallComp;

    while (estadoHallUte == false){
        cout << "Ingrese su diagnostico escrito " << endl;
        cin >> UP.hallazgosUtero;
        cout << "\nHa ingresado todo correctamente?\nSi es asi presione S o ingrese cualquier otra letra para ingresarlo nuevamente." << endl;
        cin >> uteHallComp;
        if ((uteHallComp == "S") || (uteHallComp == "s")){
            estadoHallUte = true;
        }
        system("cls || clear");
    }
    
    bool medidaEndo = false;
    string medidaEndoComp;

    while (medidaEndo == false){
        cout << "Ingrese la medida del endometrio representada en mm" << endl;
        cin >> UP.medidaEndometrio;
        cout << "\nHa ingresado todo correctamente?\nSi es asi presione S o ingrese cualquier otra letra para ingresarlo nuevamente." << endl;
        cin >> medidaEndoComp;
        if ((medidaEndoComp == "S") || (medidaEndoComp == "s")){
            medidaEndo = true;
        }
        system("cls || clear");
    }
    
    bool medidaOvarIzq = false;
    string medidaOvarIzqComp;

    while (medidaOvarIzq == false){
        cout << "Ingrese las medidas del Ovario Izquierdo - Recuerda que en el documento se mostrara de la siguiente manera: A x B x C\n" << endl;
        cout << "Medida A:" << endl;
        cin >> UP.medidaOvarIzqX;
        cout << "Medida B:" << endl;
        cin >> UP.medidaOvarIzqY;
        cout << "Medida C:" << endl;
        cin >> UP.medidaOvarIzqZ; 
        cout << "\nIngrese su conclusion del Ovario Izquierdo: ";
        cin.ignore();
        cin >> UP.otrasCaractOvarIzq;
        
        cout << "\nTiene todos los datos correctos?" << endl;
        cout << "Ingrese S para si o cualquier otra letra para volver a ingresar los datos." << endl;
        cin >> medidaOvarIzqComp;
            if ( (medidaOvarIzqComp == "S") || (medidaOvarIzqComp == "s")){
                medidaOvarIzq = true;
            }
        system("cls || clear");
    }

    bool medidaOvarDer = false;
    string medidaOvarDerComp;

    while (medidaOvarDer == false){
        cout << "Ingrese las medidas del Ovario Derecho - Recuerda que en el documento se mostrara de la siguiente manera: A x B x C\n" << endl;
        cout << "Medida A:" << endl;
        cin >> UP.medidaOvarDerX;
        cout << "Medida B:" << endl;
        cin >> UP.medidaOvarDerY;
        cout << "Medida C:" << endl;
        cin >> UP.medidaOvarDerZ; 
        cout << "\nIngrese su conclusion del Ovario Derecho: ";
        cin >> UP.otrasCaractOvarDer;
        
        cout << "\nTiene todos los datos correctos?" << endl;
        cout << "Ingrese S para si o cualquier otra letra para volver a ingresar los datos." << endl;
        cin >> medidaOvarDerComp;
            if ( (medidaOvarDerComp == "S") || (medidaOvarDerComp == "s")){
                medidaOvarDer = true;
            }
        system("cls || clear");
    }

    bool sacoDouglas = false;
    string sacoDouglasComp;

    while (sacoDouglas == false){
        cout << "Como esta el Saco de Douglas?" << endl;
        cout << "1. Esta Libre de Liquido." << endl;
        cout << "2. No Esta Libre de Liquido." << endl;
        cin >> UP.sacoDouglas;

        while ( (UP.sacoDouglas != 1) && (UP.sacoDouglas != 2)){
            system("cls || clear");
            cout << "Como esta el Saco de Douglas?" << endl;
            cout << "1. Esta Libre de Liquido." << endl;
            cout << "2. No Esta Libre de Liquido." << endl;
            cin >> UP.sacoDouglas;
        }
        
        if (UP.sacoDouglas == 1){
            system("cls || clear");
            cout << "Usted ha ingresado que el Saco de Douglas esta libre de liquido.\n" << endl;
            cout << "Esta seguro de dejarlo de esta manera?" << endl;
            cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato." << endl;
            cin >> sacoDouglasComp;

            if ( (sacoDouglasComp == "S") || (sacoDouglasComp == "s")){
                sacoDouglas = true;
            }
        } else{
            system("cls || clear");
            cout << "Usted ha ingresado que el Saco de Douglas no esta libre de liquido.\n" << endl;
            cout << "Esta seguro de dejarlo de esta manera?" << endl;
            cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato." << endl;
            cin >> sacoDouglasComp;

            if ( (sacoDouglasComp == "S") || (sacoDouglasComp == "s")){
                sacoDouglas = true;
            }
        }
    }
    
    bool ConclusionesGen = false;
    string ConclusionesGenComp;

    while (ConclusionesGen == false){
        cout << "Ingrese sus conclusiones generales del procedimiento." << endl;
        cin >> UP.conclusionesGen;
        cout << "\nHa ingresado todo correctamente?\nSi es asi presione S o ingrese cualquier otra letra para ingresarlo nuevamente." << endl;
        cin >> ConclusionesGenComp;
        if ((ConclusionesGenComp == "S") || (ConclusionesGenComp == "s")){
            ConclusionesGen = true;
        }
        system("cls || clear");
    }
    
        ofstream archivoSalida("ultrasonidoPelvico.txt");

    if (archivoSalida.is_open()) {
        // Ahora puedes escribir los datos en el archivo
        archivoSalida << "Datos del Ultrasonido Pélvico" << endl;
        archivoSalida << "Cédula del paciente: " << cedula << endl;
        archivoSalida << "Estado de las paredes de la Vejiga: ";
        if (UP.paredesVejiga == 1) {
            archivoSalida << "Paredes Regulares" << endl;
        } else if (UP.paredesVejiga == 2) {
            archivoSalida << "Paredes Engrosadas (" << UP.paredesVejiga << " mm)" << endl;
        } else if (UP.paredesVejiga == 3) {
            archivoSalida << "Paredes con lesiones" << endl;
            // Aquí puedes agregar más detalles sobre las lesiones, quistes, polipos, etc.
        }

        archivoSalida << "Posición del Útero: ";
        if (UP.posicionUtero == 1) {
            archivoSalida << "Anteversión" << endl;
        } else if (UP.posicionUtero == 2) {
            archivoSalida << "Retroversión" << endl;
        }

        archivoSalida << "Medidas del Útero (A x B x C): " << UP.medidaUteroX << " x " << UP.medidaUteroY << " x " << UP.medidaUteroZ << " mm" << endl;

        archivoSalida << "Estado del Útero según el tamaño: ";
        if (UP.segunTamanioUtero == 1) {
            archivoSalida << "Útero Aumentado" << endl;
        } else if (UP.segunTamanioUtero == 2) {
            archivoSalida << "Útero Normal" << endl;
        } else if (UP.segunTamanioUtero == 3) {
            archivoSalida << "Útero Disminuido" << endl;
        }

        archivoSalida << "Contorno del Útero: ";
        if (UP.contornoUtero == 1) {
            archivoSalida << "Regulares" << endl;
        } else if (UP.contornoUtero == 2) {
            archivoSalida << "Irregulares" << endl;
        }

        archivoSalida << "Estado del Miometrio: ";
        if (UP.miometrioUtero == 1) {
            archivoSalida << "Homogéneo" << endl;
        } else if (UP.miometrioUtero == 2) {
            archivoSalida << "Heterogéneo" << endl;
        }

        archivoSalida << "Hallazgos generales en el Útero: " << UP.hallazgosUtero << endl;

        archivoSalida << "Medida del Endometrio: " << UP.medidaEndometrio << " mm" << endl;

        archivoSalida << "Medidas del Ovario Izquierdo (A x B x C): " << UP.medidaOvarIzqX << " x " << UP.medidaOvarIzqY << " x " << UP.medidaOvarIzqZ << endl;
        archivoSalida << "Medidas del Ovario Derecho (A x B x C): " << UP.medidaOvarDerX << " x " << UP.medidaOvarDerY << " x " << UP.medidaOvarDerZ << endl;

        archivoSalida << "Saco de Douglas: ";
        if (UP.sacoDouglas == 1) {
            archivoSalida << "Está libre de líquido" << endl;
        } else if (UP.sacoDouglas == 2) {
            archivoSalida << "No está libre de líquido" << endl;
        }

        archivoSalida << "Conclusiones generales del procedimiento: " << UP.conclusionesGen << endl;
        archivoSalida << "-----------------------------------------------------" << endl;

        archivoSalida.close(); // Cierra el archivo después de escribir

        cout << "Los datos se han guardado en el archivo ultrasonidoPelvico.txt" << endl;
    } else {
        cout << "Error al abrir el archivo para escritura." << endl;
    }

    return 0;
}