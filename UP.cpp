#include <iostream>
#include <string>
#include "estructuras.h"

using namespace std;

int main(){
    UltPelv UP;

    /* Ultrasonido Pelvico */

    cout << "~ Ultrasonido Pelvico ~" << endl;

    /* Inicio - Vejiga*/
    
    cout << "Estado de las paredes de la Vejiga" << endl;
    cout << "1. Paredes Regulares." << endl;
    cout << "2. Paredes Engrosadas." << endl; // x
    cout << "3. Paredes Irregulares." << endl; // borrar
    cout << "4. Paredes con lesiones." << endl;
    cin >> UP.paredesVejiga;
    
    int opcLesVej, cantQuiste, cantPolipos;
    bool vejLesCompleto = false;
    bool estadoQuiste = false, estadoPolipos = false, estadoLesiones = false;
    string edit;

    if (UP.paredesVejiga == 4){
        
        while (vejLesCompleto == false){
        system("cls || clear");

        cout << "Que lesiones presenta? - Si ya ingreso la deseada NO la vuelva a ingresar." << endl;
        cout << "1. Quiste";
        if (estadoQuiste == false){
            cout << " - Sin Info." << endl;
        } else{
            cout << " - Con Info." << endl;
        }

        cout << "2. Lesiones tumorales";  
        if (estadoLesiones == false){
            cout << " - Sin Info." << endl;
        } else{
            cout << " - Con Info." << endl;
        }
        
        cout << "3. Polipos"; // x * y
        if (estadoPolipos == false){
            cout << " - Sin Info." << endl;
        } else{
            cout << " - Con Info." << endl;
        }

        cout << "4. Salir\n" << endl;
        cout << "Recuerda que solo tienes que Salir una vez hayas todos los datos." << endl;
        cin >> opcLesVej;

        system("cls || clear");
        
        switch (opcLesVej){
        case 1:
            if (estadoQuiste == false){
                        
                cout << "Cuantos quistes va a ingresar ?" << endl;
                cin >> cantQuiste;
                system("cls || clear");

                for (int i = 0; i < cantQuiste; i++){
                    cout << "Ingrese la medida del quiste #" << i + 1 << " expresada en mm."<< endl; 
                    cout << "Recuerda que en el documento se mostrara de la siguiente manera: A x B x C\n" << endl;
                    cout << "Medida A:" << endl;
                    cin >> UP.quisteX;
                    cout << "Medida B:" << endl;
                    cin >> UP.quisteY;
                    cout << "Medida C:" << endl;
                    cin >> UP.quisteZ;
                    cout << endl;
                }
                
                estadoQuiste = true;

                    cout << "~ Presiona Enter para volver al menu principal ~" << endl;
                    system("pause");

            } else{
                cout << "Ya agregaste informacion sobre los quistes - Deseas Cambiarla?" << endl;
                cout << "Ingresa S para editarla o ingresa N para no editarla." << endl;
                cin >> edit;
                if ((edit == "S") || (edit == "s")){
                    cout << "Cuantos quistes va a ingresar ?" << endl;
                    cin >> cantQuiste; 
                    system("cls || clear");
                    for (int i = 0; i < cantQuiste; i++){
                        cout << "Ingrese la medida del quiste #" << i + 1 << " expresada en mm."<< endl; 
                        cout << "Recuerda que en el documento se mostrara de la siguiente manera: A x B x C\n" << endl;
                        cout << "Medida A:" << endl;
                        cin >> UP.quisteX;
                        cout << "Medida B:" << endl;
                        cin >> UP.quisteY;
                        cout << "Medida C:" << endl;
                        cin >> UP.quisteZ;
                        cout << endl;
                    }
                    cout << "~ Presiona Enter para volver al menu principal ~" << endl;
                    system("pause");
                }
            }  

            break;
        
        case 2:
            if (estadoLesiones == false){
            
            estadoLesiones = true;
            } else{
                cout << "Ya agregaste informacion sobre las lesiones - Pulsa Enter para volver al Menu Principal" << endl;
                system("pause");
            }
            
            break;

        case 3:
            if (estadoPolipos == false){
            
            cout << "Cuantos polipos va a ingresar ?" << endl;
            cin >> cantPolipos;

            for (int i = 0; i < cantPolipos; i++){
                cout << "Ingrese la medida del polipo #" << i + 1<< endl; 
                cout << "Recuerda que en el documento se mostrara de la siguiente manera: A x B\n" << endl;
                cout << "Medida A:" << endl;
                cin >> UP.polipoX;
                cout << "Medida B:" << endl;
                cin >> UP.polipoY;
            }

            estadoPolipos = true;
            cout << "~ Presiona Enter para volver al menu principal ~" << endl;
            system("pause");

            } else{
                cout << "Ya agregaste informacion sobre los Polipos - Deseas Cambiarla?" << endl;
                cout << "Ingresa S para editarla o ingresa N para no editarla." << endl;
                cin >> edit;
                if ((edit == "S") || (edit == "s")){
                    cout << "Cuantos quistes va a ingresar ?" << endl;
                    cin >> cantPolipos; 
                    system("cls || clear");
                    for (int i = 0; i < cantPolipos; i++){
                        cout << "Ingrese la medida del polipo #" << i + 1 << " expresada en mm."<< endl; 
                        cout << "Recuerda que en el documento se mostrara de la siguiente manera: A x B x C\n" << endl;
                        cout << "Medida A:" << endl;
                        cin >> UP.polipoX;
                        cout << "Medida B:" << endl;
                        cin >> UP.polipoY;
                        cout << endl;
                    }
                    cout << "~ Presiona Enter para volver al menu principal ~" << endl;
                    system("pause");
                }
            }
            
            break;


        case 4:
            vejLesCompleto = true;
            break;
        default:
            break;
        }

        }   
    }
    
    
    /* Final - Vejiga*/

    return 0;
}
