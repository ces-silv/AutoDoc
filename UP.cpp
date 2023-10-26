#include <iostream>
#include <string>
#include "estructuras.h"

using namespace std;

int main(){
    UltPelv UP;

    /* Ultrasonido Pelvico */

    cout << "~ Ultrasonido Pelvico ~" << endl;

    /* Inicio - Vejiga */
    
    cout << "Estado de las paredes de la Vejiga" << endl;
    cout << "1. Paredes Regulares." << endl;
    cout << "2. Paredes Engrosadas." << endl; // x
    cout << "3. Paredes con lesiones." << endl;
    cin >> UP.paredesVejiga;
    
    while ( (UP.paredesVejiga != 1) && (UP.paredesVejiga != 2) && (UP.paredesVejiga != 3) ){
            system("cls || clear");
            cout << " Error - Opcion no Valida - Intentelo de Nuevo" << endl; 
            cout << "~ Ultrasonido Pelvico ~" << endl;
            cout << "Estado de las paredes de la Vejiga" << endl;
            cout << "1. Paredes Regulares." << endl;
            cout << "2. Paredes Engrosadas." << endl; // x
            cout << "3. Paredes con lesiones." << endl;
            cin >> UP.paredesVejiga;        
        }

    int opcLesVej, cantQuiste, cantPolipos, engrosVeji;
    bool vejLesCompleto = false;
    bool estadoQuiste = false, estadoPolipos = false, estadoLesiones = false;
    string edit;

    switch (UP.paredesVejiga){
    case 1:
        system("cls || clear;");
        cout << "La paciente presenta Paredes Regulares - Guardado\n" << endl;
        cout << "Presione Enter para continuar" << endl;
        system("pause");
        system("cls || clear;");
        break;
    
    case 2:
        system("cls || clear;");
        cout << "Ingrese las medida del engrosamiento en mm" << endl;
        cin >> engrosVeji;
        cout << "Presione Enter para continuar" << endl;
        system("pause");
        system("cls || clear;");
        break;

    case 3:  
        while (vejLesCompleto == false){
        system("cls || clear");

        cout << "Que lesiones presenta? - Si ya ingreso la deseada NO la vuelva a ingresar al menos que desee editarla." << endl;
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
                cout << "Ingresa S para editarla o cualquier otra letra para volver a ingresar el dato." << endl;
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
                cout << "Ingresa S para editarla o cualquier otra letra para volver a ingresar el dato.." << endl;
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
        break;

    /*default:
        break; */
    }
    /* Final - Vejiga*/

    /* Inicio - Utero */
    bool posUteroComp = false;
    string estadoPosUt;

    while (posUteroComp == false){
        cout << "Cual es la posicion del Utero?" << endl;
        cout << "1. En Anteversion" << endl;
        cout << "2. En Retroversion" << endl;
        cin >> UP.posicionUtero;

        while ( (UP.posicionUtero != 1) && (UP.posicionUtero != 2)){
            system("cls || clear");
            cout << "~ Opcion no valida - Ingrese una nueva" << endl;
            cout << "Cual es la posicion del Utero?" << endl;
            cout << "1. En Anteversion" << endl;
            cout << "2. En Retroversion" << endl;
            cin >> UP.posicionUtero;
        }
        
        if (UP.posicionUtero == 1){
            system("cls || clear");
            cout << "Usted ha ingresado que el Utero esta en Anteversion.\n" << endl;
            cout << "Esta seguro de dejarlo de esta manera?" << endl;
            cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato." << endl;
            cin >> estadoPosUt;

            if ( (estadoPosUt == "S") || (estadoPosUt == "s")){
                posUteroComp = true;
            }
        } else{
            system("cls || clear");
            cout << "Usted ha ingresado que el Utero esta en Retroversion.\n" << endl;
            cout << "Esta seguro de dejarlo de esta manera?" << endl;
            cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato." << endl;
            cin >> estadoPosUt;

            if ( (estadoPosUt == "S") || (estadoPosUt == "s")){
                posUteroComp = true;
            }
        }
        system("cls || clear");
    }
    
    bool estadoUteMed = false;
    string uteMedComp;

    while (estadoUteMed == false){
        cout << "Ingrese las medidas de el Utero - Recuerda que en el documento se mostrara de la siguiente manera: A x B x C\n" << endl;
        cout << "Medida A:" << endl;
        cin >> UP.medidaUteroX;
        cout << "Medida B:" << endl;
        cin >> UP.medidaUteroY;
        cout << "Medida C:" << endl;
        cin >> UP.medidaUteroZ; 
        
        cout << "\nTiene las medidas correcta?" << endl;
        cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato.." << endl;
        cin >> uteMedComp;
            if ( (uteMedComp == "S") || (uteMedComp == "s")){
                estadoUteMed = true;
            }
        system("cls || clear");
    }

    bool estadoUteTam = false;
    string uteTamComp;

    while (estadoUteTam == false){  
        cout << "Cual es el estado del Utero segun el tamanio?" << endl;
        cout << "1. Utero Aumentado" << endl;
        cout << "2. Utero Normal" << endl;
        cout << "3. Utero Disminuido" << endl;
        cin >> UP.segunTamanioUtero;
        
        while ( (UP.segunTamanioUtero != 1) && (UP.segunTamanioUtero != 2) && (UP.segunTamanioUtero != 3) ){
            system("cls || clear");
            cout << " Error - Opcion no Valida - Intentelo de Nuevo" << endl;  
            cout << "Cual es el estado del Utero segun el tamanio?" << endl;
            cout << "1. Utero Aumentado" << endl;
            cout << "2. Utero Normal" << endl;
            cout << "3. Utero Disminuido" << endl;
            cin >> UP.segunTamanioUtero; 
        }
        cout << "\nEsta bien lo que ingreso?" << endl;
        cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato." << endl;
        cin >> uteTamComp;
            if ( (uteTamComp == "S") || (uteTamComp == "s")){
                estadoUteTam = true;
            }
        system("cls || clear");
    }

    bool estadoUteCont = false;
    string uteContComp;

    while (estadoUteCont == false){
        cout << "Como es el contorno del Utero?" << endl;
        cout << "1. Regulares" << endl;
        cout << "2. Irregulares" << endl;
        cin >> UP.contornoUtero;
        
        while ( (UP.contornoUtero != 1) && (UP.contornoUtero != 2) ){
            system("cls || clear");
            cout << " Error - Opcion no Valida - Intentelo de Nuevo" << endl;  
            cout << "Como es el contorno del Utero?" << endl;
            cout << "1. Regulares" << endl;
            cout << "2. Irregulares" << endl;
            cin >> UP.contornoUtero; 
        }

        cout << "\nEsta seguro de dejar el dato asi?" << endl;
        cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato." << endl;
        cin >> uteContComp;
            if ( (uteContComp == "S") || (uteContComp == "s")){
                estadoUteCont = true;
            }
        system("cls || clear");
    }
    
    bool estadoMiomCont = false;
    string uteMioComp;

    while (estadoMiomCont == false){
        cout << "Como es el miometrio del Utero?" << endl;
        cout << "1. Homogeneo" << endl;
        cout << "2. Heterogeneo" << endl;
        cin >> UP.miometrioUtero;
        
        while ( (UP.miometrioUtero != 1) && (UP.miometrioUtero != 2) ){
            system("cls || clear");
            cout << " Error - Opcion no Valida - Intentelo de Nuevo" << endl;  
            cout << "Como es el miometrio del Utero?" << endl;
            cout << "1. Homogeneo" << endl;
            cout << "2. Heterogeneo" << endl;
            cin >> UP.miometrioUtero; 
        }
        cout << "\nEl dato del Miometrio que ingreso es el correcto ?" << endl;
        cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato." << endl;
        cin >> uteMioComp;
            if ( (uteMioComp == "S") || (uteMioComp == "s")){
                estadoMiomCont = true;
            }
        system("cls || clear");
    }


    /* Final - Utero */

    return 0;
}
