#include <stdio.h>
#include <stdlib.h>

typedef struct produto Produto,* PProduto;

PProduto incluir_produto(int* num_produtos);
void imprimir_produtos(int num_produtos, PProduto pp);
