package src.application;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

import src.entities.Atendimento;
import src.entities.Cabelereira;
import src.entities.Cliente;
import src.entities.DescontoPorDiaSemana;
import src.entities.DescontoPorValor;
import src.entities.Funcionario;
import src.entities.ItensAtendimento;
import src.entities.Manicure;
import src.entities.PoliticaDesconto;
import src.entities.Servico;

public class Program {

	public static void main(String[] args) throws ParseException {
		
		Locale.setDefault(Locale.US);
		
		SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy HH:mm");

		List<Funcionario> funcionario = new ArrayList<>();
		List<Servico> servicos = new ArrayList<>();
		List<Cliente> cliente = new ArrayList<>();
		List<Atendimento> atendimento = new ArrayList<>();
		
		Funcionario func1 = new Manicure("Maria", 1000.00, 15);
		Funcionario func2 = new Cabelereira("Paula", 1000.00, 500.00);
		Funcionario func3 = new Cabelereira("Roberta", 1000.00, 850.00);
		Funcionario func4 = new Funcionario("Liz", 2500.00);
		
		funcionario.add(func1);
		funcionario.add(func2);
		funcionario.add(func3);
		funcionario.add(func4);
		
		Servico serv1 = new Servico(1, 250.00, 30);
		Servico serv2 = new Servico(2, 50.00, 15);
		Servico serv3 = new Servico(3, 450.00, 90);
		Servico serv4 = new Servico(4, 150.00, 40);
		
		servicos.add(serv1);
		servicos.add(serv2);
		servicos.add(serv3);
		servicos.add(serv4);
		
		Cliente cli1 = new Cliente("Isabela", "Rua xxx");
		Cliente cli2 = new Cliente("Fernanda", "Rua zzz");
		Cliente cli3 = new Cliente("Juliana", "Rua yyy");
		Cliente cli4 = new Cliente("Ana", "Rua iii");
		
		cliente.add(cli1);
		cliente.add(cli2);
		cliente.add(cli3);
		cliente.add(cli4);
		
		PoliticaDesconto pd1 = new DescontoPorDiaSemana();
		PoliticaDesconto pd2 = new DescontoPorValor();
				
		ItensAtendimento iat1 = new ItensAtendimento(func1, serv1);
		ItensAtendimento iat2 = new ItensAtendimento(func3, serv2);
		ItensAtendimento iat3 = new ItensAtendimento(func2, serv3);
		ItensAtendimento iat4 = new ItensAtendimento(func4, serv2);
		ItensAtendimento iat5 = new ItensAtendimento(func1, serv1);
		ItensAtendimento iat6 = new ItensAtendimento(func1, serv1);
		ItensAtendimento iat7 = new ItensAtendimento(func2, serv2);
		ItensAtendimento iat8 = new ItensAtendimento(func3, serv4);
		ItensAtendimento iat9 = new ItensAtendimento(func1, serv2);
				
		Atendimento at1 = new Atendimento(cli1, sdf.parse("20/08/2021 14:30"), pd1, iat1);
		Atendimento at2 = new Atendimento(cli2, sdf.parse("20/08/2021 15:30"), pd2, iat2);
		Atendimento at3 = new Atendimento(cli3, sdf.parse("20/08/2021 16:30"), pd2, iat3);
		Atendimento at4 = new Atendimento(cli4, sdf.parse("20/08/2021 17:30"), pd1, iat4);
		Atendimento at5 = new Atendimento(cli2, sdf.parse("20/08/2021 18:00"), pd2, iat5);
		Atendimento at6 = new Atendimento(cli1, sdf.parse("20/08/2021 19:30"), pd2, iat6);
		Atendimento at7 = new Atendimento(cli3, sdf.parse("20/08/2021 20:00"), pd2, iat7);
		Atendimento at8 = new Atendimento(cli1, sdf.parse("20/08/2021 21:30"), pd1, iat8);
		Atendimento at9 = new Atendimento(cli3, sdf.parse("20/08/2021 14:30"), pd1, iat9);
		
		atendimento.add(at1);
		atendimento.add(at2);
		atendimento.add(at3);
		atendimento.add(at4);
		atendimento.add(at5);
		atendimento.add(at6);
		atendimento.add(at7);
		atendimento.add(at8);
		atendimento.add(at9);
		
		System.out.println();
		System.out.println("Clientes");
		System.out.println();
		for(Cliente x : cliente) {
			System.out.println(x.toString());
		}		
		
		System.out.println();
		System.out.println("Funcionarios");
		System.out.println();
		for(Funcionario x : funcionario) {
			System.out.println(x.toString());
		}
		
		System.out.println();
		System.out.println("Serviços");
		System.out.println();
		for(Servico x : servicos) {
			System.out.println(x.toString());
		}
		
		System.out.println();
		System.out.println("Resposta exercício proposto");
		System.out.println();
		for(Atendimento x : atendimento) {
			System.out.println(x.toString());
		}
		
		
		
	}
}
