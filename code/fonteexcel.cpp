#include "fonteexcel.h"
#include <QRandomGenerator>

QVector<double> FonteExcel::obterDados(const Ativo& ativo, const Periodo& periodo) {
    int dias = periodo.numeroDeDias();
    QVector<double> dados;

    double preco = 10.0 + QRandomGenerator::global()->generateDouble() * 50.0;
    for (int i = 0; i < dias; ++i) {
        double delta = QRandomGenerator::global()->generateDouble() * 4.0 - 2.0; // entre -2 e +2
        preco += delta;
        dados.append(preco);
    }

    return dados;
}
