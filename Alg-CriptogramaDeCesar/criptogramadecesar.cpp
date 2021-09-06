#include<stdio.h>
#include<stdlib.h>


/* Cria a estrutura de lista utilizando o conteudo como char, pois sera mensagem escrita, tanto letras como numeros */
struct urna
{
char mensagem[30];
struct urna *proximo;
};
typedef struct urna node;

/*Se cria as funcoes para inserir no codigo main, tornando mais simples adicionar cada funcao como um bloco na mesa(main)*/
void iniciourna(node* urna);
int menu();
void executamenu(int opt, node*urna);
void addmsg(node* urna);
void exibircript(node* urna);
void exibirdecript(node* urna);
/*Codigo main*/
int main()
{
/*Cria-se o espaco destinado ao inicio da lista encadeada*/
node* urna;
urna = (node*) malloc(sizeof(node));

if(!urna)
{
printf("\n\nMemoria insuficiente!\n");
exit(1);
}
else
{
iniciourna(urna);
int opt;
do
{
opt=menu();
executamenu(opt, urna);
}while(opt!=0);
}
return 0;
}
/*Funcao - Inicia a lista indicando o primeiro no direcionando para nulo, indicando que nao tem proximo deixando obvio entao que ele eh o primeiro da lista*/
void iniciourna(node* urna)
{
urna->proximo = NULL;
}
/*Funcao - Um menu para o usuario escolher qual acao deseja fazer*/
int menu()
{
int opt;
printf("\n\nESCOLHA A OPCAO: \n");
printf("0 - Sair;\n");
printf("1 - Adicionar mensagem;\n");
printf("2 - Exibir Criptografia;\n");
printf("3 - Exibir De-Criptografia;\n");
printf("OPCAO -> ");
scanf("%d", &opt);
return opt;
}
/*Funcao - Listagem de execucoes de todas as opcoes que podem ser escolhidas no menu*/
void executamenu(int opt, node* urna)
{
switch(opt)
{
case 0:
printf("\nSaindo...\n");
break;

case 1:
addmsg(urna);
break;		

case 2:
exibircript(urna);
break;		

case 3:
exibirdecript(urna);
break;		

default:
printf("\nComando invalido\n");
break;		
}
}
/*Funcao - Criacao de um novo noh, no final da lista*/
void addmsg(node* urna)
{
node* novaurna = (node*) malloc(sizeof(node));
if(!novaurna)
{
printf("\nMemoria insuficiente\n");
exit(1);
}
else
{
printf("\nDigite a mensagem (apenas numeros e letras)");
printf("\nMensagem: ");
scanf("%s", &novaurna->mensagem);
novaurna->proximo = NULL;
if(urna->proximo==NULL)
{
urna->proximo = novaurna;
}
else
{
node *tmp = urna->proximo;
while(tmp->proximo != NULL)
{
tmp = tmp->proximo;
}
tmp->proximo = novaurna;
}

}
}
/*Funcao - Exibir a mensagem criptografada */
void exibircript(node* urna)
{
int i;
i=0;
if(urna->proximo == NULL)
{
printf("\n\nSem registros\n");
}
else
{
node* tmp = urna->proximo;
while(tmp != NULL)
{
printf("\nA mensagem criptografada: ");
if(tmp->mensagem[i]<=tmp->mensagem[30])
{
printf("\nSenha muito grande!");
}
else
{
while(tmp->mensagem[i]!='\0')
{
if(tmp->mensagem[i]>=97&&tmp->mensagem[i]<=117)
{
printf("%c", tmp->mensagem[i]+5);
i=++i;
}
else if(tmp->mensagem[i]>117&&tmp->mensagem[i]<=122)
{
printf("%c", tmp->mensagem[i]+5-26);
i=++i;	
}
else if(tmp->mensagem[i]>=65&&tmp->mensagem[i]<=85)
{
printf("%c", tmp->mensagem[i]+5);
i=++i;
}
else if(tmp->mensagem[i]>85&&tmp->mensagem[i]<=90)
{
printf("%c", tmp->mensagem[i]+5-26);
i=++i;	
}
if(tmp->mensagem[i]>=48&&tmp->mensagem[i]<=50)
{
printf("%c", tmp->mensagem[i]-3+10);
i=++i;
}
else if(tmp->mensagem[i]>50&&tmp->mensagem[i]<=57)
{
printf("%c", tmp->mensagem[i]-3);
i=++i;	
}
}
}
tmp = tmp->proximo;
}
}
}
/*Funcao - Exibir funcao decriptografada*/
void exibirdecript(node* urna)
{
int i;
i=0;
if(urna->proximo == NULL)
{
printf("\n\nSem registros\n");
}
else
{
node* tmp = urna->proximo;
while(tmp != NULL)
{
printf("\nA mensagem de-criptografada: ");
if(tmp->mensagem[i]<=tmp->mensagem[30])
{
printf("\nSenha muito grande!");
}
else
{
while(tmp->mensagem[i]!='\0')
{
if(tmp->mensagem[i]>=97&&tmp->mensagem[i]<=117)
{
printf("%c", tmp->mensagem[i]);
i=++i;
}
else if(tmp->mensagem[i]>117&&tmp->mensagem[i]<=122)
{
printf("%c", tmp->mensagem[i]);
i=++i;	
}
else if(tmp->mensagem[i]>=65&&tmp->mensagem[i]<=85)
{
printf("%c", tmp->mensagem[i]);
i=++i;
}
else if(tmp->mensagem[i]>85&&tmp->mensagem[i]<=90)
{
printf("%c", tmp->mensagem[i]);
i=++i;	
}
if(tmp->mensagem[i]>=48&&tmp->mensagem[i]<=54)
{
printf("%c", tmp->mensagem[i]);
i=++i;
}
else if(urna->mensagem[i]>54&&urna->mensagem[i]<=57)
{
printf("%c", tmp->mensagem[i]);
i=++i;	
}
}
}
tmp = tmp->proximo;
}
}
}
