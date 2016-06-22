#include <pthread.h>//Manejo de hilos
#include <stdlib.h>//exit();
#include <stdio.h>
#include <time.h>
void* holaMundo(void* arg);
void imprimeVector(int n,int* S);
struct Estructura{
  int arreglo[10];
  int id;
};
int main(){
  srand(time(NULL));
  struct Estructura e[4];
  int i;
  pthread_t h[4];
  int estado;
  for(i=0;i<4;i++){
	
    e[i].id=i;
//	printf("Hola Mundo. We show the light n: %d\n",e[i].id);
    estado = pthread_create(&h[i],NULL,holaMundo,(void*)(&e[i]));
	  if(estado!=0){
		printf("Error al crear el hilo\n");
		exit(-1);
	  }
  }
  for(i=0;i<4;i++){pthread_join(h[i],NULL);}
}
void* holaMundo(void* arg){
    int i;
    struct Estructura* e=(struct Estructura*)(size_t)(arg);
    for(i=0;i<10;i++){e->arreglo[i]=e->id;}
	printf("Vector de id Hilo#%d:\n",e->id);
	imprimeVector(10,e->arreglo);
	for(i=0;i<10;i++){e->arreglo[i]=rand()%100;}
	printf("Vector de aleatorios Hilo#%d:\n",e->id);
	imprimeVector(10,e->arreglo);
}
void imprimeVector(int n,int* S){
	int i;
    for(i=0;i<n;i++){
        printf("%d ",S[i]);
    }
    printf("\n");
}
