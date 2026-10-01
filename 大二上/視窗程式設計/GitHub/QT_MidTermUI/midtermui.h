#ifndef MIDTERMUI_H
#define MIDTERMUI_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MidTermUI;
}
QT_END_NAMESPACE

class MidTermUI : public QWidget
{
    Q_OBJECT

public:
    MidTermUI(QWidget *parent = nullptr);
    ~MidTermUI();

private:
    Ui::MidTermUI *ui;
};
#endif // MIDTERMUI_H
