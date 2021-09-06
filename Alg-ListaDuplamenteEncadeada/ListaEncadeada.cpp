// TRABALHO 2
// LISTA DUPLAMENTE ENCADEADA

#include <stdio.h>
#include <stdlib.h>


// ESTRUTURA DA LISTA LIGADA COM UM NUMERO INTEIRO
// E UM PONTEIRO PARA O PROXIMO NODE DA ESTRUTURA
struct Banco{
    int numero;
    char nome_cliente[30];
    float saldo;
    struct Banco *anterior;
    struct Banco *proximo;
};
typedef struct Banco node;

// INICIALIZACAO DE TODAS AS FUNCOES DO PROGRAMA
void inicia(node *LISTA);
int menu(void);
void opcao(node *LISTA, int op);
node *criaNo();
void insereInicio(node *LISTA);
void insereFim(node *LISTA);
void remover(node* LISTA);
void exibe(node *LISTA);
void libera(node *LISTA);

// FUNCAO PRINCIPAL
int main()
{
    node *LISTA = (node *) malloc(sizeof(node));
    if(!LISTA){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }

    inicia(LISTA);

    int opt=1;

    // ENQUANTO A OPCAO FOR DIREFENTE DE ZERO, O PROGRAMA CONTINUA EM EXECUCAO
    while(opt > 0){
        // OPT IRA RECEBER QUAL A FUNCAO O USUARIO SELECIONOU
        opt=menu();
        // DE ACORDO COM A OPCAO SELECIONADA, IRA EXECUTAR A ACAO PARA A LISTA
        opcao(LISTA,opt);
    }

    // LIBERA O ESPACO EM MEMORIA UTILIZADO PELA LISTA
    free(LISTA);
    
	return 0;
}

// INICIA A LISTA LIGADA COM NULL POIS INICIALMENTE A LISTA ESTA VAZIA
void inicia(node *LISTA)
{
    LISTA->anterior = NULL;
    LISTA->proximo = NULL;
}

// FUNCAO QUE IMPRIME AS OPCOES PARA O USUARIO, FAZ A LEITURA DA OPCAO
// DE ACORDO COM A ESCOLHA DO USUARIO E RETORNA O VALOR INFORMADO
int menu(void)
{
    int opt;

    //IMPRIME AS OPCOES
    printf ("\n \n ALUNO: Marcus Rolim\n\n");
	printf("Escolha a opcao\n");
    printf("0. Sair\n");
    printf("1. Exibir lista\n");
    printf("2. Adicionar node no inicio\n");
    printf("3. Adicionar node no final\n");
    printf("4. Remove node da lista\n");
    printf("5. Liberar toda lista\n");
    printf("Opcao: ");
    

    // LE A OPCAO QUE O USUARIO DESEJA
    scanf("%d", &opt);

    return opt;
}

// FUNCAO QUE INVOCA AS OPCOES DA LISTA DE ACORDO COM A OPCAO QUE O USUARIO INFORMOU
void opcao(node *LISTA, int op)
{
    switch(op){
        case 0:
            // INVOCA A FUNCAO QUE LIBERA ESPACO ALOCADO PELA LISTA
            printf("\nEncerrando o programa.\n\n");
            libera(LISTA);
            break;

        case 1:
            // INVOCA A FUNCAO QUE IMPRIME A LISTA
            printf("\nExibir lista!\n\n");
            exibe(LISTA);
            break;

         case 2:
            // INVOCA A FUNCAO QUE INSERE NO INICIO DA LISTA
            printf("\nInserindo no inicio da lista!\n\n");
            insereInicio(LISTA);
            break;
        case 3:
            // INVOCA A FUNCAO QUE INSERE NO FINAL DA LISTA
            printf("\nInserindo no fim da lista!\n\n");
            insereFim(LISTA);
            break;

         case 4:
            // INVOCA A FUNCAO QUE REMOVE UM NODE DA LISTA
            printf("\nRemovendo node da lista!\n\n");
            remover(LISTA);
            break;
        case 5:
            // INVOCA A FUNCAO QUE REMOVE UM NODE DA LISTA
            printf("\nLiberando todos os nodes da lista!\n\n");
            libera(LISTA);
            break;

        default:
            printf("\nComando invalido\n\n");
    }
}

// FUNCAO QUE VERIFICA SE A LISTA ESTA VAZIA
int vazia(node *LISTA)
{
    if(LISTA->proximo == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void insereInicio(node *LISTA){
 // TENTA ALOCAR ESPACO EM MEMORIA PARA INSERIR NOVO ELEMENTO
    node *novo=(node *) malloc(sizeof(node));
    if(!novo){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }

    printf("Informe numero da conta: ");
    scanf("%d", &novo->numero);
    printf("Informe nome do cliente: ");
    scanf("%s", novo->nome_cliente);
    printf("Informe saldo do cliente: ");
    scanf("%f", &novo->saldo);
    printf("\n\n");

    novo->anterior = NULL;
    novo->proximo = NULL;

    if(vazia(LISTA)){
        LISTA->proximo=novo;

    }
//UTILIZA UMA VARIAVEL AUXILIAR PARA INTERLIGAR O NOVO ITEM COM O PRIMEIRO DA LISTA
    else{
        node *tmp = LISTA->proximo;
		tmp->anterior = novo;
		novo->proximo = tmp;
		LISTA->proximo=novo;
		}
		
}


// FUNCAO QUE INSERE UM ELEMENTO NO FINAL DA LISTA
void insereFim(node *LISTA)
{
    // TENTA ALOCAR ESPACO EM MEMORIA PARA INSERIR NOVO ELEMENTO
    node *novo=(node *) malloc(sizeof(node));
    if(!novo){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }

    printf("Informe numero da conta: ");
    scanf("%d", &novo->numero);
    printf("Informe nome do cliente: ");
    scanf("%s", novo->nome_cliente);
    printf("Informe saldo do cliente: ");
    scanf("%f", &novo->saldo);
    printf("\n\n");

    novo->proximo = NULL;
    novo->anterior = NULL;

    if(vazia(LISTA)){
        LISTA->proximo=novo;

    }
    else{

        node *tmp = LISTA->proximo;

        // PERCORRE A LISTA ENQUANTO O NODE NAO APONTAR PARA NULL
        // QUANDO O NODE FOR IGUAL A NULL, SIGNIFICA QUE ENCONTROU O FINAL DA LISTA
        while(tmp->proximo != NULL){
            tmp = tmp->proximo;
        }

        // QUANDO O NODE TEMP ENCONTRAR O ULTIMO ELEMENTO
        // ELE DEVERA APONTAR PARA O NOVO ELEMENTO QUE SERA INSERIDO
        tmp->proximo = novo;
        novo->anterior = tmp;
    }
}

// DEVE SER FEITA A BUSCA DO VALOR ESCOLHIDO, E ASSIM SUBSTITUIR O ANTERIOR PELO PROXIMO
// FAZENDO ASSIM "PULAR" O  VALOR ESCOLHIDO, E LOGO DEPOIS ZERAR A MEMORIA QUE ELE ESTAVA CONTIDO 
void remover(node* LISTA)
{
	if((LISTA->proximo == NULL) && (LISTA->anterior == NULL)){
        printf("Lista vazia!\n\n");
    }
    else
    {
    	int remove;
		printf ("Digite o numero da conta para ser excluida: ");
    	scanf ("%d", &remove);
    	
    	node *anterior = LISTA;
    	node *atual = LISTA->proximo;
    	while (atual != NULL)
    	{
    		if (atual->numero == remove){
				break;
			}
			else{
				anterior = atual;
				atual = atual->proximo;
			}
		}
		if (atual == NULL)
		{ 
		printf ("Conta nao encontrada!\n");
		}
		else{
			anterior->proximo = atual->proximo;
			free(atual);
			printf ("Conta excluida! \n");
		}
    }
    }
    


// FUNCAO QUE IMPRIME A LISTA
void exibe(node *LISTA)
{
    if(vazia(LISTA)){
        printf("Lista vazia!\n\n");
        return ;
    }

    // CASO CONTARIO PERCORRE TODA A LISTA E VAI IMPRIMINDO OS VALORES DE NUM
    // ATE QUE O NODE APONTE PARA NULL, O QUE IMPLICA QUE CHEGOU AO FINAL DA LISTA
    node *tmp;
    tmp = LISTA->proximo;
    printf("------------------------------------------------------------------------\n");
    while( tmp != NULL){
        printf("Conta do Cliente: %d\n", tmp->numero);
        printf("Nome do cliente: %s\n", tmp->nome_cliente);
        printf("Saldo do cliente: %.2f \n", tmp->saldo);
        printf("Endereco do node ant %d Endereco do node: %d Endereco do node next: %d \n", tmp->anterior, tmp, tmp->proximo);
        printf("------------------------------------------------------------------------\n");
        tmp = tmp->proximo;
    }
    printf("\n\n");
}

//FUNCAO RESPONSAVEL POR PERCERRER TODA LISTA E LIBERAR TODOS OS SEUS NODES ALOCADOS
void libera(node *LISTA)
{
    if(vazia(LISTA)){
        printf("\n\nLista vazia!\n");
    } else{

        node *proxNode, *atual;

        atual = LISTA->proximo;
        while(atual != NULL){
            proxNode = atual->proximo;
            free(atual);
            atual = proxNode;
        }
        LISTA->proximo = NULL;
    }
}

