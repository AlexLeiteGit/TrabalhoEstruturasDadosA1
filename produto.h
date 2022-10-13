#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int ITEM_NAO_ENCONTRADO;
int REALLOCFACT;

int qtdProd;
int maxProd;
typedef struct produto Produto;

Produto* incluir_produto(Produto* produto);
void alterar_produto(Produto* produto);
void listar_produtos(Produto* produto, int qtd, bool isVazio);
int buscar_produto_codigo(Produto* produto, int codigo, bool isVazio);
void consultar_produto(Produto* produto, int index);
void excluir_produto(Produto* produto);
void gravar_estoque(Produto* produto);

int menu_produto();
Produto* gerenciar_menu_produto(Produto* produto);
