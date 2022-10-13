#ifndef PEDIDO_H
# define PEDIDO_H
#include "produto.h"
int 			qtdPed;
int 			maxPed;
typedef struct	pedido Pedido;

void	adicionar_produto_carrinho(Produto* produto, Pedido* pedido);
void	consultar_carrinho_compras(Pedido* pedido, int qtd);
void	excluir_produto_carrinho();
void	alterar_quantidade_produto_carrinho();
void	esvaziar_carrinho(Pedido* pedido);
void	finalizar_pedido();
int		menu_pedido();
void	gerenciar_menu_pedido(Produto* produto, Pedido* pedido);
#endif
