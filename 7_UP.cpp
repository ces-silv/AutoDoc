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


void UP(){
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

    printf("~ Ultrasonido Pélvico ~\n");

    /* Inicio - Vejiga */
    bool compVeji = false;
    string estadParVeji;

    while (compVeji == false){
    cout << "Estado de las paredes de la Vejiga" << endl;
    cout << "1. Paredes Regulares." << endl;
    cout << "2. Paredes Engrosadas." << endl; // x
    cout << "3. Paredes con lesiones." << endl;
    cin >> UP.paredesVejiga;
    
        while ( (UP.paredesVejiga != 1) && (UP.paredesVejiga != 2) && (UP.paredesVejiga != 3) ){
                system("cls || clear");
                printf(" Error - Opción no válida - Inténtelo de nuevo\n");
                printf("~ Ultrasonido Pélvico ~\n");
                cout << "Estado de las paredes de la Vejiga" << endl;
                cout << "1. Paredes Regulares." << endl;
                cout << "2. Paredes Engrosadas." << endl; // x
                cout << "3. Paredes con lesiones." << endl;
                cin >> UP.paredesVejiga;        
                }

                if (UP.paredesVejiga == 1){
                system("cls || clear");
                cout << "Usted ha ingresado que las paredes de la vejiga son Regulares" << endl;
                printf("¿Estás seguro de dejarlo de esta manera?\n");
                cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato." << endl;
                cin >> estadParVeji;
                    if ( (estadParVeji == "S") || (estadParVeji == "s")){compVeji = true;}  
                    } else if(UP.paredesVejiga == 2) {
                        system("cls || clear");
                        cout << "Usted ha ingresado que las paredes de la vejiga estan Engrosadas" << endl;
                        printf("¿Está seguro de dejarlo de esta manera?\n");
                        cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato." << endl;
                        cin >> estadParVeji;
                        if ( (estadParVeji == "S") || (estadParVeji == "s")){compVeji = true;}  
                    } else{
                            system("cls || clear");
                            cout << "Usted ha ingresado que las paredes de la vejiga presentan Lesiones" << endl;
                            printf("¿Está seguro de dejarlo de esta manera?\n");
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
        printf("¿Cuál es la posición del útero?\n");
        printf("1. En Anterversión\n");
        printf("2. En Retroversión\n");
        cin >> UP.posicionUtero;

        while ( (UP.posicionUtero != 1) && (UP.posicionUtero != 2)){
            system("cls || clear");
            printf("~ Opción no válida - Ingrese una nueva ~\n");
            printf("¿Cuál es la posición del útero?\n");
            printf("1. En Anterversión\n");
            printf("2. En Retroversión\n");
            cin >> UP.posicionUtero;
        }
        
        if (UP.posicionUtero == 1){
            system("cls || clear");
            printf("Usted ha ingresado que el útero está en Anteversión.\n\n");
            printf("¿Está seguro de dejarlo de esta manera?\n");
            cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato." << endl;
            cin >> estadoPosUt;

            if ( (estadoPosUt == "S") || (estadoPosUt == "s")){
                posUteroComp = true;
            }
        } else{
            system("cls || clear");
            printf("Usted ha ingresado que el útero está en Retroversión.\n\n");
            printf("¿Está seguro de dejarlo de esta manera?\n");
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
        printf("Ingrese las medidas del útero - Recuerda que en el documento se mostrará de la siguiente manera: A x B x C\n\n");
        cout << "Medida A:" << endl;
        cin >> UP.medidaUteroX;
        cout << "Medida B:" << endl;
        cin >> UP.medidaUteroY;
        cout << "Medida C:" << endl;
        cin >> UP.medidaUteroZ; 
        
        printf("¿Tiene las medidas correctas?\n");
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
        printf("¿Cuál es el estado del útero según el tamaño?\n");
        printf("1. Útero Aumentado\n");
        printf("2. Úctero Normal\n");
        printf("3. Útero Disminuido\n");
        cin >> UP.segunTamanioUtero;
        
        while ( (UP.segunTamanioUtero != 1) && (UP.segunTamanioUtero != 2) && (UP.segunTamanioUtero != 3) ){
            system("cls || clear");
            printf(" Error - Opción no válida - Inténtelo de nuevo\n");
            printf("¿Cuál es el estado del útero según el tamaño?\n");
            printf("1. Útero Aumentado\n");
            printf("2. Útero Normal\n");
            printf("3. Útero Disminuido\n");
            cin >> UP.segunTamanioUtero; 
        }
        printf("¿Está bien lo que ingresó?\n");
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
        printf("¿Cómo es el contorno del útero?\n");
        cout << "1. Regulares" << endl;
        cout << "2. Irregulares" << endl;
        cin >> UP.contornoUtero;
        
        while ( (UP.contornoUtero != 1) && (UP.contornoUtero != 2) ){
            system("cls || clear");
            printf(" Error - Opción no válida - Inténtelo de nuevo\n");  
            printf("¿Cómo es el contorno del útero?\n");
            cout << "1. Regulares" << endl;
            cout << "2. Irregulares" << endl;
            cin >> UP.contornoUtero; 
        }

        printf("\n¿Está seguro de dejar el dato así?\n");
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
        printf("¿Cómo es el miometrio del útero?\n");
        printf("1. Homogéneo\n");
        printf("2. Heterogéneo\n");
        cin >> UP.miometrioUtero;
        
        while ( (UP.miometrioUtero != 1) && (UP.miometrioUtero != 2) ){
            system("cls || clear");
            printf(" Error - Opción no válida - Inténtelo de nuevo\n");  
            printf("¿Cómo es el miometrio del útero?\n");
            printf("1. Homogéneo\n");
            printf("2. Heterogéneo\n");
            cin >> UP.miometrioUtero; 
        }
        printf("\n¿El dato del Miometrio que ingresó es el correcto?\n");
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
        cout << "Ingrese las medidas del Ovario Izquierdo - Recuerda que en el documento se mostrará de la siguiente manera: A x B x C\n" << endl;
        cout << "Medida A:" << endl;
        cin >> UP.medidaOvarIzqX;
        cout << "Medida B:" << endl;
        cin >> UP.medidaOvarIzqY;
        cout << "Medida C:" << endl;
        cin >> UP.medidaOvarIzqZ; 
        cout << "\nIngrese su conclusión del Ovario Izquierdo: ";
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

    time_t tiempoActual = time(nullptr);
    tm* tiempoLocal = localtime(&tiempoActual);

    UP.Paciente.fechas.realizacion.dia = tiempoLocal->tm_mday;
    UP.Paciente.fechas.realizacion.mes = tiempoLocal->tm_mon + 1; // tm_mon está en el rango 0-11
    UP.Paciente.fechas.realizacion.anio = tiempoLocal->tm_year + 1900; // tm_year es el año desde 1900

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
    header_text += "                                                 ULTRASONIDO PELVICO\n\n";

    full_text += "Cedula: " + cedula + "\n";
    full_text += "Nombre: " + paciente.nombrePaciente.primerNombre + " " + paciente.nombrePaciente.segundoNombre + " " + paciente.nombrePaciente.primerApellido + " " + paciente.nombrePaciente.segundoApellido + "\n";
    full_text += "Fecha: " + to_string(UP.Paciente.fechas.realizacion.dia) + "/" + to_string(UP.Paciente.fechas.realizacion.mes) + "/" + to_string(UP.Paciente.fechas.realizacion.anio) + "\n\n";

    full_text += "Estado de las paredes de la Vejiga: ";
        if (UP.paredesVejiga == 1) {
            full_text += "Paredes Regulares.\n";
        } else if (UP.paredesVejiga == 2) {
            full_text += "Paredes Engrosadas (" + to_string(UP.paredesVejiga) + " mm).\n";
        } else if (UP.paredesVejiga == 3) {
            full_text += "Paredes con lesiones.\n";
            // Aquí puedes agregar más detalles sobre las lesiones, quistes, polipos, etc.
        }

    full_text += "Posicion del Utero: ";
        if (UP.posicionUtero == 1) {
            full_text += "Anteversion.\n";
        } else if (UP.posicionUtero == 2) {
            full_text += "Retroversion.\n";
        }

    full_text += "Medidas del Utero (A x B x C): " + to_string(UP.medidaUteroX) + " x " + to_string(UP.medidaUteroY) + " x " + to_string(UP.medidaUteroZ) + " mm\n";

    full_text += "Estado del Utero segun su medida: ";
        if (UP.segunTamanioUtero == 1) {
            full_text += "Utero Aumentado.\n";
        } else if (UP.segunTamanioUtero == 2) {
            full_text += "Utero Normal.\n";
        } else if (UP.segunTamanioUtero == 3) {
            full_text += "Utero Disminuido.\n";
        }
    full_text += "Contorno del Utero: ";
        if (UP.contornoUtero == 1) {
            full_text += "Regulares.\n";
        } else if (UP.contornoUtero == 2) {
            full_text += "Irregulares.\n";
        }

    full_text += "Contorno del Utero: ";
        if (UP.contornoUtero == 1) {
            full_text += "Regulares.\n";
        } else if (UP.contornoUtero == 2) {
            full_text += "Irregulares.\n";
        }

        full_text += "Estado del Miometrio: ";
        if (UP.miometrioUtero == 1) {
            full_text += "Homogeneo.\n";
        } else if (UP.miometrioUtero == 2) {
            full_text += "Heterogeneo.\n";
        }

        full_text += "Hallazgos generales en el Utero: " + UP.hallazgosUtero + "\n";

        full_text += "Medida del Endometrio: " + to_string(UP.medidaEndometrio) + " mm\n";

        full_text += "Medidas del Ovario Izquierdo (A x B x C): " + to_string(UP.medidaOvarIzqX) + " x " + to_string(UP.medidaOvarIzqY) + " x " + to_string(UP.medidaOvarIzqZ) + " mm\n";
        full_text += "Medidas del Ovario Derecho (A x B x C): " + to_string(UP.medidaOvarDerX) + " x " + to_string(UP.medidaOvarDerY) + " x " + to_string(UP.medidaOvarDerZ) + " mm\n";
        full_text += "Saco de Douglas: ";
        if (UP.sacoDouglas == 1) {
            full_text += "Esta libre de liquido.\n";
        } else if (UP.sacoDouglas == 2) {
            full_text += "No esta libre de liquido.\n";
        }

        full_text += "\nConclusiones generales del procedimiento: " + UP.conclusionesGen + "\n";

    draw_text_with_header_and_footer(page, font, full_text, margin, HPDF_Page_GetHeight(page) - margin, HPDF_Page_GetWidth(page) - 2 * margin, font_size, line_spacing, header_text, footer_text, header_spacing, footer_spacing);

    ostringstream formatoFecha; //es declarado para construir la cadena de caracteres

    formatoFecha << setw(2) << setfill('0') << tiempoLocal->tm_mday << "_" << setw(2) << setfill('0') << (tiempoLocal->tm_mon + 1) << "_"<< (tiempoLocal->tm_year + 1900);
    //se define dia y mes en 2 digitos, rellenando a la izquierda en caso que falte, por ejemplo el primero de enero de 2023 se guardaria como 01_01_2023
    //se le suma 1900 para que de la fecha actual ya que estamos usando formato unix

    string fechaActual = ("C:/Users/user/OneDrive/Escritorio/AutoDoc/" + cedula + "/UP/" + formatoFecha.str() + ".pdf").c_str();

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