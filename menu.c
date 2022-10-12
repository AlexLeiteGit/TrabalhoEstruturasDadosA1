#include <stdio.h>
#include <stdlib.h>
#include "produto.h"
#include "menu.h"
#include <math.h>


//Menu Principal do Sistema
int menu_principal_opcoes(){
	int opcao;
	system("cls");		
	printf("\n(1) Gerenciar Produto");
	printf("\n(2) Gerenciar Pedido");
	printf("\n(3) Sair");
	printf("\n\nDigite uma opcao: ");
	scanf("%d",&opcao);	
	return opcao;
}

//Menu de Gerenciamento de Produtos
int menu_gerenciar_produto_opcoes(){
	int opcao;
	system("cls");	
	printf("\n------------------------");
	printf("\n   Gerenciar Produto");
	printf("\n------------------------");
	printf("\n(1) Incluir");
	printf("\n(2) Alterar");
	printf("\n(3) Listar");
	printf("\n(4) Consultar");
	printf("\n(5) Excluir");
	printf("\n(6) Salvar Estoque em txt");
	printf("\n(7) Imprimir Relatório de Estoque");
	printf("\n(8) Recuperar Estoque em txt");
	printf("\n(8) Voltar");
	printf("\n\nDigite uma opcao: ");
	scanf("%d",&opcao);	
	return opcao;
}

//Menu de Gerenciamento de Pedidos
int menu_gerenciar_pedido_opcoes(){
	int opcao;
	system("cls");	
	printf("\n------------------------");
	printf("\n   Gerenciar Pedido");
	printf("\n------------------------");	
	printf("\n(1) Adicionar produto no carrinho");
	printf("\n(2) Consultar carrinho de compras");
	printf("\n(3) Excluir produto do carrinho");
	printf("\n(4) Alterar quantidade do produto do carrinho");	
	printf("\n(5) Finalizar Pedido");	
	printf("\n(6) Esvaziar carrinho de compras");
	printf("\n(7) Voltar");
	printf("\n\nDigite uma opcao: ");
	scanf("%d",&opcao);	
	return opcao;
}

//Switch de opções de produtos
void gerenciar_menu_produto(){
	int opcao;
	PProduto produtos; 
   	int qtd_produtos;
	int sair = 0;
	do{	
		opcao = menu_gerenciar_produto_opcoes();		
		switch(opcao){
			case 1:
				produtos = incluir_produto(&qtd_produtos);	//ATENÇÃO nesta versão a função incluir passou a retornar o ponteiro para o início 
															//	do vetor, pois a alocação dinâmica do vetor foi feita 
															//dentro da função e o escopo global não iria visualizar este endereço, 
															//ocasionando erro de execução.
				//getch();
				break;
			case 2:
				printf("Alterar Produto");
				getch();
				break;								
			case 3:
				 imprimir_produtos(qtd_produtos,produtos);
				sair = 1;
				break;
			case 4:
				printf("Consultar Produto");				
				getch();
				break;
			case 5:
				printf("Excluir Produto");
				getch();
				break;								
			case 6:
				printf("Voltar");
				sair = 1;
				break;
			default:
				printf("Opcao Invalida!");
				getch();
				sair = 0;			
		}
	}while(!sair);
	
}

//Switch de opções de pedidos
void gerenciar_menu_pedido(){
	int opcao;
	int sair = 0;
	do{	
		opcao = menu_gerenciar_pedido_opcoes();		
		switch(opcao){
			case 1:
				printf("Adicionar produto no carrinho");				
				getch();
				break;
			case 2:
				printf("Consultar carrinho de compras");
				getch();
				break;								
			case 3:
				printf("Excluir produto do carrinho");
				sair = 1;
				break;
			case 4:
				printf("Alterar quantidade do produto do carrinho");				
				getch();
				break;
			case 5:
				printf("Finalizar Pedido");
				getch();
				break;								
			case 6:
				printf("Esvaziar carrinho de compras");
				getch();
				break;								
			case 7:
				printf("Voltar");
				sair = 1;
				break;
			default:
				printf("Opcao Invalida!");
				getch();
				sair = 0;			
		}
	}while(!sair);
	
}

//Switch de gerenciamento do menu principal
void gerenciar_menu_principal(){
	int opcao;
	int sair = 0;
	do{	
		opcao = menu_principal_opcoes();		
		switch(opcao){
			case 1:				
				gerenciar_menu_produto();
				getch();
				break;
			case 2:			
				gerenciar_menu_pedido();
				getch();
				break;								
			case 3:
				printf("Sair");
				sair = 1;
				break;
			default:
				printf("Opcao Invalida!");
				getch();
				sair = 0;			
		}
	}while(!sair);
	
}
