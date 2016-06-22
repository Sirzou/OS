#include <pthread.h>//Manejo de hilos
#include <stdlib.h>//exit();
#include <stdio.h>
void* holaMundo(void* arg);
struct Estructura{
  //char* nombre;
  int peso;
  int edad;
};
int main(){
  int id[10];
  int i;
  for(i=0;i<10;i++)id[i]=i;
  pthread_t h[10];
  int estado;
  for(i=0;i<10;i++){
    estado = pthread_create(&h[i],NULL,holaMundo,(void*)(&id[i]));
	  if(estado!=0){
		printf("Error al crear el hilo\n");
		exit(-1);
	  }
  }
  for(i=0;i<10;i++)pthread_join(h[i],NULL);
}
void* holaMundo(void* arg){
    int* id=(int*)((size_t)arg);
    printf("Hola Mundo. Soy el hilo %d\n",*id);
}
