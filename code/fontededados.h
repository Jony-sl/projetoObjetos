#ifndef FONTEDEDADOS_H
#define FONTEDEDADOS_H

#include "ativo.h"
#include "periodo.h"
#include <QVector>

class FonteDeDados {
public:
    virtual ~FonteDeDados() = default;
    virtual QVector<double> obterDados(const Ativo& ativo, const Periodo& periodo) = 0;
};

#endif // FONTEDEDADOS_H
