#include <stdio.h>
#include <stdlib.h>

//ESTRUTURAS
//Criando a estrutura de cada nó
struct node{
	int info;
	struct node *left;
	struct node *right;
};

//Nomeando o nó
typedef struct node *Tree;

//FUNÇÕES
//Função para criar a raiz da árvore, isto é o primeiro nó da árvore.
Tree* newTree(){
	Tree* mainTree = (Tree*) malloc(sizeof(Tree));
		if (mainTree != NULL){
			*mainTree = NULL;
			return mainTree;	
		}
}

//Função para acionar o menu do programa.
int menu(void);
//Função para executar as opções do menu do programa.
void choice(Tree *mainTree, int option);
//Função para o segundo menu, quando ativado a opção de imprimir.
int print(void);
//Função para executar as opções do segundo menu do programa.
void choice2(Tree *mainTree, int option2);
//Função para imprimir de forma pré-Ordem.
void preOrder(Tree *mainTree);
//Função para imprimir de forma em-Ordem.
void inOrder(Tree *mainTree);
//Função para imprimir de forma pós-Ordem.
void postOrder(Tree *mainTree);
//Função para imprimir o total de nós tem na árvore.
int totalTree(Tree *mainTree);
//Função para adicionar folhas na árvore.
int addSheet(Tree *mainTree, int data);
//Função para remover folhas na árvore.
int delSheet(Tree *mainTree, int data);
struct node *delTemp1(struct node *temp1);
//PROGRAMA PRINCIPAL
int main(){
	
	Tree *mainTree = newTree();
	int option = 5;
	int option2;
	
	while(option > 0){
		option = menu();
		choice(mainTree, option);
		if (option == 1){
		option2 = print();
		choice2(mainTree, option2);
		}
	}
	
	return 0;	
}
//FIM PROGRAMA PRINCIPAL
//INICIO FUNCAO MENU
int menu(){
	
	int option;
	printf("*************************************************\n");
	printf("\tALUNO: MARCUS VINICIUS ROLIM DE OLIVEIRA\n");
	printf("\tCURSO: CIENCIA DA COMPUTACAO\n");
	printf("\tPERIODO: 5 SEMESTRE - NOTURNO\n");
	printf("\tUNIDERP - 2021\n");
	printf("*************************************************\n\n");
	printf("Realize a operacao desejada:\n");
	printf("1. Imprimir\n");
	printf("2. Inserir novo valor\n");
	printf("3. Remover a arvore\n");
	printf("4. Sair\n");
	scanf("%d",&option);
	return option;
	
}
//FIM FUNCAO MENU
//INICIO FUNCAO DE EXECUCAO DAS OPCOES DO MENU
void choice(Tree *mainTree, int option) {
	switch(option){
		int data;
		case 1:
			return;
			break;
		
		case 2:
			system("cls");
			printf("Digite qual valor inteiro para ser inserido: \n");
			scanf("%d", &data);
			printf("Adicionando ...\n");
			printf("Adicionando ........\n");
			printf("Adicionando .....................\n");
			printf("Adicionando ............................. 100%%\n");
			system("pause");
			system("cls");
			addSheet(mainTree, data);

			system("pause");
			system("cls");
			
			break;
		
		case 3:
			system("cls");
			printf("Removendo\n\n\n");
			printf("Digite qual valor inteiro sera excluido: \n");
			scanf("%d", &data);
			printf("Removendo ...\n");
			printf("Removendo ........\n");
			printf("Removendo .....................\n");
			printf("Removendo ............................. 100%%\n");
			system("pause");
			system("cls");
			delSheet(mainTree, data);
			system("pause");
			system("cls");
			break;
		
		case 4:
			system("cls");
			printf("Encerrando programa\n\n\n");
			exit(1);
			break;
		
		default:
			printf("Opcao invalida\n\n\n");

	}
}
//FIM FUNCAO OPCOES DO MENU
//INICIO FUNCAO OPCOES DO SUBMENU
int print(){
	int option2;
	system("cls");
	printf("1. Pre-Ordem\n");
	printf("2. Em-Ordem\n");
	printf("3. Pos-Ordem\n\n\n");
	scanf("%d", &option2);
	return option2;
}
//FIM FUNCAO OPCOES DO SUBMENU
//INICIO FUNCAO DA EXECUCAO DAS OPCOES DO SUBMENU
void choice2(Tree *mainTree, int option2){
	
	switch(option2){
		case 1:
			system("cls");
			printf("Pre-Ordem\n\n");
			preOrder(mainTree);
			printf("\n\n\n\n");
			printf("Reiniciando programa...\n\n\n\n");
			system("pause");
			system("cls");
		break;
		
		case 2:
			system("cls");
			printf("Em-Ordem\n\n");
			inOrder(mainTree);
			printf("\n\n\n\n");
			printf("Reiniciando programa...\n\n\n\n");
			system("pause");
			system("cls");			
		break;
		
		case 3:
			system("cls");
			printf("Pos-Ordem\n\n");
			postOrder(mainTree);
			printf("\n\n\n\n");
			printf("Reiniciando programa...\n\n\n\n");
			system("pause");
			system("cls");			
		break;
		
		default:
			system("cls");
			printf("Opcao invalida2\n\n");
			printf("Reiniciando programa...\n\n\n\n");
			system("pause");
			system("cls");
	}
}
//FIM FUNCAO DA EXECUCAO DAS OPCOES DO SUBMENU
	
//INICIO DA FUNCAO PRÉ-ORDEM
void preOrder(Tree *mainTree){
	if(mainTree == NULL)
	return;
	
	if(*mainTree != NULL){
		printf("%d\n", (*mainTree)->info);
		preOrder(&((*mainTree)->left));
		preOrder(&((*mainTree)->right));
	}
}
//FIM DA FUNCAO PRÉ-ORDEM
//INICIO DA FUNCAO EM-ORDEM
void inOrder(Tree *mainTree){
	if (mainTree == NULL)
	return;

	if (*mainTree != NULL){
		inOrder(&((*mainTree)->left));
		printf("%d\n", (*mainTree)->info);
		inOrder(&((*mainTree)->right));
	}
}
//FIM DA FUNCAO EM-ORDEM
//INICIO DA FUNCAO PÓS-ORDEM
void postOrder(Tree *mainTree){
	if(mainTree == NULL)
	return;
	
	if(*mainTree != NULL){
		postOrder(&((*mainTree)->left));
		postOrder(&((*mainTree)->right));
		printf("%d\n", (*mainTree)->info);
	}
}
//FIM DA FUNCAO PÓS-ORDEM
//INICIO DA FUNCAO ADICIONAR FOLHA
int addSheet(Tree *mainTree, int data){
	if(mainTree == NULL)
	return 0;
	struct node *newSheet;
	newSheet = (struct node*) malloc(sizeof(struct node));
	if(newSheet == NULL)
	return 0;
	newSheet->info = data;
	newSheet->left = NULL;
	newSheet->right = NULL;
	if(*mainTree == NULL)
		*mainTree = newSheet;
	else{
		struct node *temp1 = *mainTree;
		struct node *temp2 = NULL;
		while(temp1 != NULL){
			temp2 = temp1;
			if(data == temp1->info){
				free(newSheet);
				printf("\nValor ja inserido na arvore.\n\n");
				return 0;
			}
			if(data > temp1->info)
				temp1 = temp1->right;
			else
				temp1 = temp1->left;
			}
		if(data > temp2->info)
			temp2->right = newSheet;
		else
			temp2->left = newSheet;
	}
	if (newSheet != NULL)
		printf("\nValor inserido com sucesso\n\n");
	return 1;
}
//FIM DA FUNCAO ADICIONAR FOLHA			
//INICIO DA FUNCAO REMOVER FOLHA
int delSheet(Tree *mainTree, int data){
	
	if(mainTree == NULL)
	return 0;
	struct node *temp1 = *mainTree;
	struct node *temp2 = NULL;
	while(temp1 != NULL){
		if(data == temp1->info){
			if(temp1 == *mainTree)
				*mainTree = delTemp1(temp1);
			else{
				if(temp2->right == temp1)
				temp2->right = delTemp1(temp1);
				else 
				temp2->left = delTemp1(temp1);
			}
		printf("\nValor removido com sucesso\n");
			return 1;
		}
		temp2 = temp1;
		if(data > temp1->info)
		temp1 = temp1->right;
		else
		temp1 = temp1->left;
	}
	if(data != (temp1 && temp2))
	printf("\nValor nao encontrado\n");
	return 0;
}
	struct node *delTemp1(struct node *temp1){
	
	struct node *temp1a;
	struct node *temp2a;
			
			if(temp1->left == NULL){
			temp2a = temp1->right;
			free(temp1);
			return temp2a;
		}
		temp1a = temp1;
		temp2a = temp1->left;
		while(temp2a->right != NULL){
			temp1a = temp2a;
			temp2a = temp2a->right;
		}
		if (temp1a != temp1){
			temp1a->right = temp2a->left;
			temp2a->left = temp1->left;
		}
		temp2a->right = temp1->right;
		free(temp1);
		return temp2a;
	}
//FIM DA FUNCAO REMOVER FOLHA

