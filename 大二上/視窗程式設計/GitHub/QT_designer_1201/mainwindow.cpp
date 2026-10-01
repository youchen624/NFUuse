#include "mainwindow.h"
#include <QMessageBox>
#include <QDateTime>
#include <QFile>
#include <QFileDialog>

void write_file(QString path, QString str) {
    QFile mFile(path);
    if (!mFile.open(QFile::WriteOnly | QFile::Text)) {
        qDebug() << "Could not open file for write.";
        return;
    }

    QTextStream out(&mFile);
    out << str;
    mFile.flush();
    mFile.close();
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);

    // Connect the new actions to slots
    connect(actionShowTime, &QAction::triggered, this, &MainWindow::showCurrentTime);
    connect(actionAbout, &QAction::triggered, this, &MainWindow::showAbout);
}

MainWindow::~MainWindow() {}

void MainWindow::showCurrentTime()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    QString timeString = currentTime.toString("yyyy-MM-dd hh:mm:ss");
    QMessageBox::information(this, "目前時間", "現在時間是：\n" + timeString);
}

void MainWindow::showAbout()
{
    QMessageBox::about(this, "關於",
        "這是一個 Qt Designer 示範程式\n\n"
        "版本：1.0\n"
        "特色：Dark 暗色主題風格");
}


void MainWindow::on_actionSave_triggered()
{

    QString path = QFileDialog::getSaveFileName(
        this,
        tr("將資料儲存至..."),
        QDir::homePath(),
        tr("(*.txt)"))
        ;
    write_file(path, textEdit->toPlainText());
}

