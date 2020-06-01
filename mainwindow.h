#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include <bits/stdc++.h>
#include <fstream>


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
    void makePlot(QVector<double> &x,QVector<double> &y);
    void handleStartButton();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
