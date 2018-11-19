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
        //Si i,j es un borde, entonces retorne la solucion para un punto anterior, para que no sea infinitesimal
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
            // Si i,j no es un borde ni la varrilla calcule la temperatura a traves de la formula
            T[k][i][j]=(1-4*fo)*solucionFronterasAbiertas(k-1,i,j)+fo*(solucionFronterasAbiertas(k-1,i+1,j)+solucionFronterasAbiertas(k-1,i,j-1)+solucionFronterasAbiertas(k-1,i-1,j)+solucionFronterasAbiertas(k-1,i,j+1));
        }
    }
    //retorne la respuesta
    return T[k][i][j];
}
//Creo el archivo para guardar los datos
ofstream fileEE;
//Creo una variable para guardar el promedio
double Tpromedio[N][N];

///Funcion para imprimir los valores del arreglo de temperatura
void imprimir(int tiempo,int limite_inferior,int limite_superior){
    int aumentoTiempo=(tiempo/4)-2;
    for(int k=0;k<4;k++)
        for(int i=limite_inferior;i<limite_superior;i++)
            for(int j=limite_inferior;j<limite_superior;j++)
                fileEE<<T[1+aumentoTiempo*k][i][j]<<endl;
}

///Funcion para hallar la temperatura promedio
void hallarTemperaturaPromedio(int tim,int limite_inferior,int limite_superior){
    //Se inicializa el arreglo con 0
    for(int i=limite_inferior;i<limite_superior;i++)
            for(int j=limite_inferior;j<limite_superior;j++)
                Tpromedio[i][j]=0;
    //Se suman todas las temperaturas en i,j a traves del tiempo divididas en el tiempo total para sacar el primedio
    for(int k=0;k<tim;k++)
        for(int i=limite_inferior;i<limite_superior;i++)
            for(int j=limite_inferior;j<limite_superior;j++)
                Tpromedio[i][j]+=(T[k][i][j])/tim;
    for(int i=limite_inferior;i<limite_superior;i++)
        for(int j=limite_inferior;j<limite_superior;j++)
            fileEE<<Tpromedio[i][j]<<endl;
}

void iniciarCondicionesFijas(){
    tim=1500;
    dx=0.5/N;
    fileEE<<N<<endl;
    fileEE<<dx<<endl;
    solucionFronterasFijas();
    imprimir(tim,0,N);
    hallarTemperaturaPromedio(tim,0,N);
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
    imprimir(tim,0,N);
    hallarTemperaturaPromedio(tim,0,N);

}

//Constante para moverse sobre la matriz en condiciones periodicas
const float mov=0.5;
//Funcion que retorna verdadero o falso  dependiendo si las cordenadas x,y corresponden a una de las 9 varillas generadas para periodicas
bool puntoDeVarrilla(int x,int y){
    double a=x*dx;
    double b=y*dx;
    for(int i=-1; i<=1;i++){
        for(int j=-1; j<=1;j++){
            if((a+mov*i)>=0.7 and (a+mov*i)<=0.8 and (b+mov*j)>=0.7 and (b+mov*j)<=0.8){
                return true;
            }
        }
    }
    return false;
}
//Para fronteras periodicas
double solucionFronterasPeriodicas(int k, int i, int j){
    //Si ya se calculó la solucion que me la retorne
    if(T[k][i][j]!=-1.0)
        return T[k][i][j];
    //Si i,j es un punto en el cual esta ubicada alguna de las 9 varillas asigne la temperatura de la varilla
    if(puntoDeVarrilla(i,j)){
        T[k][i][j]=373.15;
    }else{
        //Si i,j es un borde, retorne la solucion para un punto anterior que apunte hacia el centro
        if(i==N or i==0 or j==0 or j==N){
            if(i>=N/2 and j>=N/2){
                T[k][i][j]=(1-4*fo)*solucionFronterasPeriodicas(k-1,i,j)+fo*(solucionFronterasPeriodicas(k-1,i-1,j)+solucionFronterasPeriodicas(k-1,i,j-1));
            }else if(i<N/2 and j<N/2){
                T[k][i][j]=(1-4*fo)*solucionFronterasPeriodicas(k-1,i,j)+fo*(solucionFronterasPeriodicas(k-1,i+1,j)+solucionFronterasPeriodicas(k-1,i,j+1));
            }else if(i>=N/2 and j<N/2){
                T[k][i][j]=(1-4*fo)*solucionFronterasPeriodicas(k-1,i,j)+fo*(solucionFronterasPeriodicas(k-1,i-1,j)+solucionFronterasPeriodicas(k-1,i,j+1));
            }else if(i<N/2 and j>=N/2){
                T[k][i][j]=(1-4*fo)*solucionFronterasPeriodicas(k-1,i,j)+fo*(solucionFronterasPeriodicas(k-1,i+1,j)+solucionFronterasPeriodicas(k-1,i,j-1));
            }
        }else{
            // Si i,j no es un borde ni una  varrilla calcule la temperatura a traves de la formula
            T[k][i][j]=(1-4*fo)*solucionFronterasPeriodicas(k-1,i,j)+fo*(solucionFronterasPeriodicas(k-1,i+1,j)+solucionFronterasPeriodicas(k-1,i,j-1)+solucionFronterasPeriodicas(k-1,i-1,j)+solucionFronterasPeriodicas(k-1,i,j+1));
        }
    }
    //retorne la respuesta
    return T[k][i][j];
}
///Funcion que genera la solucion para condiciones periodicas

void iniciarCondicionesPeriodicas(){
    tim=1500;
    //Dado que solo nos interesa la varilla del centro tomamos los valores del arreglo desde 25 a 55
    //estos valores son aproximadamente N/3 y 2N/3 respectivamente
    //Limite inferior y limite superior de nuestra cuadricula
    int li=25;
    int lf=55;
    fileEE<<lf-li<<endl;
    //dado que la altura es 0.5 al generar las demas varillas nuestra altura es 1.5
    //se actualiza dx con la nueva altura
    dx=1.5/N;
    //se imprime el dx tomando solo la parte que nos interesa
    fileEE<<0.5/30<<endl;
    //Se llena la matriz con -1 para indicar que no tiene calculado ningun valor
    for(int k=0;k<tim;k++)
        for(int i=0;i<=N;i++)
            for(int j=0;j<=N;j++)
                T[k][i][j]=-1.0;
    //Se genera el tiempo 0 con las condiciones iniciales del problema
    for(int i=0;i<=N;i++)
        for(int j=0;j<=N;j++)
            T[0][i][j]=285.15;
    for(int k=0;k<tim;k++)
        for(int i=li;i<=lf;i++)
            for(int j=li;j<=lf;j++)
                solucionFronterasPeriodicas(k,i,j);
    //Se imprime el arreglo con los limites indicados
    imprimir(tim,li,lf);
    hallarTemperaturaPromedio(tim,li,lf);

}

int main(){
	fileEE.open("datos.dat");
	iniciarCondicionesFijas();
	iniciarCondicionesAbiertas();
	iniciarCondicionesPeriodicas();
    return 0;
}
