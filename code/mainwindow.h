#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QDateEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QChartView>
#include <QWidget>
#include <QMessageBox>

#include "fonteexcel.h"
#include "controladorgrafico.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // Widgets da interface
    QWidget* central;
    QComboBox* comboBoxAtivos;
    QDateEdit* dateEditInicio;
    QDateEdit* dateEditFim;
    QPushButton* botaoAtualizar;
    QVBoxLayout* layoutPrincipal;

    // Domínio
    FonteExcel fonte;
    ControladorGrafico* controlador;

    // Métodos auxiliares
    void configurarInterface();
    void conectarSinais();
    void atualizarGrafico();
};

#endif // MAINWINDOW_H
