#include "midtermui.h"
#include "ui_midtermui.h"

MidTermUI::MidTermUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MidTermUI)
{
    ui->setupUi(this);
}

MidTermUI::~MidTermUI()
{
    delete ui;
}
