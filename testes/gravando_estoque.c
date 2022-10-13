#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	FILE *pont_arq;
	
	pont_arq = fopen("arquivo.txt", "a");
	
	fclose(pont_arq);
	
	printf("O arquivo foi criado com sucesso!\n");
	
	system("pause");
	return(0);
}
