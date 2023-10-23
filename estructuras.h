#include <string>

using namespace std;

struct fechaMain{
    int dia;
    int mes;
    int anio;
};

struct F_Especiales{
    fechaMain nacimiento;
    fechaMain realizacion;
};

struct F_Seguimiento{
    fechaMain seguimiento;
};

struct registroP{
    string cedula;
    string nombre;
    F_Especiales fechas;
};

struct UltTrans{
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

struct seguimEmb{
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