//Marcus Rolim
//ALGORITMO SELECTION SORT

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000

// INDICE DE FUNÇÕES

void selectionSort(int *vetor);

//FIM INDICE DE FUNÇÕES

// INÍCIO DO MAIN

int main(){
	
	int vetor[MAX];
	
	selectionSort(vetor);
	

system("pause");
return 0;	
}

//FIM DO MAIN

// ESTRUTURAS DAS FUNÇÕES

void selectionSort(int *vetor){
	
	
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
	
	lerArquivo = fopen("MarcusRolimSelectionSort.txt", "w");
	
	tempo = clock();
	
	for(i = 0 ; i < (MAX-1) ; i++)
	{
		MIN = i;
		for(j = i+1 ; j < MAX ; j++){
			if (vetor[j] < vetor[MIN]){
			MIN = j;
			} // end if	
		} // end for j
		if(i != MIN){
			aux = vetor[i];
			vetor[i] = vetor[MIN];
			vetor[MIN] = aux;
		}
		if(vetor[i] != NULL){
		fprintf(lerArquivo, "%d ", vetor[i]);
		}//end if
		
	} // end for 
	fclose(lerArquivo);
	tempo = (clock() - tempo)/1000; 
	printf("\nTempo utilizado para odernar foi de %.4f segundos.\n", tempo);
	printf("\nProcessamento concluido. Arquivo salvo como MarcusRolimSelectionSort.txt\n");
}// end selectionSort

// FIM DAS ESTRUTURAS DAS FUNÇÕES
