#ifndef WHELLP_H
#define WHELLP_H

#include <QWidget>

class QPushButton;

QT_BEGIN_NAMESPACE
namespace Ui {
class WHellP;
}
QT_END_NAMESPACE

class WHellP : public QWidget
{
    Q_OBJECT

public:
    WHellP(QWidget *parent = nullptr);
    ~WHellP();

private:
    QPushButton *hellButton;
    Ui::WHellP *ui;
};
#endif // WHELLP_H
