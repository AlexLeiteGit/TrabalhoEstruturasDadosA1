
typedef struct produto Produto;

//Verifica se array de produtos est� vazio ou n�o
int vazio_vet(int*vet){
	return vet == NULL;
}

Produto* incluir_produto(Produto *p, int *qtd, int *max);


//altera um produto do estoque. A l�gica envolvida primeira encontramos o produto, depois alteramos seus dados
Produto buscar_produto(Produto* p, int qtd, int elem);

Produto* alterar_produto();
