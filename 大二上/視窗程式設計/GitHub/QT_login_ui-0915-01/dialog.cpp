#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("提示");
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &Dialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &Dialog::reject);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setDialogText(const QString &text)
{
    ui->label->setText(text);
}
