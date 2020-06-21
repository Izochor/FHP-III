#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "backend/fhpmain.h"
#include "backend/init.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->boardPlot->xAxis->setTicks(false);
    ui->boardPlot->yAxis->setTicks(false);
    ui->boardPlot->xAxis->setTickLabels(false);
    ui->boardPlot->yAxis->setTickLabels(false);

    connect(ui->startButton, SIGNAL (released()), this, SLOT (handleStartButton()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makeFinalPlot(QVector<double> &x,QVector<double> &y)
{
    ui->finalPlot->xAxis->setRange(0, 14);
    ui->finalPlot->yAxis->setRange(0, 1);
    ui->finalPlot->addGraph();
    ui->finalPlot->graph(0)->setData(x, y);
    ui->finalPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->finalPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->finalPlot->xAxis->setLabel("sectors");

    ui->finalPlot->replot();
}

void MainWindow::makeConvergePlot(QVector<double> &conv,int finalIter)
{
    QVector<double> iter(iterations);
    for(double i = 0; i<iterations;i++){
        iter[i] = i;
    }

    ui->convergencePlot->yAxis->setRange(0,1);
    ui->convergencePlot->addGraph();
    ui->convergencePlot->graph(0)->setData(iter,conv);
    ui->convergencePlot->xAxis->setLabel("iterations");
    ui->convergencePlot->xAxis->setRange(0,finalIter-150);

    QCPItemLine *item = new QCPItemLine(ui->convergencePlot);
    item->setPen(QPen(Qt::red));
    item->start->setCoords(0,0.1);
    item->end->setCoords(finalIter-150,0.1);

    ui->convergencePlot->replot();
}

void MainWindow::handleStartButton()
{
    QVector<double> x(14), y(14);
    QVector<double> conv(iterations);
    double board[HEIGHT][WIDTH];
    int finalIter = 1000;

    fhpmain(x,y,conv,board,finalIter);

    QFuture<void> future1 = QtConcurrent::run(this,&MainWindow::makeFinalPlot,x,y);
    QFuture<void> future2 = QtConcurrent::run(this,&MainWindow::makeConvergePlot,conv,finalIter);
//    MainWindow::makeFinalPlot(x,y);
//    MainWindow::makeConvergePlot(conv,finalIter);
    MainWindow::plotBoard(board);

}

void MainWindow::plotBoard(double board[HEIGHT][WIDTH]){

    ui->boardPlot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom);
    ui->boardPlot->axisRect()->setupFullAxesBox(true);

    QCPColorMap *colorMap = new QCPColorMap(ui->boardPlot->xAxis, ui->boardPlot->yAxis);

    colorMap->data()->setSize(300, HEIGHT-2);
    colorMap->data()->setRange(QCPRange(0, 300), QCPRange(0, HEIGHT-2));
    double x, y, z;
    for (int xIndex=0; xIndex<300; ++xIndex)
    {
      for (int yIndex=0; yIndex<HEIGHT-2; ++yIndex)
      {
        colorMap->data()->cellToCoord(xIndex, yIndex, &x, &y);
        z = board[yIndex+1][xIndex+60];
        colorMap->data()->setCell(xIndex, yIndex, z);
      }
    }

    QCPColorScale *colorScale = new QCPColorScale(ui->boardPlot);

    colorMap->setGradient(QCPColorGradient::gpSpectrum);
    colorMap->setInterpolate(true);

    colorMap->rescaleDataRange();

    ui->boardPlot->rescaleAxes();
    ui->boardPlot->replot();

}
