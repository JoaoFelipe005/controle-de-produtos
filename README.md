# controle-de-produtos

# Sistema de Controle de Produtos em C

Projeto desenvolvido para a disciplina **Programação Estruturada**.  
O objetivo é criar um sistema simples de gerenciamento de produtos utilizando:

- Vetores  
- Structs  
- Strings  
- Funções  
- Leitura de arquivos texto (`produtos.txt`)

O programa lê inicialmente um arquivo contendo 20 produtos e permite diferentes operações sobre os dados carregados em memória.

---

## Funcionalidades

O sistema apresenta um menu com as seguintes opções:

1. **Adicionar produto**  
   - Lê código, nome, preço e quantidade.  
   - Valida código duplicado.  
   - Insere o produto na memória.

2. **Buscar produto por código**  
   - Retorna a posição se o produto existir.  
   - Exibe os dados do produto encontrado.

3. **Imprimir produtos**  
   - Lista todos os produtos carregados ou adicionados.

4. **Ordenar por preço e imprimir**  
   - Ordena os produtos do mais barato ao mais caro usando *bubble sort*.  
   - Imprime os produtos ordenados.

5. **Sair**  
   - Encerra o programa.

Cada linha no arquivo deve ter:  
`codigo nome preco quantidade`

Exemplo:
101 Arroz 5.49 20
102 Feijao 8.90 15
103 Macarrao 4.25 12

Observação: o nome não pode ter espaços (o programa lê com `%s`).

## Como compilar e executar
gcc projeto.c -o projeto.exe
./projeto.exe
