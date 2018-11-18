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
//Coeficiente de difusion62
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
    for(int k=1;k<tim;k++){
        //Se llena las condiciones de frontera para el tiempo k
        for(int i=0;i<N;i++){
            T[k][i][0]=285.15;
            T[k][i][N]=285.15;
        }
        for(int j=0;j<N;j++){
            T[k][0][j]=285.15;
            T[k][N][j]=285.15;
        }
        //Se empieza a llenar la cuadricula de temperaturas
        for(int i=1;i<N;i++){
            for(int j=1;j<N;j++){
                //Si las posiciones i,j corresponden a las posciciones donde esta la varilla temperatura es 100 grados
                //Si no es asi, entonces aplico la formula
                if(i*dx>=0.2 and i*dx<=0.3 and j*dy>=0.2 and j*dy<=0.3)
                    T[k][i][j]=373.15;
                else
                    T[k][i][j]=(1-4*fo)*T[k-1][i][j]+fo*(T[k-1][i+1][j]+T[k-1][i-1][j]+T[k-1][i][j+1]+T[k-1][i][j-1]);
            }
        }
    }
}

double solucionFronterasAbiertas(int k, int i, int j){
    //Si ya se calculó la solucion retornela
    if(T[k][i][j]!=-1.0)
        return T[k][i][j];
    //Si i,j es un punto en el cual esta ubicada la varrilla asignele su temperatura
    if(i*dx>=0.2 and i*dx<=0.3 and j*dy>=0.2 and j*dy<=0.3){
        T[k][i][j]=373.15;
    }else{
        //Si i,j es un borde, retorne la solucion para un punto anterior que apunte hacia el centro
        if(i==N-1 or i==0 or j==0 or j==N-1){
            if(i>=N/2 and j>=N/2){
                T[k][i][j]=solucionFronterasAbiertas(k-1,i-1,j-1);
            }else if(i<N/2 and j<N/2){
                T[k][i][j]=solucionFronterasAbiertas(k-1,i+1,j+1);
            }else if(i>=N/2 and j<N/2){
                T[k][i][j]=solucionFronterasAbiertas(k-1,i-1,j+1);
            }else if(i<N/2 and j>=N/2){
                T[k][i][j]=solucionFronterasAbiertas(k-1,i+1,j-1);
            }
        }else{
            // Si i,j no es un borde ni ula varrilla calcule la temperatura a traves de la formula
            T[k][i][j]=(1-4*fo)*solucionFronterasAbiertas(k-1,i,j)+fo*(solucionFronterasAbiertas(k-1,i+1,j)+solucionFronterasAbiertas(k-1,i,j-1)+solucionFronterasAbiertas(k-1,i-1,j)+solucionFronterasAbiertas(k-1,i,j+1));
        }
    }
    //retorne la respuesta
    return T[k][i][j];
}
ofstream fileEE;
void iniciarCondicionesFijas(){
    tim=1500;
    dx=0.5/N;
    fileEE<<N<<endl;
    fileEE<<dx<<endl;
    solucionFronterasFijas();
}
void iniciarCondicionesAbiertas(){
    //Se aumenta el tiempo para apreciar un mejor resutado
    tim=1500;
    fileEE<<N<<endl;
    fileEE<<dx<<endl;
    //Se llena la matriz con -1 para indicar que no tiene calculado ningun valor
    for(int k=0;k<tim;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                T[k][i][j]=-1.0;
    //Se genera el tiempo 0 con las condiciones iniciales del problema
    for(int i=0;i<=N;i++)
        for(int j=0;j<=N;j++)
            T[0][i][j]=285.15;
    for(int k=0;k<tim;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                solucionFronterasAbiertas(k,i,j);

}

int main(){

    return 0;
}
