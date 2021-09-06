package src.entities;

import java.text.SimpleDateFormat;
import java.util.Date;

public class Atendimento {

	private Cliente cliente;
	private Date data;
	private PoliticaDesconto tipoDesconto;
	private ItensAtendimento itens;
	
	SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy HH:mm");
	
	public Atendimento(Cliente cliente, Date data, PoliticaDesconto tipoDesconto, ItensAtendimento itens) {
		this.cliente = cliente;
		this.data = data;
		this.tipoDesconto = tipoDesconto;
		this.itens = itens;
	}
	
	public Cliente getCliente() {
		return cliente;
	}
	public void setCliente(Cliente cliente) {
		this.cliente = cliente;
	}
	public Date getData() {
		return data;
	}
	public void setData(Date data) {
		this.data = data;
	}
	public PoliticaDesconto getTipoDesconto() {
		return tipoDesconto;
	}
	public void setTipoDesconto(PoliticaDesconto tipoDesconto) {
		this.tipoDesconto = tipoDesconto;
	}
	public ItensAtendimento getItens() {
		return itens;
	}
	public void setItens(ItensAtendimento itens) {
		this.itens = itens;
	}
	public PoliticaDesconto obterPoliticaVigente() {
		return null;
	}
	public double total() {
		return getItens().getServico().getValor() - (getItens().getServico().getValor() * getTipoDesconto().gerarPorcentual());
	}
	

	@Override
	public String toString() {
		return "Atendimento -> Data: " + sdf.format(getData()) 
		+ "  Cliente: " + getCliente().getNome() 
		+ " - Funcionário:  " + getItens().getResponsavel().getNome() 
		+ " \nServiço: " + getItens().getServico().getDescricao() 
		+ " - Duração: " + getItens().getServico().getTempo()
		+ " minutos - Desconto: " + getTipoDesconto().gerarPorcentual() 
		+ "% - Valor do serviço: " + String.format("%.2f", getItens().getServico().getValor()) 
		+ "\nTotal: R$ " + String.format("%.2f", total()) + "\n\n";
	}
	
	
}
