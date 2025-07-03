#ifndef PERIODO_H
#define PERIODO_H

#include <QDate>

class Periodo {
public:
    Periodo();
    Periodo(const QDate& inicio, const QDate& fim);

    QDate getInicio() const;
    QDate getFim() const;
    int numeroDeDias() const;

private:
    QDate inicio_;
    QDate fim_;
};

#endif // PERIODO_H
