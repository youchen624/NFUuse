#include "widget.h"
#include "ui_widget.h"

WidGet::WidGet(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WidGet)
{
    ui->setupUi(this);
}

WidGet::~WidGet()
{
    delete ui;
}
