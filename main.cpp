#include <iostream>
#include<ctime>
using namespace std;

string edad(int dia, int mes, int anio, string nombre){
    //Fecha/hora actual basado en el sistema actual
    time_t now=time(0);
    //Objeto de una estructura tm con fecha/hora local
    tm *time = localtime(&now);

    int aactual=1900+(time->tm_year), mactual=(1+ time->tm_mon), dactual=time->tm_mday;
    int diasactuales=aactual*360 + mactual*30 + dactual;
    int diaspersona= anio*360 + mes*30 + dia;
    double difdias=(diasactuales-diaspersona);
    //operador para el residuo es "%", pero solo funciona en entero
    //operador para obtener residuo en numeros de coma flotante es "div"
    div_t anios_vida = div(difdias, 360);
    //cout<<"cociente: "<< anios_vida.quot;
    //cout<<"residuo: "<< anios_vida.rem;
    div_t mes_via=div(anios_vida.rem,30);
    string aux="Bienvenido, "+nombre+", tu tienes "+ to_string(anios_vida.quot) +" anios";
        aux=aux+", meses: "+to_string(mes_via.quot);
        aux=aux+", dias: "+to_string(mes_via.rem);
    return aux;
}
int paso_por_valor(int a){
    a=a*5;
    cout<<endl<<"Dentro de la funcion: el valor de la variable a: "<<a<<endl;
    return 1;
}
int paso_por_referencia(int &a){
    a=a*5;
    cout<<endl<<"Por referencia: valor de la variable a:"<<a<<endl;
    return 1;
}
string saludos(){
    return "Bienvenido";
}
string saludos(string nombre){
    return "Bienvenido "+nombre;
}
string saludos(string nombre, int edad){
    if(edad>=18){
        return "bienvenido señor "+nombre;
    }else{
        return "bienvenido joven "+nombre;
    }
}
int main() {
    cout<<edad(17,5,2003,"juan")<<endl;
    cout<<edad(17,5,2003,"juan")<<endl;
    int a=2;
    paso_por_valor(a);
    cout<<endl<<"En el main, valor de la variable a: "<<a<<endl;
    paso_por_referencia(a);
    cout<<endl<<"En el main el valor de la variable a:"<<a<<endl;
    cout<<endl<<saludos();
    cout<<endl<<saludos("juan");
    cout<<endl<<saludos("juan",18);
}
