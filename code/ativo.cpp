#include "ativo.h"

Ativo::Ativo(const QString& nome, const QString& ticker)
    : nome_(nome), ticker_(ticker) {}

QString Ativo::getNome() const {
    return nome_;
}

QString Ativo::getTicker() const {
    return ticker_;
}
