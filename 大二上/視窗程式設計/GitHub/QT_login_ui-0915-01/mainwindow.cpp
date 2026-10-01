#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QDebug>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_password->setMaxLength(64);
    setWindowTitle("登入帳號");
    // connect(ui->lineEdit_password, &QLineEdit::textChanged, this, &MainWindow::on_lineEdit_textChanged);
    connect(ui->lineEdit_password, &QLineEdit::cursorPositionChanged, this, &MainWindow::on_lineEdit_cursorPositionChanged);
    connect(ui->button_login, &QPushButton::clicked, this, [this]() {
        show_dialog("登入失敗，請再試一次");
        rnd_caesar();
    });
    connect(ui->button_delete, &QPushButton::clicked, this, [this]() {
        show_dialog("成功刪除帳號");
        ui->lineEdit_account->setText("");
        ui->lineEdit_password->setText("");
        rnd_caesar();
    });
    rnd_caesar();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::show_dialog(const QString &text) {
    Dialog *dialog = new Dialog(this);
    dialog->setDialogText(text);
    dialog->exec();
}
void MainWindow::setCaesarText(const QString &text) {
    ui->label_caesar->setText(text);
}
void MainWindow::on_lineEdit_cursorPositionChanged(int oldPos, int newPos)
{
    const char theChar = chars_ref[caesar_offsets[newPos]];
    ui->label_caesar->setText(QString("Caesar\nA->%1").arg(theChar));
    // qDebug() << QString("游標位置已從 %1 移動到 %2").arg(oldPos).arg(newPos);
    // ui->statusBar->showMessage(QString("游標位置已從 %1 移動到 %2").arg(oldPos).arg(newPos));
}
void MainWindow::rnd_caesar()
{
    for(int i = 0; i < 65; i++) {
        const int offset = QRandomGenerator::global()->bounded(1, 26);
        caesar_offsets[i] = offset;
    }
    const char theChar = chars_ref[caesar_offsets[0]];
    ui->label_caesar->setText(QString("Caesar\nA->%1").arg(theChar));
}
/*
 *
void MainWindow::on_lineEdit_textChanged(const QString &text)
{
    int charCount = text.length();
    qDebug() << QString("當前字數: %1").arg(charCount);
    // ui->label_caesar->setText(QString("當前字數: %1").arg(charCount));
}
void MainWindow::handle_login()
{
    Dialog *dialog = new Dialog(this);
    dialog->setDialogText("登入失敗，請再試一次");
    dialog->exec();
    // int result = dialog->exec();
    // if (result == QDialog::Accepted) {
    //     qDebug() << "使用者按下了確定。";
    // } else {
    //     qDebug() << "使用者按下了取消或關閉了視窗。";
    // }
    dialog->deleteLater();
}
void MainWindow::handle_delete()
{
    Dialog *dialog = new Dialog(this);
    dialog->setDialogText("成功刪除帳號");
    dialog->exec();
    // int result = dialog->exec();
    // if (result == QDialog::Accepted) {
    //     qDebug() << "使用者按下了確定。";
    // } else {
    //     qDebug() << "使用者按下了取消或關閉了視窗。";
    // }
    dialog->deleteLater();
}*/
