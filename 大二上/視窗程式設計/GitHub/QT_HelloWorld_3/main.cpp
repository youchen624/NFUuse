#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WidGet w1, w2;
    w1.show();
    w1.move(300, 0);
    w2.show();
    return a.exec();
}
