#include "whellp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WHellP w;
    w.show();
    return a.exec();
}
