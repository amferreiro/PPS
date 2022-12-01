#include <stdio.h>
#include <limits.h>
#include <stdbool.h>



int main(int argc, char const *argv[])
{
	/*Declarcion de Variables*/
	FILE *fichero;
	float max=LONG_MIN;
	float min=LONG_MAX;
	float cero = 0.00;
	bool vacio=true;
	float num;


	/*Test num argumentos*/
	if(argc>2 || argc<2)
		return -1;

	/*Abrir Fichero*/
	if(argc==2){
		fichero=fopen(argv[1],"r");
		/*No se puede leer*/
		if(fichero==NULL)
			return -1;
	}


	while(fscanf(fichero,"%f",&num)!=-1){
		vacio = false;
		if(num>max){
			max=num;
		}
		if(num<min){
			min=num;
		}
	}

	if(vacio){
		/*Fichero vacio*/
		printf("%10.2f%10.2f\n",cero,cero);
	}
	else{
		/*Fichero no vacio*/
		printf("%10.2f%10.2f\n",max,min);
	}

	fclose(fichero);
	return 0;	
}