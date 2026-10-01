#include "whellp.h"
#include "ui_whellp.h"
#include <QPushButton>
#include <QHBoxLayout>

WHellP::WHellP(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WHellP)
{
    ui->setupUi(this);
    hellButton = new QPushButton(QStringLiteral("&Hell你好"), this);
    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(hellButton);
    mainLayout->addStretch();
    this->setLayout(mainLayout);
}

WHellP::~WHellP()
{
    delete ui;
}
