#include <iostream>
#include <fstream>
#include <string>
#include "estructuras.h"

using namespace std;

void segEmb() {
    seguimEmb seguimiento;
    cout << "Introduza el peso de la madre: ";
    cin >> seguimiento.pesoMadre;
    cout << "Introduzca la presión arterial sistólica: ";
    cin >> seguimiento.presArtSisto;
    cout << "Introduzca la presión arterial diastólica: ";
    cin >> seguimiento.presArtDias;
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
    cin.ignore();  // Ignore any previous newline character in the buffer
    cout << "Redacte sus conclusiones y valoraciones: ";
    getline(cin, seguimiento.conclusionesGen);

    // Open the file in append mode
    ofstream outFile("seguimientoEmbarazo.txt", ios::app);

    if (outFile.is_open()) {
        // Write the data to the file
        outFile << "Peso de la madre: " << seguimiento.pesoMadre << endl;
        outFile << "Presión arterial sistólica: " << seguimiento.presArtSisto << endl;
        outFile << "Presión arterial diastólica: " << seguimiento.presArtDias << endl;
        outFile << "Medidas Leopold: " << seguimiento.medidasLeopold << endl;
        outFile << "Circunferencia craneana del bebé: " << seguimiento.circunfCraneana << endl;
        outFile << "Diámetro biparietal del bebé: " << seguimiento.diametBiparietal << endl;
        outFile << "Circunferencia abdominal del bebé: " << seguimiento.circunfAbdominal << endl;
        outFile << "Peso del bebé: " << seguimiento.pesoBebe << endl;
        outFile << "Edad del bebé: " << seguimiento.edadBebe << endl;
        outFile << "Conclusiones y valoraciones: " << seguimiento.conclusionesGen << endl;

        cout << "Datos guardados en el archivo seguimientoEmbarazo.txt" << endl;

        // Close the file
        outFile.close();
    } else {
        cout << "Error: No se pudo abrir el archivo." << endl;
    }
}

int main() {
    segEmb();
    return 0;
}
