#ifndef ATIVO_H
#define ATIVO_H

#include <QString>

class Ativo {
public:
    Ativo() = default;
    Ativo(const QString& nome, const QString& ticker);

    QString getNome() const;
    QString getTicker() const;

private:
    QString nome_;
    QString ticker_;
};

#endif // ATIVO_H
