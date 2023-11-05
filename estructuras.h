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

    bool sacoDouglas;
    
    string conclusionesGen;
};

struct UltMamas{
    registroP Paciente;
    string tejidoPredominIzq;
    int cuadrante1Izq;
    int cuadrante2Izq;
    int cuadrante3Izq;
    int cuadrante4Izq;

    string tejidoPredominDer;
    int cuadrante1Der;
    int cuadrante2Der;
    int cuadrante3Der;
    int cuadrante4Der;

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

    bool sacoDouglas;
    
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
    string dosis;
    string cantidad;
};