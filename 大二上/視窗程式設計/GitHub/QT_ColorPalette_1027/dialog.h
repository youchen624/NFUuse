#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtWidgets>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    QTextEdit* displayTextEdit;
    QPushButton* colorPushButton;
    QPushButton* errorPushButton;
    QPushButton* filePushButton;
    QPushButton* fontPushButton;
    QPushButton* inputPushButton;
    QPushButton* pagePushButton;
    QPushButton* progressPushButton;
    QPushButton* printPushButton;
    QPushButton* fcolorPushButton;
private slots:
    void doPushBtn();
};
#endif // DIALOG_H
