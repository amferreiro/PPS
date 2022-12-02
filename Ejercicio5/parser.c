#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "parser.h"

#define MaxPalabra 250

/*POSIBLES ERRORES:
	- No hay cabecera
	- Cabecera vacia
	- Linea más o menos campos que cabecera
*/

int parser(FILE * file){
	/*Variables*/
	char cabecera[MaxPalabra][MaxCampos];
	char linea[MaxLinea];
	char* campo;
	int tam;
	int i=0;

	/*Leer cabecera*/
	if(fgets(linea,MaxLinea,file)==NULL){
		/*Fichero Vacio*/
		fprintf(stderr,"ERROR: Fichero vacio\n");
		return -1;
	}

	linea[strlen(linea)-1]='\0';
	campo = strtok(linea,",");
	while(campo!=NULL){
		strcpy(cabecera[i],campo);
		i++;
		campo = strtok(NULL, ",");
	}
	tam=i;

	/*Cabecera vacia*/
	if(tam==0){
		fprintf(stderr,"ERROR: Cabecera vacia\n");
		return -1;
	}
	if(tam>15){
		fprintf(stderr,"ERROR: Cabecera de mayor tamaño a lo permitido\n");
		return -1;
	}

	/*Leer lineas*/
	while(fgets(linea,MaxLinea,file)){
		if(linea[0]!='\n'){
			linea[strlen(linea)-1]='\0';
			campo=strtok(linea,",");
			i=0;
			while(campo!=NULL){
				/*Mas campos que los indicados en la cabecera*/
				if(i>=tam){
					fprintf(stderr,"ERROR: Mas campos que los indicados en la cabecera\n");
					return -1;
				}
				if(i==tam-1)
					printf("%s: %s",cabecera[i],campo);
				else
					printf("%s: %s; ",cabecera[i],campo);
				i++;
				campo = strtok(NULL, ",");
			}
			/*Menos campos que los indicados en la cabecera*/
			if(i!=tam){
				fprintf(stderr,"ERROR: Menos campos que los indicados en la cabecera\n");
				return-1;
			}
			printf("\n"); 
		}
	}

	return 0;
}

