#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void rnd_caesar();

private slots:
    void show_dialog(const QString &text);
    void setCaesarText(const QString &text);
    // void on_lineEdit_textChanged(const QString &text);
    void on_lineEdit_cursorPositionChanged(int oldPos, int newPos);
private:
    Ui::MainWindow *ui;
    int caesar_offsets[65] = { 0 };
    const char chars_ref[53] = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
};
#endif // MAINWINDOW_H
