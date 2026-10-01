#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class WidGet;
}
QT_END_NAMESPACE

class WidGet : public QWidget
{
    Q_OBJECT

public:
    WidGet(QWidget *parent = nullptr);
    ~WidGet();

private:
    Ui::WidGet *ui;
};
#endif // WIDGET_H
