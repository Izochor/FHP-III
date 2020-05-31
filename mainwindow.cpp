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

void MainWindow::makePlot()
{
//    // generate some data:
    QVector<double> x(14), y(14); // initialize with entries 0..100
//    for (int i=0; i<101; ++i)
//    {
//      x[i] = i/50.0 - 1; // x goes from -1 to 1
//      y[i] = x[i]; // let's plot a quadratic function
//    }

    std::ifstream file("final/final23.dat");

    //in need of fixes!!!
    int i = 0;
    float a=0,b=0;
    while(file >> a >> b)
    {
        file >> a >> b;
        x[i]=a;
        y[i]=b;
        i+=1;
    }

    for(int j=0;j<14;j++){
        qDebug()<<j<<" "<<x[j]<<" "<<y[j];
    }

    file.close();


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
    fhpmain();
    MainWindow::makePlot();
    ui->startButton->setText("Start simulation");
}

