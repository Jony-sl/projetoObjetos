#include "geradorgrafico.h"
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QDate>

GeradorGrafico::GeradorGrafico() {}

QChartView* GeradorGrafico::gerar(const Ativo& ativo, const QVector<double>& dados, const QDate& dataInicial) {
    QChart* chart = montarGrafico(ativo, dados, dataInicial);
    auto* view = new QChartView(chart);
    view->setRenderHint(QPainter::Antialiasing);
    return view;
}

QChart* GeradorGrafico::montarGrafico(const Ativo& ativo, const QVector<double>& dados, const QDate& dataInicial) {
//QChart* montarGrafico(const Ativo& ativo, const QVector<double>& dados, const QDate& dataInicial) {
    QLineSeries* serie = new QLineSeries();

    for (int i = 0; i < dados.size(); ++i) {
        serie->append(i, dados[i]);
    }

    QChart* chart = new QChart();
    chart->addSeries(serie);
    chart->setTitle("Preço do Ativo: " + ativo.getNome());
    chart->legend()->hide();

    // Eixo Y: preço
    auto* eixoY = new QValueAxis();
    eixoY->setTitleText("Preço (USD)");
    chart->setAxisY(eixoY, serie);

    // Eixo X: data
    auto* eixoX = new QCategoryAxis();
    eixoX->setTitleText("Data");

    for (int i = 0; i < dados.size(); ++i) {
        QDate data = dataInicial.addDays(i);
        eixoX->append(data.toString("dd/MM"), i);
    }

    eixoX->setLabelsAngle(-45); // inclina pra melhor leitura
    chart->setAxisX(eixoX, serie);

    return chart;
}
