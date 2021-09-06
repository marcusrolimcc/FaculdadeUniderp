package entities;

public abstract class Funcionario {
	
	protected int id;
	protected String nome;
	protected String telefone;
	protected double salario = 1455.67;
	
	public Funcionario(int id, String nome, String telefone) {
		this.id = id;
		this.nome = nome;
		this.telefone = telefone;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getTelefone() {
		return telefone;
	}

	public void setTelefone(String telefone) {
		this.telefone = telefone;
	}

	public double getSalario() {
		calcularSalario();
		return salario;
	}

	public void setSalario(double salario) {
		this.salario = salario;
	}

	public void calcularSalario() {}

}
