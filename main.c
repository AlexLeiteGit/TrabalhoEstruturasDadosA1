#include <stdio.h>
#include <stdlib.h>
#include "produto.h"
#include "menu.h"
#include <math.h>
#include <funcoes_produto.h>

int main(int argc, char *argv[]) {
	
	//gerenciar_menu_principal();
	printf("\nInforme a quantidade de Produtos a serem cadastrados")
	
	
	Produto p[];
	
	printf("Digite a descricao do produto: ");
	fgets(p.descricao, 100, stdin);
	printf("Digite o codigo do produto: ");
	scanf("%d", &p.codigo);
	scanf("%c");
	printf("Digite a quantidade do produto: ");
	scanf("%d", &p.qtd_estoque);
	printf("Digite o preco ao consumidor: ");
	scanf("%f", &p.valor);
	
	
	
	return 0;
}
