#include "geradorgrafico.h"
#include <QtCharts/QValueAxis>

GeradorGrafico::GeradorGrafico() {}

QChartView* GeradorGrafico::gerar(const Ativo& ativo, const QVector<double>& dados) {
    QChart* chart = montarGrafico(ativo, dados);
    auto* view = new QChartView(chart);
    view->setRenderHint(QPainter::Antialiasing);
    return view;
}

QChart* GeradorGrafico::montarGrafico(const Ativo& ativo, const QVector<double>& dados) {
    QLineSeries* serie = new QLineSeries();
    for (int i = 0; i < dados.size(); ++i) {
        serie->append(i, dados[i]);
    }

    QChart* chart = new QChart();
    chart->addSeries(serie);
    chart->createDefaultAxes();
    chart->setTitle("Preço do Ativo: " + ativo.getNome());
    chart->legend()->hide();

    QValueAxis* eixoX = reinterpret_cast<QValueAxis*>(chart->axes(Qt::Horizontal).first());
    if (eixoX) eixoX->setTitleText("Dias");
    QValueAxis* eixoY = reinterpret_cast<QValueAxis*>(chart->axes(Qt::Vertical).first());
    if (eixoY) eixoY->setTitleText("Preço (USD)");

    return chart;
}
