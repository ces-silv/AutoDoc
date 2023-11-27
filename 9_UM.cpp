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

void mamaIzq(UltMamas& UM) {
    bool tejidoPredominIzq = false;
    string opc;

    while (tejidoPredominIzq == false) {
        cout << "ULTRASONIDO DE MAMAS\n\n";
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

        if (opc == "S" || opc == "s") {
            tejidoPredominIzq = true;
        }
        system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
        system("clear || cls");
    }
}

void mamaDer(UltMamas& UM) {
    bool tejidoPredominDer = false;
    string opc;

    while (tejidoPredominDer == false) {
        cout << "ULTRASONIDO DE MAMAS\n\n";
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

        if (opc == "S" || opc == "s") {
            tejidoPredominDer = true;
        }
        system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
        system("clear || cls");
    }
}

void lesionMamaIzq(UltMamas& UM) {
    UM.lesionesMamaIzq = false;
    string lesionesMamaIzq;
    while (UM.lesionesMamaIzq == false) {
        cout << "ULTRASONIDO DE MAMAS\n\n";
        printf("Ingrese las medidas en mm del quiste izquierdo - ");
        printf("Recuerda que en el documento se mostrar%c de la siguiente manera : A x B x C\n\n", 160);
        cout << "Medida A:" << endl;
        while (!(cin >> UM.xQuisteIzq) || cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            printf("ERROR - No ingresaste un n%cmero, int%cntelo otra vez\n", 163, 130);
            printf("Medida A:\n");
        }
        cout << "Medida B:" << endl;
        while (!(cin >> UM.yQuisteIzq) || cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            printf("ERROR - No ingresaste un n%cmero, int%cntelo otra vez\n", 163, 130);
            printf("Medida B:\n");
        }
        cout << "Medida C:" << endl;
        while (!(cin >> UM.zQuisteIzq) || cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            printf("ERROR - No ingresaste un n%cmero, int%cntelo otra vez\n", 163, 130);
            printf("Medida C:\n");
        }

        printf("\n%cTiene las medidas correctas?\n", 168);
        cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato." << endl;
        cin >> lesionesMamaIzq;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if ((lesionesMamaIzq == "S") || (lesionesMamaIzq == "s")) {
            UM.lesionesMamaIzq = true;
        }
        system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
        system("cls || clear");
    }
}

void lesionMamaDer(UltMamas& UM) {
    UM.lesionesMamaDer = false;
    string lesionesMamaDer;
    while (UM.lesionesMamaDer == false) {
        cout << "ULTRASONIDO DE MAMAS\n\n";
        printf("Ingrese las medidas en mm del quiste derecho - ");
        printf("Recuerda que en el documento se mostrar%c de la siguiente manera : A x B x C\n\n", 160);
        cout << "Medida A:" << endl;
        while (!(cin >> UM.xQuisteDer) || cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            printf("ERROR - No ingresaste un n%cmero, int%cntelo otra vez\n", 163, 130);
            printf("Medida A:\n");
        }
        cout << "Medida B:" << endl;
        while (!(cin >> UM.yQuisteDer) || cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            printf("ERROR - No ingresaste un n%cmero, int%cntelo otra vez\n", 163, 130);
            printf("Medida B:\n");
        }
        cout << "Medida C:" << endl;
        while (!(cin >> UM.zQuisteDer) || cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            printf("ERROR - No ingresaste un n%cmero, int%cntelo otra vez\n", 163, 130);
            printf("Medida C:\n");
        }

        printf("\n%cTiene las medidas correctas?\n", 168);
        cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato." << endl;
        cin >> lesionesMamaDer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if ((lesionesMamaDer == "S") || (lesionesMamaDer == "s")) {
            UM.lesionesMamaDer = true;
        }
        system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
        system("cls || clear");
    }
}

void lesionesMamas(UltMamas& UM) {
    int opc;
    cout << "ULTRASONIDO DE MAMAS\n\n";
    printf("%cAlguna de las mamas tiene lesiones?\n", 168);
    printf("1. S%clo la mama izquierda.\n", 162);
    printf("2. S%clo la mama derecha.\n", 162);
    printf("3. Ambas.\n");
    printf("4. Ninguna.\n");
    cout << " ---> "; cin >> opc;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (opc) {
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

void conclusionesGen(UltMamas& UM) {
    bool conclusionesGen = false;
    string opc;

    do {
        cout << "ULTRASONIDO DE MAMAS\n\n";
        cout << "Ingrese sus conclusiones generales del procedimiento." << endl;
        getline(cin, UM.conclusionesGen);
        printf("\n%cHa ingresado todo correctamente? Si es as%c, presione S o ingrese cualquier otra letra para ingresarlo nuevamente.\n", 168, 161);
        cin >> opc;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (opc == "S" || opc == "s") {
            conclusionesGen = true;
        }
        system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
        system("clear || cls");

    } while (conclusionesGen == false);
}

void BIRADS(UltMamas& UM) {
    cout << "ULTRASONIDO DE MAMAS\n\n";
    cout << "Breast Imaging-Reporting and Data System (BI-RADS)" << endl;
    printf("Escala de 0 a 5. Ingrese el n%cmero correspondiente seg%cn las normas internacionales.\n", 163, 163);
    cout << " ---> ";
    cin >> UM.BIRADS;

    if (cin.fail()) {
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


void error_handler(HPDF_STATUS error_no, HPDF_STATUS detail_no, void* user_data) {
    // Esta función se encarga de manejar los errores generados por LibHaru.
    // Recibe el número de error principal (error_no) y el número de detalle (detail_no).
    // Además, user_data es un parámetro adicional que no estamos utilizando en este caso.

    // Imprimir información de error en formato hexadecimal y decimal
    cout << "LibHaru error: " << hex << error_no << ", " << dec << detail_no << endl;

    // Salir del programa con código de error 1
    exit(1);
}

void draw_text_with_header_and_footer(HPDF_Page page, HPDF_Font font, const string& text, float x, float y, float max_width, float font_size, float line_spacing, const string& header, const string& footer, float header_spacing, float footer_spacing) {
    HPDF_Page_SetFontAndSize(page, font, font_size);
    const float margin = 50.0f;

    // Dividir el texto del encabezado en líneas
    vector<string> header_lines;
    stringstream header_stream(header);
    string header_line;
    while (getline(header_stream, header_line, '\n')) {
        header_lines.push_back(header_line);
    }

    // Dibujar encabezado
    for (const auto& line : header_lines) {
        HPDF_Page_BeginText(page);
        HPDF_Page_TextOut(page, x, y, line.c_str());
        HPDF_Page_EndText(page);
        y -= header_spacing;
    }

    // Actualizar la posición y para el contenido principal
    y -= header_spacing;

    // Calcular la altura de una línea de texto
    float line_height = static_cast<float>(HPDF_Font_GetCapHeight(font)) * font_size / 1000.0f;

    // Encontrar saltos de línea en el texto
    size_t start_pos = 0;
    size_t end_pos = text.find('\n');

    // Iterar sobre las líneas del texto
    while (end_pos != string::npos) {
        // Obtener una línea de texto
        string line = text.substr(start_pos, end_pos - start_pos);

        // Verificar si la posición y está en la parte superior de la página
        if (y > HPDF_Page_GetHeight(page) - margin) {
            // Agregar el encabezado
            for (const auto& header_line : header_lines) {
                HPDF_Page_BeginText(page);
                HPDF_Page_TextOut(page, x, y, header_line.c_str());
                HPDF_Page_EndText(page);
                y -= header_spacing;
            }

            // Actualizar la posición Y para el siguiente encabezado
            y -= header_spacing;
        }

        // Verificar si la línea cabe en el ancho disponible
        if (HPDF_Page_TextWidth(page, line.c_str()) <= max_width) {
            // Dibujar la línea
            HPDF_Page_BeginText(page);
            HPDF_Page_TextOut(page, x, y, line.c_str());
            HPDF_Page_EndText(page);

            // Mover la posición Y para la siguiente línea con espacio adicional
            y -= line_height + line_spacing;
        }
        else {
            // Dividir la línea en fragmentos que se ajusten al ancho
            size_t pos = 0;
            while (pos < line.length()) {
                size_t len = line.length() - pos;
                while (HPDF_Page_TextWidth(page, line.substr(pos, len).c_str()) > max_width) {
                    len--;
                }

                // Dibujar la porción que cabe en la página
                HPDF_Page_BeginText(page);
                HPDF_Page_TextOut(page, x, y, line.substr(pos, len).c_str());
                HPDF_Page_EndText(page);

                // Mover la posición Y para la siguiente línea con espacio adicional
                y -= line_height + line_spacing;

                pos += len;
            }
        }

        // Actualizar las posiciones para la siguiente línea
        start_pos = end_pos + 1;
        end_pos = text.find('\n', start_pos);
    }

    // Dibujar la última línea
    string last_line = text.substr(start_pos);

    // Verificar si la última línea cabe en el ancho disponible
    if (HPDF_Page_TextWidth(page, last_line.c_str()) <= max_width) {
        // Dibujar la última línea
        HPDF_Page_BeginText(page);
        HPDF_Page_TextOut(page, x, y, last_line.c_str());
        HPDF_Page_EndText(page);
    }
    else {
        // Dividir la última línea en fragmentos que se ajusten al ancho
        size_t pos = 0;
        while (pos < last_line.length()) {
            size_t len = last_line.length() - pos;
            while (HPDF_Page_TextWidth(page, last_line.substr(pos, len).c_str()) > max_width) {
                len--;
            }

            // Dibujar la porción que cabe en la página
            HPDF_Page_BeginText(page);
            HPDF_Page_TextOut(page, x, y, last_line.substr(pos, len).c_str());
            HPDF_Page_EndText(page);

            // Mover la posición Y para la siguiente línea con espacio adicional
            y -= line_height + line_spacing;

            pos += len;
        }
    }

    // Dividir el texto del pie de página en líneas
    vector<string> footer_lines;
    stringstream footer_stream(footer);
    string footer_line;
    while (getline(footer_stream, footer_line, '\n')) {
        footer_lines.push_back(footer_line);
    }

    // Agregar el pie de página
    for (const auto& footer_line : footer_lines) {
        HPDF_Page_BeginText(page);
        HPDF_Page_TextOut(page, x, y - line_height - footer_spacing, footer_line.c_str());
        HPDF_Page_EndText(page);
        y -= footer_spacing;
    }
}

void UM() {
    UltMamas UM;
    registroP paciente;
    string cedula;
    HPDF_Doc pdf;
    HPDF_Page page;
    HPDF_Font font;
    string full_text = "";

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

    cin.ignore();
    mamaIzq(UM);
    mamaDer(UM);
    lesionesMamas(UM);
    conclusionesGen(UM);
    BIRADS(UM);

    time_t tiempoActual = time(nullptr);
    tm* tiempoLocal = localtime(&tiempoActual);

    UM.Paciente.fechas.realizacion.dia = tiempoLocal->tm_mday;
    UM.Paciente.fechas.realizacion.mes = tiempoLocal->tm_mon + 1; // tm_mon está en el rango 0-11
    UM.Paciente.fechas.realizacion.anio = tiempoLocal->tm_year + 1900; // tm_year es el año desde 1900

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

    // Establecer el tamaño de la página (carta)
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

    full_text += "Cedula: " + cedula + "\n";
    full_text += "Nombre: " + paciente.nombrePaciente.primerNombre + " " + paciente.nombrePaciente.segundoNombre +
        " " + paciente.nombrePaciente.primerApellido + " " + paciente.nombrePaciente.segundoApellido + "\n";
    full_text += "Fecha: " + to_string(UM.Paciente.fechas.realizacion.dia) + "/" + to_string(UM.Paciente.fechas.realizacion.mes) + "/" + to_string(UM.Paciente.fechas.realizacion.anio) + "\n\n";

    full_text += "Caracteristicas de tejido predominante de la mama izquierda: \n" + UM.tejidoPredominIzq + "\n";
    full_text += "  -Cuadrante 1: " + UM.cuadrante1Izq + "\n";
    full_text += "  -Cuadrante 2: " + UM.cuadrante2Izq + "\n";
    full_text += "  -Cuadrante 3: " + UM.cuadrante3Izq + "\n";
    full_text += "  -Cuadrante 4: " + UM.cuadrante4Izq + "\n\n";

    full_text += "Caracteristicas de tejido predominante de la mama derecha: \n" + UM.tejidoPredominDer + "\n";
    full_text += "  -Cuadrante 1: " + UM.cuadrante1Der + "\n";
    full_text += "  -Cuadrante 2: " + UM.cuadrante2Der + "\n";
    full_text += "  -Cuadrante 3: " + UM.cuadrante3Der + "\n";
    full_text += "  -Cuadrante 4: " + UM.cuadrante4Der + "\n\n";


    if (UM.lesionesMamaIzq == true) {
        full_text += "Lesiones en mama izquierda: Sí\n";
        full_text += "Medidas del quiste izquierdo (A x B x C): " + to_string(UM.xQuisteIzq) + " x " + to_string(UM.yQuisteIzq) + " x " + to_string(UM.zQuisteIzq) + " mm.\n\n";
    }
    else {
        full_text += "Lesiones en mama izquierda: No\n";
    }
    if (UM.lesionesMamaDer == true) {
        full_text += "Lesiones en mama derecha: Sí\n";
        full_text += "Medidas del quiste derecho (A x B x C): " + to_string(UM.xQuisteDer) + " x " + to_string(UM.yQuisteDer) + " x " + to_string(UM.zQuisteDer) + " mm.\n\n";
    }
    else {
        full_text += "Lesiones en mama derecha: No\n\n";
    }
    full_text += "BI-RADS: " + to_string(UM.BIRADS) + "\n";
    full_text += "Conclusiones generales: " + UM.conclusionesGen + "\n\n";

    string footer_text = "";
    footer_text += "                                                  Dr. Carlos Ernesto Silva Bustos\n";
    footer_text += "                                          Especialista en Ginecologia y Obstetricia\n";
    footer_text += "                                                            Ultrasonografista\n";
    footer_text += "                                                              Colposcopista\n";
    footer_text += "                                                        Codigo minsa 12962";

    string header_text = "";
    header_text += "                                              CLINICA MEDICA ESPERANZA\n";
    header_text += "                                                ULTRASONIDO DE MAMAS\n\n";


    draw_text_with_header_and_footer(page, font, full_text, margin, HPDF_Page_GetHeight(page) - margin, HPDF_Page_GetWidth(page) - 2 * margin, font_size, line_spacing, header_text, footer_text, header_spacing, footer_spacing);

     //Esta línea obtiene el tiempo actual en segundos desde el 1 de enero de 1970 y lo guarda en la variable
    //Esto se haceya que se representa el tiempo en formato unix, el cual se empieza desde el 1 de enero de 1970 a las 00:00:00
    //tm* fecha = localtime(&tiempoActual); //Luego, este tiempo se convierte en una estructura que contiene información detallada sobre la fecha y la hora asi como dia mas año
    ostringstream formatoFecha; //es declarado para construir la cadena de caracteres

    formatoFecha << setw(2) << setfill('0') << tiempoLocal->tm_mday << "_" << setw(2) << setfill('0') << (tiempoLocal->tm_mon + 1) << "_"<< (tiempoLocal->tm_year + 1900);
    //se define dia y mes en 2 digitos, rellenando a la izquierda en caso que falte, por ejemplo el primero de enero de 2023 se guardaria como 01_01_2023
    //se le suma 1900 para que de la fecha actual ya que estamos usando formato unix

    string fechaActual = ("C:/Users/user/OneDrive/Escritorio/AutoDoc/" + cedula + "/UM/" + formatoFecha.str() + ".pdf").c_str();

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