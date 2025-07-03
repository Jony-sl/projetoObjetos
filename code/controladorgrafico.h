#ifndef CONTROLADORGRAFICO_H
#define CONTROLADORGRAFICO_H

#include <QtCharts/QChartView>
#include "fontededados.h"
#include "geradorgrafico.h"
#include "ativo.h"
#include "periodo.h"

class ControladorGrafico {
public:
    explicit ControladorGrafico(FonteDeDados* fonteDados);

    void selecionarAtivo(const Ativo& ativo);
    void alterarPeriodo(const Periodo& periodo);
    QChartView* gerarGrafico();

private:
    FonteDeDados* fonte;
    GeradorGrafico gerador;

    Ativo ativoSelecionado;
    Periodo periodoSelecionado;
    bool ativoFoiSelecionado;
};

#endif // CONTROLADORGRAFICO_H
