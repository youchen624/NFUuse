#include "mainwindow.h"
#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Dialog dialog;
    w.show();
    // dialog.show();
    return a.exec();
}
