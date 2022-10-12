#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct produto {
    int codigo, qtd_estoque;
	char descricao[40];
    float valor;   
 }Produto,* PProduto;
/* Com o uso do typedef uma variável do tipo "struct produto" pode ser declarada
 apenas como "Produto" e um ponteiro para esta estrutura como "PProduto"*/

PProduto incluir_produto(int* num_produtos){
    int i;
    PProduto pa;
    //num_produtos é uma variável que será lida para guardar o número de produtos inseridos 
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

    /* Nesta versão podemos usar o "." para acessar as variáveis do struct, pois
       o vetor  contém estruturas estáticas e o uso dos colchetes [i] permite
       acessar diretamente o conteúdo da célula de um vetor */

   /*O & foi usado, pois a função "scanf" necessita saber o endereço da variável.
   No caso do descricao não foi necessário, pois em C um String é tratado como um vetor
   de caracteres e o descricao dado a um vetor sempre representa o endereço
   da sua primeira posição.*/
      
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
   
   Produtos = incluir_Produto(&qtd_Produtos); //ATENÇÃO nesta versão a função incluir passou a retornar o ponteiro para o início do vetor
   //, pois a alocação dinâmica do vetor foi feita dentro da função e o escopo global não iria visualizar este endereço, ocasionando erro de execução.
   
   imprimir_Produtos(10,Produtos);
      
   system("PAUSE");	
   return 0;
}
