#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define	SIZE 64
int matriz1[SIZE][SIZE];
int matriz2[SIZE][SIZE];
int matrizr[SIZE][SIZE];

int main(void){

	int m, n, p;
	int i, j, a;

	scanf("%d",&m); 
	scanf("%d",&n); 
	scanf("%d",&p); 

	/*lee primera matriz*/
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matriz1[i][j]);
		}
	}
	

	/*lee segunda matriz*/
	for(i=0;i<n;i++){
		for(j=0;j<p;j++){
			scanf("%d",&matriz2[i][j]);
		}
	}


	/*multiplica matrices*/
	for(a=0; a<p;a++){
		for(i=0;i<m;i++){
			int suma=0;
			for(j=0;j<n;j++){
				suma += matriz1[i][j] * matriz2[j][a];
			}
			matrizr[i][a] = suma;
		}
	}


	/*escribe la matriz resultado*/
	for(i=0;i<m;i++){
		for (j=0;j<p-1; j++){
			printf("%d ",matrizr[i][j]);
		}
		printf("%d\n",matrizr[i][p-1]);
	}
	return 0;
}
