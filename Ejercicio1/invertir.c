#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 1000
#define TAM_PALABRA 256


int main (void){
        /*Variables*/
        char palabra[TAM_PALABRA];
        int array[SIZE];
        int i=0;
        int ultimo=0;
        int k=0;
        int num,r;
        bool fin=false;


        while(i<SIZE && !fin){
                r=scanf(" %d",&num);
                /*Error, al leer algo que no es un entero*/
                if(r==0){
                        /*Si no hay nada en el fichero, se acaba el programa*/
                        if(scanf("%s",palabra)==0){
                                fin=true;
                        }
                        /*Imprime el array*/
                        for(k=ultimo-1;k>=1;k--){
                                printf("%d ",array[k]);
                        }
                        printf("%d\n",array[0]);
                        /*Resetea el array para la nueva secuencia*/
                        ultimo=0;
                        i++;
                /*Lee entero y lo añade al array*/
                }else{
                        array[ultimo]=num;
                        ultimo++;
                        i++;
                }
        }
        return 0;
}