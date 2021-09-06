//Marcus Rolim
//ALGORITMO SELECTION SORT

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000

// INDICE DE FUNÇÕES

void insertionSort(int *vetor);

//FIM INDICE DE FUNÇÕES

// INÍCIO DO MAIN

int main(){
	
	int vetor[MAX];
	
	insertionSort(vetor);
	

system("pause");
return 0;	
}

//FIM DO MAIN

// ESTRUTURAS DAS FUNÇÕES

void insertionSort(int *vetor){
	
	
	int i, j, MIN, aux;
	char nomeArquivo[30];
	float tempo;
	
	FILE *lerArquivo;
	
	printf("Caso queira fazer teste, ja existe arquivos modelos: \n\n -> 'aleatorio.txt' \n -> 'ordeminversa.txt' \n -> 'ordenado.txt'\n");
	printf("\nDigite o nome do arquivo que deseja organizar: \n");
	printf("-> ");
	scanf("%s", &nomeArquivo);
	printf("PROCESSANDO...");
	
	lerArquivo = fopen(nomeArquivo, "r");
	
	for(i = 0 ; i < MAX ; i++){
		fscanf(lerArquivo, "%d", &vetor[i]);
	}//end for
	
	lerArquivo = fopen("MarcusRolimInsertionSort.txt", "w");
	
	tempo = clock();
	
	for(j = 1 ; j < MAX ; j++)
	{
		aux = vetor[j];
		i = j-1;
		while(i >= 0 && vetor[i] > aux){
			vetor[i+1] = vetor[i];
			i--;
		}
		vetor[i+1] = aux;
	} // end for 
	for(i=0; i <= MAX; i++){
		fprintf(lerArquivo, "%d ", vetor[i]);	
	}
	fclose(lerArquivo);
	tempo = (clock() - tempo)/1000; 
	printf("\nTempo utilizado para odernar foi de %.4f segundos.\n", tempo);
	printf("\nProcessamento concluido. Arquivo salvo como MarcusRolimInsertionSort.txt\n");
}// end insetionSort

// FIM DAS ESTRUTURAS DAS FUNÇÕES
