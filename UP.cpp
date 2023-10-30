#include <iostream>
#include <string>
#include "estructuras.h"

using namespace std;

int main(){
    UltPelv UP;

    /* Ultrasonido Pelvico */

    printf("~ Ultrasonido P%clvico ~\n", 130);

    /* Inicio - Vejiga */
    
    cout << "Estado de las paredes de la Vejiga" << endl;
    cout << "1. Paredes Regulares." << endl;
    cout << "2. Paredes Engrosadas." << endl; // x
    cout << "3. Paredes con lesiones." << endl;
    cin >> UP.paredesVejiga;
    
    while ( (UP.paredesVejiga != 1) && (UP.paredesVejiga != 2) && (UP.paredesVejiga != 3) ){
            system("cls || clear");
            printf(" Error - Opci%cn no v%clida - Int%cntelo de nuevo\n", 162, 160, 130);
            printf("~ Ultrasonido P%clvico ~\n", 130);
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

        printf("%cQu%c lesiones presenta? - Si ya ingres%c la deseada NO la vuelva a ingresar al menos que desee editarla.\n", 168, 130, 162);
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
        
        printf("3. P%clipos\n", 162); // x * y
        if (estadoPolipos == false){
            cout << " - Sin Info." << endl;
        } else{
            cout << " - Con Info." << endl;
        }

        cout << "4. Salir\n" << endl;
        cout << "Recuerda que solamente tienes que Salir una vez hayas ingresado todos los datos." << endl;
        cin >> opcLesVej;

        system("cls || clear");
        
        switch (opcLesVej){
        case 1:
            if (estadoQuiste == false){
                
                printf("%cCu%cntos quistes vas a ingresar?\n", 168, 160);
                cin >> cantQuiste;
                system("cls || clear");

                for (int i = 0; i < cantQuiste; i++){
                    cout << "Ingrese la medida del quiste #" << i + 1 << " expresada en mm."<< endl;
                    printf("Recuerda que en el documento se mostrar%c de la siguiente manera: A x B x C\n\n", 160);
                    cout << "Medida A:" << endl;
                    cin >> UP.quisteX;
                    cout << "Medida B:" << endl;
                    cin >> UP.quisteY;
                    cout << "Medida C:" << endl;
                    cin >> UP.quisteZ;
                    cout << endl;
                }
                
                estadoQuiste = true;

                    printf("~ Presiona Enter para volver al men%c principal ~\n", 163);
                    system("pause");

            } else{
                printf("Ya agregaste informaci%cn sobre los quistes. %cDeseas cambiarla?\n", 162, 168);
                cout << "Ingresa S para editarla o cualquier otra letra para volver a ingresar el dato." << endl;
                cin >> edit;
                if ((edit == "S") || (edit == "s")){
                    printf("%cCu%cntos quistes vas a ingresar?\n", 168, 160);
                    cin >> cantQuiste; 
                    system("cls || clear");
                    for (int i = 0; i < cantQuiste; i++){
                        cout << "Ingrese la medida del quiste #" << i + 1 << " expresada en mm."<< endl; 
                        printf("Recuerda que en el documento se mostrar%c de la siguiente manera: A x B x C\n\n", 160);
                        cout << "Medida A:" << endl;
                        cin >> UP.quisteX;
                        cout << "Medida B:" << endl;
                        cin >> UP.quisteY;
                        cout << "Medida C:" << endl;
                        cin >> UP.quisteZ;
                        cout << endl;
                    }
                    printf("~ Presiona Enter para volver al men%c principal ~\n", 163);
                    system("pause");
                }
            }  
            break;
        
        case 2:
            if (estadoLesiones == false){
            
            estadoLesiones = true;
            } else{
                printf("Ya agregaste informaci%cn sobre las lesiones - Pulsa Enter para volver al Men%c Principal\n", 162, 163);
                system("pause");
            }
            
            break;

        case 3:
            if (estadoPolipos == false){
            
            printf("%cCu%cntos p%clipos vas a ingresar?\n", 168, 160, 162);
            cin >> cantPolipos;

            for (int i = 0; i < cantPolipos; i++){
                cout << "Ingrese la medida del polipo #" << i + 1<< endl;
                printf("Recuerda que en el documento se mostrar%c de la siguiente manera: A x B\n\n", 160);
                cout << "Medida A:" << endl;
                cin >> UP.polipoX;
                cout << "Medida B:" << endl;
                cin >> UP.polipoY;
            }

            estadoPolipos = true;
            printf("~ Presiona Enter para volver al men%c principal ~\n", 163);
            system("pause");

            } else{
                printf("Ya agregaste informaci%cn sobre los p%clipos. %cDeseas cambiarla?\n", 162, 162, 168);
                cout << "Ingresa S para editarla o cualquier otra letra para volver a ingresar el dato.." << endl;
                cin >> edit;
                if ((edit == "S") || (edit == "s")){
                    printf("%cCu%cntos p%clipos vas a ingresar?\n", 168, 160, 162);
                    cin >> cantPolipos; 
                    system("cls || clear");
                    for (int i = 0; i < cantPolipos; i++){
                        cout << "Ingrese la medida del polipo #" << i + 1 << " expresada en mm."<< endl; 
                        printf("Recuerda que en el documento se mostrar%c de la siguiente manera: A x B\n\n", 160);
                        cout << "Medida A:" << endl;
                        cin >> UP.polipoX;
                        cout << "Medida B:" << endl;
                        cin >> UP.polipoY;
                        cout << endl;
                    }
                    printf("~ Presiona Enter para volver al men%c principal ~\n", 163);
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
        printf("%cCu%cl es la posici%cn del %ctero?\n", 168, 160, 162, 233);
        printf("1. En Anterversi%cn\n", 162);
        printf("2. En Retroversi%cn\n", 162);
        cin >> UP.posicionUtero;

        while ( (UP.posicionUtero != 1) && (UP.posicionUtero != 2)){
            system("cls || clear");
            printf("~ Opci%cn no v%clida - Ingrese una nueva ~\n", 162, 160);
            printf("%cCu%cl es la posici%cn del %ctero?\n", 168, 160, 162, 233);
            printf("1. En Anterversi%cn\n", 162);
            printf("2. En Retroversi%cn\n", 162);
            cin >> UP.posicionUtero;
        }
        
        if (UP.posicionUtero == 1){
            system("cls || clear");
            printf("Usted ha ingresado que el %ctero est%c en Anteversi%cn.\n\n", 233, 160, 162);
            printf("%cEst%c seguro de dejarlo de esta manera?\n", 168, 160);
            cout << "Ingrese S para si o cualquier otra letra para volver a ingresar el dato." << endl;
            cin >> estadoPosUt;

            if ( (estadoPosUt == "S") || (estadoPosUt == "s")){
                posUteroComp = true;
            }
        } else{
            system("cls || clear");
            printf("Usted ha ingresado que el %ctero est%c en Retroversi%cn.\n\n", 233, 160, 162);
            printf("%cEst%c seguro de dejarlo de esta manera?\n", 168, 160);
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
        printf("Ingrese las medidas del %ctero - Recuerda que en el documento se mostrar%c de la siguiente manera: A x B x C\n\n", 233, 160);
        cout << "Medida A:" << endl;
        cin >> UP.medidaUteroX;
        cout << "Medida B:" << endl;
        cin >> UP.medidaUteroY;
        cout << "Medida C:" << endl;
        cin >> UP.medidaUteroZ; 
        
        printf("%cTiene las medidas correctas?\n", 168);
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
        printf("%cCu%cl es el estado del %ctero seg%cn el tama%co?\n", 168, 160, 233, 163, 164);
        printf("1. %ctero Aumentado\n", 233);
        printf("2. %ctero Normal\n", 233);
        printf("3. %ctero Disminuido\n", 233);
        cin >> UP.segunTamanioUtero;
        
        while ( (UP.segunTamanioUtero != 1) && (UP.segunTamanioUtero != 2) && (UP.segunTamanioUtero != 3) ){
            system("cls || clear");
            printf(" Error - Opci%cn no v%clida - Int%cntelo de nuevo\n", 162, 160, 130);
            printf("%cCu%cl es el estado del %ctero seg%cn el tama%co?\n", 168, 160, 233, 163, 164);
            printf("1. %ctero Aumentado\n", 233);
            printf("2. %ctero Normal\n", 233);
            printf("3. %ctero Disminuido\n", 233);
            cin >> UP.segunTamanioUtero; 
        }
        printf("%cEst%c bien lo que ingres%c?\n", 168, 160, 162);
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
        printf("%cC%cmo es el contorno del %ctero?\n", 168, 162, 233);
        cout << "1. Regulares" << endl;
        cout << "2. Irregulares" << endl;
        cin >> UP.contornoUtero;
        
        while ( (UP.contornoUtero != 1) && (UP.contornoUtero != 2) ){
            system("cls || clear");
            printf(" Error - Opci%cn no v%clida - Int%cntelo de nuevo\n", 162, 160, 130);  
            printf("%cC%cmo es el contorno del %ctero?\n", 168, 162, 233);
            cout << "1. Regulares" << endl;
            cout << "2. Irregulares" << endl;
            cin >> UP.contornoUtero; 
        }

        printf("\n%cEst%c seguro de dejar el dato as%c?\n", 168, 160, 161);
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
        printf("%cC%cmo es el miometrio del %ctero?\n", 168, 162, 233);
        printf("1. Homog%cneo\n", 130);
        printf("2. Heterog%cneo\n", 130);
        cin >> UP.miometrioUtero;
        
        while ( (UP.miometrioUtero != 1) && (UP.miometrioUtero != 2) ){
            system("cls || clear");
            printf(" Error - Opci%cn no v%clida - Int%cntelo de nuevo\n", 162, 160, 130);  
            printf("%cC%cmo es el miometrio del %ctero?\n", 168, 162, 233);
            printf("1. Homog%cneo\n", 130);
            printf("2. Heterog%cneo\n", 130);
            cin >> UP.miometrioUtero; 
        }
        printf("\n%cEl dato del Miometrio que ingres%c es el correcto?\n", 168, 162);
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
