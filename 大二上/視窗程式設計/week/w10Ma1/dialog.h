#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QLineEdit;
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    QLineEdit *decEdit;
    QLineEdit *hexEdit;
    QLineEdit *binEdit;
private slots:
    void decChanged(const QString&);
    void hexChanged(const QString&);
    void binChanged(const QString&);
};
#endif // DIALOG_H
