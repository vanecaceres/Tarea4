#include<bits/stdc++.h>
using namespace std;
ofstream fileEE;
///Variebles que guarda los grados con los cuales se alcanza la distanica maxima
int max_dist=-1;
int max_dist_angle=-1;
///Gravedad 10m/s²
double gravity=10.0;
///Tiempo estimado en el que caera el proyectil en segundos
double tim=10.0;
///Numero de pasos a realizar para completar el tiempo estimado
const int steps=1000001;
///Diferencial de tiempo,El tiempo estimado sobre el numero de pasos
double dt=tim/(steps-1);
///Arreglo para la velocidad en el eje x
double vx[steps];
///Arreglo para la velocidad en el eje y
double vy[steps];
    ///Arreglo para poscición en el eje x
double x[steps];
///Arreglo para la poscición en el eje y
double y[steps];
///Arreglo para la aceleración en el eje x
double ax[steps];
///Arreglo para la aceleración en el eje y
double ay[steps];
///Arreglo para el tiempo
double T[steps];
///PI
double PI = 3.1416;
int limit=0;
bool flag=true;
//Creo una funcion general que me resuelva de acuerdo a los parametros que le entren, en este caso la masa, coeficiente de friccion, angulo y posiciones iniciales
//Long double me coge más numeros, mirar luego si long o double
void solution(double mass,double coefficient_of_friction,double angle, double Xo, double Yo, double Vo){
	//Angulo con unidades en radianes para usar sin y cos
	double theta=angle*PI/180.0;
	//Condiciones iniciales
	x[0]=Xo;
	y[0]=Yo;
	T[0]=0;
	//Desarmo el vector de velocidad en x y y
	vx[0]=Vo*cos(theta);
   	vy[0]=Vo*sin(theta);
	//Desarmo el vector de aceleracion en x y y
    	ax[0]=-coefficient_of_friction*vx[0]*Vo/mass;
	//En y mi gravedad afecta, en x no hay gravedad
    	ay[0]=-gravity-coefficient_of_friction*vy[0]*Vo/mass;
	//Mi límite es 0, que sería el suelo
	double norm;
	limit=0;
	///Por el método de leapfrog
    	for(int i=1;i<steps;i++){
	//Se guarda el tiempo actual
        T[i]=T[i-1]+dt;
        //Se calculan los nuevos valores para la poscicion la velocidad y
        //la aceleración en base a los valores obtenidos anteriormente
        x[i]=x[i-1]+vx[i-1]*dt+ax[i-1]*0.5*dt*dt;
        y[i]=y[i-1]+vy[i-1]*dt+ay[i-1]*0.5*dt*dt;
        //Creo la norma
        norm=sqrt((vx[i-1]*vx[i-1])+(vy[i-1]*vy[i-1]));

        //Aceleraciòn en x y y
        ax[i]=-coefficient_of_friction*norm*vx[i-1]/mass;
        ay[i]=-gravity-coefficient_of_friction*norm*vy[i-1]/mass;
        vx[i]=vx[i-1]+(ax[i]+ax[i-1])*0.5*dt;
        vy[i]=vy[i-1]+(ay[i]+ay[i-1])*0.5*dt;
        ///Si el proyectil ha caido, se debe dejar de iterar
        if(y[i]<0){
            limit=i;
            break;
        }
    }
    if(x[limit]>max_dist){
        max_dist=x[limit];
        max_dist_angle=angle;
    }
    if(flag == true){
        fileEE<<"Distancia recorrida con "<<angle<<" grados respecto a la horizontal : "<<x[limit]<<endl;
    }	
}


int main(){
//Hago un archivo donde agregue la distancia recorrida a 45 grados
	fileEE.open("angulo45.dat");
	solution(0.2,0.2,45,0,0,300);
	fileEE.close();
//Hago un archivo donde agrego los datos a 45 grados para luego hacer el plot
	fileEE.open("datos45.dat");
    fileEE<<limit<<endl;

	return 0;

}
