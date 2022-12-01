#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include"ec2g.c"

int main(void){
	/*Variables*/
	double a;
	double b;
	double c;
	int caso;
	bool fin=false;
	

	double *x1;
	double *x2;

	/*Reserva memoria para los punteros*/
	x1=malloc(sizeof(double));
	x2=malloc(sizeof(double));	




	/*Lee los datos del fichero*/
	while(!fin){	
	if(scanf("%le %le %le",&a ,&b ,&c)<3){
		fin=true;
	}
	else{
		/*Se resuelve la ecuacion y almacena el caso*/
		caso=resolver(a,b,c,x1,x2);

		/*Imprime resultados*/
		printf("Caso %d: %f , %f\n",caso,*x1,*x2);
 	}
 }
	/*Se libera la memoria reservada*/
	free(x1);
	free(x2);
	return 0;
}