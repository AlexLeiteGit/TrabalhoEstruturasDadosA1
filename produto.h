#ifndef	PRODUTO_H
# define PRODUTO_H
int				qtdProd;
int				maxProd;

typedef struct	produto Produto;
typedef struct	produto_l ProdutoLista;

Produto*	incluir_produto(Produto* produto);
void		alterar_produto(Produto* produto);
void		listar_produtos(Produto* produto, int qtd, bool isVazio);
int			buscar_produto_codigo(Produto* produto, int codigo, bool isVazio);
void		consultar_produto(Produto* produto, int index);
void		excluir_produto(Produto* produto);
void		gravar_estoque_arquivo(Produto* produto, int qtdProd);
void		adicionar_estoque_arquivo(Produto* produto, int qtdProd);
int			menu_produto();
Produto*	gerenciar_menu_produto(Produto* produto);
#endif
