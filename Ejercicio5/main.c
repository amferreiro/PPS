#include <stdio.h>

#include "parser.h"


int main(int argc, char const *argv[])
{	
	FILE *file;
	char path[90382];
	int res;
	/*Test num argumentos*/
	if(argc>2)
		return -1;

	if(argc==2){
		file=fopen(argv[1],"r");
	}
	else{
		scanf("%s",path);
		file=fopen(path,"r");
	}
	
	if(file==NULL)
		return -1;
	
	res = parser(file);

	return res;

}