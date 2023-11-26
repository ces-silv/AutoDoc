#include <string>
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
    float edadBebe;
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

struct informesMedicos {
    registroP Paciente;
    citasProgramadas procdRealizado;
    string Resultados;
};