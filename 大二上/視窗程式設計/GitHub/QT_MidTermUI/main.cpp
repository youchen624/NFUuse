#include "midtermui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MidTermUI w;
    w.show();
    return a.exec();
}
