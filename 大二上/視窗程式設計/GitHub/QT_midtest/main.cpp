#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w1;
    MainWindow w2;

    // Position first window at (50, 50)
    w1.move(50, 50);
    w1.show();

    // Position second window next to first with 20px gap
    w2.move(50 + w1.width() + 20, 50);
    w2.show();

    return a.exec();
}
