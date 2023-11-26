#include <iostream>
#include <string>
#include <limits>
/*límites de los diferentes tipos de datos, como el número máximo
y mínimo que se puede almacenar en un tipo de dato específico.*/
#include <cstdlib>
/*funcionalidades generales de la biblioteca estándar de C.
Incluye funciones como system() para ejecutar comandos del sistema operativo
y exit() para finalizar la ejecución del programa.*/
#include <stdlib.h>
/*Esta es una biblioteca de C que proporciona
funcionalidades relacionadas con la gestión de memoria y otras operaciones estándar.*/
#include <fstream>
/*funcionalidades para trabajar con archivos.
Incluye clases y funciones para leer y escribir datos en archivos.*/
#include <Windows.h>

#include <direct.h>
#include <io.h>

#ifdef _WIN32
#include <conio.h> // Solo para Windows
#endif

using namespace std;

bool folderExists(const string& folderPath);

void login(){

    /* Declaracion de variables para el logeo */
    string usuarioCorrecto = "admin";
    string passCorrecto = "1234";
    string usuario, contrasenia;
    char charAst;
    int intentoRestante = 3;

    while (intentoRestante > 0)
    { /* El while permite que haya un maximo de 3 intentos fallidos */
        cout << "Ingrese su nombre de usuario: ";
        cin >> usuario;
        cout << "Ingrese su contrasena: ";
        contrasenia = "";
#ifdef _WIN32
        while (true)
        {
            charAst = getch();
            if (charAst == 13)
            {
                break;
            } // Si se presiona Enter, terminar el bucle
            if (charAst == 8)
            { // Si se presiona Borrar, borrar el último caracter de la contraseña
                if (contrasenia.length() > 0)
                {
                    contrasenia.erase(contrasenia.length() - 1);
                    cout << "\b \b"; // Borrar el ultimo asterisco ingresado, \b es igual a decir 8 en sistema ASCII
                }
            }

            else
            {
                contrasenia += charAst;
                cout << "*"; // Reemplaza los caracteres que ingrese el usuario por asteriscos
            }
        }
#else
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("stty -echo");
        charAst = cin.get();
        while (charAst != '\n')
        {
            if (charAst == 127 || charAst == 8)
            { // Si se presiona Borrar o Retroceso, borrar el último caracter de la contraseña
                if (contrasenia.length() > 0)
                {
                    contrasenia.erase(contrasenia.length() - 1);
                    cout << "\b \b"; // Borrar el ultimo asterisco ingresado
                }
            }
            else
            {
                contrasenia += charAst;
                cout << "*"; // Reemplaza los caracteres que ingrese el usuario por asteriscos
            }
            charAst = cin.get();
        }
        cout << endl;
        system("stty echo");
#endif
        cout << endl;

        /* Restriccion para que se se pueda o no logear el usuario */
        if (usuario == usuarioCorrecto && contrasenia == passCorrecto)
        {
            system("clear || cls");
            //INICIA EL PROGRAMA
            string desktopPath = "C:/Users/silva/OneDrive/Escritorio/AutoDoc";

            // Verificar si la carpeta ya existe
            if (_access(desktopPath.c_str(), 0) == 0) { //Se utiliza la funcion access para que verifique si la carpeta ya esta creada
            // c_str = constant string, busca en el escritorio la carpeta y el parametro 0 significa que ya existe, si es igual a 0 significa que existe, si no crea la carpeta
            } else {
                //crear la carpeta
                if (_mkdir(desktopPath.c_str()) == 0) {
                    //Carpeta creada exitosamente :)
                }
            }
            //Fin


            break;
        }

        else
        {
            system("clear || cls");
            intentoRestante--;
            cout << "Usuario o contrasena incorrectos - Tiene " << intentoRestante << " intentos disponibles." << endl;
        }
    }

    if (intentoRestante == 0)
    { /* Restriccion si se llega al limite de intentos */
        system("clear || cls");
        cout << "Ha excedido el maximos de intentos permitidos." << endl;
    }

}

bool folderExists(const string& folderPath) {
    DWORD attributes = GetFileAttributesA(folderPath.c_str()); // Usar GetFileAttributesA para cadenas de un solo byte
    return (attributes != INVALID_FILE_ATTRIBUTES && (attributes & FILE_ATTRIBUTE_DIRECTORY));
}