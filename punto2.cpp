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
//Creo una funcion general que me resuelva de acuerdo a los parametros que le entren, en este caso la masa, coeficiente de friccion, angulo y posiciones iniciales
void solution(double mass,double coefficient_of_friction,double angle,long double Xo,long double Yo,long double Vo){


}
int main(){

	return 0;

}
