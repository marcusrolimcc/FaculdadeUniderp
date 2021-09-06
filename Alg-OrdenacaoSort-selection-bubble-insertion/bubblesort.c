//Marcus Rolim
//ALGORITMO SELECTION SORT

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000

// INDICE DE FUNÇÕES

void bubbleSort(int *vetor);

//FIM INDICE DE FUNÇÕES

// INÍCIO DO MAIN

int main(){
	
	int vetor[MAX];

	bubbleSort(vetor);
		
return 0;	
}

//FIM DO MAIN

// ESTRUTURAS DAS FUNÇÕES

void bubbleSort(int *vetor){
	
	
	int i, j, MIN, aux;
	char nomeArquivo[30], opcao;
	float tempo;
	
	FILE *lerArquivo;
	printf("Caso queira fazer teste, ja existe arquivos modelos: \n\n -> 'aleatorio.txt' \n -> 'ordeminversa.txt' \n -> 'ordenado.txt'\n");
	printf("\nDigite o nome do arquivo que deseja organizar: \n");
	printf("OBS: O arquivo deve estar no mesmo diretorio do executavel.\n");
	printf("-> ");
	scanf("%s", &nomeArquivo);
	printf("PROCESSANDO...");
	
	lerArquivo = fopen(nomeArquivo, "r");
	
	for(i = 0 ; i < MAX ; i++){
		fscanf(lerArquivo, "%d", &vetor[i]);
	}//end for
	
	lerArquivo = fopen("MarcusRolimBubbleSort.txt", "w");
	
	tempo = clock();
	for(i = 1 ; i < MAX ; i++){
		for( j = 0; j < (MAX - 1); j++){
			if(vetor[j] > vetor[j+1]){
				aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
			}//end if
		}//end for j
	} // end for 
	for(i=0; i <= MAX; i++){
		fprintf(lerArquivo, "%d ", vetor[i]);	
	}
	fclose(lerArquivo);
	tempo = (clock() - tempo)/1000; 
	printf("\nTempo utilizado para odernar foi de %.4f segundos.\n", tempo);
	printf("\nProcessamento concluido. Arquivo salvo como MarcusRolimBubbleSort.txt\n");
}// end bubbleSort

// FIM DAS ESTRUTURAS DAS FUNÇÕES
