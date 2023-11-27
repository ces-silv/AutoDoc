#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <limits>
#include <ctime>
#include <iomanip>
#include <hpdf.h>
#include <vector>
#include "1_estructuras.h"

using namespace std;


void crearUT(){
    registroP paciente;
    UltTrans UT;
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

    printf("~ Ultrasonido Transvaginal ~\n");

    /* Inicio - Vejiga */
    bool compVeji = false;
    string estadParVeji;

    while (compVeji == false){
    cout << "Estado de las paredes de la Vejiga" << endl;
    cout << "1. Paredes Regulares." << endl;
    cout << "2. Paredes Engrosadas." << endl; // x
    cout << "3. Paredes con lesiones." << endl;
    cin >> UT.paredesVejiga;
    
        while ( (UT.paredesVejiga != 1) && (UT.paredesVejiga != 2) && (UT.paredesVejiga != 3) ){
                system("cls || clear");
                printf(" Error - Opci%cn no v%clida - Int%cntelo de nuevo\n", 162, 160, 130);
                printf("~ Ultrasonido P%clvico ~\n", 130);
                cout << "Estado de las paredes de la Vejiga" << endl;
                cout << "1. Paredes Regulares." << endl;
                cout << "2. Paredes Engrosadas." << endl; // x
                cout << "3. Paredes con lesiones." << endl;
                cin >> UT.paredesVejiga;        
                }

                if (UT.paredesVejiga == 1){
                system("cls || clear");
                cout << "Usted ha ingresado que las paredes de la vejiga son Regulares" << endl;
                printf("%cEst%c seguro de dejarlo de esta manera?\n", 168, 160);
                cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato." << endl;
                cin >> estadParVeji;
                    if ( (estadParVeji == "S") || (estadParVeji == "s")){compVeji = true;}  
                    } else if(UT.paredesVejiga == 2) {
                        system("cls || clear");
                        cout << "Usted ha ingresado que las paredes de la vejiga estan Engrosadas" << endl;
                        printf("%cEst%c seguro de dejarlo de esta manera?\n", 168, 160);
                        cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato." << endl;
                        cin >> estadParVeji;
                        if ( (estadParVeji == "S") || (estadParVeji == "s")){compVeji = true;}  
                    } else{
                            system("cls || clear");
                            cout << "Usted ha ingresado que las paredes de la vejiga presentan Lesiones" << endl;
                            printf("%cEst%c seguro de dejarlo de esta manera?\n", 168, 160);
                            cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato." << endl;
                            cin >> estadParVeji;
                            if ( (estadParVeji == "S") || (estadParVeji == "s")){compVeji = true;}
                        }
    }

    int opcLesVej, cantQuiste, cantPolipos, engrosVeji;
    bool vejLesCompleto = false;
    bool estadoQuiste = false, estadoPolipos = false, estadoLesiones = false;
    string edit;

    switch (UT.paredesVejiga){
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
                    cin >> UT.quisteX;
                    cout << "Medida B:" << endl;
                    cin >> UT.quisteY;
                    cout << "Medida C:" << endl;
                    cin >> UT.quisteZ;
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
                        cin >> UT.quisteX;
                        cout << "Medida B:" << endl;
                        cin >> UT.quisteY;
                        cout << "Medida C:" << endl;
                        cin >> UT.quisteZ;
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
                cin >> UT.polipoX;
                cout << "Medida B:" << endl;
                cin >> UT.polipoY;
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
                        cin >> UT.polipoX;
                        cout << "Medida B:" << endl;
                        cin >> UT.polipoY;
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
        cin >> UT.posicionUtero;

        while ( (UT.posicionUtero != 1) && (UT.posicionUtero != 2)){
            system("cls || clear");
            printf("~ Opci%cn no v%clida - Ingrese una nueva ~\n", 162, 160);
            printf("%cCu%cl es la posici%cn del %ctero?\n", 168, 160, 162, 233);
            printf("1. En Anterversi%cn\n", 162);
            printf("2. En Retroversi%cn\n", 162);
            cin >> UT.posicionUtero;
        }
        
        if (UT.posicionUtero == 1){
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
        cin >> UT.medidaUteroX;
        cout << "Medida B:" << endl;
        cin >> UT.medidaUteroY;
        cout << "Medida C:" << endl;
        cin >> UT.medidaUteroZ; 
        
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
        cin >> UT.segunTamanioUtero;
        
        while ( (UT.segunTamanioUtero != 1) && (UT.segunTamanioUtero != 2) && (UT.segunTamanioUtero != 3) ){
            system("cls || clear");
            printf(" Error - Opci%cn no v%clida - Int%cntelo de nuevo\n", 162, 160, 130);
            printf("%cCu%cl es el estado del %ctero seg%cn el tama%co?\n", 168, 160, 233, 163, 164);
            printf("1. %ctero Aumentado\n", 233);
            printf("2. %ctero Normal\n", 233);
            printf("3. %ctero Disminuido\n", 233);
            cin >> UT.segunTamanioUtero; 
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
        cin >> UT.contornoUtero;
        
        while ( (UT.contornoUtero != 1) && (UT.contornoUtero != 2) ){
            system("cls || clear");
            printf(" Error - Opci%cn no v%clida - Int%cntelo de nuevo\n", 162, 160, 130);  
            printf("%cC%cmo es el contorno del %ctero?\n", 168, 162, 233);
            cout << "1. Regulares" << endl;
            cout << "2. Irregulares" << endl;
            cin >> UT.contornoUtero; 
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
        cin >> UT.miometrioUtero;
        
        while ( (UT.miometrioUtero != 1) && (UT.miometrioUtero != 2) ){
            system("cls || clear");
            printf(" Error - Opci%cn no v%clida - Int%cntelo de nuevo\n", 162, 160, 130);  
            printf("%cC%cmo es el miometrio del %ctero?\n", 168, 162, 233);
            printf("1. Homog%cneo\n", 130);
            printf("2. Heterog%cneo\n", 130);
            cin >> UT.miometrioUtero; 
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
        cin >> UT.hallazgosUtero;
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
        cin >> UT.medidaEndometrio;
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
        cin >> UT.medidaOvarIzqX;
        cout << "Medida B:" << endl;
        cin >> UT.medidaOvarIzqY;
        cout << "Medida C:" << endl;
        cin >> UT.medidaOvarIzqZ; 
        cout << "\nIngrese su conclusion del Ovario Izquierdo: ";
        cin.ignore();
        cin >> UT.otrasCaractOvarIzq;
        
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
        cin >> UT.medidaOvarDerX;
        cout << "Medida B:" << endl;
        cin >> UT.medidaOvarDerY;
        cout << "Medida C:" << endl;
        cin >> UT.medidaOvarDerZ; 
        cout << "\nIngrese su conclusion del Ovario Derecho: ";
        cin >> UT.otrasCaractOvarDer;
        
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
        cin >> UT.sacoDouglas;

        while ( (UT.sacoDouglas != 1) && (UT.sacoDouglas != 2)){
            system("cls || clear");
            cout << "Como esta el Saco de Douglas?" << endl;
            cout << "1. Esta Libre de Liquido." << endl;
            cout << "2. No Esta Libre de Liquido." << endl;
            cin >> UT.sacoDouglas;
        }
        
        if (UT.sacoDouglas == 1){
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
        cin >> UT.conclusionesGen;
        cout << "\nHa ingresado todo correctamente?\nSi es asi presione S o ingrese cualquier otra letra para ingresarlo nuevamente." << endl;
        cin >> ConclusionesGenComp;
        if ((ConclusionesGenComp == "S") || (ConclusionesGenComp == "s")){
            ConclusionesGen = true;
        }
        system("cls || clear");
    }

        ofstream archivoSalida("ultrasonidoTransvaginal.txt", ios :: app);

    if (archivoSalida.is_open()) {
        // Primero, escribimos la información del paciente en el archivo
        archivoSalida << "Información del Paciente:" << endl;
        archivoSalida << "Cédula: " << paciente.cedula << endl;
        archivoSalida << "Nombre: " << paciente.nombrePaciente.primerNombre << ' ' << paciente.nombrePaciente.segundoNombre << ' ' << paciente.nombrePaciente.primerApellido << ' ' << paciente.nombrePaciente.segundoApellido << endl;
        archivoSalida << "Fecha de nacimiento: " << paciente.fechas.nacimiento.dia << "/" << paciente.fechas.nacimiento.mes << "/" << paciente.fechas.nacimiento.anio << endl;
        archivoSalida << "Peso: " << paciente.peso << " lb" << endl;
        archivoSalida << "Altura: " << paciente.altura << " cm" << endl;
        archivoSalida << "Número de teléfono: " << paciente.num_celular << endl;
        archivoSalida << "-----------------------------------------------------" << endl;
        // Ahora puedes escribir los datos en el archivo
        archivoSalida << "Datos del Ultrasonido Transvaginal" << endl;
        archivoSalida << "Cédula del paciente: " << cedula << endl;
        archivoSalida << "Estado de las paredes de la Vejiga: ";
        if (UT.paredesVejiga == 1) {
            archivoSalida << "Paredes Regulares" << endl;
        } else if (UT.paredesVejiga == 2) {
            archivoSalida << "Paredes Engrosadas (" << UT.paredesVejiga << " mm)" << endl;
        } else if (UT.paredesVejiga == 3) {
            archivoSalida << "Paredes con lesiones" << endl;
            // Aquí puedes agregar más detalles sobre las lesiones, quistes, polipos, etc.
        }

        archivoSalida << "Posición del Útero: ";
        if (UT.posicionUtero == 1) {
            archivoSalida << "Anteversión" << endl;
        } else if (UT.posicionUtero == 2) {
            archivoSalida << "Retroversión" << endl;
        }

        archivoSalida << "Medidas del Útero (A x B x C): " << UT.medidaUteroX << " x " << UT.medidaUteroY << " x " << UT.medidaUteroZ << " mm" << endl;

        archivoSalida << "Estado del Útero según el tamaño: ";
        if (UT.segunTamanioUtero == 1) {
            archivoSalida << "Útero Aumentado" << endl;
        } else if (UT.segunTamanioUtero == 2) {
            archivoSalida << "Útero Normal" << endl;
        } else if (UT.segunTamanioUtero == 3) {
            archivoSalida << "Útero Disminuido" << endl;
        }

        archivoSalida << "Contorno del Útero: ";
        if (UT.contornoUtero == 1) {
            archivoSalida << "Regulares" << endl;
        } else if (UT.contornoUtero == 2) {
            archivoSalida << "Irregulares" << endl;
        }

        archivoSalida << "Estado del Miometrio: ";
        if (UT.miometrioUtero == 1) {
            archivoSalida << "Homogéneo" << endl;
        } else if (UT.miometrioUtero == 2) {
            archivoSalida << "Heterogéneo" << endl;
        }

        archivoSalida << "Hallazgos generales en el Útero: " << UT.hallazgosUtero << endl;

        archivoSalida << "Medida del Endometrio: " << UT.medidaEndometrio << " mm" << endl;

        archivoSalida << "Medidas del Ovario Izquierdo (A x B x C): " << UT.medidaOvarIzqX << " x " << UT.medidaOvarIzqY << " x " << UT.medidaOvarIzqZ << endl;
        archivoSalida << "Medidas del Ovario Derecho (A x B x C): " << UT.medidaOvarDerX << " x " << UT.medidaOvarDerY << " x " << UT.medidaOvarDerZ << endl;

        archivoSalida << "Saco de Douglas: ";
        if (UT.sacoDouglas == 1) {
            archivoSalida << "Está libre de líquido" << endl;
        } else if (UT.sacoDouglas == 2) {
            archivoSalida << "No está libre de líquido" << endl;
        }

        archivoSalida << "Conclusiones generales del procedimiento: " << UT.conclusionesGen << endl;
        archivoSalida << "-----------------------------------------------------" << endl;

        archivoSalida.close(); // Cierra el archivo después de escribir

        cout << "Los datos se han guardado en el archivo ultrasonidoPelvico.txt" << endl;
    } else {
        cout << "Error al abrir el archivo para escritura." << endl;
    }

}

string convertirMin(const string& str) {
    string minStr;
    for (char c : str) {
        minStr += tolower(static_cast<unsigned char>(c));
    }
    return minStr;
}

bool buscarRegistroPorNombreCompleto(const string& nombreBuscado) {
    ifstream archivo("ultrasonidoTransvaginal.txt");
    string linea;
    bool encontrado = false;

    string nombreBuscadoLower = convertirMin(nombreBuscado);

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            // Encuentra la línea que comienza con "Nombre: "
            if (convertirMin(linea).find("nombre: ") != string::npos) {
                string nombreCompleto = linea.substr(linea.find(":") + 2); // Extrae el nombre completo
                if (convertirMin(nombreCompleto).find(nombreBuscadoLower) != string::npos) {
                    // Mostrar detalles del registro encontrado
                    cout << linea << endl; // Muestra la línea con el nombre
                    for (int i = 0; i < 19; ++i) { // Asumiendo que los siguientes 19 líneas son del registro
                        getline(archivo, linea);
                        cout << linea << endl;
                    }
                    encontrado = true;
                    break;
                }
            }
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para lectura." << endl;
    }
    return encontrado;
}

void mostrarMenu() {
    int opcion;
    string nombreBuscado;

    do {
        cout << "Menú de Opciones:" << endl;
        cout << "1. Crear un nuevo procedimiento de ultrasonido transvaginal" << endl;
        cout << "2. Buscar un procedimiento por nombre del paciente" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                crearUT();
                break;
            case 2:
                cout << "Ingrese el nombre completo del paciente a buscar: ";
                cin.ignore(); // Limpia el buffer de entrada
                getline(cin, nombreBuscado);
                if (!buscarRegistroPorNombreCompleto(nombreBuscado)) {
                    cout << "Registro no encontrado." << endl;
                }
                break;
            case 3:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 3);
}