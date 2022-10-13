#include "pedido.h"

typedef struct produto{
	char codigo[10];
	char descricao[50];
	int qtd_estoque;
	float preco;
}Produto;

typedef struct produto_l{
	Produto* produto;
}ProdutoLista;

int qtdPed = 0;
int maxPed = 0;

char codigo[10];
//bool finalizado = false;
float totalGeral = 0;

struct pedido{
	Produto* produto;
	int quantidade;
	float preco;
	float total;
};

struct pedido_l{
	Pedido* pedido;
};

PedidoLista* excluir_pedido(PedidoLista* pedido_l){
	int ped = 0;
	for(ped = 0; ped < qtdPed; ped++){
		free(pedido_l[ped].pedido);
	}
	qtdPed = 0;
	totalGeral = 0;
	//finalizado = false;
	maxPed = REALLOCFACT;
	strcpy(codigo,"");
	pedido_l = (PedidoLista*) realloc(pedido_l, REALLOCFACT * sizeof(PedidoLista));
}

Pedido* incluir_pedido(){
	return (Pedido*) malloc(sizeof(Pedido));
}

int buscar_produto_codigo_pedido(PedidoLista* pedido_l, char codigo[10]){
	int i = 0;
	int retorno = ITEM_NAO_ENCONTRADO;
	for(i = 0; i < qtdProd; i++){
		if(!strcmp(pedido_l[i].pedido->produto->codigo, codigo)){
			return i;
		}
	}
	return retorno;
}

PedidoLista* adicionar_produto_carrinho(ProdutoLista* produto_l, PedidoLista* pedido_l){
	//LISTAR PRODUTOS DISPONIVEIS
	printf("Produtos Disponiveis\n\n");
	listar_produtos(produto_l, qtdProd, false);
	//SELECIONAR O PRODUTO
	char codProd[10];
	printf("Digite o codigo do produto desejado! ");
	scanf("%s", codProd);
	//VERIFICAR EXISTENCIA
	int prodResult = buscar_produto_codigo(produto_l, codProd, false);
	if(prodResult > ITEM_NAO_ENCONTRADO){
		consultar_produto(produto_l, prodResult);
	}else{
		printf("\n\nPRODUTO NAO ENCONTRADO\n\n");
		adicionar_produto_carrinho(produto_l, pedido_l);
	}

	//MALLOC LISTAPEDIDO
	if(maxPed == 0){
		maxPed = REALLOCFACT;
		pedido_l = (PedidoLista*) malloc(maxPed * sizeof(PedidoLista));
		if (pedido_l == NULL){
			printf("\n\nMemoria insuficiente\n\n");
			exit(0);
	    }
	}
	//REALLOC LISTAPEDIDO
	if(qtdPed == maxPed){
		pedido_l = (PedidoLista*) realloc(pedido_l, (maxPed + REALLOCFACT) * sizeof(PedidoLista));
		if (pedido_l == NULL){
			printf("\n\nMemoria insuficiente\n\n");
			exit(0);
	    }
	    maxPed = maxPed + REALLOCFACT;
	}
	//MALLOC PEDIDO
	pedido_l[qtdPed].pedido = incluir_pedido();

	//INCLUIR PEDIDO
	pedido_l[qtdPed].pedido->produto = produto_l[prodResult].produto;
	pedido_l[qtdPed].pedido->preco = produto_l[prodResult].produto->preco;
	
	//VERIFICAR QUANTIDADE DISPONIVEL
	do{
		printf("\nDigite a quantidade de produto desejada! ");
		scanf("%d", &pedido_l[qtdPed].pedido->quantidade);
	}while(!consulta_disponibilidade(produto_l, prodResult, pedido_l[qtdPed].pedido->quantidade));
	
	pedido_l[qtdPed].pedido->total = pedido_l[qtdPed].pedido->quantidade * pedido_l[qtdPed].pedido->preco;
	totalGeral += pedido_l[qtdPed].pedido->total;
	qtdPed++;
	printf("\nProduto adicionado com sucesso!\n\n");
	return pedido_l;
}

void consultar_carrinho_compras(PedidoLista* pedido_l, int qtd){
	int i = 0;
	if(qtd == 0){
		printf("\n\nPedido se encontra vazio!\n\n");
		return;
	}
	printf("\n\n# Pedido : -- %s", codigo);
	if(!finalizado)
		printf("\nStatus : ABERTO");
	else
		printf("\nStatus : FINALIZADO");
	printf("\n\nItens :\n");
	for (i = 0; i < qtd; i++){
		printf("\Codigo: %s -- Descricao: %s -- Quantidade: %d -- Preco Unitario: %.2f -- Total: %.2f\n", 
			pedido_l[i].pedido->produto->codigo,
			pedido_l[i].pedido->produto->descricao,
			pedido_l[i].pedido->quantidade,
			pedido_l[i].pedido->produto->preco,
			pedido_l[i].pedido->total
		);
	}
	printf("\nA pagar : -- %.2f\n", totalGeral);
	printf("\n");	
}

void excluir_produto_carrinho(PedidoLista* pedido_l){
	consultar_carrinho_compras(pedido_l, qtdPed);
	char codProd[10];
	int index = 0;
	printf("Por favor, digite o codigo do produto a ser exluido. ");
	scanf("%s", codProd);
	index = buscar_produto_codigo_pedido(pedido_l, codProd);
	if(index == ITEM_NAO_ENCONTRADO){
		printf("\nItem nao encontrado!!!\n\n");
		return;
	}
	//EXCLUSAO
	if(qtdPed == 1 || index == qtdPed - 1){
		//LIMPA O VET DE PEDIDO
		totalGeral -= pedido_l[index].pedido->total;
		free(pedido_l[index].pedido);
		qtdPed--;
	}
	else{
		totalGeral -= pedido_l[index].pedido->total;
		pedido_l[index].pedido->produto = pedido_l[qtdPed - 1].pedido->produto;
		pedido_l[index].pedido->preco = pedido_l[qtdPed - 1].pedido->preco;
		pedido_l[index].pedido->quantidade = pedido_l[qtdPed - 1].pedido->quantidade;
		pedido_l[index].pedido->total = pedido_l[qtdPed - 1].pedido->total;
		//LIMPA O VET DE PEDIDO
		free(pedido_l[qtdPed-1].pedido);
		qtdPed--;
	}
	printf("\nProduto excluido com sucesso\n\n");
}

/*void alterar_quantidade_produto_carrinho(ProdutoLista* produto_l, PedidoLista* pedido_l){
	consultar_carrinho_compras(pedido_l, qtdPed);
	char codProd[10];
	int index = 0;
	printf("Por favor, digite o codigo do produto desejado. ");
	scanf("%s", codProd);
	index = buscar_produto_codigo_pedido(pedido_l, codProd);
	int prodResult = buscar_produto_codigo(produto_l, codProd, false);
	if(index == ITEM_NAO_ENCONTRADO){
		printf("\nItem nao encontrado!!!\n\n");
		return;
	}	
	//VERIFICAR QUANTIDADE DISPONIVEL
	int quantidadeNova = 0;
	do{
		printf("\nDigite a quantidade de produto desejada! ");
		scanf("%d", &quantidadeNova);
	}while(!consulta_disponibilidade(produto_l, prodResult, quantidadeNova));
	
	//ACERTAR VALORES
	totalGeral -= pedido_l[index].pedido->total;
	pedido_l[index].pedido->quantidade = quantidadeNova;
	pedido_l[index].pedido->total = pedido_l[index].pedido->quantidade * pedido_l[index].pedido->preco;
	totalGeral += pedido_l[index].pedido->total;
}*/

/*void finalizar_pedido(PedidoLista* pedido_l){
	printf(codigo, "%lld", rand_code());
	finalizado = true;
	int i = 0;
	for (i = 0; i < qtdPed; i++){
		pedido_l[i].pedido->produto->qtd_estoque -= pedido_l[i].pedido->quantidade;
	}
	printf("\nPedido finalizado com sucesso!\n");
	consultar_carrinho_compras(pedido_l, qtdPed);
}*/

/*PedidoLista* esvaziar_carrinho(PedidoLista* pedido_l){
	int i = 0;
	for(i = 0; i < qtdPed; i++){
		free(pedido_l[i].pedido);
	}
	qtdPed = 0;
	maxPed = REALLOCFACT;
	totalGeral = 0;
	pedido_l = (PedidoLista*) realloc(pedido_l, REALLOCFACT * sizeof(PedidoLista));
	printf("\n\nCarrinho esvaziado com sucesso!\n\n");
	return pedido_l;
}*/

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

PedidoLista* gerenciar_menu_pedido(ProdutoLista* produto_l, PedidoLista* pedido_l){
	int opcao;
	int sair = 0;
	do{
		opcao = menu_pedido();
		switch(opcao){
			case 1:
				printf("\nAdicionar produto no carrinho\n\n");
				if(finalizado){
					printf("Pedido ja se encontra finalizado\n");
				}
				else{
					pedido_l = adicionar_produto_carrinho(produto_l, pedido_l);
				}				
				break;
			case 2:
				printf("\nConsultar carrinho de compras");
				consultar_carrinho_compras(pedido_l, qtdPed);
				break;								
			case 3:
				printf("\nExcluir produto do carrinho");
				if(finalizado){
					printf("\n\nPedido ja se encontra finalizado\n");
				}
				else{
					excluir_produto_carrinho(pedido_l);
				}				
				break;
			case 4:
				printf("\nAlterar quantidade do produto do carrinho");
				if(finalizado){
					printf("\n\nPedido ja se encontra finalizado\n");
				}
				else{
					alterar_quantidade_produto_carrinho(produto_l, pedido_l);
				}				
				break;
			case 5:
				printf("\nFinalizando Pedido...\n\n");
				if(finalizado){
					printf("Pedido ja se encontra finalizado\n");
				}
				else{
					finalizar_pedido(pedido_l);
				}
				break;
			case 6:
				printf("\nEsvaziar carrinho de compras\n\n");
				if(finalizado){
					printf("Pedido ja se encontra finalizado\n");
				}
				else{
					pedido_l = esvaziar_carrinho(pedido_l);
				}				
				break;
			case 7:
				sair = 1;
				return pedido_l;
				break;
			default:
				printf("Opcao Invalida!\n\n");
				sair = 0;
		}
	}while(!sair);
}
