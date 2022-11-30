/**
 * Este programa calcula sobre cada uno de los enteros de un vector su
 * fibonacci.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max_random(min, max) min + rand()%(max + 1 - min)
#define printf_vector(v,n) for (i = 0; i < n; i++) { printf("%d ",v[i]); }
#define println printf("\n")
#define CONSTANTE 5

int fibonacci(int);

int main(int argc, char *argv[]) {
  int vl, // vl: vector_length
      mr; // mr: max_random
  int *vector;
  int i;
  if (argc != 3) {
    printf("Ejecutar de la siguiente manera: \n");
    printf("\t %s <vector_length> <max_random>\n",argv[0]);
    exit(1);
  }
  vl = atoi(argv[1]);
  mr = atoi(argv[2]);

  vector = (int*)malloc(sizeof(int) * vl);

  srand(time(NULL));
  for (i = 0 ; i < vl; i++) {
    vector[i] = max_random(mr - CONSTANTE, mr);
  }
  printf_vector(vector,vl);
  println;

  for (i = 0; i < vl; i++) {
    vector[i] = fibonacci(vector[i]);
  }
  //printf("%d\n",fibonacci(vl));

  printf_vector(vector,vl);
  println;

  return 0;
}

int fibonacci(int m) {
  if (m == 0)
    return 0;
  if (m == 1)
    return 1;
  return fibonacci(m - 1) + fibonacci(m - 2);
}

