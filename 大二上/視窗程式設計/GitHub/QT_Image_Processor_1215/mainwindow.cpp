#include "mainwindow.h"

#include <QHBoxLayout>
#include <QMenuBar>
#include <QScrollArea>
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("影像處理"));
    central = new QWidget();
    QHBoxLayout *mainLayout = new QHBoxLayout(central);
    imgWin = new QLabel();
    QPixmap *intiPixmap = new QPixmap(300, 200);
    intiPixmap->fill(QColor(255, 255, 255));
    // imgWin->resize(300, 200);
    // imgWin->setScaledContents(true);
    imgWin->setPixmap(*intiPixmap);
    imgWin->adjustSize();
    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setWidget(imgWin);
    scrollArea->setWidgetResizable(true);
    mainLayout->addWidget(scrollArea);
    // mainLayout->addWidget(imgWin);
    setCentralWidget(central);
    createActions();
    createMenus();
    createToolBars();
};

MainWindow::~MainWindow() {}

void MainWindow::createActions() {
    openFileAction = new QAction(QStringLiteral("開啟檔案&O"), this);
    openFileAction->setShortcut(tr("Ctrl+O"));
    openFileAction->setStatusTip(QStringLiteral("開啟影像檔案"));
    connect(
        openFileAction,
        SIGNAL(triggered()),
        this,
        SLOT(showOpenFile())
    );

    exitAction = new QAction(QStringLiteral("結束&Q"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(QStringLiteral("退出程式"));
    connect(
        exitAction,
        SIGNAL(triggered()),
        this,
        SLOT(close())
    );

    zoonInAction = new QAction(QStringLiteral("放大&["), this);
    zoonInAction->setShortcut(tr("Ctrl+["));
    zoonInAction->setStatusTip(QStringLiteral("放大"));
    connect(
        zoonInAction,
        SIGNAL(triggered()),
        this,
        SLOT(zoon_in())
    );
    zoonOutAction = new QAction(QStringLiteral("縮小&]"), this);
    zoonOutAction->setShortcut(tr("Ctrl+]"));
    zoonOutAction->setStatusTip(QStringLiteral("縮小"));
    connect(
        zoonOutAction,
        SIGNAL(triggered()),
        this,
        SLOT(zoon_out())
    );
};
void MainWindow::createMenus() {
    fileMenu = menuBar()->addMenu(QStringLiteral("檔案&F"));
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(exitAction);

    fileMenuTools = menuBar()->addMenu(QStringLiteral("工具"));
    fileMenuTools->addAction(zoonInAction);
    fileMenuTools->addAction(zoonOutAction);
};
void MainWindow::createToolBars() {
    fileTool = addToolBar("file");
    fileTool->addAction(openFileAction);
};

void MainWindow::zoon_in() {
    img = img.scaled(img.size()*2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imgWin->setPixmap(QPixmap::fromImage(img));
    imgWin->adjustSize();
    qDebug() << "size" << img.size();
};
void MainWindow::zoon_out() {
    img = img.scaled(img.size()/2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imgWin->setPixmap(QPixmap::fromImage(img));
    imgWin->adjustSize();
    qDebug() << "size" << img.size();
};

void MainWindow::loadFile(QString filename) {
    qDebug() << QString("file name %1").arg(filename);
    QByteArray ba = filename.toLatin1();
    printf("FN: %s\n", (char*) ba.data());
    img.load(filename);
    imgWin->setPixmap(QPixmap::fromImage(img));
    imgWin->adjustSize();
};
void MainWindow::showOpenFile() {
    filename = QFileDialog::getOpenFileName(
        this,
        QStringLiteral("開啟影像"),
        tr("."),
        "png(*.png);;bmp(*.bmp)"
        ";;Jpeg(*.jpg)"
    );
    if (!filename.isEmpty()) {
        if (img.isNull()) {
            loadFile(filename);
        } else {
            MainWindow *newIPWin = new MainWindow();
            newIPWin->show();
            newIPWin->loadFile(filename);
        }
    }
};
