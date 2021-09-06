package entities;

public class Secretaria extends Funcionario{
	
	public Secretaria(int id, String nome, String telefone) {
		super(id, nome, telefone);
	}

	@Override
	public void calcularSalario() {
		salario += 500;	
	}

}
