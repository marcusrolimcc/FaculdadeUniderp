$(function () {
    Estados();
    Show(false);
});
//INICIO FUNÇÃO ESTADOS
function Estados() {
    var urlEstados = 'https://servicodados.ibge.gov.br/api/v1/localidades/estados/';
    $.get(urlEstados, function (retorno, status) {
        if (retorno.length == 0) {
            alert('Erro - Dados não encontrados. Status: ' + status);
        }
        else {
            Show(false);
            $('#estados').append($('<option>', { value: 0, text: 'Selecionar estado' }));
            for (var i = 0; i < retorno.length; i++) {
                var estado = retorno[i];
                $('#estados').append($('<option>', { value: estado.id, text: estado.nome }));
            }
        }
    })
}//FIM FUNÇÃO ESTADOS

//INICIO FUNÇÃO CIDADES
function Cidades() {
    var estadoID = $('#estados').val();
    var urlCidades = 'https://servicodados.ibge.gov.br/api/v1/localidades/estados/' + estadoID + '/municipios';
    $.get(urlCidades, function (data, status) {
        if (data.length == 0) {
            alert('Erro - Dados não encontrados. Status: ' + status);
        }
        else {
            Show(false);
            $('#cidades').empty();
            $('#cidades').append($('<option>', { value: 0, text: 'Selecione a cidade' }));
            for (var i = 0; i < data.length; i++) {
                var linha = data[i];
                $('#cidades').append($('<option>', { value: linha.id, text: linha.nome }));
            }
        }
    });
}
//FIM FUNÇÃO CIDADES

//INICIO FUNÇÃO DETALHES
function Detalhes() {
    var cidadeID = $('#cidades').val();
    var urlDetalhes = 'https://servicodados.ibge.gov.br/api/v1/localidades/municipios/' + cidadeID;
    $.get(urlDetalhes, function (data, status) {
        if (data.length == 0) {
            alert('Erro - Dados não encontrados. Status: ' + status);
        }
        else {
            Show(true);
            var linha = data;
            $('#txtIdCidade').val(linha.id);
            $('#txtNomeCidade').val(linha.nome);

            $('#txtIdMicro').val(linha.microrregiao.id);
            $('#txtNomeMicro').val(linha.microrregiao.nome);

            $('#txtIdMeso').val(linha.microrregiao.mesorregiao.id);
            $('#txtNomeMeso').val(linha.microrregiao.mesorregiao.nome);

            $('#txtIdEstado').val(linha.microrregiao.mesorregiao.UF.id);
            $('#txtSiglaEstado').val(linha.microrregiao.mesorregiao.UF.sigla);
            $('#txtNomeEstado').val(linha.microrregiao.mesorregiao.UF.nome);

            $('#txtIdRegiao').val(linha.microrregiao.mesorregiao.UF.regiao.id);
            $('#txtSiglaRegiao').val(linha.microrregiao.mesorregiao.UF.regiao.sigla);
            $('#txtNomeRegiao').val(linha.microrregiao.mesorregiao.UF.regiao.nome);
        }
    });
}
//FIM FUNÇÃO DETALHES

//INICIO FUNÇÃO SHOW
function Show(exibirDetalhes) {
    if (exibirDetalhes == true) {
        $('#detalhes').show();
    }
    else {
        $('#detalhes').hide();
    }
}
//FIM FUNÇÃO SHOW

