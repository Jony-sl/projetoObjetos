#include "fonteexcel.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QTextStream>
#include <QUrl>
#include <QDebug>

QVector<double> FonteExcel::obterDados(const Ativo& ativo, const Periodo& periodo) {
    QVector<double> dados;

    // Extrai informações do ativo e do período
    QString ticker = ativo.getNome().toUpper().trimmed(); // Ex: "AAPL", "BLK", "TSLA"
    QString startDate = periodo.getInicio().toString("yyyy-MM-dd");
    QString endDate = periodo.getFim().toString("yyyy-MM-dd");

    // Monta a URL da API Tiingo
    QString url = QString("https://api.tiingo.com/tiingo/daily/%1/prices?startDate=%2&endDate=%3&format=csv&token=d081476625726d7694d1f55990c28cd4ac6c01c6")
                      .arg(ticker).arg(startDate).arg(endDate);

    qDebug() << "🔍 Requisitando dados para:" << ticker;
    qDebug() << "🌐 URL da API:" << url;

    QNetworkAccessManager manager;
    QNetworkRequest request{QUrl(url)};
    QNetworkReply* reply = manager.get(request);

    // Espera pela resposta da API
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray csvData = reply->readAll();
        QTextStream stream(csvData);
        stream.readLine(); // ignora o cabeçalho

        while (!stream.atEnd()) {
            QString line = stream.readLine();
            QStringList columns = line.split(",");
            if (columns.size() >= 5) {
                bool ok = false;
                double closePrice = columns[4].toDouble(&ok); // Coluna "close"
                if (ok) {
                    dados.append(closePrice);
                }
            }
        }

        qDebug() << "✅ Preços recebidos:" << dados.size();
    } else {
        qDebug() << "❌ Erro na requisição para o ticker" << ticker << ":" << reply->errorString();
    }

    reply->deleteLater();
    return dados;
}
