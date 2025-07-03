#include "mainwindow.h"
#include <QtCharts/QChartView>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    controlador = new ControladorGrafico(&fonte);
    configurarInterface();
    conectarSinais();
    atualizarGrafico();
}

MainWindow::~MainWindow()
{
    delete controlador;
}

void MainWindow::configurarInterface()
{
    central = new QWidget(this);
    setCentralWidget(central);

    comboBoxAtivos = new QComboBox(this);
    comboBoxAtivos->addItem("Empresa XPTO", "XPTO3");
    comboBoxAtivos->addItem("Petrobras", "PETR4");
    comboBoxAtivos->addItem("Vale", "VALE3");

    dateEditInicio = new QDateEdit(QDate::currentDate().addDays(-10), this);
    dateEditFim = new QDateEdit(QDate::currentDate(), this);
    botaoAtualizar = new QPushButton("Atualizar Período", this);

    auto* layoutTopo = new QHBoxLayout;
    layoutTopo->addWidget(comboBoxAtivos);
    layoutTopo->addWidget(dateEditInicio);
    layoutTopo->addWidget(dateEditFim);
    layoutTopo->addWidget(botaoAtualizar);

    layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addLayout(layoutTopo);

    central->setLayout(layoutPrincipal);

    controlador->selecionarAtivo(Ativo("Empresa XPTO", "XPTO3"));
    controlador->alterarPeriodo(Periodo(dateEditInicio->date(), dateEditFim->date()));
}

void MainWindow::conectarSinais()
{
    connect(comboBoxAtivos, &QComboBox::currentIndexChanged, this, [=]() {
        QString nome = comboBoxAtivos->currentText();
        QString ticker = comboBoxAtivos->currentData().toString();
        controlador->selecionarAtivo(Ativo(nome, ticker));
        atualizarGrafico();
    });

    connect(botaoAtualizar, &QPushButton::clicked, this, [=]() {
        QDate inicio = dateEditInicio->date();
        QDate fim = dateEditFim->date();

        if (inicio > fim) {
            QMessageBox::warning(this, "Erro", "A data inicial não pode ser maior que a final.");
            return;
        }

        controlador->alterarPeriodo(Periodo(inicio, fim));
        atualizarGrafico();
    });
}

void MainWindow::atualizarGrafico()
{

    while (layoutPrincipal->count() > 1) {
        QLayoutItem* item = layoutPrincipal->takeAt(1);
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }

    QChartView* grafico = controlador->gerarGrafico();
    if (grafico) {
        layoutPrincipal->addWidget(grafico);
    }
}
