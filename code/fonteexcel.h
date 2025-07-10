#ifndef FONTEEXCEL_H
#define FONTEEXCEL_H

#include "fontededados.h"
#include "ativo.h"
#include "periodo.h"
#include <QVector>

class FonteExcel : public FonteDeDados {
public:
    QVector<double> obterDados(const Ativo& ativo, const Periodo& periodo) override;
};

#endif // FONTEEXCEL_H
