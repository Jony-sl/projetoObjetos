#warning
#ifndef GERADORGRAFICO_H
#define GERADORGRAFICO_H

#include "ativo.h"
#include <QVector>
#include <QDate>
#include <QtCharts/QChartView>

class GeradorGrafico {
public:
    GeradorGrafico();
    QChartView* gerar(const Ativo& ativo, const QVector<double>& dados, const QDate& dataInicial);
private:
    QChart* montarGrafico(const Ativo& ativo, const QVector<double>& dados, const QDate& dataInicial);
};


#endif // GERADORGRAFICO_H
