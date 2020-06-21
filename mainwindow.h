#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPainter>
#include <QtConcurrent/QtConcurrent>
#include <QThread>

#include <bits/stdc++.h>
#include <fstream>

#include "backend/init.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void makeFinalPlot(QVector<double> &x,QVector<double> &y);
    void makeConvergePlot(QVector<double> &conv, int finalIter);
    void plotBoard(double board[HEIGHT][WIDTH]);

    void handleStartButton();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
