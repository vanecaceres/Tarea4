#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream> 
#include<bits/stdc++.h>
using namespace std;

///Variebles que guarda los grados con los cuales se alcanza la distanica maxima
int max_dist=-1;
int max_dist_angle=-1;
///Gravedad 10m/s²
double gravity=10.0;
///Tiempo estimado en el que caera el proyectil en segundos
double tim=10.0;
///Numero de pasos a realizar para completar el tiempo estimado
int steps=1000;
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
//Creo una funcion general que me resuelva de acuerdo a los parametros que le entren, en este caso la masa, coeficiente de friccion, angulo y posiciones iniciales
//Long double me coge más numeros, mirar luego si long o double
void solution(double mass,double coefficient_of_friction,double angle,long double Xo,long double Yo,long double Vo){
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
	int limit=0;
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
	}
}
int main(){

	return 0;

}
