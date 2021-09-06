package src.entities;

public class Cabelereira extends Funcionario{
	
	private Double comissao;

	public Cabelereira(String nome, Double salarioBasico, Double comissao) {
		super(nome, salarioBasico);
		this.comissao = comissao;
	}

	public Double getComissao() {
		return comissao;
	}

	public void setComissao(Double comissao) {
		this.comissao = comissao;
	}
	
	public double comporSalario() {
		return getSalarioBasico() + comissao;
	}

	@Override
	public String toString() {
		return "Cargo: Cabelereira - " + "Nome: " + getNome() + " - Salário: " + String.format("%.2f", comporSalario());
	}

}
