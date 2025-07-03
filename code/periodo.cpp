#include "periodo.h"

Periodo::Periodo()
    : inicio_(QDate::currentDate().addDays(-5)),
    fim_(QDate::currentDate()) {}

Periodo::Periodo(const QDate& inicio, const QDate& fim)
    : inicio_(inicio), fim_(fim) {}

QDate Periodo::getInicio() const {
    return inicio_;
}

QDate Periodo::getFim() const {
    return fim_;
}

int Periodo::numeroDeDias() const {
    return inicio_.daysTo(fim_) + 1;
}
