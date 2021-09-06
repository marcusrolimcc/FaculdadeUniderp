
/* 
UNIDERP - 3º SEMESTRE - NOTURNO - ALGORITMOS E ESTRUTURA DE DADOS
ALUNOS:MARCUS ROLIM
TRABALHO REVISÃO DE FUNÇÕES - 250 PONTOS

Seu algoritmo deverá pedir ao usuário para fornecer o valor da sua hora e a quantidade de
horas trabalhadas no mês para o cálculo de uma folha de pagamento.
Os descontos para este cálculo são o do INSS, Imposto de Renda (IR) e FGTS.
• O INSS corresponde a 10% do Salário Bruto
• O FGTS corresponde a 11% do Salário Bruto
• IR depende do valor salário bruto (conforme tabela abaixo):
o Salário Bruto até 900 (inclusive) - isento
o Salário Bruto até 1500 (inclusive) - desconto de 10%
o Salário Bruto acima de 1500 - desconto de 20% Imprima na tela as
informações, dispostas conforme o exemplo abaixo.
Para calcular o Salário Líquido você deve subtrair o Salário Bruto dos descontos. Vale
ressaltar que o FGTS não é descontado para o cálculo do salário líquido (é a empresa que
deposita).	*/
	
#include<stdio.h>
#include<stdlib.h>
/* CALCULO DO SALARIO BRUTO (horas trabalhadas * quantidade de horas) */

	float calcsbruto(float h, float qh)
	{
		float sbruto = h * qh;
		return sbruto;
	}

/* CALCULO DE DESCONTO IMPOSTO DE RENDA 
(salario bruto <=900 ) -> 0%
(900<salario bruto<=1500 -> 10% )
(salario bruto > 1500 -> 20% )*/	
	float calcir (float sbruto)
	{
		if (sbruto <= 900)
		{
			float ir = 0;
			return ir;
		}
		else if (sbruto > 900 && sbruto <= 1500)
		{
			float ir = sbruto * 0.10;
			return ir;
		}
		else 
		{
			float ir = sbruto * 0.20;
			return ir;
		}
	}

/* CALCULO DE DESCONTO INSS 
(salario bruto -> 10%) */			
	float calcinss (float sbruto)
	{
		float inss = sbruto * 0.10;
		return inss;
	}

/* CALCULO DE DESCONTO FGTS 
(salario bruto -> 11%) */	
	float calcfgts (float sbruto)
	{
		float fgts = sbruto *0.11;
		return fgts;
	}
/* CALCULO DE DESCONTO  
(salario bruto - INSS - IR ) */		
	float descontos (float ir, float inss)
	{
		float desc = ir + inss;
		
		return desc;
	}
	float sliquido (float sbruto, float desc)
	{
		float sobra = sbruto - desc;
		return sobra;
	}

int main()
{
	float vhora, qtdhora;
	char opcao;
	
	do
	{	
	
	printf ("\n\t \t \t ****************** H O L E R I T E - 2020 *******************\n");
	printf ("\n \t Digite o valor da hora trabalhada: ");
	scanf ("%f", &vhora);
	printf ("\t Digite quantas horas foram trabalhadas: ");
	scanf ("%f", &qtdhora);
	
	
	float sbruto = calcsbruto(vhora, qtdhora);
	float ir = calcir(sbruto);
	float inss = calcinss(sbruto);
	float fgts = calcfgts(sbruto);
	float desc = descontos(ir, inss);
	float sobra = sliquido(sbruto, desc);
	
	
	system ("cls");
	printf ("\n\n\n\n");
	printf ("\t \t \t ****************** H O L E R I T E - 2020 *******************\n");
	printf ("\t \t \t Quantidade de horas trabalhadas:----------------> %.2f hs \n", qtdhora);
	printf ("\t \t \t Valor da hora trabalhada -----------------------> R$ %.2f \n", vhora);
	printf ("\t \t \t Salario bruto: (horas * valor da hora) ---------> R$ %.2f\n", sbruto);
	printf ("\t \t \t (-) IR (0 a 20%%)) ------------------------------> R$ %.2f\n", ir);
	printf ("\t \t \t (-) INSS (10%%)) --------------------------------> R$ %.2f\n", inss);
	printf ("\t \t \t FGTS (11%%)) ------------------------------------> R$ %.2f\n", fgts);
	printf ("\t \t \t Total de descontos -----------------------------> R$ %.2f\n", desc);
	printf ("\t \t \t Salario Liquido --------------------------------> R$ %.2f\n", sobra);
	printf ("\t \t \t ****************** H O L E R I T E - 2020 *******************\n");
	printf (" \n\n\n\t \t \t Calculado por: \n\t \t \t Marcus Rolim");
	printf ("\n\t \t \t Trabalho de revisao de funcoes");
	printf ("\n\n\n  Deseja calcular outro holerite? (s/n)");
	scanf ("%s", &opcao);
	
	if (opcao == 'n')
	{
		return(1);
	}
	else (opcao != 'n' && opcao !='s');
	{
		printf ("\n \n Opcao invalida! \n");
		printf ("\n \n LEIA COM ATENCAO \n");
		printf ("\n D-e-s-e-j-a   c-a-l-c-u-l-a-r   o-u-t-r-o   h-o-l-e-r-i-t-e? (s/n) ");
		printf ("\n Em caso de SIM, digite s \n Em caso de NAO digite n");
		printf ("\n(s/n) -> ");
		scanf ("%s", &opcao);
	}
	}while (opcao == 's');
	return 0;
}
