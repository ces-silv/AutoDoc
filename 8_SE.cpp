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

string cedula;
registroP paciente;
seguimEmb seguimiento;

// Método para realizar el seguimiento del embarazo
void realizarSeguimiento() {
    // Solicitar la cédula del paciente y validarla
    string cedula;
    registroP paciente;
    seguimEmb seguimiento;

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

    time_t tiempoActual = time(nullptr);
    tm* tiempoLocal = localtime(&tiempoActual);

    seguimiento.Paciente.fechas.realizacion.dia = tiempoLocal->tm_mday;
    seguimiento.Paciente.fechas.realizacion.mes = tiempoLocal->tm_mon + 1; // tm_mon está en el rango 0-11
    seguimiento.Paciente.fechas.realizacion.anio = tiempoLocal->tm_year + 1900; // tm_year es el año desde 1900

    // Resto de la lógica para realizar el seguimiento del embarazo
    cout << "Introduza el peso de la madre (lb): ";
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

    cout << "Introduzca las medidas Leopold (cm): ";
    cin >> seguimiento.medidasLeopold;
    cout << "Introduzca las medidas de la circunferencia craneana del bebé (mm): ";
    cin >> seguimiento.circunfCraneana;
    cout << "Introduzca el diámetro biparietal del bebé (mm): ";
    cin >> seguimiento.diametBiparietal;
    cout << "Introduzca la circunferencia abdominal del bebé (mm): ";
    cin >> seguimiento.circunfAbdominal;
    cout << "Introduzca el peso del bebé (lb): ";
    cin >> seguimiento.pesoBebe;
    cout << "Introduzca la edad del bebé (semanas): ";
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
    footer_text += "                                          Especialista en Ginecologia y Obstetricia\n";
    footer_text += "                                                            Ultrasonografista\n";
    footer_text += "                                                              Colposcopista\n";
    footer_text += "                                                        Codigo minsa 12962";

    string header_text = "";
    header_text += "                                              CLINICA MEDICA ESPERANZA\n";
    header_text += "                                               SEGUIMIENTO DE EMBARAZO\n\n";

    full_text += "Cedula: " + cedula + "\n";
    full_text += "Nombre: " + paciente.nombrePaciente.primerNombre + " " + paciente.nombrePaciente.segundoNombre + " " + paciente.nombrePaciente.primerApellido + " " + paciente.nombrePaciente.segundoApellido + "\n";
    full_text += "Fecha: " + to_string(seguimiento.Paciente.fechas.realizacion.dia) + "/" + to_string(seguimiento.Paciente.fechas.realizacion.mes) + "/" + to_string(seguimiento.Paciente.fechas.realizacion.anio) + "\n\n";

    full_text += "Peso de la madre : " + to_string(seguimiento.pesoMadre) + " lb\n";
    full_text += "Presion arterial sistolica: " + to_string(seguimiento.presArtSisto) + "\n";
    full_text += "Presion arterial diastolica: " + to_string(seguimiento.presArtDias) + "\n";
    full_text += "Medidas Leopold: " + to_string(seguimiento.medidasLeopold) + " cm\n";
    full_text += "Circunferencia craneana del bebe: " + to_string(seguimiento.circunfCraneana) + " mm\n";
    full_text += "Diametro biparietal del bebe: " + to_string(seguimiento.diametBiparietal) + " mm\n";
    full_text += "Circunferencia abdominal del bebe: " + to_string(seguimiento.circunfAbdominal) + " mm\n";
    full_text += "Peso del bebe: " + to_string(seguimiento.pesoBebe) + " lb\n";
    full_text += "Edad del bebe: " + to_string(seguimiento.edadBebe) + " semanas\n\n";

    full_text += "Conclusiones y valoraciones: " + seguimiento.conclusionesGen + "\n\n";

    draw_text_with_header_and_footer(page, font, full_text, margin, HPDF_Page_GetHeight(page) - margin, HPDF_Page_GetWidth(page) - 2 * margin, font_size, line_spacing, header_text, footer_text, header_spacing, footer_spacing);

    ostringstream formatoFecha; //es declarado para construir la cadena de caracteres

    formatoFecha << setw(2) << setfill('0') << tiempoLocal->tm_mday << "_" << setw(2) << setfill('0') << (tiempoLocal->tm_mon + 1) << "_"<< (tiempoLocal->tm_year + 1900);
    //se define dia y mes en 2 digitos, rellenando a la izquierda en caso que falte, por ejemplo el primero de enero de 2023 se guardaria como 01_01_2023
    //se le suma 1900 para que de la fecha actual ya que estamos usando formato unix

    string fechaActual = ("C:/Users/user/OneDrive/Escritorio/AutoDoc/" + cedula + "/SE/" + formatoFecha.str() + ".pdf").c_str();

    // Guardar el documento en un archivo
    HPDF_SaveToFile(pdf, fechaActual.c_str());

    cin.ignore();

    cout << fechaActual;
    // Guardar el documento en un archivo
    system("pause");
    system("cls");
    // Liberar recursos
    menuPrincipal();
};

void SE() {
    seguimEmb seguimiento;
    realizarSeguimiento();
}
