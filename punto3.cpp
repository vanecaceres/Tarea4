//incluir bibliotecas
#include<bits/stdc++.h>
using namespace std;
///Declaración de constantes
// Todas las temperaturas tienen unidades K (Kelvin)
//Conductividad Termica
double k=1.62;
//Calor especifico
double Cp=820.0;
//Densidad g/cm³ -> k/m³
double p=2.71*1000;
//Coeficiente de difusion
double v=k/(Cp*p);
//Altura de la calcita 0.5m
double h=0.5;
//Ancho de la calcita 0.5m
double w=0.5;
//Numero de iteraciones
const int N=80;
//Tiempo de simulacion maximo
const int max_time=10000;
// arreglo que guarda la temperatura en el tiempo i, la fila j y la columna 4k 
double T[max_time][N][N];
double dx=h/N;
double dy=dx;
double dt=10;
int tim;
//Constante de estabilidad
double fo=(v*dt/(dx*dx));

void solucionFronterasFijas(){
    //Se llena las condiciones de frontera para el tiempo 0
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            T[0][i][j]=285.15;
    //Se empieza a iterar desde el tiempo 1

}

void solucionFronterasAbiertas(){
}

void solucionFronterasPeriodicas(){
}

int main(){

    return 0;
}
