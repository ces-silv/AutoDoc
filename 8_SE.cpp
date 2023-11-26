#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

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
        string fechaActual = obtenerFechaActual();

        // Resto de la lógica para realizar el seguimiento del embarazo
        cout << "Introduza el peso de la madre: ";
        cin >> seguimiento.pesoMadre;
        cout << "Introduzca la presión arterial sistólica: ";
        cin >> seguimiento.presArtSisto;
        cout << "Introduzca la presión arterial diastólica: ";
        cin >> seguimiento.presArtDias;
        
        if ( (seguimiento.presArtSisto >= 120 && seguimiento.presArtSisto <= 129) && (seguimiento.presArtDias <= 80) ){
            cout << "Se detecta una presion arterial elevada, recuerde agregarlo en las valoraciones finales.\nRecuerde valorar segun su experiencia medica.\n" << endl;
        } else if ( (seguimiento.presArtSisto >= 130 && seguimiento.presArtSisto <= 180) && (seguimiento.presArtDias >= 80 && seguimiento.presArtDias <= 120) ){
            cout << "Cuidado - Hay una Hipertension Arterial, agreguelo a su valoracion final.\nRecuerde valorar segun su experiencia medica.\n" << endl;
            } else if ( (seguimiento.presArtSisto > 180) && (seguimiento.presArtDias > 120) ){
                cout << "Tiene una Crisis Hipertensiva - Necesita ayuda inmediata.\nRecuerde valorar segun su experiencia medica.\n" << endl;
            } else{
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
        switch (seguimiento.edadBebe){
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

        ofstream archivo("seguimientoEmbarazo.txt", ios::app);

        if (archivo.is_open()) {
            archivo << "Cédula: " << cedula << endl;
            archivo << "Nombre: " << paciente.nombrePaciente.primerNombre << ' ' << paciente.nombrePaciente.segundoNombre << ' ' << paciente.nombrePaciente.primerApellido << ' ' << paciente.nombrePaciente.segundoApellido << endl;
            archivo << "Peso de la madre: " << seguimiento.pesoMadre  << endl;
            archivo << "Presión arterial sistólica: " << seguimiento.presArtSisto << endl;
            archivo << "Presión arterial diastólica: " << seguimiento.presArtDias << endl;
            archivo << "Medidas Leopold: " << seguimiento.medidasLeopold << endl;
            archivo << "Circunferencia craneana del bebé: " << seguimiento.circunfCraneana << endl;
            archivo << "Diámetro biparietal del bebé: " << seguimiento.diametBiparietal << endl;
            archivo << "Circunferencia abdominal del bebé: " << seguimiento.circunfAbdominal << endl;
            archivo << "Peso del bebé: " << seguimiento.pesoBebe << endl;
            archivo << "Edad del bebé: " << seguimiento.edadBebe << endl;
            archivo << "Conclusiones y valoraciones: " << seguimiento.conclusionesGen << endl;
            archivo << "Fecha de realización: " << fechaActual << endl;
            archivo << "-------------------------------------------------------" << endl;

            cout << "\nDatos guardados en el archivo seguimientoEmbarazo.txt" << endl;
            archivo.close();
        } else {
            cout << "Error: No se pudo abrir el archivo." << endl;
        }
    };

void SE() {
    seguimEmb seguimiento;
    realizarSeguimiento();
}
