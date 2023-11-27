#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <limits>
#include <ctime>
#include <hpdf.h>
#include <vector>
#include "1_estructuras.h"

using namespace std;

string cedula;
registroP paciente;
seguimEmb seguimiento;

void asignarProcedimientoAPaciente(seguimEmb& seguimiento);
void error_handler(HPDF_STATUS error_no, HPDF_STATUS detail_no, void* user_data);
void draw_text_with_header_and_footer(HPDF_Page page, HPDF_Font font, const string& text, float x, float y, float max_width, float font_size, float line_spacing, const string& header, const string& footer, float header_spacing, float footer_spacing);
void realizarSeguimiento();


void asignarProcedimientoAPaciente(seguimEmb& seguimiento) {
    string cedulaPaciente;
    cout << "Ingrese la cedula del paciente: ";
    cin >> seguimiento.Paciente.cedula;

    // Abrir el archivo de pacientes para lectura
    string filePath = "C:\\Users\\user\\OneDrive\\Escritorio\\AutoDocprueba\\AutoDoc\\output\\pacientes.txt";
    ifstream pacientesFile(filePath);
    if (!pacientesFile.is_open()) {
        cerr << "Error al abrir el archivo de pacientes." << endl;
        exit(EXIT_FAILURE);
    }

    // Buscar al paciente por cedula y cargar su información
    string line;
    while (getline(pacientesFile, line)) {
        if (line.find(seguimiento.Paciente.cedula) == 0) {
            // Suponiendo que la estructura del archivo de pacientes es: cedula,primerNombre,segundoNombre,primerApellido,segundoApellido,altura,peso,num_celular,nacimiento.dia,nacimiento.mes,nacimiento.anio
            stringstream ss(line);
            string token;

            getline(ss, token, ',');
            getline(ss, seguimiento.Paciente.nombrePaciente.primerNombre, ' ');
            getline(ss, seguimiento.Paciente.nombrePaciente.segundoNombre, ' ');
            ss >> seguimiento.Paciente.nombrePaciente.primerApellido;
            ss.ignore();
            getline(ss, seguimiento.Paciente.nombrePaciente.segundoApellido, ',');
            ss >> seguimiento.Paciente.fechas.nacimiento.dia;
            ss.ignore(1, '/');
            ss >> seguimiento.Paciente.fechas.nacimiento.mes;
            ss.ignore(1, '/');
            ss >> seguimiento.Paciente.fechas.nacimiento.anio;
            ss.ignore(1, ',');
            ss >> seguimiento.Paciente.peso;
            ss.ignore(1, ',');
            ss >> seguimiento.Paciente.altura;
            ss.ignore(1, ',');
            getline(ss, seguimiento.Paciente.num_celular);

            cout << "\nPaciente encontrado" << endl << endl;
            printf("C%cdula: ", 130); cout << seguimiento.Paciente.cedula << endl;
            cout << "Nombre: " << seguimiento.Paciente.nombrePaciente.primerNombre << ' ' << seguimiento.Paciente.nombrePaciente.segundoNombre << ' ' << seguimiento.Paciente.nombrePaciente.primerApellido << ' ' << seguimiento.Paciente.nombrePaciente.segundoApellido << endl;
            cout << "Fecha de nacimiento: " << seguimiento.Paciente.fechas.nacimiento.dia << "/" << seguimiento.Paciente.fechas.nacimiento.mes << "/" << seguimiento.Paciente.fechas.nacimiento.anio << endl;
            cout << "Peso: " << seguimiento.Paciente.peso << " lb" << endl;
            cout << "Altura: " << seguimiento.Paciente.altura << " cm" << endl;
            printf("N%cmero de tel%cfono: ", 163, 130); cout << seguimiento.Paciente.num_celular << endl << endl;

            printf("%cEste es el paciente que estabas buscando? Si es as%c, presione S o ingrese cualquier otra letra para ingresarlo nuevamente.\n", 168, 161);
            cin >> cedulaPaciente;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if ((cedulaPaciente == "S") || (cedulaPaciente == "s")) {
                pacientesFile.close();
                return;
            }
            else {
                pacientesFile.close();
                system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
                system("clear || cls");
                asignarProcedimientoAPaciente(seguimiento);
                return;
            }
        }
    }

    // Si llega aquí, no se encontró al paciente
    cerr << "Paciente no encontrado." << endl;
    pacientesFile.close();
    exit(EXIT_FAILURE);
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

// Método para realizar el seguimiento del embarazo
void realizarSeguimiento() {
    // Solicitar la cédula del paciente y validarla
    string cedula;
    registroP paciente;
    seguimEmb seguimiento;

    asignarProcedimientoAPaciente(seguimiento);

    time_t tiempoActual = time(nullptr);
    tm* tiempoLocal = localtime(&tiempoActual);

    seguimiento.Paciente.fechas.realizacion.dia = tiempoLocal->tm_mday;
    seguimiento.Paciente.fechas.realizacion.mes = tiempoLocal->tm_mon + 1; // tm_mon está en el rango 0-11
    seguimiento.Paciente.fechas.realizacion.anio = tiempoLocal->tm_year + 1900; // tm_year es el año desde 1900

    // Resto de la lógica para realizar el seguimiento del embarazo
    cout << "Introduza el peso de la madre: ";
    cin >> seguimiento.pesoMadre;
    cout << "Introduzca la presión arterial sistólica: ";
    cin >> seguimiento.presArtSisto;
    cout << "Introduzca la presión arterial diastólica: ";
    cin >> seguimiento.presArtDias;

    if ((seguimiento.presArtSisto >= 120 && seguimiento.presArtSisto <= 129) && (seguimiento.presArtDias <= 80)) {
        cout << "Se detecta una presion arterial elevada, recuerde agregarlo en las valoraciones finales.\nRecuerde valorar segun su experiencia medica.\n" << endl;
    }
    else if ((seguimiento.presArtSisto >= 130 && seguimiento.presArtSisto <= 180) && (seguimiento.presArtDias >= 80 && seguimiento.presArtDias <= 120)) {
        cout << "Cuidado - Hay una Hipertension Arterial, agreguelo a su valoracion final.\nRecuerde valorar segun su experiencia medica.\n" << endl;
    }
    else if ((seguimiento.presArtSisto > 180) && (seguimiento.presArtDias > 120)) {
        cout << "Tiene una Crisis Hipertensiva - Necesita ayuda inmediata.\nRecuerde valorar segun su experiencia medica.\n" << endl;
    }
    else {
        cout << "Tiene una presion arterial saludable - Recuerde valorar segun su experiencia medica.\n" << endl;
    }

    cout << "Introduzca las medidas Leopold: ";
    cin >> seguimiento.medidasLeopold;
    cout << "Introduzca las medidas de la circunferencia craneana del bebé: ";
    cin >> seguimiento.circunfCraneana;
    cout << "Introduzca el diámetro biparietal del bebé: ";
    cin >> seguimiento.diametBiparietal;
    cout << "Introduzca la circunferencia abdominal del bebé: ";
    cin >> seguimiento.circunfAbdominal;
    cout << "Introduzca el peso del bebé: ";
    cin >> seguimiento.pesoBebe;
    cout << "Introduzca la edad del bebé: ";
    cin >> seguimiento.edadBebe;
    cin.ignore();
    switch (seguimiento.edadBebe) {
    case 4:
        cout << "A esta temprana edad el bebe mide entre 0.4 a 1 mm - Tomar en cuenta para la valoracion final." << endl;
        break;

    case 5:
        cout << "A esta temprana edad el bebe mide alrededor de 2 mm - Tomar en cuenta para la valoracion final." << endl;
        break;

    case 6:
        cout << "A esta temprana edad el bebe mide entre 2 a 4 mm - Tomar en cuenta para la valoracion final." << endl;
        break;

    case 7:
        cout << "A esta temprana edad el bebe mide entre 5 a 6 mm - Tomar en cuenta para la valoracion final." << endl;
        break;

    case 8:
        cout << "A esta edad el bebe debe de medir al rededor de 1.6 cm y pesar alrededor de 1 gramo.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 9:
        cout << "A esta edad el bebe debe de medir al rededor de 2.3 cm y pesar alrededor de 2 gramos.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 10:
        cout << "A esta edad el bebe debe de medir al rededor de 3.1 cm y pesar alrededor de 4 gramos.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 11:
        cout << "A esta edad el bebe debe de medir al rededor de 4.1 cm y pesar alrededor de 7 gramos.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 12:
        cout << "A esta edad el bebe debe de medir al rededor de 5.4 cm y pesar alrededor de 14 gramos.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 13:
        cout << "A esta edad el bebe debe de medir al rededor de 7.4 cm y pesar alrededor de 23 gramos.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 14:
        cout << "A esta edad el bebe debe de medir al rededor de 8.7 cm y pesar alrededor de 43 gramos.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 15:
        cout << "A esta edad el bebe debe de medir al rededor de 10.1 cm y pesar alrededor de 70 gramos.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 16:
        cout << "A esta edad el bebe debe de medir al rededor de 11.6 cm y pesar alrededor de 100 gramos.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 17:
        cout << "A esta edad el bebe debe de medir al rededor de 13 cm y pesar alrededor de 140 gramos.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 18:
        cout << "A esta edad el bebe debe de medir al rededor de 14.2 cm y pesar alrededor de 190 gramos.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 19:
        cout << "A esta edad el bebe debe de medir al rededor de 15.3 cm y pesar alrededor de 240 gramos.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 20:
        cout << "A esta edad el bebe debe de medir al rededor de 16.4 cm y pesar alrededor de 300 gramos.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 21:
        cout << "A esta edad el bebe debe de medir al rededor de 26.7 cm y pesar alrededor de 360 gramos.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 22:
        cout << "A esta edad el bebe debe de medir al rededor de 27.8 cm y pesar alrededor de 430 gramos.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 23:
        cout << "A esta edad el bebe debe de medir al rededor de 28.9 cm y pesar alrededor de 1.10 lbs.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 24:
        cout << "A esta edad el bebe debe de medir al rededor de 30 cm y pesar alrededor de 1.32 lbs.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 25:
        cout << "A esta edad el bebe debe de medir al rededor de 34.6 cm y pesar alrededor de 1.45 lbs.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 26:
        cout << "A esta edad el bebe debe de medir al rededor de 35.6 cm y pesar alrededor de 1.67 lbs.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 27:
        cout << "A esta edad el bebe debe de medir al rededor de 36.6 cm y pesar alrededor de 1.92 lbs.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 28:
        cout << "A esta edad el bebe debe de medir al rededor de 37.6 cm y pesar alrededor de 2.21 lbs.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 29:
        cout << "A esta edad el bebe debe de medir al rededor de 38.6 cm y pesar alrededor de 2.54 lbs.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 30:
        cout << "A esta edad el bebe debe de medir al rededor de 39.9 cm y pesar alrededor de 2.90 lbs.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 31:
        cout << "A esta edad el bebe debe de medir al rededor de 41.1 cm y pesar alrededor de 3.31 lbs.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 32:
        cout << "A esta edad el bebe debe de medir al rededor de 42.4 cm y pesar alrededor de 3.75 lbs.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 33:
        cout << "A esta edad el bebe debe de medir al rededor de 43.7 cm y pesar alrededor de 4.22 lbs.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 34:
        cout << "A esta edad el bebe debe de medir al rededor de 45 cm y pesar alrededor de 4.73 lbs.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 35:
        cout << "A esta edad el bebe debe de medir al rededor de 46.2 cm y pesar alrededor de 5.25 lbs.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 36:
        cout << "A esta edad el bebe debe de medir al rededor de 47.4 cm y pesar alrededor de 5.78 lbs.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 37:
        cout << "A esta edad el bebe debe de medir al rededor de 48.6 cm y pesar alrededor de 6.30 lbs.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 38:
        cout << "A esta edad el bebe debe de medir al rededor de 49.8 cm y pesar alrededor de 6.79 lbs.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 39:
        cout << "A esta edad el bebe debe de medir al rededor de 50.7 cm y pesar alrededor de 7.24 lbs.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;

    case 40:
        cout << "A esta edad el bebe debe de medir al rededor de 51.2 cm y pesar alrededor de 7.63 lbs.\nTomelo en cuenta para su valoracion final.\n" << endl;
        break;
    }

    cout << "Redacte sus conclusiones y valoraciones: ";
    getline(cin, seguimiento.conclusionesGen);

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
    footer_text += "                                          Especialista en Ginecología y Obstetricia\n";
    footer_text += "                                                            Ultrasonografista\n";
    footer_text += "                                                              Colposcopista\n";
    footer_text += "                                                        Código minsa 12962";

    string header_text = "";
    header_text += "                                              CLINICA MEDICA ESPERANZA\n";
    header_text += "                                                ULTRASONIDO DE MAMAS\n\n";

    full_text += "ID: " + seguimiento.Paciente.cedula + "\n";
    full_text += "Nombre: " + seguimiento.Paciente.nombrePaciente.primerNombre + " " + seguimiento.Paciente.nombrePaciente.segundoNombre + " " + seguimiento.Paciente.nombrePaciente.primerApellido + " " + seguimiento.Paciente.nombrePaciente.segundoApellido + "\n";
    full_text += "Fecha: " + to_string(seguimiento.Paciente.fechas.realizacion.dia) + "/" + to_string(seguimiento.Paciente.fechas.realizacion.mes) + "/" + to_string(seguimiento.Paciente.fechas.realizacion.anio) + "\n\n";

    full_text += "Peso de la madre : " + to_string(seguimiento.pesoMadre) + "\n";
    full_text += "Presion arterial sistolica: " + to_string(seguimiento.presArtSisto) + "\n";
    full_text += "Presion arterial diastolica: " + to_string(seguimiento.presArtDias) + "\n";
    full_text += "Medidas Leopold: " + to_string(seguimiento.medidasLeopold) + "\n";
    full_text += "Circunferencia craneana del bebe: " + to_string(seguimiento.circunfCraneana) + "\n";
    full_text += "Diámetro biparietal del bebe: " + to_string(seguimiento.diametBiparietal) + "\n";
    full_text += "Circunferencia abdominal del bebe: " + to_string(seguimiento.circunfAbdominal) + "\n";
    full_text += "Peso del bebe: " + to_string(seguimiento.pesoBebe) + "\n";
    full_text += "Edad del bebe: " + to_string(seguimiento.edadBebe) + "\n\n";

    full_text += "Conclusiones y valoraciones: " + seguimiento.conclusionesGen + "\n\n";

    draw_text_with_header_and_footer(page, font, full_text, margin, HPDF_Page_GetHeight(page) - margin, HPDF_Page_GetWidth(page) - 2 * margin, font_size, line_spacing, header_text, footer_text, header_spacing, footer_spacing);

    // Guardar el documento en un archivo
    HPDF_SaveToFile(pdf, "output.pdf");

    // Liberar recursos
    HPDF_Free(pdf);

    printf("Documento PDF generado con %cxito: output.pdf\n", 130);
};

int main() {
    seguimEmb seguimiento;
    realizarSeguimiento();

    return 0;
}
