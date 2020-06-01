#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "backend/fhpmain.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0, 14);
    ui->customPlot->yAxis->setRange(0, 1);
//    MainWindow::makePlot();

    connect(ui->startButton, SIGNAL (released()), this, SLOT (handleStartButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makePlot(QVector<double> &x,QVector<double> &y)
{
    for(int j=0;j<14;j++){
        qDebug()<<j<<" "<<x[j]<<" "<<y[j];
    }

    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("sectors");
//    ui->customPlot->yAxis->setLabel(" ");

    ui->customPlot->replot();
}

void MainWindow::handleStartButton()
{
    ui->startButton->setText("loading");
    QVector<double> x(14), y(14);
    fhpmain(x,y);
    MainWindow::makePlot(x,y);
    ui->startButton->setText("Start simulation");
}

