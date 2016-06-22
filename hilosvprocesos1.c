#include <sys/types.h>//Manejo de procesos
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
  clock_t start,end,buff;
  srand(time(NULL));
  struct Estructura e;
  end = clock();
  start = clock();
  fork();
  fork();
  e.id=1;
  holaMundo(&e);
  buff=clock();
  //if(end<=buff){end=buff;}
  printf("el tiempo total es: %d ms\n",(start-end));
  sleep(5);
}
void* holaMundo(void* arg){
    int i;
    struct Estructura* e=(struct Estructura*)(size_t)(arg);
    for(i=0;i<10;i++){e->arreglo[i]=rand()%10;}
	printf("Vector de id proceso %d:\n",getpid());
	imprimeVector(10,e->arreglo);
}
void imprimeVector(int n,int* S){
	int i;
    for(i=0;i<n;i++){
        printf("%d ",S[i]);
    }
    printf("\n");
}
