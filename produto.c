//Struct do produto
struct produto{
	int codigo;
	char descricao[100];
	int qtd_estoque;
	float valor;
};

//Verifica se array de produtos está vazio ou não
int vazio_vet(int*vet){
	return vet == NULL;
}

Produto* incluir_produto(Produto *p, int *qtd, int *max){
	
	if(vazio_vet(p)){ //ou poderia ser if(qtd==0) ou if(!qtd)
		printf("\nO vetor estava vazio - primeira alocacao!");
		Produto p = (Produto*) malloc(FATOR_REALLOC *sizeof(Produto));
		if(!p){ //não conseguiu espaço em memória
			return NULL;
		}
		*max = 2;
		*qtd = 0;
	}
	
	if(*qtd == *max){ //meu vetor está cheio
		printf("\nO vetor precisa de realocacao!");
		p = (Produto*) realloc(p, (*max*FATOR_REALLOC)*sizeof(Produto));
		if(!p){ //não conseguiu espaço em memória
			return NULL;
		}
		*max = *max + 2;
	}
	
	p[*qtd];
	
	for(int i=0; i<qtd; i++) {
    	printf("Digite a descricao do produto: ");
		fgets(p[i].descricao, 100, stdin);
		printf("Digite o codigo do produto: ");
		scanf("%d", &p[i].codigo);
		scanf("%c");
		printf("Digite a quantidade do produto: ");
		scanf("%d", &p[i].qtd_estoque);
		printf("Digite o preco ao consumidor: ");
		scanf("%f", &p[i].valor);
	}
	
	for(int i=0; i<qtd; i++) {
    	printf("\nDescricao: %s", p[i].descricao);
		printf("\nCodigo: %d", p[i].codigo);
		printf("\nEstoque: %d", p[i].qtd_estoque);
		printf("\nPreco: %.2f", p[i].valor);
	}
		
	*qtd = *qtd + 1;
	getch();
	return p;		
}


//altera um produto do estoque. A lógica envolvida primeira encontramos o produto, depois alteramos seus dados
Produto buscar_produto(Produto* p, int qtd, int elem){
	
	int i;
	
	for(i=0;i<qtd;i++){
		if(vet[i]==elem){
			return i;
		}
	}
	return -1;
}

Produto* alterar_produto(){
	
	
	
}
