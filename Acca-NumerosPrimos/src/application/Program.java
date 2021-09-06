package src.application;

import java.util.Scanner;

public class Program {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		char opt;
		
		do {
			System.out.println("Descubra se o número escolhido é primo");
			System.out.print("Digite um numero inteiro qualquer maior que 0 de até 9 dígitos: ");
			int num = sc.nextInt();
			
			//INÍCIO ALGORITMO A
			
			System.out.println();
			System.out.println("Algoritmo A");
			long inicio = System.currentTimeMillis();
			long fim = 0;
			long tempoGasto = 0;
		
		if( num == 2 || num == 3 || num == 5 || num == 7) {
			System.out.println("O número " + num + " é primo!");
			fim = System.currentTimeMillis();
			tempoGasto = (fim - inicio);
			
			System.out.println();
			System.out.println("Algoritmo Direto");
			System.out.println("Tempo gasto para execução algoritmo: " + tempoGasto + " milissegundos!");
		}else {
				
		int divisores = 0;
		System.out.println();
		
		inicio = System.currentTimeMillis();
		for(int i = 1; i <= num; i++) {
			if( num % i == 0) {
				divisores++;
			}
		}
		if(divisores == 2) {
			System.out.println("O número " + num + " é primo!");
		}else {
			System.out.println("O número " + num + " não é primo!");
		}
		fim = System.currentTimeMillis();
		tempoGasto = (fim - inicio);
		
		System.out.println("Tempo gasto para execução algoritmo: " + tempoGasto + " milissegundos!");
		
		//FIM ALGORITMO A
		
		//INÍCIO ALGORITMO B
		
		System.out.println();
		System.out.println("Algoritmo B");
		inicio = System.currentTimeMillis();
		boolean numPrimo = true;
		for(int i = 2 ; i < num; i++) {
			if(num % i == 0) {
				numPrimo = false;
			}
		}
		if(numPrimo) {
			System.out.println("O número " + num + " é primo!");
		}else {
			System.out.println("O número " + num + " não é primo!");
		}
		fim = System.currentTimeMillis();
		tempoGasto = (fim - inicio);
		
		System.out.println("Tempo gasto para execução algoritmo: " + tempoGasto + " milissegundos!");
		
		//FIM ALGORITMO B
		
		//INÍCIO ALGORITMO C
		
		System.out.println();
		System.out.println("Algoritmo C");
		divisores = 2;
		inicio = System.currentTimeMillis();
		for(int i = 1; i <= num; i++) {
			if( num % 2 == 0) {
				divisores = divisores + 1;
			}else if(num % 3 == 0) {
				divisores = divisores + 1;
			}else if(num % 5 == 0) {
				divisores = divisores + 1;
			}else if(num % 7 == 0) {
				divisores = divisores + 1;
			}
		}
		if(divisores == 2) {
			System.out.println("O número " + num + " é primo!");
		}else {
			System.out.println("O número " + num + " não é primo!");
		}
		fim = System.currentTimeMillis();
		tempoGasto = (fim - inicio);
		
		System.out.println("Tempo gasto para execução algoritmo: " + tempoGasto + " milissegundos!");
		}
		
		//FIM ALGORITMO C
		
		//INÍCIO MENU
		
		System.out.println();
		System.out.println("Deseja escolher outro número? (s/n)");
		sc.nextLine();
		opt = sc.nextLine().toLowerCase().charAt(0);
		System.out.println(opt);
		
		if(opt != 's' && opt != 'n') {
			System.out.println("Opção inválida!");
			System.out.println("Deseja escolher outro número? (s/n)");
			opt = sc.next().toLowerCase().charAt(0);
		}
		 for (int i = 0; i < 100; ++i)  
		       System.out.println();
		}while(opt == 's');
		
		//FIM MENU
		
		sc.close();
	}
}
