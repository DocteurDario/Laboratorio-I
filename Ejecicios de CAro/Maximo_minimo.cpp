//Materia:
//Nombre:
//TP N°:
//Ej N°:
//Comentario:
//____________________________________

#include <iostream>

using namespace std;

    int main(){
    int numero=0, maximo=0 , minimo=0;
    cout <<"Ingresar 10 numeros: "<<endl<< "posicion 1 :";
    cin>>numero;
    maximo=minimo=numero;
    for(int i=1; i < 10; i ++)
    {
        cout<<"posicion "<< i+1 << " :";
        cin >> numero;

        if(numero >maximo)
        {
        maximo=numero;
        }
        if( numero < minimo)
        {
        minimo=numero;
        }
    }
cout <<"Numero Maximo es : "<<maximo << " y  el numero Minimo es : "<<minimo<<endl;


return 0;
}
