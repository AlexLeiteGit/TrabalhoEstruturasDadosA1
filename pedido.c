#include "common.h"
#include "pedido.h"

int	qtdPed = 0;
int	maxPed = 0;

struct pedido{
	int codigo;
	int produto;
	int quantidade;
	float preco;
	int total;
};

void adicionar_produto_carrinho(Produto* produto, Pedido* pedido){
	printf("Produtos Disponiveis\n\n");
	listar_produtos(produto, qtdProd, false);
	
	int codProd;
	printf("Digite o codigo do produto desejado! ");
	scanf("%d", &codProd);
	
	int prodResult = buscar_produto_codigo(produto, codProd, false);
	if(prodResult > ITEM_NAO_ENCONTRADO){
		consultar_produto(produto, prodResult);
	}else{
		printf("\n\nPRODUTO NAO ENCONTRADO\n\n");
		adicionar_produto_carrinho(produto, pedido);		
	}		
	
	if(qtdPed == maxPed){
		pedido = (Pedido*) realloc(pedido, (maxPed + 10) * sizeof(Pedido));
		maxPed = maxPed + 10;
	}
	
	pedido[qtdPed].codigo = qtdPed + 1;
	pedido[qtdPed].produto = prodResult;
	pedido[qtdPed].preco = 10;
	
	printf("Digite a quantidade de produto desejada! ");
	scanf("%d", pedido[qtdPed].quantidade);
	pedido[qtdPed].total = pedido[qtdPed].quantidade * pedido[qtdPed].preco;
	
	//Criar um if para conferir a quantidade.
	printf("\nIMPLEMENTAR");
}

void consultar_carrinho_compras(Pedido* pedido, int qtd){
	//Exibir todos os produtos e o total de compras.
	printf("\nIMPLEMENTAR");
}

void excluir_produto_carrinho(){
	printf("\nIMPLEMENTAR");
}

void alterar_quantidade_produto_carrinho(){
	printf("\nIMPLEMENTAR");
}

void esvaziar_carrinho(Pedido* pedido){
	printf("\nIMPLEMENTAR");
}

void finalizar_pedido(){
	printf("\nIMPLEMENTAR");
}


int menu_pedido(){
	int opcao;
	printf("-------------------------\n");
	printf("     Gerenciar Pedido    \n");
	printf("-------------------------\n");
	printf("\n(1) Adicionar produto no carrinho");
	printf("\n(2) Consultar carrinho de compras");
	printf("\n(3) Excluir produto do carrinho");
	printf("\n(4) Alterar quantidade do produto do carrinho");	
	printf("\n(5) Esvaziar carrinho de compras");
	printf("\n(6) Finalizar Pedido");	
	printf("\n(7) Voltar");
	printf("\n\nSelecionar opcao: ");
	scanf("%d", &opcao);
	return opcao;
}

void gerenciar_menu_pedido(Produto* produto, Pedido* pedido){
	int opcao;
	int sair = 0;
	do{	
		opcao = menu_pedido();		
		switch(opcao){
			case 1:
				printf("\nAdicionar produto no carrinho\n\n");
				adicionar_produto_carrinho(produto, pedido);
				break;
			case 2:
				printf("Consultar carrinho de compras");
				consultar_carrinho_compras(pedido, qtdPed);
				break;								
			case 3:
				printf("Excluir produto do carrinho");
				excluir_produto_carrinho();
				break;
			case 4:
				printf("Alterar quantidade do produto do carrinho");
				alterar_quantidade_produto_carrinho();
				break;
			case 5:
				printf("Esvaziar carrinho de compras");
				esvaziar_carrinho(pedido);
				break;								
			case 6:
				printf("Finalizar Pedido");
				finalizar_pedido();
				break;								
			case 7:
				exit(0);
				break;
			default:
				printf("Opcao Invalida!\n\n");
				sair = 0;
		}
	}while(!sair);
}
