#include "widget.h"

#include <Qpixmap>
#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    mainLayout = new QHBoxLayout(this);
    leftLayout = new QVBoxLayout(this);
    // leftLayout = new QVBoxLayout();
    mirrorGroup = new QGroupBox(QStringLiteral("鏡射"), this);
    groupLayout = new QVBoxLayout(mirrorGroup);

    hCheckBox = new QCheckBox(QStringLiteral("水平"), mirrorGroup);
    vCheckBox = new QCheckBox(QStringLiteral("垂直"),mirrorGroup);
    mirrorButton = new QPushButton(QStringLiteral("執行"),mirrorGroup);
    saveButton = new QPushButton(QStringLiteral("儲存"),mirrorGroup);
    importButton = new QPushButton(QStringLiteral("開啟"),mirrorGroup);

    /*
    groupLayout->addWidget(hCheckBox);
    groupLayout->addWidget(vCheckBox);
    groupLayout->addWidget(mirrorButton);
    groupLayout->addWidget(saveButton);
    groupLayout->addWidget(importButton);
    */
    hCheckBox->setGeometry(QRect(13, 28, 87, 19));
    vCheckBox->setGeometry(QRect(13, 54, 87, 19));
    mirrorButton->setGeometry(QRect(13, 80, 93, 28));
    saveButton->setGeometry(QRect(13, 108, 93, 28));
    importButton->setGeometry(QRect(13, 136, 93, 28));

    groupLayout->addWidget(hCheckBox);
    groupLayout->addWidget(vCheckBox);
    groupLayout->addWidget(mirrorButton);
    groupLayout->addWidget(saveButton);
    groupLayout->addWidget(importButton);

    leftLayout->addWidget(mirrorGroup);
    rotateDial = new QDial(this);
    rotateDial->setNotchesVisible(true);
    vSpacer = new QSpacerItem(
        20, 58,
        QSizePolicy:: Minimum,
        QSizePolicy:: Expanding
    );

    leftLayout->addWidget(rotateDial);
    leftLayout->addItem(vSpacer);
    mainLayout->addLayout(leftLayout);

    inWin = new QLabel(this);
    inWin->setScaledContents(true);
    QPixmap *initPixmap= new QPixmap(300,200);
    initPixmap->fill(QColor(255,255,255));
    inWin->setPixmap(*initPixmap);
    inWin->setSizePolicy(QSizePolicy:: Expanding, QSizePolicy:: Expanding);
    if (srcImg.isNull())
    {
        QPixmap *initPixmap= new QPixmap(300,200);
        initPixmap->fill(QColor(255,255,255));
        inWin->setPixmap(*initPixmap);
    }
    mainLayout->addWidget (inWin);
    connect(mirrorButton, SIGNAL(clicked()), this, SLOT(mirrorImage()));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveImage()));
    connect(importButton, SIGNAL(clicked()), this, SLOT(importImage()));
    connect(rotateDial, SIGNAL(valueChanged(int)), this, SLOT(rotateImage()));


}

Widget::~Widget() {}

void Widget::mirrorImage() {
    bool H, V;
    if (srcImg.isNull()) return;
    H = hCheckBox->isChecked();
    V = vCheckBox->isChecked();
    dstImg = srcImg.mirrored(H, V);
    inWin->setPixmap(QPixmap::fromImage(dstImg));
    srcImg = dstImg;
};

void Widget::rotateImage() {
    if(srcImg.isNull()) return;
    QTransform tran;
    int angle = rotateDial->value();
    tran.rotate(angle);
    dstImg = srcImg.transformed(tran);
    inWin->setPixmap(QPixmap::fromImage(dstImg));
};

void Widget::saveImage() {
    if(srcImg.isNull()) return;
    try {
        QString path = QFileDialog::getSaveFileName(
            this,
            tr("儲存圖片"),
            QDir::homePath(),
            tr("(*.png);;(*.jpg);;(*.jpeg);;All(*)")
        );
        srcImg.save(path);
    } catch (QString e) {
        qDebug() << "Catched an error: \n" <<e;
    }
}

void Widget::importImage() {
    // if(srcImg.isNull()) return;
    try {
        QString path = QFileDialog::getOpenFileName(
            this,
            tr("請選擇要開啟的圖片"),
            QDir::homePath(),
            tr("(*.png);;(*.jpg);;(*.jpeg);;All(*)")
        );
        if (srcImg.load(path)) {
            inWin->setPixmap(QPixmap::fromImage(srcImg));
        }
    } catch (QString e) {
        qDebug() << "Catched an error: \n" <<e;
    }
}
