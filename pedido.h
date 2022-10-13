#ifndef PEDIDO_H
# define PEDIDO_H
# include "common.h"
# include "produto.h"

int qtdPed;
int maxPed;

typedef struct pedido Pedido;
typedef struct pedido_l PedidoLista;

PedidoLista* pedido_excluir(PedidoLista* pedido_l);

int buscar_produto_codigo_pedido(PedidoLista* pedido_l, char codigo[10]);
PedidoLista* adicionar_produto_carrinho(ProdutoLista* produto_l, PedidoLista* pedido_l);
void consultar_carrinho_compras(PedidoLista* produto_l, int qtd);
void excluir_produto_carrinho(PedidoLista* produto_l);
//void alterar_quantidade_produto_carrinho(ProdutoLista* produto_l, PedidoLista* pedido_l);
//void finalizar_pedido(PedidoLista* pedido_l);
//PedidoLista* esvaziar_carrinho(PedidoLista* pedido_l);

int menu_pedido();
PedidoLista* gerenciar_menu_pedido(ProdutoLista* produto_l, PedidoLista* pedido_l);

#endif
