#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "produto.h"
#include "pedido.h"

//GERENCIAR
int menu_principal(){
	int opcao = 0;
	printf("\n-------------------------");
	printf("\n        LOJA XPTO        ");
	printf("\n-------------------------");
	printf("\n(1) Gerenciar Produto");
	printf("\n(2) Gerenciar Pedido");
	printf("\n(3) Sair");
	printf("\n\nSelecionar opcao: ");
	scanf("%d", &opcao);
	return opcao;
}

void gerenciar_menu_principal(Produto* produto, Pedido* pedido){
	int opcao;
	int sair = 0;
	do{
		opcao = menu_principal();
		switch(opcao){
			case 1:
				produto = gerenciar_menu_produto(produto);
				break;
			case 2:
				gerenciar_menu_pedido(produto, pedido);
				break;
			case 3:
				exit(0);
				break;
			default:
				printf("Opcao Invalida!!!\n");
				exit(0);
		}
	}while(!sair);
}

//CODIGO
int main(int argc, char** argv){
	
	Produto* produtos = NULL;
	Pedido* pedidos = NULL;
		
	gerenciar_menu_principal(produtos, pedidos);
	return 0;
}
