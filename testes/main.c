#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct produto {
    int codigo, qtd_estoque;
	char descricao[40];
    float valor;   
 }Produto,* PProduto;
/* Com o uso do typedef uma vari�vel do tipo "struct produto" pode ser declarada
 apenas como "Produto" e um ponteiro para esta estrutura como "PProduto"*/

PProduto incluir_produto(int* num_produtos){
    int i;
    PProduto pa;
    //num_produtos � uma vari�vel que ser� lida para guardar o n�mero de produtos inseridos 
    printf("Informe o numero de produtos a serem inseridos: ");
    scanf("%d",num_produtos);
    pa = (PProduto) malloc((*num_produtos)*sizeof(Produto));
    if (pa == NULL){
       printf("FALTOU MEMORIA");
       exit(1);     
    }
        
    for(i=0;i<(*num_produtos);i++){     
      printf("Informe a codigo: "); 
      scanf("%d",&pa[i].codigo);  
	  printf("Informe o descricao do Produto: "); 
      scanf(" %[^\n]",pa[i].descricao);
      printf("Informe a Quantidade em Estoque do Produto: "); 
      scanf("%d",&pa[i].qtd_estoque);  
      printf("Informe o valor do Produto: ");   
      scanf("%f",&pa[i].valor);
    }

    /* Nesta vers�o podemos usar o "." para acessar as vari�veis do struct, pois
       o vetor  cont�m estruturas est�ticas e o uso dos colchetes [i] permite
       acessar diretamente o conte�do da c�lula de um vetor */

   /*O & foi usado, pois a fun��o "scanf" necessita saber o endere�o da vari�vel.
   No caso do descricao n�o foi necess�rio, pois em C um String � tratado como um vetor
   de caracteres e o descricao dado a um vetor sempre representa o endere�o
   da sua primeira posi��o.*/
      
   return pa;  
}

void imprimir_produtos(int num_produtos, PProduto pa){
  int i;                       
  for(i=0;i<num_produtos;i++){     
    printf("descricao: %s codigo: %d Quantidade em Estoque: %.2d  Valor: %.2f\n",pa[i].descricao,pa[i].codigo,pa[i].qtd_estoque,pa[i].valor);
  }                                         
}

int main(int argc, char *argv[])
{
   PProduto Produtos; 
   int qtd_Produtos = 10;
   
   Produtos = incluir_Produto(&qtd_Produtos); //ATEN��O nesta vers�o a fun��o incluir passou a retornar o ponteiro para o in�cio do vetor
   //, pois a aloca��o din�mica do vetor foi feita dentro da fun��o e o escopo global n�o iria visualizar este endere�o, ocasionando erro de execu��o.
   
   imprimir_Produtos(10,Produtos);
      
   system("PAUSE");	
   return 0;
}
