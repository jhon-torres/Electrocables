#include <iostream>
#include <iomanip>
using namespace std;

void error ();
float costo (int n);
float distancia_imprev(int n);
float precio_conectores (int n);
int main(){
    const float GANANCIA = 45.0/100;
    string lugar;
    int puntos_red,cantidad_conectores;
    float distancia, total_distancia, costo_cable, total_conectores, total_material, ganancia, total_pagar; 
    
    puntos_red = total_distancia = total_conectores = 0;
    
    cout<<"\t\t*** Empresa Electrocables ***"<<endl<<endl;
    cout<<"\t\tEste es un software contable"<<endl<<endl;
    cout<<"Ingrese el nombre del lugar de la instalacion:"<<endl;
    getline(cin, lugar);

    while (puntos_red<=0){
        cout<<"Ingrese el numero de puntos de red que van a ser instalados:"<<endl;
        cin>>puntos_red;
        if (puntos_red<=0){
            error();
        }
    }

    for (int i=1; i<=puntos_red; i++ ){

        cout<<"Punto de red #"<<i<<endl;
        distancia = cantidad_conectores = 0;

        while (distancia<=0){
            cout<<"Ingrese la distancia entre el conector del punto de red hasta el equipo de conectividad:"<<endl;
            cin>>distancia;
            if (distancia<=0){
                error();
            }
        }
        while (cantidad_conectores<=0){
            cout<<"Ingresa el numero de conectores para el punto de red:"<<endl;
            cin>>cantidad_conectores;
            if ( cantidad_conectores<=0){
                error();
            }
        }

        total_distancia+=distancia;
        total_conectores+=cantidad_conectores;        

    }
    total_distancia*=6; 
    costo_cable=costo (total_distancia);
    total_material= costo_cable+precio_conectores(total_conectores);
    ganancia = total_material * GANANCIA;
    total_pagar = ganancia + total_material;

    cout<<"\t\tEl detalle de la instalacion es la siguiente"<<endl<<endl;
    cout<<"La distancia total del cable utilizado en la instalacion es: "<<fixed<<setprecision(2)<<distancia_imprev(total_distancia)<<endl; 
    cout<<"El costo del cable segun la categoria 5e es: "<<fixed<<setprecision(2)<<costo_cable<<endl; 
    cout<<"El precio total de los conectores RJ45 (hembre y macho) es: "<<fixed<<setprecision(2)<<precio_conectores(total_conectores)<<endl;
    cout<<"El total del material utilizado es: "<<fixed<<setprecision(2)<<total_material<<endl;
    cout<<"La ganancia es: "<<fixed<<setprecision(2)<<ganancia<<endl;
    cout<<"El total a pagar por su instalacion es: "<<fixed<<setprecision(2)<<total_pagar<<endl;

    system("pause");
    return 0;
}

void error (){
    cout<<"\t\t-- Vuelva a intentarlo --"<<endl;
}

float costo (int n){
    const float COSTO_CABLE=0.9;
    float distancia;

    distancia = n * COSTO_CABLE;
    return distancia;
}

float distancia_imprev(int n){
    const float IMPREVISTO_CABLE=5.0/100;
    float m;

    m = n * (1+IMPREVISTO_CABLE);
    return m;
}

float precio_conectores (int n){
    const float COSTO_CONECT_MACHO= 0.15, COSTO_CONECT_HEMBRA= 0.35, IMPREVISTO_CONECT=15.0/100;
    float precio;
    n*=2;
    precio=n*(COSTO_CONECT_HEMBRA+COSTO_CONECT_MACHO);
    precio = precio * (1+IMPREVISTO_CONECT);    
    
    return precio;
}