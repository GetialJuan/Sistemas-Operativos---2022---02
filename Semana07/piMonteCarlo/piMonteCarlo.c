//Algoritmo que calcula pi por el metodo MonteCarlo
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char* argv[]){
	
	//verficamos que los argumentos sean correctos
	if(argc != 2){
		printf("Argumentos invalidos\n");
		exit(1);
	}

	//puntos dentro del circulo
	double pCirculo = 0.0;
	//puntos totales
	double pTotales = (double) atoi(argv[1]);

	//punto/coordenadas
	double x;
	double y;

	//centro
	double c = 0.5;

	//distancia del centro
	double d;

	//suma de catetas al 2
	double sumC2;

	//Cambiamos la semilla de numeros aleatorios
	srand48(time(NULL));


	for(int i = 0; i < pTotales; i++){
		x = (drand48() * (2-0) + 0)-1;
		y = (drand48() * (2-0) + 0)-1;
		sumC2 =(x*x) + (y*y);
		d = pow(sumC2, 0.5);
		if(d < 1){
			pCirculo += 1;
		}
	}

	double pi = 4 * (pCirculo/pTotales);

	printf("valor pi = %f\n",pi);

	return 0;
}

