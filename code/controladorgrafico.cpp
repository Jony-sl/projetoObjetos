#include "controladorgrafico.h"

ControladorGrafico::ControladorGrafico(FonteDeDados* fonteDados)
    : fonte(fonteDados),
    ativoFoiSelecionado(false),
    periodoSelecionado(QDate::currentDate().addDays(-5), QDate::currentDate())
{}

void ControladorGrafico::selecionarAtivo(const Ativo& ativo) {
    ativoSelecionado = ativo;
    ativoFoiSelecionado = true;
}

void ControladorGrafico::alterarPeriodo(const Periodo& periodo) {
    periodoSelecionado = periodo;
}

QChartView* ControladorGrafico::gerarGrafico() {
    if (!ativoFoiSelecionado) return nullptr;
    QVector<double> dados = fonte->obterDados(ativoSelecionado, periodoSelecionado);
    return gerador.gerar(ativoSelecionado, dados, periodoSelecionado.getInicio());

}
