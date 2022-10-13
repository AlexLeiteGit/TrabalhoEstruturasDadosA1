#include "produto.h"

int qtdProd = 0;
int maxProd = 0;

struct produto{
	int codigo;
	char descricao[50];
	int qtd_estoque;
	float preco;
};

Produto* incluir_produto(Produto* produto){
	if(maxProd == 0){
		maxProd = REALLOCFACT;
		produto = (Produto*) malloc(maxProd * sizeof(Produto));
	}
	if(qtdProd == maxProd){
		produto = (Produto*) realloc(produto, (maxProd + REALLOCFACT) * sizeof(Produto));
		if (produto == NULL){
			printf("\n\nMemoria insuficiente\n\n");
			exit(0);           
	    }
		maxProd = maxProd + REALLOCFACT;
	}
	printf("Cadastrando produto: %d\n", qtdProd+1);
	printf("Digite o codigo do produto: ");
	scanf("%d", &produto[qtdProd].codigo);
	getchar();
	
	printf("Digite a descricao do produto: ");
	scanf("%s", produto[qtdProd].descricao); 
	getchar();
	
	printf("Digite a quantidade inicial do produto em estoque: ");
	scanf("%d", &produto[qtdProd].qtd_estoque);
	getchar();
	
	printf("Digite o preco do produto: ");
	scanf("%f", &produto[qtdProd].preco);
	getchar();
	
	printf("\nProduto cadastrado com sucesso\n");
	consultar_produto(produto, qtdProd);
	qtdProd++;
	
	return produto;
}

void alterar_produto(Produto* produto){
	int codProd;
	int index = 0;
	printf("Por favor, digite o codigo do produto desejado. ");
	scanf("%d", &codProd);
	index = buscar_produto_codigo(produto, codProd, true);
	if(index == ITEM_NAO_ENCONTRADO){
		printf("\nItem nao encontrado!!!\n\n");
		return;
	}
	//ALTERACAO
	int opcao;
	int sair = 0;
	do{
		printf("\nInformacoes do produto:\n Codigo: %d\n Descricao: %s\n Quantidade em estoque: %d\n Preco: %.2f\n",
			produto[index].codigo,
			produto[index].descricao,
			produto[index].qtd_estoque,
			produto[index].preco
		);
		printf("\nQual informacao voce deseja editar ?");
		printf("\n(1) Codigo");
		printf("\n(2) Descricao");
		printf("\n(3) Quantidade em estoque");
		printf("\n(4) Preco");
		printf("\n(5) Sair");
		printf("\n\nSelecionar opcao: ");
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				printf("\nDigite o novo codigo do produto: ");
				scanf("%d", &produto[index].codigo);
				getchar();
				printf("\nAlterado com sucesso!\n");
				break;
			case 2:
				printf("Digite a nova descricao do produto: ");
				scanf("%s", produto[index].descricao);
				getchar();
				printf("\nAlterado com sucesso!\n");
				break;
			case 3:
				printf("Digite a nova quantidade do produto em estoque: ");
				scanf("%d", &produto[index].qtd_estoque);
				getchar();
				printf("\nAlterado com sucesso!\n");
				break;
			case 4:
				printf("Digite o novo preco do produto: ");
				scanf("%f", &produto[index].preco);
				getchar();
				printf("\nAlterado com sucesso!\n");
				break;
			case 5:
				sair = 1;
				break;
			default:
				printf("\nOpcao Invalida!!!\n\n");
				sair = 0;
		}
	}while(!sair);
}

void listar_produtos(Produto* produto, int qtd, bool isVazio){
	int i = 0;
	if(qtd == 0){
		printf("Lista se encontra vazia!\n");
	}
	for (i = 0; i < qtd; i++){
		if(isVazio){
			printf("Produto : -- Codigo: %d -- Descricao: %s -- Quantidade em estoque: %d -- Preco: %.2f\n", 
				produto[i].codigo,
				produto[i].descricao,
				produto[i].qtd_estoque,
				produto[i].preco
			);
		}
		else if(produto[i].qtd_estoque > 0){			
			printf("Produto : -- Codigo: %d -- Descricao: %s -- Quantidade em estoque: %d -- Preco: %.2f\n", 
				produto[i].codigo,
				produto[i].descricao,
				produto[i].qtd_estoque,
				produto[i].preco
			);
		}
	}
	printf("\n");
}

int buscar_produto_codigo(Produto* produto, int codigo, bool isVazio){
	int i = 0;
	int retorno = ITEM_NAO_ENCONTRADO;
	for(i=0; i<qtdProd; i++){
		if(produto[i].codigo == codigo){
			if(isVazio){
				return i;
			}
			else if(produto[i].qtd_estoque > 0){
				return i;
			}
		}
	}
	return retorno;
}

void consultar_produto(Produto* produto, int index){
	if(index == ITEM_NAO_ENCONTRADO){
		int codProd;
		printf("Por favor, digite o codigo do produto desejado. ");
		scanf("%d", &codProd);
		index = buscar_produto_codigo(produto, codProd, true);
		if(index == ITEM_NAO_ENCONTRADO){
			printf("\nItem nao encontrado!!!\n\n");
			return;
		}			
	}
	printf("\nInformacoes do produto:\n Codigo: %d\n Descricao: %s\n Quantidade em estoque: %d\n Preco: %.2f\n\n", 
		produto[index].codigo,
		produto[index].descricao,
		produto[index].qtd_estoque,
		produto[index].preco
	);
}

void excluir_produto(Produto* produto){
	int codProd;
	int index = 0;
	printf("Por favor, digite o codigo do produto desejado. ");
	scanf("%d", &codProd);
	index = buscar_produto_codigo(produto, codProd, true);
	if(index == ITEM_NAO_ENCONTRADO){
		printf("\nItem nao encontrado!!!\n\n");
		return;
	}
	//EXCLUSAO
	if(qtdProd == 1 || index == qtdProd - 1){
		qtdProd--;
		printf("\nProduto excluido com sucesso\n");
	}
	else{
		produto[index].codigo = produto[qtdProd-1].codigo;
		strcpy(produto[index].descricao, produto[qtdProd-1].descricao);
		produto[index].qtd_estoque = produto[qtdProd-1].qtd_estoque;
		produto[index].preco =	produto[qtdProd-1].preco;
		qtdProd--;
		printf("\nProduto excluido com sucesso\n");
	}	
}

void gravar_estoque(Produto* produto){
	FILE *pont_arq;
	
	pont_arq = fopen("estoque.txt", "w");
	
	if(pont_arq == NULL){
		fprintf(pont_arq, "Erro na criação do arquivo!");

	} else {
		printf("Gravando o estoque da Loja!\n");
		int i;                       
  		for(i=0;i<num_produtos;i++){     
    		fprintf(pont_arq, "Descricao: %s Codigo: %d Quantida em Estoque: %d  Valor em R$: %.2f\n", pp[i].descricao,pp[i].codigo,pp[i].qtd_estoque,pp[i].valor);
  		}
	}
	
	fclose(pont_arq);
	
	printf("Estoque Gravado com Sucesso!\n");	
}

int menu_produto(){
	int opcao;
	printf("#########################\n");
	printf("    Gerenciar Produto    \n");
	printf("#########################\n");
	printf("\n(1) Incluir");
	printf("\n(2) Alterar");
	printf("\n(3) Listar");
	printf("\n(4) Consultar");
	printf("\n(5) Excluir");
	printf("\n(6) Voltar");
	printf("\n\nSelecionar opcao: ");
	scanf("%d", &opcao);
	return opcao;
}

Produto* gerenciar_menu_produto(Produto* produto){
	int opcao;
	int sair = 0;
	do{
		opcao = menu_produto();
		switch(opcao){
			case 1:
				printf("\nIncluir Produto\n\n");
				produto = incluir_produto(produto);
				break;
			case 2:
				printf("\nAlterar Produto\n\n");
				alterar_produto(produto);
				break;								
			case 3:
				printf("\nListar produtos\n\n");
				listar_produtos(produto, qtdProd, true);
				break;
			case 4:
				printf("\nConsultar Produto\n\n");
				consultar_produto(produto, ITEM_NAO_ENCONTRADO);
				break;
			case 5:
				printf("\nExcluir Produto\n\n");
				excluir_produto(produto);
				break;								
			case 6:
				exit(0);				
				return produto;
				break;
			default:
				printf("Opcao Invalida!!!\n");
				sair = 0;
		}	
	}while(!sair);	
}
