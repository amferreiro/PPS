/*
Ecuacion de segundo grado
a * x^2 + b * x + c = 0

Especificaciones:
        1. Soluciones reales --> Guardar en las variables apuntadas por px1, px2.
        2. Soluciones imaginarias --> Parte real en px1
                                      Parte imaginaria en px2 > 0
        3. Solucion no existe --> Fijar las variables apuntadas por px1, px2 a cero.
        4. Solucion unica --> Guardarla en px1
                              Guardar valor NaN(raiz cuadrada de -1) en px2
        5. Funcion debe devolver el numero entero correspondiente al caso encontrado.
*/

#include<stdio.h>
#include<math.h>

/*Variables*/
double discriminante;
double raiz1;
double raiz2;
int caso;

int resolver(double a, double b, double c, double* px1, double *px2){
        discriminante=pow(b, 2.0)-4*a*c;

        /*Soluciones Reales*/
        if(discriminante>=0.0){
                raiz1=((-b+sqrt(discriminante))/(2.0*a));
                raiz2=((-b-sqrt(discriminante))/(2.0*a));
                *px1=raiz1;
                *px2=raiz2;
                caso=1;
        }
        else{
                /*Soluciones Imaginarias*/
                raiz1=(-b/(2.0*a));
                raiz2=(sqrt(-discriminante)/(2.0*a));
                *px1=raiz1;
                if(raiz2>0)*px2=raiz2;
                else *px2=-raiz2;
                caso = 2;

        }
        
        if(a==0.0){
        	/*No es una ecuacion*/
                if(b==0.0){
                        *px1=0.0;
                        *px2=0.0;
                        caso=3;
                }
                else{
                	/*No es ec2g*/
                        raiz1=(-c/b);
                        raiz2=sqrt(-1.0);
                        *px1=raiz1;
                        *px2=raiz2;
                        caso=4;
                }
        
        }
        return caso;
}
