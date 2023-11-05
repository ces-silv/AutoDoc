#include <iostream>
#include <vector>
#include <string>

// Función para buscar y mostrar sugerencias
void mostrarSugerencias(const std::string& entrada, const std::vector<std::string>& datos) {
    std::cout << "Sugerencias para '" << entrada << "':" << std::endl;
    for (std::vector<std::string>::const_iterator it = datos.begin(); it != datos.end(); ++it) {
        if (it->find(entrada) != std::string::npos) {
            std::cout << *it << std::endl;
        }
    }
}

int main() {
    // Datos de ejemplo
    std::vector<std::string> datos;
    datos.push_back("Juan");
    datos.push_back("María");
    datos.push_back("Pedro");
    datos.push_back("Ana");
    datos.push_back("Carlos");

    std::string entrada;

    std::cout << "Ingrese una letra o letras para buscar: ";
    while (true) {
        std::cin >> entrada;

        if (entrada == "q" || entrada == "quit") {
            break;
        }

        mostrarSugerencias(entrada, datos);

        std::cout << "Ingrese una letra o letras para buscar (o 'q' para salir): ";
    }

    return 0;
}
