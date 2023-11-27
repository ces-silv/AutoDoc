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


void UT(){
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
        getline(cin, UT.otrasCaractOvarIzq);
        
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
        getline(cin, UT.conclusionesGen);
        cout << "\nHa ingresado todo correctamente?\nSi es asi presione S o ingrese cualquier otra letra para ingresarlo nuevamente." << endl;
        cin >> ConclusionesGenComp;
        if ((ConclusionesGenComp == "S") || (ConclusionesGenComp == "s")){
            ConclusionesGen = true;
        }
        system("cls || clear");
    }

    time_t tiempoActual = time(nullptr);
    tm* tiempoLocal = localtime(&tiempoActual);

    UT.Paciente.fechas.realizacion.dia = tiempoLocal->tm_mday;
    UT.Paciente.fechas.realizacion.mes = tiempoLocal->tm_mon + 1; // tm_mon está en el rango 0-11
    UT.Paciente.fechas.realizacion.anio = tiempoLocal->tm_year + 1900; // tm_year es el año desde 1900

    HPDF_Doc pdf;
    HPDF_Page page;
    HPDF_Font font;
    string full_text = "";

    // Crear el objeto HPDF_Doc
    pdf = HPDF_New(error_handler, NULL);
    if (!pdf) {
        cout << "Error al inicializar el documento PDF" << endl;
        return;
    }

    // Crear la primera página del documento
    page = HPDF_AddPage(pdf);
    if (!page) {
        cout << "Error al agregar la página al documento" << endl;
        HPDF_Free(pdf);
        return;
    }

    HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_LETTER, HPDF_PAGE_PORTRAIT);

    // Obtener el objeto HPDF_Font
    font = HPDF_GetFont(pdf, "Helvetica", NULL);

    // Dibujar el texto respetando los límites de la página
    float font_size = 12;
    float margin = 50;
    float line_spacing = 10.0f;  // Espacio adicional entre líneas

    const float header_spacing = 20.0f;
    const float footer_spacing = 20.0f;

    // Establecer límites de texto
    float max_width = HPDF_Page_GetWidth(page) - 2 * margin;
    float max_height = HPDF_Page_GetHeight(page) - 2 * margin;

    string footer_text = "";
    footer_text += "                                                  Dr. Carlos Ernesto Silva Bustos\n";
    footer_text += "                                          Especialista en Ginecologia y Obstetricia\n";
    footer_text += "                                                            Ultrasonografista\n";
    footer_text += "                                                              Colposcopista\n";
    footer_text += "                                                        Codigo minsa 12962";

    string header_text = "";
    header_text += "                                              CLINICA MEDICA ESPERANZA\n";
    header_text += "                                               ULTRASONIDO TRANSVAGINAL\n\n";

    full_text += "Cedula: " + cedula + "\n";
    full_text += "Nombre: " + paciente.nombrePaciente.primerNombre + " " + paciente.nombrePaciente.segundoNombre + " " + paciente.nombrePaciente.primerApellido + " " + paciente.nombrePaciente.segundoApellido + "\n";
    full_text += "Fecha: " + to_string(UT.Paciente.fechas.realizacion.dia) + "/" + to_string(UT.Paciente.fechas.realizacion.mes) + "/" + to_string(UT.Paciente.fechas.realizacion.anio) + "\n\n";

    full_text += "Estado de las paredes de la Vejiga: ";
        if (UT.paredesVejiga == 1) {
            full_text += "Paredes Regulares.\n";
        } else if (UT.paredesVejiga == 2) {
            full_text += "Paredes Engrosadas (" + to_string(UT.paredesVejiga) + " mm).\n";
        } else if (UT.paredesVejiga == 3) {
            full_text += "Paredes con lesiones.\n";
        }

    full_text += "Posicion del Utero: ";
        if (UT.posicionUtero == 1) {
            full_text += "Anteversion.\n";
        } else if (UT.posicionUtero == 2) {
            full_text += "Retroversion.\n";
        }

    full_text += "Medidas del Utero (A x B x C): " + to_string(UT.medidaUteroX) + " x " + to_string(UT.medidaUteroY) + " x " + to_string(UT.medidaUteroZ) + " mm\n";

    full_text += "Estado del Utero segun su medida: ";
        if (UT.segunTamanioUtero == 1) {
            full_text += "Utero Aumentado.\n";
        } else if (UT.segunTamanioUtero == 2) {
            full_text += "Utero Normal.\n";
        } else if (UT.segunTamanioUtero == 3) {
            full_text += "Utero Disminuido.\n";
        }
    full_text += "Contorno del Utero: ";
        if (UT.contornoUtero == 1) {
            full_text += "Regulares.\n";
        } else if (UT.contornoUtero == 2) {
            full_text += "Irregulares.\n";
        }

    full_text += "Contorno del Utero: ";
        if (UT.contornoUtero == 1) {
            full_text += "Regulares.\n";
        } else if (UT.contornoUtero == 2) {
            full_text += "Irregulares.\n";
        }

        full_text += "Estado del Miometrio: ";
        if (UT.miometrioUtero == 1) {
            full_text += "Homogeneo.\n";
        } else if (UT.miometrioUtero == 2) {
            full_text += "Heterogeneo.\n";
        }

        full_text += "Hallazgos generales en el Utero: " + UT.hallazgosUtero + "\n";

        full_text += "Medida del Endometrio: " + to_string(UT.medidaEndometrio) + " mm\n";

        full_text += "Medidas del Ovario Izquierdo (A x B x C): " + to_string(UT.medidaOvarIzqX) + " x " + to_string(UT.medidaOvarIzqY) + " x " + to_string(UT.medidaOvarIzqZ) + " mm\n";
        full_text += "Medidas del Ovario Derecho (A x B x C): " + to_string(UT.medidaOvarDerX) + " x " + to_string(UT.medidaOvarDerY) + " x " + to_string(UT.medidaOvarDerZ) + " mm\n";
        full_text += "Saco de Douglas: ";
        if (UT.sacoDouglas == 1) {
            full_text += "Esta libre de liquido.\n";
        } else if (UT.sacoDouglas == 2) {
            full_text += "No esta libre de liquido.\n";
        }

        full_text += "\nConclusiones generales del procedimiento: " + UT.conclusionesGen + "\n";

    draw_text_with_header_and_footer(page, font, full_text, margin, HPDF_Page_GetHeight(page) - margin, HPDF_Page_GetWidth(page) - 2 * margin, font_size, line_spacing, header_text, footer_text, header_spacing, footer_spacing);

    ostringstream formatoFecha; //es declarado para construir la cadena de caracteres

    formatoFecha << setw(2) << setfill('0') << tiempoLocal->tm_mday << "_" << setw(2) << setfill('0') << (tiempoLocal->tm_mon + 1) << "_"<< (tiempoLocal->tm_year + 1900);
    //se define dia y mes en 2 digitos, rellenando a la izquierda en caso que falte, por ejemplo el primero de enero de 2023 se guardaria como 01_01_2023
    //se le suma 1900 para que de la fecha actual ya que estamos usando formato unix

    string fechaActual = ("C:/Users/user/OneDrive/Escritorio/AutoDoc/" + cedula + "/UT/" + formatoFecha.str() + ".pdf").c_str();

    // Guardar el documento en un archivo
    HPDF_SaveToFile(pdf, fechaActual.c_str());

    cin.ignore();

    cout << fechaActual;
    // Guardar el documento en un archivo
    system("pause");
    system("cls");
    // Liberar recursos
    menuPrincipal();

}
