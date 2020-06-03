#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "backend/fhpmain.h"
#include "backend/init.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->finalPlot->xAxis->setRange(0, 14);
    ui->finalPlot->yAxis->setRange(0, 1);

    ui->convergencePlot->xAxis->setRange(0,iterations-150);
    ui->convergencePlot->yAxis->setRange(0,1);

    QCPItemLine *item = new QCPItemLine(ui->convergencePlot);
    item->setPen(QPen(Qt::red));
    item->start->setCoords(0,0.1);
    item->end->setCoords(iterations-150,0.1);

    connect(ui->startButton, SIGNAL (released()), this, SLOT (handleStartButton()));

    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::black);

    ui->boardWiget->setAutoFillBackground(true);
    ui->boardWiget->setPalette(pal);
    ui->boardWiget->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makeFinalPlot(QVector<double> &x,QVector<double> &y)
{
    ui->finalPlot->addGraph();
    ui->finalPlot->graph(0)->setData(x, y);
    ui->finalPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->finalPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->finalPlot->xAxis->setLabel("sectors");

    ui->finalPlot->replot();
}

void MainWindow::makeConvergePlot(QVector<double> &conv)
{
    QVector<double> iter(iterations);
    for(double i = 0; i<iterations;i++){
        iter[i] = i;
    }

    ui->convergencePlot->addGraph();
    ui->convergencePlot->graph(0)->setData(iter,conv);
    ui->convergencePlot->xAxis->setLabel("iterations");

    ui->convergencePlot->replot();
}

void MainWindow::handleStartButton()
{
    QVector<double> x(14), y(14);
    QVector<double> conv(iterations);
    fhpmain(x,y,conv);
    MainWindow::makeFinalPlot(x,y);
    MainWindow::makeConvergePlot(conv);
    ui->startButton->setText("Start simulation");
}

