#include <pthread.h>//Manejo de hilos
#include <stdlib.h>//exit();
#include <stdio.h>
#include <time.h>
#define N 5
void* holaMundo(void* arg);
void imprimeVector(int n,int* S);
struct Estructura{
  int arreglo[10];
  int id;
};
int main(){
  clock_t start,end;
  srand(time(NULL));
  struct Estructura e[N];
  int i;
  pthread_t h[N];
  int estado;
  start = clock();
  for(i=0;i<N;i++){
    e[i].id=i;
    estado = pthread_create(&h[i],NULL,holaMundo,(void*)(&e[i]));
	  if(estado!=0){
		printf("Error al crear el hilo\n");
		exit(-1);
	  }
  }
  for(i=0;i<N;i++){pthread_join(h[i],NULL);}
  end=clock();
  printf("el tiempo total es: %d ms\n",(end-start));
}
void* holaMundo(void* arg){
    int i;
    struct Estructura* e=(struct Estructura*)(size_t)(arg);
    for(i=0;i<10;i++){e->arreglo[i]=e->id;}
	printf("Vector de id Hilo#%d:\n",e->id);
	imprimeVector(10,e->arreglo);
}
void imprimeVector(int n,int* S){
	int i;
    for(i=0;i<n;i++){
        printf("%d ",S[i]);
    }
    printf("\n");
}
