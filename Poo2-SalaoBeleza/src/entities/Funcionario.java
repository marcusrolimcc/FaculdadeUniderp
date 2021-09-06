package src.entities;

public class Funcionario {
	
	private String nome;
	private Double salarioBasico;
	
	public Funcionario(String nome, Double salarioBasico) {
		this.nome = nome;
		this.salarioBasico = salarioBasico;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public Double getSalarioBasico() {
		return salarioBasico;
	}

	public void setSalarioBasico(Double salarioBasico) {
		this.salarioBasico = salarioBasico;
	}

	@Override
	public String toString() {
		return "Cargo: Indefinido - Nome: " + nome + " - Salário: " + String.format("%.2f", salarioBasico);
	}
}
