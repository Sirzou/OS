#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void imprimeVector(int n,int* S){
		int i;
    for(i=0;i<n;i++){
        printf("%d\t",S[i]);
    }
    printf("\n");
}
void virtualizacion(int* virt,int* phys){

}
int main(){
	srand(time(NULL));
	int tamFisica,tamVirtual;
	int i,N,x;
	//scanf("%d%d",&tamFisica,&tamVirtual);
	scanf("%d%d%d",&tamFisica,&tamVirtual,&N);
	int virt[tamVirtual],phys[tamFisica];
	int page,frame;
	for(i=0;i<tamFisica;i++){
		phys[i]=i;
	}
	for(i=0;i<tamVirtual;i++){
		virt[i]=i%tamFisica;
	}
	//printf("Número de eventos: ");
	//scanf("%d",&N);
	//imprimeVector(tamVirtual,virt);
	//printf("\n\n");
	for(i=0;i<N;i++){
		imprimeVector(tamFisica,phys);
		x=rand()%tamVirtual;
		frame=virt[x];
		page=phys[virt[x]];
		printf("Hay una ocurrencia en la pagina %d\n",x);
		if(x!=page){
			printf("La pagina %d tiene asignado el marco %d\n",x,frame);
			printf("El marco %d esta guardando actualmente a la pagina %d\n",frame,page);
			printf("Guardando la pagina %d...\n",page);
			printf("Cargando la pagina %d...\n\n",x);
			phys[frame]=x;
		}else{
			printf("Afortunadamente el marco %d ya esta guardando actualmente a la pagina %d\n\n",frame,page);
		}
	}
	imprimeVector(tamFisica,phys);
	return 0;
}
