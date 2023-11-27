#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <hpdf.h>

using namespace std;

struct fechaMain{
    int dia;
    int mes;
    int anio;
};

struct nombre{
    string primerNombre;
    string segundoNombre;
    string primerApellido;
    string segundoApellido;
};

struct F_Especiales{
    fechaMain nacimiento;
    fechaMain realizacion;
};


struct registroP{
    string cedula;
    nombre nombrePaciente;
    float altura;
    float peso;
    string num_celular;
    F_Especiales fechas;
};

struct citasProgramadas{
    registroP Paciente;
    fechaMain F_Seguimiento;
    string Procedimiento;
};

struct UltTrans{
    registroP Paciente;
    int paredesVejiga;
    
    int quisteX;
    int quisteY;
    int quisteZ;
    string conclusionesQuiste;
    int polipoX;
    int polipoY;
    string conclusionesPolipo;

    string anomaliasVejiga;
    
    int posicionUtero;
    float medidaUteroX;
    float medidaUteroY;
    float medidaUteroZ;
    int segunTamanioUtero;
    int contornoUtero;
    int miometrioUtero;
    string hallazgosUtero;
    
    float medidaEndometrio;

    float medidaOvarDerX;
    float medidaOvarDerY;
    float medidaOvarDerZ;
    float volumenOvarDer;
    string otrasCaractOvarDer;

    float medidaOvarIzqX;
    float medidaOvarIzqY;
    float medidaOvarIzqZ;
    float volumenOvarIzq;
    string otrasCaractOvarIzq;

    int sacoDouglas;
    
    string conclusionesGen;
};

struct UltMamas{
    registroP Paciente;
    string tejidoPredominIzq;
    string cuadrante1Izq;
    string cuadrante2Izq;
    string cuadrante3Izq;
    string cuadrante4Izq;

    string tejidoPredominDer;
    string cuadrante1Der;
    string cuadrante2Der;
    string cuadrante3Der;
    string cuadrante4Der;

    bool lesionesMamaIzq;
    bool lesionesMamaDer;

    float xQuisteIzq;
    float yQuisteIzq;
    float zQuisteIzq;
    string caractQuisteIzq;

    float xQuisteDer;
    float yQuisteDer;
    float zQuisteDer;
    string caractQuisteDer;

    string conclusionesGen;

    int BIRADS;
};

struct UltPelv{
    registroP Paciente;
    int paredesVejiga;
    
    int quisteX;
    int quisteY;
    int quisteZ;
    string conclusionesQuiste;
    int polipoX;
    int polipoY;
    string conclusionesPolipo;

    string anomaliasVejiga;
    
    int posicionUtero;
    float medidaUteroX;
    float medidaUteroY;
    float medidaUteroZ;
    int segunTamanioUtero;
    int contornoUtero;
    int miometrioUtero;
    string hallazgosUtero;
    
    float medidaEndometrio;

    float medidaOvarDerX;
    float medidaOvarDerY;
    float medidaOvarDerZ;
    float volumenOvarDer;
    string otrasCaractOvarDer;

    float medidaOvarIzqX;
    float medidaOvarIzqY;
    float medidaOvarIzqZ;
    float volumenOvarIzq;
    string otrasCaractOvarIzq;

    int sacoDouglas;
    
    string conclusionesGen;
};

struct seguimEmb{
    registroP Paciente;
    float pesoMadre;
    int presArtSisto;
    int presArtDias;
    float medidasLeopold;
    float circunfCraneana;
    float diametBiparietal;
    float circunfAbdominal;
    float longFemoral;
    float pesoBebe;
    int edadBebe;
    string conclusionesGen;
    F_Especiales realizacion;
};

struct diagnostico{
    registroP Paciente;
    string diagnostico;
    string recomenMedicas;
    float costoConsulta;
    F_Especiales realizacion;
};

struct prescripcion{
    registroP Paciente;
    string nombreMed;
    string dosis;
    string cantidad;
};


inline void cargarRegistroDesdeLinea(const string& linea, registroP& paciente) {
    stringstream ss(linea);
    string cedula, nombre, fechaNacimiento, peso, altura, numCelular;
    getline(ss, cedula, ',');
    getline(ss, nombre, ',');
    getline(ss, fechaNacimiento, ',');
    getline(ss, peso, ',');
    getline(ss, altura, ',');
    getline(ss, numCelular);

    paciente.cedula = cedula;

    string token;

    stringstream nombreStream(nombre);
    getline(nombreStream, token, ' ');
    paciente.nombrePaciente.primerNombre = token;
    getline(nombreStream, token, ' ');
    paciente.nombrePaciente.segundoNombre = token;
    getline(nombreStream, token, ' ');
    paciente.nombrePaciente.primerApellido = token;
    getline(nombreStream, token, ' ');
    paciente.nombrePaciente.segundoApellido = token;

    stringstream fechaNacStream(fechaNacimiento);
    getline(fechaNacStream, token, '/');
    paciente.fechas.nacimiento.dia = stoi(token);
    getline(fechaNacStream, token, '/');
    paciente.fechas.nacimiento.mes = stoi(token);
    getline(fechaNacStream, token, '/');
    paciente.fechas.nacimiento.anio = stoi(token);

    stringstream pesoStream(peso);
    pesoStream >> paciente.peso;

    stringstream alturaStream(altura);
    alturaStream >> paciente.altura;

    stringstream numCelularStream(numCelular);
    numCelularStream >> paciente.num_celular;
}

inline bool obtenerInfoPaciente(const string& cedula, registroP& paciente) {
    ifstream archivoPacientes("C:\\Users\\user\\OneDrive\\Escritorio\\AutoDoc\\pacientes.txt");

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

//Menu Principal
void Procedimientos();
void menuPrincipal();
void agenda();
void mainPacientes();
void diagPres();
void regresarMenuPrincipal();

//Login
bool folderExists(const string& folderPath);
void login();

//Pacientes
string convertirMayus(const string& str);
bool esFechaValida(int dia, int mes, int anio); 
void guardarRegistro(const registroP& paciente);
void crearPaciente();
void buscarPacientes();
void listarPacientes();
void actualizarPaciente();
void eliminarDirectorio(const string& path);
void eliminarPaciente();

//Citas Programadas
bool esBisiesto(int anio);
bool esFechaFutura(const fechaMain& fecha);
void programarCita();
void mostrarCitasProgramadas();

//Diagnóstico y preescripciones
void guardarDiagnostico(const diagnostico& diag);
void guardarPrescripcion(const prescripcion& presc);
void mostrarDiagnosticosYPrescripciones(const string& cedula);

//UM
void UM();
void mamaIzq(UltMamas& UM);
void mamaDer(UltMamas& UM);
void lesionesMamas(UltMamas& UM);
void lesionMamaIzq(UltMamas& UM);
void lesionMamaDer(UltMamas& UM);
void conclusionesGen(UltMamas& UM);
void BIRADS(UltMamas& UM);
void asignarProcedimientoAPaciente(UltMamas& UM);
void error_handler(HPDF_STATUS error_no, HPDF_STATUS detail_no, void* user_data);
void draw_text_with_header_and_footer(HPDF_Page page, HPDF_Font font, const string& text, float x, float y, float max_width, float font_size, float line_spacing, const string& header, const string& footer, float header_spacing, float footer_spacing);

//SE
void SE();
void realizarSeguimiento();

//UP
void UP();

//UT
void UT();
