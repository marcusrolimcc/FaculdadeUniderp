package src.entities;

public class ItensAtendimento {

	private Funcionario responsavel;
	private Servico servico;

	public ItensAtendimento(Funcionario responsavel, Servico servico) {
		this.responsavel = responsavel;
		this.servico = servico;
	}

	public Funcionario getResponsavel() {
		return responsavel;
	}

	public void setResponsavel(Funcionario responsavel) {
		this.responsavel = responsavel;
	}

	public Servico getServico() {
		return servico;
	}

	public void setServico(Servico servico) {
		this.servico = servico;
	}
}
