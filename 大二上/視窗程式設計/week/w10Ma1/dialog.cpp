#include "dialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QGridLayout *editLayout = new QGridLayout;
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    mainLayout->addLayout(editLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonLayout);

    QLabel *decLabel = new QLabel(tr("十進位"));
    QLabel *hexLabel = new QLabel(tr("十六進位"));
    QLabel *binLabel = new QLabel(tr("二進位"));
    decEdit = new QLineEdit;
    hexEdit = new QLineEdit;
    binEdit = new QLineEdit;

    editLayout->addWidget(decLabel, 0, 0);
    editLayout->addWidget(decEdit, 0, 1);
    editLayout->addWidget(hexLabel, 1, 0);
    editLayout->addWidget(hexEdit, 1, 1);
    editLayout->addWidget(binLabel, 2, 0);
    editLayout->addWidget(binEdit, 2, 1);

    QPushButton* exitButton = new QPushButton(tr("離開"));
    buttonLayout->addStretch();
    buttonLayout->addWidget(exitButton);

    connect(
        exitButton,
        SIGNAL(clicked()),
        this,
        SLOT(accept())
    );
    connect(
        decEdit,
        SIGNAL(textChanged(QString)),
        this,
        SLOT(decChanged(QString))
    );
    connect(
        hexEdit,
        SIGNAL(textChanged(QString)),
        this,
        SLOT(hexChanged(QString))
    );
    connect(
        binEdit,
        SIGNAL(textChanged(QString)),
        this,
        SLOT(binChanged(QString))
    );
}


void Dialog::decChanged(const QString& newValue) {
    bool ok;
    int num = newValue.toInt(&ok);
    if (ok) {
        hexEdit->setText(QString::number(num, 16));
        binEdit->setText(QString::number(num, 2));
    } else {
        hexEdit->setText("");
        binEdit->setText("");
    }
};
void Dialog::hexChanged(const QString& newValue) {
    bool ok;
    int num = newValue.toInt(&ok, 16);
    if (ok) {
        decEdit->setText(QString::number(num, 10));
        binEdit->setText(QString::number(num, 2));
    } else {
        decEdit->setText("");
        binEdit->setText("");
    }
};
void Dialog::binChanged(const QString& newValue) {
    bool ok;
    int num = newValue.toInt(&ok, 2);
    if (ok) {
        decEdit->setText(QString::number(num, 10));
        hexEdit->setText(QString::number(num, 16));
    } else {
        decEdit->setText("");
        hexEdit->setText("");
    }
};

Dialog::~Dialog() {}
