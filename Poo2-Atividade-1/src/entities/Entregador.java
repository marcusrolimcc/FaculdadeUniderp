package entities;

public class Entregador extends Funcionario{
	
	private String cnh;

	public Entregador(int id, String nome, String telefone, String cnh) {
		super(id, nome, telefone);
		this.cnh = cnh;
	}
	
	@Override
	public void calcularSalario() {
		
		salario += 850;
	}
	
	
	
	
	

}
