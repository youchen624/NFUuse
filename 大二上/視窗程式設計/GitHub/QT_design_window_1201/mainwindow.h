#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>

class MainWindow : public QMainWindow,
                   public Ui_MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showCurrentTime();
    void showAbout();

    void on_actionSave_triggered();
};
#endif // MAINWINDOW_H
