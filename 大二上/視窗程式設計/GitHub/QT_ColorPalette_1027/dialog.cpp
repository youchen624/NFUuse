#include "dialog.h"

#include <QtPrintSupport/qprinter.h>
#include <QtPrintSupport/qpagesetupdialog.h>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrintPreviewDialog>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    QGridLayout* gridLayout = new QGridLayout;
    displayTextEdit = new QTextEdit(QStringLiteral("通用對話盒"));
    colorPushButton = new QPushButton(QStringLiteral("顏色對話盒"));
    errorPushButton = new QPushButton(QStringLiteral("錯誤訊息盒"));
    filePushButton = new QPushButton(QStringLiteral("檔案對話盒"));
    fontPushButton = new QPushButton(QStringLiteral("字體對話盒"));
    inputPushButton = new QPushButton(QStringLiteral("輸入對話盒"));
    pagePushButton = new QPushButton(QStringLiteral("頁面設定對話盒"));
    progressPushButton = new QPushButton(QStringLiteral("進度對話盒"));
    printPushButton = new QPushButton(QStringLiteral("列印對話盒"));
    fcolorPushButton = new QPushButton(QStringLiteral("文字顏色對話盒"));

    gridLayout->addWidget(colorPushButton, 0, 0, 1, 1);
    gridLayout->addWidget(errorPushButton, 0, 1, 1, 1);
    gridLayout->addWidget(filePushButton, 0, 2, 1, 1);
    gridLayout->addWidget(fontPushButton, 1, 0, 1, 1);
    gridLayout->addWidget(inputPushButton, 1, 1, 1, 1);
    gridLayout->addWidget(pagePushButton, 1, 2, 1, 1);
    gridLayout->addWidget(progressPushButton, 2, 0, 1, 1);
    gridLayout->addWidget(printPushButton, 2, 1, 1, 1);
    gridLayout->addWidget(fcolorPushButton, 2, 2, 1, 1);
    gridLayout->addWidget(displayTextEdit, 3, 0, 3, 3);

    setLayout(gridLayout);
    setWindowTitle(QStringLiteral("內建對話盒展示"));
    resize(400, 300);

    connect (colorPushButton,SIGNAL(clicked()),this, SLOT (doPushBtn()));
    connect (errorPushButton, SIGNAL(clicked()),this, SLOT (doPushBtn()));
    connect (filePushButton, SIGNAL(clicked()), this, SLOT (doPushBtn()));
    connect (fontPushButton, SIGNAL(clicked()), this, SLOT (doPushBtn()));
    connect (inputPushButton, SIGNAL(clicked()), this, SLOT (doPushBtn()));
    connect (progressPushButton, SIGNAL(clicked()),this, SLOT (doPushBtn()));
    connect (pagePushButton, SIGNAL(clicked()), this, SLOT (doPushBtn()));
    connect (printPushButton, SIGNAL(clicked()), this, SLOT (doPushBtn()));
    connect (fcolorPushButton, SIGNAL(clicked()), this, SLOT (doPushBtn()));
}

void Dialog::doPushBtn() {
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    if (btn == colorPushButton) {
        QPalette palette = displayTextEdit->palette();
        const QColor& color = QColorDialog::getColor(
            palette.color(QPalette::Base),
            this,
            QStringLiteral("設定背景顏色")
        );

        if (color.isValid()) {
            palette.setColor(QPalette::Base, color);
            displayTextEdit->setPalette(palette);
        }
    }
    if (btn == errorPushButton) {
        /*
         * // MAKES CRASHS
        QErrorMessage box(this);
        box.setWindowTitle(QStringLiteral("錯誤訊息盒"));
        box.showMessage(QStringLiteral("錯誤訊息盒測試1"));
        box.showMessage(QStringLiteral("錯誤訊息盒測試2"));
        box.showMessage(QStringLiteral("錯誤訊息盒測試3"));
        box.exec();
        */
        QMessageBox::critical(
            this,
            QStringLiteral("錯誤訊息"),
            QStringLiteral("錯誤訊息盒測試1")
        );
        QMessageBox::critical(
            this,
            QStringLiteral("錯誤訊息"),
            QStringLiteral("錯誤訊息盒測試2")
        );
        QMessageBox::critical(
            this,
            QStringLiteral("錯誤訊息"),
            QStringLiteral("錯誤訊息盒測試3")
        );
    }
    if (btn == filePushButton) {
        QString fileName = QFileDialog::getOpenFileName(
            this,
            QStringLiteral("打開檔案"),
            ".",
            QStringLiteral(
                "任何檔案(*.*)"
                // L";;文字檔(*.txt)" // ??
                // L";;XML檔(*.xml)" // ??
            )
        );
        displayTextEdit->setText(fileName);
    }
    if (btn == fontPushButton) {
        bool ok;
        const QFont& font = QFontDialog::getFont(
            &ok,
            displayTextEdit->font(),
            this,
            QStringLiteral("字體對話盒")
        );
        if (ok) displayTextEdit->setFont(font);
    }
    if (btn == inputPushButton) {
        bool ok;
        QString text = QInputDialog::getText(
            this,
            QStringLiteral("輸入對話盒"),
            QStringLiteral("輸入文字"),
            QLineEdit::Normal,
            QDir::home().dirName(),
            &ok
        );
        if (ok && !text.isEmpty()) displayTextEdit->setText(text);
    }
    if (btn == pagePushButton) {
        QPrinter printer(QPrinter::HighResolution);
        QPageSetupDialog* dlg = new QPageSetupDialog(&printer, this);
        dlg->setWindowTitle(QStringLiteral("頁面設定話方塊"));
        if (dlg->exec() == QDialog::Accepted) {
            ;
        }
    }
    if (btn == progressPushButton) {
        QProgressDialog progress(
            QStringLiteral("在複製檔案"),
            QString("取消"),
            0,
            10000,
            this
        );
        progress.setWindowTitle(QStringLiteral("進度對話方塊"));
        progress.show();
        for (int i = 0; i < 10000; ++i) {
            progress.setValue(i);
            qApp->processEvents();
            if (progress.wasCanceled()) break;
            qDebug() << i;
        }
        progress.setValue(10000);
    }
    if (btn == printPushButton) {
        QPrinter printer(QPrinter::HighResolution);
        QPrintDialog dialog(&printer, this);
        if (dialog.exec() != QDialog::Accepted) return;
    }
    if (btn == fcolorPushButton) {
        QPalette palette = displayTextEdit->palette();
        const QColor& initialColor = palette.color(QPalette::Text);
        const QColor& newColor = QColorDialog::getColor(
            initialColor,
            this,
            QStringLiteral("設定文字顏色")
            );
        if (newColor.isValid()) {
            palette.setColor(QPalette::Text, newColor);
            displayTextEdit->setPalette(palette);
        }
    }
};

Dialog::~Dialog() {}
