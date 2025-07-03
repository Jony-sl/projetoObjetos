#ifndef GERADORGRAFICO_H
#define GERADORGRAFICO_H

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QVector>
#include "ativo.h"

class GeradorGrafico {
public:
    GeradorGrafico();
    QChartView* gerar(const Ativo& ativo, const QVector<double>& dados);

private:
    QChart* montarGrafico(const Ativo& ativo, const QVector<double>& dados);
};

#endif // GERADORGRAFICO_H
