//Algoritmo que calcula pi por el metodo MonteCarlo
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <pthread.h>
//puntos dentro del circulo
double pC_p1 = 0;
double pC_p2 = 0;
//puntos totales
double pTotales = 0.0;
//bool
int bool;

void *calcularPuntos(void *arg){
	int p = *((int*)arg);

	//punto/coordenadas
	double x;
	double y;

	//suma de catetas al 2
	double sumC2;
	
	//distancia del centro
	double d;
	

	for(int i = 0; i < bool; i++){
		x = (drand48() * (2-0) + 0)-1;
		y = (drand48() * (2-0) + 0)-1;
		sumC2 =(x*x) + (y*y);
		d = pow(sumC2, 0.5);
		if(d < 1){
			if(p == 1){
				pC_p1++;
			} else {
				pC_p2++;
			}
		}
	}
}

int main(int argc, char* argv[]){
	
	//verficamos que los argumentos sean correctos
	if(argc != 2){
		printf("Argumentos invalidos\n");
		exit(1);
	}

	bool = atoi(argv[1]);

	//se multiplica por el # de hilos
	pTotales = bool*2;

	//Cambiamos la semilla de numeros aleatorios
	srand48(time(NULL));

	//vals de hilo
	int vp1 = 1;
	int vp2 = 2;

	//creamos los hilos
	pthread_t p1,p2;
	pthread_create(&p1, NULL, calcularPuntos, &vp1);
	pthread_create(&p2, NULL, calcularPuntos, &vp2);
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);

	double pCirculo = pC_p1 + pC_p2;

	double pi = 4 * (pCirculo/pTotales);

	printf("valor pi = %f\n",pi);

	return 0;
}

