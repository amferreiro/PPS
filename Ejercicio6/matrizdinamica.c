#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	/*Variables*/
	long int m;
	long int p;
	long int **matriz;
	int i=0;
	int j=0;

	if(argc!=3)
		exit(-1);

	m=atol(argv[1]);
	p=atol(argv[2]);
	

	/*Reserva de memoria para la matriz*/
	matriz = (long int**)malloc(m*sizeof(long int*));
	if(matriz==NULL){
		exit(71);	
	}
	for(i=0;i<m;i++){
		matriz[i]=(long int*)malloc(p*sizeof(long int));	
		if(matriz[i]==NULL){
			exit(71);
		}
	}


	/*Rellena los elementos de la matriz*/
	for(i=0;i<m;i++){
		for(j=0;j<p;j++){
			if(i==0 || j==0 ||((matriz[i-1][j])+(matriz[i][j-1]))>1.e6){
				matriz[i][j]=1;	
			}
			else{
				matriz[i][j]=(matriz[i-1][j])+(matriz[i][j-1]);
			}
		}
	}


	/*Imprime la matriz*/
	for(i=0;i<m;i++){
		for (j=0;j<p; j++){
			if(j==p-1)
				printf("%li\n",matriz[i][j]);
			else
				printf("%li\t",matriz[i][j]);
		}
	}

	for(i = 0; i < m; i++){
    	free(matriz[i]);
	}

	free(matriz);
	return 0;
}