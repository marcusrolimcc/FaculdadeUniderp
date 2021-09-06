package src.entities;

public class Servico {
	
	private Integer descricao;
	private Double valor;
	private Integer tempo;

	public Servico(Integer descricao, Double valor, Integer tempo) {
		this.descricao = descricao;
		this.valor = valor;
		this.tempo = tempo;
	}

	public Integer getDescricao() {
		return descricao;
	}

	public void setDescricao(Integer descricao) {
		this.descricao = descricao;
	}

	public Double getValor() {
		return valor;
	}

	public void setValor(Double valor) {
		this.valor = valor;
	}

	public Integer getTempo() {
		return tempo;
	}

	public void setTempo(Integer tempo) {
		this.tempo = tempo;
	}

	@Override
	public String toString() {
		return "Codigo: " + descricao + " - Valor: " + String.format("%.2f", valor) + " - Tempo: " + tempo + " minutos";
	}
	
	
}
