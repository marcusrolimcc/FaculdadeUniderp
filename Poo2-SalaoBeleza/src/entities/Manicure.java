package src.entities;

public class Manicure extends Funcionario{
	
	private Integer produtividade;

	public Manicure(String nome, Double salarioBasico, Integer produtividade) {
		super(nome, salarioBasico);
		this.produtividade = produtividade;
	}

	public Integer getProdutividade() {
		return produtividade;
	}

	public void setProdutividade(Integer produtividade) {
		this.produtividade = produtividade;
	}
	
	public double comporSalario() {
		return getSalarioBasico() + produtividade * 5.00;
	}
	@Override
	public String toString() {
		return "Cargo: Manicure - " + "Nome: " + getNome() + " - Salário: " + String.format("%.2f", comporSalario());
	}
}
