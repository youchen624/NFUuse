#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupConnections();
    
    // Set initial status bar message
    statusBar()->showMessage("就緒");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupConnections()
{
    // Connect button signals to slots
    connect(ui->btnSubmit, &QPushButton::clicked, this, &MainWindow::onSubmitClicked);
    connect(ui->btnSecondary, &QPushButton::clicked, this, &MainWindow::onProcessClicked);
    connect(ui->btnWarning, &QPushButton::clicked, this, &MainWindow::onClearClicked);
}

void MainWindow::onSubmitClicked()
{
    QString name = ui->txtName->text();
    QString email = ui->txtEmail->text();
    
    if (name.isEmpty() || email.isEmpty()) {
        ui->txtOutput->append("⚠ 錯誤：請填寫所有欄位");
        statusBar()->showMessage("請完成表單");
        return;
    }
    
    ui->txtOutput->append("✓ 資料已提交");
    ui->txtOutput->append(QString("姓名：%1").arg(name));
    ui->txtOutput->append(QString("電子郵件：%1").arg(email));
    ui->txtOutput->append("-------------------");
    statusBar()->showMessage("資料提交成功");
}

void MainWindow::onProcessClicked()
{
    QString name = ui->txtName->text();
    
    if (name.isEmpty()) {
        ui->txtOutput->append("⚠ 無資料可處理");
        statusBar()->showMessage("請先輸入資料");
        return;
    }
    
    ui->txtOutput->append("⚙ 正在處理資料...");
    ui->txtOutput->append(QString("處理中：%1").arg(name));
    ui->txtOutput->append("✓ 處理完成");
    ui->txtOutput->append("-------------------");
    statusBar()->showMessage("資料處理完成");
}

void MainWindow::onClearClicked()
{
    ui->txtName->clear();
    ui->txtEmail->clear();
    ui->txtOutput->clear();
    statusBar()->showMessage("已清除所有欄位");
    ui->txtOutput->append("ℹ 所有欄位已清除");
}
