#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

 typedef struct produto {
    int codigo, qtd_estoque;
	char descricao[100];
    float valor;   
 }Produto,* PProduto;
/* Com o uso do typedef uma variável do tipo "struct produto" pode ser declarada
 apenas como "Produto" e um ponteiro para esta estrutura como "PProduto"*/

PProduto incluir_produto(int* num_produtos){
    int i;
    PProduto pp;
    //num_produtos é uma variável que será lida para guardar o número de alunos inseridos 
    printf("Informe o numero de alunos a serem inseridos: ");
    scanf("%d",num_produtos);
    pp = (PProduto) malloc((*num_produtos)*sizeof(Produto));
    if (pp == NULL){
       printf("FALTOU MEMORIA");
       exit(1);     
    }
        
    for(i=0;i<(*num_produtos);i++){     
      printf("Informe o codigo do produto: "); 
      scanf("%d",&pp[i].codigo);  
	  printf("Informe a descricao do produto: "); 
      scanf(" %[^\n]",pp[i].descricao);
      printf("Informe a quantidade em estoque do produto: "); 
      scanf("%d",&pp[i].qtd_estoque);  
      printf("Informe o valor do produto: ");   
      scanf("%f",&pp[i].valor);
    }

    /* Nesta versão podemos usar o "." para acessar as variáveis do struct, pois
       o vetor  contém estruturas estáticas e o uso dos colchetes [i] permite
       acessar diretamente o conteúdo da célula de um vetor */

   /*O & foi usado, pois a função "scanf" necessita saber o endereço da variável.
   No caso do nome não foi necessário, pois em C um String é tratado como um vetor
   de caracteres e o nome dado a um vetor sempre representa o endereço
   da sua primeira posição.*/
      
   return pp;  
}

void imprimir_produtos(int num_produtos, PProduto pp){
  int i;                       
  for(i=0;i<num_produtos;i++){     
    printf("Descricao: %s Codigo: %d Quantida em Estoque: %d  Valor em R$: %.2f\n",pp[i].descricao,pp[i].codigo,pp[i].qtd_estoque,pp[i].valor);
  }                                         
}

